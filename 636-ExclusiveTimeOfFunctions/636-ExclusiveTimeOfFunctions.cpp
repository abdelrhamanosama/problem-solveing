// Last updated: 6/10/2026, 11:48:21 AM
class Solution {
public:
    array<int, 3> helper(const string& s) {
        array<int, 3> a{};
        int id, time;
        string type;
        // نقسم السطر على ':' بشكل مباشر
        int p1 = s.find(':'), p2 = s.find(':', p1 + 1);
        id = stoi(s.substr(0, p1));
        type = s.substr(p1 + 1, p2 - p1 - 1);
        time = stoi(s.substr(p2 + 1));
        a[0] = id;
        a[1] = (type == "start" ? 1 : 2);
        a[2] = (type == "end" ? time + 1 : time);
        return a;
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> func(n, 0);
        array<int, 3> a1, a2;
        stack<array<int,3>> st;
        int timo = 0;
        for (int i = 0; i < logs.size(); i++) {
            if (st.empty()) {
                cout<<"hi";
                a1 = helper (logs[i]);
                st.push(a1);
                timo = a1[2];
            } else{
                a1 = helper (logs[i]);
                a2 = st.top();
                if(a1[0] == a2[0] && a1[1] == 2 && a2[1] == 1){
                    func[a2[0]] += a1[2] - timo;
                    timo = a1[2];
                    st.pop();
                    continue;
                }
                else if(a1[1] == a2[1] == a1[1] == 1){
                    func[a2[0]] += a1[2] - timo;
                    st.push(a1);
                    timo = a1[2];
                }
                cout<<timo<<"\n";
            }
        }
        return func;
    }
};