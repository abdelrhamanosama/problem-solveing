// Last updated: 9/6/2026, 2:23:10 PM
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