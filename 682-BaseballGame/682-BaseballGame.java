// Last updated: 6/10/2026, 11:48:10 AM
import java.util.Stack;
class Solution {
    public int calPoints(String[] operations) {
    Stack<Integer> stack = new Stack<Integer>();
    for (String s : operations) {
        int i = 0, x = 0;
        // System.out.print(s);
        switch (s) {
            case "D":
                if(!stack.isEmpty()) stack.push(stack.peek()*2);
                break;
            case "C": if(!stack.isEmpty()) stack.pop();   
                break;
            case "+":   i = stack.pop();
                        x = stack.peek();
                        stack.push(i);
                        stack.push(i+x);
                break;
            default:
                stack.push(Integer.parseInt(s));
                break;
        }
        // System.out.println(stack.toString());
    }
    int record = 0;
    while (!stack.isEmpty()) {
        record += stack.pop();
    }
    return record;
    }
}