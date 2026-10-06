// Last updated: 10/6/2026, 7:37:23 PM
1public class Solution {
2        public int minAddToMakeValid(String pattern) {
3        Stack<Character> s = new Stack<Character>();
4            s.push(pattern.charAt(0));
5            // System.out.println("stack" + s);
6        for(int i = 1; i < pattern.length(); i++)
7            {
8                char ch = pattern.charAt(i);
9                if(!s.empty())
10                    {
11                        if(s.peek() == '(' && ch == ')')
12                            s.pop();
13                        else
14                            s.push(ch);
15                    }
16                else
17                    s.push(ch);
18        }
19            return s.size();
20    }
21}
22/*
23public class Solution {
24        public int minAddToMakeValid(String s) {
25        Stack<Character> s = new Stack<Character>();
26            s.push(pattern.charAt(0));
27            // System.out.println("stack" + s);
28        for(int i = 1; i < pattern.length(); i++)
29            {
30                char ch = pattern.charAt(i);
31                if(!s.empty())
32                    {
33                        if(s.peek() == '(' && ch == ')')
34                            s.pop();
35                        else
36                            s.push(ch);
37                    }
38                else
39                    s.push(ch);
40        }
41            return s.size();
42    }
43}
44/*4
45)((()
46((
47(((((
48))(
49 */
50 