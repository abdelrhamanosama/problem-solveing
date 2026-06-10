// Last updated: 6/10/2026, 11:48:07 AM
import java.util.Stack;
class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        Stack <Integer> stack = new Stack<Integer>();
        int []answer = new int[temperatures.length];
        for(int i = 0; i < temperatures.length; i++) {
            while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
                int index = stack.pop();
                answer[index] = i - index;
            }
            stack.push(i);
        }
        return answer;         
    }
}