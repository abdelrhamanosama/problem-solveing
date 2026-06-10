// Last updated: 6/10/2026, 11:42:17 AM
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for(int i = low ; i <= high ; i++)
        {
            int a[10] = {};
            int l = 0, sumr = 0, suml = 0, num = i;
            
            while(num){
                a[l++] = num%10;
                num/=10;
            }
            if(l&1) continue;
            for(int j = 0; j < l /2 ;j++){
                suml+=a[j];
                sumr+=a[l-j-1];
            }
            if(!(sumr-suml))cnt++;
        }
        return cnt;
    }
};