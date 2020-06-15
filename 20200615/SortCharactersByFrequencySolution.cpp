// Sort Characters By Frequency
class Solution {
public:
    string frequencySort(string s) {
        // Start 15:45 - 16:05
        unordered_map<char, size_t> dict;
        vector<pair<char, int>> arr;
        ostringstream ss;
        // One pass to put char: count into hash map
        for (auto& c: s)
        {
            if (dict.find(c) == end(dict))
            {
                dict[c] = 1;
            }
            else
            {
                dict[c]++;
            }
        }
        // Put pair<char, count> into vector
        arr.insert(begin(arr), begin(dict), end(dict));

        // Sort the vector by count
        auto cmpFcn = [](const pair<char, size_t>& t1, const pair<char, size_t>& t2){
            return t1.second > t2.second;
        };
        sort(begin(arr), end(arr), cmpFcn);

        // Loop through to give answer
        for (auto& p: arr)
        {
            for (size_t i{0}; i < p.second; ++i)
            {
                ss << p.first;
            }
        }
        return ss.str();
    }
};
