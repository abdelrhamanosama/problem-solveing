// Last updated: 7/28/2026, 2:17:11 PM
1class Solution {
2public String smallestPalindrome(String s) {
3    Map<Character, Integer> mp = new HashMap<>();
4    for (char c : s.toCharArray()) {
5        mp.put(c, mp.getOrDefault(c, 0) + 1);
6    }
7
8    // اتأكد إن مفيش أكتر من حرف بعدد فردي
9    char oddChar = 0;
10    int oddCount = 0;
11    for (Map.Entry<Character, Integer> e : mp.entrySet()) {
12        if (e.getValue() % 2 != 0) {
13            oddCount++;
14            oddChar = e.getKey();
15        }
16    }
17    if (oddCount > 1) return ""; // مستحيل تعمل بالندروم
18
19    List<Character> keys = new ArrayList<>(mp.keySet());
20    Collections.sort(keys); // ترتيب تصاعدي عشان أصغر بالندروم ممكن
21
22    StringBuilder half = new StringBuilder();
23    for (char c : keys) {
24        int cnt = mp.get(c) / 2;
25        for (int i = 0; i < cnt; i++) half.append(c);
26    }
27
28    StringBuilder result = new StringBuilder();
29    result.append(half);
30    if (oddCount == 1) result.append(oddChar);
31    result.append(half.reverse());
32
33    return result.toString();
34}
35}