// Last updated: 10/28/2026, 2:26:27 AM
1class Solution {
2    public String[] createGrid(int m, int n) {
3        String g[] = new String[m];
4        for(int j=  0; j <  m-1; j++)
5            {
6                String step = "";
7                for(int i = 0 ; i < n; i++)
8                {
9                    if(i > 0)
10                        step+="#";
11                    else 
12                        step+=".";
13                }
14                g[j] = step;
15            }
16            String step = "";
17                for(int i = 0 ; i < n; i++)
18                {
19                        step+=".";
20                }
21            g[m-1] = step;
22        return g;
23    }
24}