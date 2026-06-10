// Last updated: 6/10/2026, 11:49:39 AM
class Solution {
    public int calculate(String s) {
        int number  = 0;
        boolean negative = false;
        boolean positive = false;
        negative=(s.contains("-"))? true:false;
        positive=(s.contains("+"))? true:false;
        String arr[] = s.split("\\+");
        if(arr.length == 1 && !negative && !positive) { System.out.println("A\n" + s); return MAndD((s));}
        System.out.println(arr.length + " length \n" + negative + " bool \t" + positive + " bool 2 \n" + arr[0]);
        for (String string : arr) {
            String ss[]  = string.split("\\-");
            for (int i = 0 ; i < ss.length ; i++) {
                if(i == 0 )
                    number += MAndD(ss[i]);
                else
                    number -= MAndD(ss[i]);
            }   
        }
        return number;
    }
    public int MAndD(String ss){
        StringBuilder temp1=new StringBuilder();
        boolean done = false; char op='\0';
        int sum = 1 ;
        for(int i = 0; i < ss.length(); i++) {
                char ch = ss.charAt(i);
                if((ch >= '0' && ch <= '9')) {
                        temp1.append(ch);
                        System.out.println(temp1 + " temp");
                    }
                else if(!(ch >= '0' && ch <= '9')&& ch !=' ') {
                    if(done) sum=temper(temp1, op,sum);
                    if(!done && op=='\0') sum=temper(temp1, '*',sum);
                    if((!done)&&ch=='/') sum = Integer.parseInt(new String(temp1));
                    done = true;
                    op = ch;
                    temp1 = new StringBuilder("");
                }
                System.out.println(sum + "sum");
            }
        if(done) sum=temper(temp1, op,sum);
    return (!done)? Integer.parseInt(ss.trim()):sum;
    }
    private int temper(StringBuilder x , char ch , int sum){
            String s = x.toString();
            // int sum=1;
                    switch (ch) {
                        case '*':
                                sum *= Integer.parseInt(s);
                            break;
                        case '/':
                                sum /= Integer.parseInt(s);
                            break;
                    }
            return sum;
    }
}