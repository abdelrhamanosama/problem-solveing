// Last updated: 6/10/2026, 11:44:58 AM
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        deque<int> dq;
        for(int i : students) dq.push_back(i);
        int cnt = students.size();
        int  j = 0; // for sandwiches
        int k = 0;
        while(!dq.empty()){
            if(dq.front() == sandwiches[j]){
                dq.pop_front();
                j++;
                cnt--;
                k = 0;
            }
            else{
                dq.push_back(dq.front());
                dq.pop_front();
                k++;
            }
            if(k == cnt *2) return cnt;
        }
        return cnt;
    }
};