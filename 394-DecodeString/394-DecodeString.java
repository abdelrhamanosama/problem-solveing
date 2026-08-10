// Last updated: 8/11/2026, 2:36:22 AM
1class Solution {
2    public String decodeString(String s) {
3        Stack<StringBuilder> stText = new Stack<>();
4        Stack<Integer> stNum = new Stack<>();
5        Integer num = 0;
6        StringBuilder current = new StringBuilder("");
7        for (int i = 0; i < s.length(); i++) {
8            char c = s.charAt(i);
9             // Build the number 
10            if (Character.isDigit(c)) {
11                num = num * 10 + (c - '0');
12            }
13            else if(c == '['){
14                stNum.push(num);
15                stText.push(current);
16                current = new StringBuilder("");
17                num = 0;
18            }
19            else if(c == ']'){
20                Integer times = stNum.pop();
21
22                StringBuilder previous = stText.pop();
23
24                StringBuilder decoded = new StringBuilder();
25
26                for (Integer j = 0; j < times; j++) {
27                    decoded.append(current);
28                }
29                previous.append(decoded);
30                current = previous;   
31            }
32            else 
33                {
34                    current.append(c);
35                }
36        }
37        return current.toString();
38    }
39}