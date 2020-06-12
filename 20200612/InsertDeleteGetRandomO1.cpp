class RandomizedSet {
public:
    unordered_map<int, size_t> data; // val: idx
    vector<int> arr;
    /** Initialize your data structure here. */
    RandomizedSet() : data(unordered_map<int, size_t>()), arr(vector<int>()) {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (data.find(val) == end(data))
        {
            data[val] = arr.size();
            arr.push_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (data.find(val) == end(data))
        {
            return false;
        }
        auto arrIdx = data[val];
        data[arr.back()] = arrIdx;
        arr[arrIdx] = arr.back();
        arr.pop_back();
        data.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        size_t randIdx= getRand(static_cast<int>(arr.size()));
        return arr[randIdx];
    }

    int getRand(int modulo) {
        if (modulo == 0) {
            return 0;
        }
        while (true) {
            int x = rand();
            if (x < RAND_MAX - RAND_MAX % modulo) {
                return x % modulo;
            }
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
