// Last updated: 6/10/2026, 11:45:39 AM
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
    if(numBottles < numExchange) return numBottles;
    // else if(numBottles % numExchange == 0) return numBottles+ numBottles / numExchange + 1;
    int total = numBottles, get = 1, remainder = 0;
    while(get != 0){
        get = numBottles / numExchange;
        remainder = numBottles % numExchange;
        total += get;
        numBottles = get  + remainder;
        cout<<get<<"\t"<<remainder<<endl;
    }
    return total;
}
};