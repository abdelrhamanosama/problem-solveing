// Last updated: 8/3/2026, 9:05:01 PM
1class RandomizedSet {
2    unordered_map<int,int> valueToIndex;
3    vector<int> values;
4public:
5    RandomizedSet() {
6        
7    }
8    bool search(int val){
9        return valueToIndex.find(val) != valueToIndex.end();
10    }
11    bool insert(int val) {
12        if(search(val)) return false;
13
14        values.push_back(val);
15        valueToIndex[val] = values.size() - 1;
16        return true;
17    }
18    
19    bool remove(int val) {
20        if(!search(val)) return false;
21        int freeIndex = valueToIndex[val];
22        int lastIndex = valueToIndex[values.back()];
23        
24        swap(values[freeIndex] , values[lastIndex]);
25        valueToIndex[values[freeIndex]] = freeIndex;
26        values.pop_back();
27        valueToIndex.erase(val);
28        return true;
29    }
30    
31    int getRandom() {
32        return values[rand()%values.size()];
33    }
34};
35
36/**
37 * Your RandomizedSet object will be instantiated and called as such:
38 * RandomizedSet* obj = new RandomizedSet();
39 * bool param_1 = obj->insert(val);
40 * bool param_2 = obj->remove(val);
41 * int param_3 = obj->getRandom();
42 */