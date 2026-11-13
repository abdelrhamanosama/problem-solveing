// Last updated: 11/13/2026, 2:54:04 PM
1class Solution {
2    public int[] assignTasks(int[] servers, int[] tasks) {
3        PriorityQueue<int[]> free = new PriorityQueue<>((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
4        for (int i = 0; i < servers.length; i++) {
5            free.offer(new int[]{servers[i], i});
6        }
7        PriorityQueue<long[]> busy = new PriorityQueue<>((a, b) -> {
8            if (a[0] != b[0]) return Long.compare(a[0], b[0]);
9            if (a[1] != b[1]) return Long.compare(a[1], b[1]);
10            return Long.compare(a[2], b[2]);
11        });
12        int m = tasks.length;
13        int[] ans = new int[m];
14        for (int j = 0; j < m; j++) {
15            while (!busy.isEmpty() && busy.peek()[0] <= j) {
16                long[] cur = busy.poll();
17                free.offer(new int[]{(int)cur[1], (int)cur[2]});
18            }
19            if (!free.isEmpty()) {
20                int[] cur = free.poll();
21                ans[j] = cur[1];
22                busy.offer(new long[]{j + (long)tasks[j], cur[0], cur[1]});
23            } else {
24                long[] cur = busy.poll();
25                ans[j] = (int)cur[2];
26                busy.offer(new long[]{cur[0] + tasks[j], cur[1], cur[2]});
27            }
28        }
29        return ans;
30    }
31}