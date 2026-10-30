// Last updated: 10/30/2026, 7:52:02 PM
1import java.util.*;
2
3class Solution {
4    int dijkstra(List<int[]>[] adj, String labels, int n, int k) {
5        final long INF = Long.MAX_VALUE / 4;
6        long[][] dist = new long[n][k + 1];
7
8        for (int i = 0; i < n; i++) {
9            Arrays.fill(dist[i], INF);
10        }
11
12        // State: {distance, node, consecutive count}
13        PriorityQueue<long[]> pq = new PriorityQueue<>(
14            Comparator.comparingLong(a -> a[0])
15        );
16
17        dist[0][1] = 0;
18        pq.offer(new long[]{0, 0, 1});
19
20        while (!pq.isEmpty()) {
21            long[] cur = pq.poll();
22
23            long d = cur[0];
24            int u = (int) cur[1];
25            int cnt = (int) cur[2];
26
27            if (d != dist[u][cnt]) continue;
28
29            if (u == n - 1) return (int) d;
30
31            for (int[] edge : adj[u]) {
32                int v = edge[0];
33                int w = edge[1];
34
35                int nextCnt = (labels.charAt(u) == labels.charAt(v))
36                    ? cnt + 1
37                    : 1;
38
39                if (nextCnt > k) continue;
40
41                long nd = d + w;
42
43                if (nd < dist[v][nextCnt]) {
44                    dist[v][nextCnt] = nd;
45                    pq.offer(new long[]{nd, v, nextCnt});
46                }
47            }
48        }
49
50        return -1;
51    }
52
53    public int shortestPath(int n, int[][] edges, String labels, int k) {
54        List<int[]>[] adj = new ArrayList[n];
55
56        for (int i = 0; i < n; i++) {
57            adj[i] = new ArrayList<>();
58        }
59
60        // The graph is directed.
61        for (int[] edge : edges) {
62            int u = edge[0];
63            int v = edge[1];
64            int w = edge[2];
65
66            adj[u].add(new int[]{v, w});
67        }
68
69        return dijkstra(adj, labels, n, k);
70    }
71}