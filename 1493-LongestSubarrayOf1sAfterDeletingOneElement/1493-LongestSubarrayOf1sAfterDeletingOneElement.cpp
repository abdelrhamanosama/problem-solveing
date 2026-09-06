// Last updated: 9/6/2026, 2:24:05 PM
class Solution {
public:
int longestSubarray(vector<int> &nums)
{
    int counter = 0, maxvalue = 0, flag = 0, i, j;
    for ( i = 0, j = 0; j < nums.size(); j++)
    {
        if (nums[j] == 0)
            counter++;
        // cout<<maxvalue << " " << i<<" "<< j<<" " <<counter<<endl;
        
        if (counter > 1)
        {
            maxvalue = max(maxvalue, j - i - 1);

            while (counter > 1)
            {
                if (nums[i] == 0)
                    counter--;
                i++;
            }
            flag = 1;
        }
        // cout<<maxvalue << " " << i<<" "<< j<<" " <<counter<<endl;
    }
    if(counter < 2)
    maxvalue = max(maxvalue, j - i - 1);
    if (counter == 0 || !flag)
        return nums.size() - 1;
    return maxvalue;
}

};