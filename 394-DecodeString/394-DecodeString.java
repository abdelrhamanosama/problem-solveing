// Last updated: 8/11/2026, 2:28:14 AM
1
2class Solution {
3
4    public String decodeString(String s) {
5
6        Stack<Integer> stNum = new Stack<>();
7        Stack<StringBuilder> stText = new Stack<>();
8
9        StringBuilder current = new StringBuilder();
10        int num = 0;
11
12        for (int i = 0; i < s.length(); i++) {
13
14            char c = s.charAt(i);
15
16            // Build the number
17            if (Character.isDigit(c)) {
18
19                num = num * 10 + (c - '0');
20            }
21
22            // Start a new encoded section
23            else if (c == '[') {
24
25                // Save the multiplier
26                stNum.push(num);
27
28                // Save everything built before '['
29                stText.push(current);
30
31                // Start building the content inside brackets
32                current = new StringBuilder();
33
34                num = 0;
35            }
36
37            // Finish an encoded section
38            else if (c == ']') {
39
40                int times = stNum.pop();
41
42                StringBuilder previous = stText.pop();
43
44                StringBuilder decoded = new StringBuilder();
45
46                for (int j = 0; j < times; j++) {
47                    decoded.append(current);
48                }
49
50                // Append decoded part to the text before '['
51                previous.append(decoded);
52
53                current = previous;
54            }
55
56            // Normal character
57            else {
58
59                current.append(c);
60            }
61        }
62
63        return current.toString();
64    }
65}
66