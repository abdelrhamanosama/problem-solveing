// Last updated: 9/6/2026, 2:20:45 PM
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt = 0;

        for (int i = 0; i < 26; i++) {
            char a = 'a' + i;

            // ابحث عن أول وآخر مرة يظهر فيها a
            int first = s.find(a);
            int last  = s.rfind(a);

            if (first == string::npos || first == last) continue;

            // حروف الوسط الفريدة
            vector<bool> seen(26, false);

            for (int k = first + 1; k < last; k++) {
                seen[s[k] - 'a'] = true;
            }

            for (int x = 0; x < 26; x++) {
                if (seen[x]) cnt++;
            }
        }

        return cnt;
    }
};
