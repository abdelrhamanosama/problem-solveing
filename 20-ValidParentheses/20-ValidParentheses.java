// Last updated: 6/10/2026, 11:51:10 AM
import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        if(s.length()%2 == 1) return false;
        Stack<Character> stack = new Stack<Character>();
        for(int i=0; i<s.length(); i++)
        {
            char ch  = s.charAt(i);
            if(ch == ')' || ch == ']' || ch == '}') {
                if(stack.isEmpty())
                    return false;
                    switch (stack.peek()) {
                    case '(':
                            if(ch == ')')
                                stack.pop();
                            else
                                return false;
                        break;
                    case '[':
                            if(ch == ']')
                                stack.pop();
                            else
                                return false;
                        break;
                    case '{':
                            if(ch == '}')
                                stack.pop();
                            else
                                return false;
                        break;
                }
                }
                else
                {   
                    stack.push(ch);
                }
        }
        return(stack.isEmpty());
    }
}