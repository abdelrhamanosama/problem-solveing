// Last updated: 6/10/2026, 11:50:27 AM
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        if(rowIndex == 0) 
            {
                v.push_back(1);
                return v;
            }
        else {
            v.push_back(1);
            v.push_back(1);
            rowIndex--;
            if(rowIndex == 0) return v;
            rowIndex--;
            while(rowIndex >= 0){
                vector<int>temp;
                temp.push_back(1);
                for(int i = 0 ; i < v.size()-1; i++)
                    temp.push_back(v[i]+v[i+1]);
                temp.push_back(1);
                rowIndex--;
                v = temp;    
            }
            return v;

        }

    }
};