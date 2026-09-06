// Last updated: 9/6/2026, 2:20:42 PM
class Solution {
    public int getLucky(String s, int k) {
    String num = "" ;
    for(int i = 0 ; i < s.length() ; i ++)
        num += (s.charAt(i) - 'a' + 1);
    while(k -- > 0)
    {
        int sum = 0 ;
        for(int i = num.length() - 1 ; i >= 0; i --)
        {
            sum += num.charAt(i) -'0';
        }
        num = sum + "";
    }
    return Integer.parseInt(num);
    
    }
    
}