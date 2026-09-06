// Last updated: 9/6/2026, 2:26:18 PM
class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> pq;

        for (int x : target) {
            sum += x;
            pq.push(x);
        }

        while (true) {
            long long x = pq.top(); 
            pq.pop();
            long long rest = sum - x;  // مجموع باقي العناصر

            if (x == 1 || rest == 1)
                return true;  // دايمًا ممكن نوصل لـ 1

            if (rest == 0 || rest >= x)
                return false;

            long long newVal = x % rest;

            if (newVal == 0) newVal = rest;

            sum = rest + newVal;
            pq.push(newVal);
        }
        return true;
    }
};
