// Last updated: 8/10/2026, 11:17:35 PM
1class Solution {
2    
3    public char findKthBit(int n, int k) {
4        return work(n).charAt(k-1);
5    }
6
7    private StringBuilder work(int n)
8    {
9        if(n == 1) return new StringBuilder("0");
10
11        StringBuilder sb = work(n-1);
12        StringBuilder sbb = new StringBuilder(sb);
13        sbb.append("1");
14        for(int i = sb.length()- 1 ; i >= 0; i--)
15            {
16                if(sb.charAt(i) == '1') sbb.append("0");
17                else sbb.append("1");
18            }
19        // System.out.println(sbb + "\t" + sb + "\t" + n);
20        return sbb;
21    }
22}