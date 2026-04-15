import os
import requests
import git
from dotenv import load_dotenv

load_dotenv()

# GraphQL endpoint
LEETCODE_GRAPHQL_URL = "https://leetcode.com/graphql"

def get_headers():
    csrf_token = os.getenv("LEETCODE_CSRF_TOKEN", "")
    session = os.getenv("LEETCODE_SESSION_COOKIE", "")
    
    return {
        "Content-Type": "application/json",
        "cookie": f"LEETCODE_SESSION={session}; csrftoken={csrf_token}",
        "x-csrftoken": csrf_token,
        "Referer": "https://leetcode.com/",
        "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36"
    }

def fetch_recent_submissions(limit=10):
    """Fetch recent submissions from LeetCode."""
    query = """
    query submissionList($offset: Int!, $limit: Int!) {
      submissionList(offset: $offset, limit: $limit) {
        submissions {
          id
          title
          titleSlug
          statusDisplay
          lang
        }
      }
    }
    """
    
    variables = {
        "offset": 0,
        "limit": limit
    }
    
    response = requests.post(
        LEETCODE_GRAPHQL_URL,
        json={"query": query, "variables": variables},
        headers=get_headers()
    )
    
    if response.status_code != 200:
        print(f"Failed to fetch submissions. HTTP {response.status_code}.")
        return []
        
    data = response.json()
    submissions = data.get("data", {}).get("submissionList", {}).get("submissions", [])
    
    # Just to be extra safe, double filter
    accepted = [s for s in submissions if s.get("statusDisplay") == "Accepted"]
    return accepted

def fetch_submission_code(submission_id):
    """Fetch the actual source code for a specific submission."""
    query = """
    query submissionDetails($submissionId: Int!) {
      submissionDetails(submissionId: $submissionId) {
        code
      }
    }
    """
    
    variables = {
        "submissionId": submission_id
    }
    
    response = requests.post(
        LEETCODE_GRAPHQL_URL,
        json={"query": query, "variables": variables},
        headers=get_headers()
    )
    
    if response.status_code == 200:
        data = response.json()
        return data.get("data", {}).get("submissionDetails", {}).get("code", "")
    return ""

def get_file_extension(language):
    lang_map = {
        "cpp": ".cpp",
        "python": ".py",
        "python3": ".py",
        "java": ".java",
        "javascript": ".js",
        "rust": ".rs",
        "c": ".c",
        "golang": ".go",
        "csharp": ".cs"
    }
    return lang_map.get(language.lower(), ".txt")

def ensure_cpp_boilerplate(code: str) -> str:
    """Ensure using namespace std; is present per user requirements"""
    if "using namespace std" not in code and "#include" in code:
        lines = code.split("\n")
        insert_idx = sum(1 for i, line in enumerate(lines) if line.strip().startswith("#include"))
        lines.insert(insert_idx, "\nusing namespace std;\n")
        return "\n".join(lines)
    return code

def process_submissions():
    if not os.getenv("LEETCODE_SESSION_COOKIE") or not os.getenv("LEETCODE_CSRF_TOKEN"):
        print("Wait! Please set your LEETCODE_SESSION_COOKIE and LEETCODE_CSRF_TOKEN in your .env file first.")
        return
        
    print("Fetching recent accepted LeetCode submissions...")
    submissions = fetch_recent_submissions(limit=10)
    
    if not submissions:
        print("No accepted submissions found, or your authentication cookies have expired/rejected.")
        return
        
    base_dir = os.path.join(os.getcwd(), "LeetCode")
    os.makedirs(base_dir, exist_ok=True)
    
    print(f"Found {len(submissions)} accepted submissions. Downloading code...\n")
    
    for sub in submissions:
        sub_id = sub["id"]
        title = sub["title"]
        lang = sub["lang"]
        
        print(f"-> Processing: {title} ({lang})")
        
        code = fetch_submission_code(int(sub_id))
        if not code:
            print("   [!] Could not fetch source code.")
            continue
            
        ext = get_file_extension(lang)
        if ext == ".cpp":
            code = ensure_cpp_boilerplate(code)
            
        safe_title = title.replace("/", "_").replace("\\", "_")
        
        # We can add difficulty sub-folders later if needed, saving directly to LeetCode/ for now
        file_path = os.path.join(base_dir, f"{safe_title}{ext}")
        
        try:
            repo = git.Repo(os.getcwd())
        except Exception as e:
            repo = None
            print(f"   [Git Error] Could not initialize repo: {e}")
        
        # Check if we already have this exact file to avoid redundant commits
        skip_write = False
        if os.path.exists(file_path):
            with open(file_path, "r", encoding="utf-8") as f:
                existing_code = f.read()
            if existing_code == code:
                print(f"   [Skipped] {safe_title} (Already exists)")
                skip_write = True

        if not skip_write:
            with open(file_path, "w", encoding="utf-8") as f:
                f.write(code)
            print(f"   Saved to {file_path}")

        # Git Automation
        if repo:
            try:
                repo.git.add(file_path)
                
                # Check if there are actually changes to commit
                # Using repo.index.diff("HEAD") instead of uncommitted generic changes for tight control
                if repo.is_dirty() or file_path in repo.untracked_files or repo.index.diff("HEAD"):
                    commit_message = f"Add {title} from LeetCode"
                    repo.index.commit(commit_message)
                    print(f"   [Git] Committed: '{commit_message}'")
                    
                    # Push if origin exists
                    if "origin" in [r.name for r in repo.remotes]:
                        repo.remotes.origin.push()
                        print(f"   [Git] Pushed to origin!")
            except Exception as e:
                # If there's nothing to commit, it will just quietly pass
                pass

if __name__ == "__main__":
    process_submissions()
