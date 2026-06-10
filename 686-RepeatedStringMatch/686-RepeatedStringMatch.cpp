// Last updated: 6/10/2026, 11:48:08 AM
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string repeated = "";
        int count = 0;
        // كرر a حتى يغطي طول b
        while (repeated.size() < b.size()) {
            repeated += a;
            count++;
        }
        // تحقق إذا b موجودة
        if (repeated.find(b) != string::npos) return count;
        // أضف نسخة واحدة إضافية لتغطية التداخل
        repeated += a;
        if (repeated.find(b) != string::npos) return count + 1;
        return -1;
    }
};
