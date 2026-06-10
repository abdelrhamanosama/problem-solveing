// Last updated: 6/10/2026, 11:42:42 AM
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int  distance = 1e9 , n = words.size();
        for(int i = 0 ; i < words.size(); i++)
            {
                if(words[i] == target)
                    {
                        distance = min(distance , abs(i-startIndex));
                        if(i<=startIndex){
                            distance= min(distance , i+(n-startIndex));
                        }
                        else {
                            distance= min(distance , startIndex+(n-i));

                        }
                    }
            }   
        return distance == 1e9 ? -1 : distance;
    }
};