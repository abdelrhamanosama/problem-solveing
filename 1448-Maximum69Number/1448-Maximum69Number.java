// Last updated: 6/10/2026, 11:46:37 AM
class Solution {
   public int maximum69Number (int num) {
        String s = num + "";
        for(int x = 0 ; x < s.length(); x++){
            if(s.charAt(x) == '6'){
                int n = s.length() - x;
                // System.out.println(x + " " + n);
                
                int p = (int)Math.pow(10, n-1);
                int temp = num % p;
                
                num-=temp;
                num/=p;
                num+=3;
                num*=p;
                num+=temp;
                return num;
            }
        }
        return num;
    }
}