// Last updated: 7/27/2026, 3:27:33 AM
1class Solution {
2    long mx;
3    int cnt;
4    public int countHighestScoreNodes(int[] parents) {
5        int n = parents.length;
6        List<Integer> list []= new ArrayList[n];
7        for(int i = 0 ; i < n; i++)
8            list[i] = new ArrayList<>();
9        for(int i = 1 ; i < n; i++)
10            list[parents[i]].add(i);
11        mx = cnt = 0;
12        dfs(0,list, n);
13        return cnt;
14    }
15    int dfs(int root , List<Integer>list[] , int n){
16        int total = 0;
17        long prod = 1 , val = 0 , rem = 0;
18        for(var node: list[root]){
19            val = dfs(node , list, n);
20            total+=val;
21            prod*=val;
22        }
23        rem = n-total -1;
24        if(rem > 0) prod*=rem;
25        if(prod>mx){
26            mx=prod;
27            cnt=1;            
28        }
29        else if(prod==mx){
30            cnt++;
31            System.out.println(cnt);
32        }
33        
34        return total+1;
35    }
36}