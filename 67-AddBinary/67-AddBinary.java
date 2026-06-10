// Last updated: 6/10/2026, 11:50:43 AM
class Solution {
    public String addBinary(String a, String b) {
        if(a.length() == b.length())
            return (revString(go(a, b)));
        else if(a.length() < b.length())
            {
                a = makStringEqString(a, b.length() - a.length());
                System.out.println(a  +  "\t" +  b);
            }
        else
            {   
                b = makStringEqString(b, a.length() - b.length());
                System.out.println(a  +  "\t" + b);
            }
        return (revString(go(a, b)));

        
    }
    private String go(String a, String b)
    {   
        byte keeper = 0 ;
        String sum = "";
        for(int i = a.length() - 1 ; i >= 0 ; i --)
            {   int resitreation = keeper + (a.charAt(i) - '0') + (b.charAt(i) - '0');
                if(resitreation < 2 )
                    {
                        sum += resitreation + "";
                        keeper = 0 ;
                    }
                else if (resitreation == 2)
                    {
                        sum += 0;
                        keeper = 1;
                    }
                else
                    {
                        sum += 1;
                        keeper = 1;
                    }
            }
            if(keeper == 1)
                sum += 1;
        return sum;
    } 
    private String revString(String sum)
    {
        String end = "";
        for(int i = sum.length() - 1 ; i >= 0 ; i --)
            end += sum.charAt(i);
        return end; 
    }
    private String makStringEqString(String any , int theAdded)
    {
        String New = "";
        for(int i = 0 ; i < theAdded ; i ++)
            New += "0";
        New += any;
        return New;
    }
}