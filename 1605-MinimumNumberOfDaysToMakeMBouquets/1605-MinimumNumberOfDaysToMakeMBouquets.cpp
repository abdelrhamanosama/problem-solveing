// Last updated: 6/10/2026, 11:45:50 AM
class Solution {
public:
int minDays(vector<int>& bloomDay, int m, int k) {
    int size = bloomDay.size();
    if((long long)m * k > size) return -1;
    int min = 1000000000,max = 0;
    for(int i = 0; i < size; i++)
        {
            if(max < bloomDay.at(i))
                max = bloomDay.at(i);
            if(min > bloomDay.at(i))
                min = bloomDay.at(i);
        }
        while(min < max){
            int mid = (min+max)/2;
            int x = getNumberOfFlowers(bloomDay, mid,k);
            if(x < m)
                min = mid + 1;
            else
                max = mid;
        }
        return min;
}  
int getNumberOfFlowers(vector<int> vec, int m , int k) {
    int bouquets = 0, numberOfFlowers = 0;
    int size = vec.size();
    for(int i = 0; i < size; i++) {
        if(vec.at(i) <= m)
            numberOfFlowers++;
        else 
            numberOfFlowers = 0;
        if(numberOfFlowers == k) {
            numberOfFlowers = 0;
            bouquets++;
        }
    }
    return bouquets;
}};