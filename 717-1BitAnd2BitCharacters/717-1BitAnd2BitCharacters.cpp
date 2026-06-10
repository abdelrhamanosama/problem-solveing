// Last updated: 6/10/2026, 11:48:04 AM
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        for(int i = 0 ; i < bits.size(); i++){
            if(bits[i] == 0) continue;
            if(bits[i] == 1){
                if(i == bits.size() - 1){
                    return 0;
                }
                if(i+1 == bits.size()-1)    return 0;
                else i++;
            }
        }    
        return 1;
    }
};