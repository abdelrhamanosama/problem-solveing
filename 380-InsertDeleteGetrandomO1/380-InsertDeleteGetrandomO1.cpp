// Last updated: 9/6/2026, 4:03:22 PM
class RandomizedSet {
    unordered_map<int,int> valueToIndex;
    vector<int> values;
public:
    RandomizedSet() {
        
    }
    bool search(int val){
        return valueToIndex.find(val) != valueToIndex.end();
    }
    bool insert(int val) {
        if(search(val)) return false;

        values.push_back(val);
        valueToIndex[val] = values.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!search(val)) return false;
        int freeIndex = valueToIndex[val];
        int lastIndex = valueToIndex[values.back()];
        
        swap(values[freeIndex] , values[lastIndex]);
        valueToIndex[values[freeIndex]] = freeIndex;
        values.pop_back();
        valueToIndex.erase(val);
        return true;
    }
    
    int getRandom() {
        return values[rand()%values.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */