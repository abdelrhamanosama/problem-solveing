// Last updated: 9/6/2026, 2:14:39 PM
class Solution {
public String smallestPalindrome(String s) {
    Map<Character, Integer> mp = new HashMap<>();
    for (char c : s.toCharArray()) {
        mp.put(c, mp.getOrDefault(c, 0) + 1);
    }

    // اتأكد إن مفيش أكتر من حرف بعدد فردي
    char oddChar = 0;
    int oddCount = 0;
    for (Map.Entry<Character, Integer> e : mp.entrySet()) {
        if (e.getValue() % 2 != 0) {
            oddCount++;
            oddChar = e.getKey();
        }
    }
    if (oddCount > 1) return ""; // مستحيل تعمل بالندروم

    List<Character> keys = new ArrayList<>(mp.keySet());
    Collections.sort(keys); // ترتيب تصاعدي عشان أصغر بالندروم ممكن

    StringBuilder half = new StringBuilder();
    for (char c : keys) {
        int cnt = mp.get(c) / 2;
        for (int i = 0; i < cnt; i++) half.append(c);
    }

    StringBuilder result = new StringBuilder();
    result.append(half);
    if (oddCount == 1) result.append(oddChar);
    result.append(half.reverse());

    return result.toString();
}
}