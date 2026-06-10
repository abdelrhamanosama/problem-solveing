// Last updated: 6/10/2026, 11:51:18 AM
class Solution {
    public int romanToInt(String s) {
       int number = 0;
       char last = '\0';
       for (int i = 0; i < s.length(); i++) {
            char ch  = s.charAt(i); // ch = s[i];
            switch (ch) {
                case 'I':
                        number++;
                    break;
                
                case 'V':
                        number+=5;
                    break;
                case 'X':
                        number+=10;
                    break;
                case 'L':
                        number+=50;
                    break;
                
                case 'C':
                        number+=100;
                    break;
                case 'D':
                        number += 500;
                    break;
                case 'M':
                        number+=1000;
                    break;
                
                default:
                    break;
            }
            if(last == 'I' && (ch == 'V' || ch == 'X')){
                    number -= 2; //  -11 + 9
            }
            else if(last == 'X' && (ch == 'L' || ch == 'C'))
            {   //  60 40 110 90 
                number -= 20;
            }
            else if(last == 'C' && (ch == 'D' || ch == 'M'))
            {
                number -= 200;
            }
            last = ch;
       } // IV == 4 
       return number; 
    }
}
// string  Abced