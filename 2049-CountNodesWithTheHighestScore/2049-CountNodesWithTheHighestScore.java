// Last updated: 9/6/2026, 2:19:53 PM
class Solution {
    long mx;
    int cnt;
    public int countHighestScoreNodes(int[] parents) {
        int n = parents.length;
        List<Integer> list []= new ArrayList[n];
        for(int i = 0 ; i < n; i++)
            list[i] = new ArrayList<>();
        for(int i = 1 ; i < n; i++)
            list[parents[i]].add(i);
        mx = cnt = 0;
        dfs(0,list, n);
        return cnt;
    }
    int dfs(int root , List<Integer>list[] , int n){
        int total = 0;
        long prod = 1 , val = 0 , rem = 0;
        for(var node: list[root]){
            val = dfs(node , list, n);
            total+=val;
            prod*=val;
        }
        rem = n-total -1;
        if(rem > 0) prod*=rem;
        if(prod>mx){
            mx=prod;
            cnt=1;            
        }
        else if(prod==mx){
            cnt++;
            System.out.println(cnt);
        }
        
        return total+1;
    }
}