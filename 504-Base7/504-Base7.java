// Last updated: 6/10/2026, 11:48:49 AM
class Solution {
    public String convertToBase7(int x) {
        StringBuilder sb = new StringBuilder("");
        boolean flag = (x >= 0)? true: false;
        x = (flag)? x : x*-1;
        if(x==0) sb.append(x);
        while(x>0){
            sb.append(x%7);
            x/=7;
        }
        StringBuilder s = new StringBuilder();
        s.append('-');
        s.append(sb.reverse());
        return((flag)? sb.toString(): s.toString());
    }
}