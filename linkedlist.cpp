#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val, Node* next1) { 
        data = val;
        next = next1;
    }
    public:
    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node* convert2LL(vector<int> arr){
    if(arr.size()==0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        curr->next=temp;
        curr = curr->next;
    }
    return head;
}
int llen(Node* head){
    int len = 0;
    Node* temp = head;
    while(temp){
        len++;
        temp = temp->next;
    }
    return len;
}
int checkifpresent(Node* head, int key){
    Node* temp = head;
    while(temp){
        if(temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    vector<int> arr ; // Ensure C++11 or later is enabled
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(50);
    Node* head = convert2LL(arr);
     Node* temp= head;
   while(temp){
         cout << temp->data << " ";
         temp = temp->next;
   }
   int length =llen(head);
    cout << "\nLength of linked list: " << length << endl;
    checkifpresent(head,30)?cout<<"Present":cout<<"Not Present";
    return 0;
}