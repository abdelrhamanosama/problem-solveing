// Last updated: 6/10/2026, 11:46:43 AM
import java.util.Queue;
import java.util.concurrent.ConcurrentLinkedQueue;

class Solution {
    public boolean canReach(int[] arr, int start) {
        Queue<Integer> q = new ConcurrentLinkedQueue<>();
        boolean visited[] = new boolean[arr.length];
        q.add(start);
        while(!q.isEmpty()){
            Integer x = q.peek();
            q.poll();
            visited[x] = true;
            if(arr[x] == 0) return true;
            Integer y = x - arr[x];
            Integer z = x + arr[x];
            if(y >=0 && !visited[y]) q.add(y);
            if(z < arr.length && !visited[z]) q.add(z);
        }
        return false;
    }
}