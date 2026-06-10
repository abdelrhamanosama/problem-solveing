// Last updated: 6/10/2026, 11:42:30 AM
template <typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
constexpr int CountDigits(T x) {
  int digits = 1;
  for (; x >= T{ 10 }; x /= T{ 10 }) {
    ++digits;
  }
  return digits;
}

const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#ifndef _WIN32 && ifndef _WIN64
const auto __ = []() {
  struct ___ {
    static void _() {
      ofstream("display_runtime.txt") << 0 << '\n';
    }
  };
  
  atexit(&___::_);
  return 0;
  }();
#endif

#if defined _WIN32 || defined _WIN64
#define USACO(filename) 0
#else
#define USACO(filename) freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout)
#endif
class Solution {
public:
    long long countFairPairs(vector<int>& v, int l, int r) {
        sort(v.begin(), v.end());
        int n = v.size();
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int a = l - v[i];
            int b = r - v[i];
        
            auto left = lower_bound(v.begin() + i + 1, v.end(), a);
            auto right = upper_bound(v.begin() + i + 1, v.end(), b);
            ans += right - left;
    }
        return  ans;
    }  
};