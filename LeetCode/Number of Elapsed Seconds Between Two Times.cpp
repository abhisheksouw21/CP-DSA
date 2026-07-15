class Solution {
    int f(string timestr){
        int h=stoi(timestr.substr(0,2));
        int m=stoi(timestr.substr(3,2));
        int s=stoi(timestr.substr(6,2));
        return (h*3600)+(m*60)+s;
    }
public:
    int secondsBetweenTimes(string startTime, string endTime) {
       return f(endTime)-f(startTime);
    }
};