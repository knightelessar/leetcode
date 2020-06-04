class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty()) {
            return;
        }
        auto i = begin(s);
        auto j = end(s) - 1;
        while (i < j) {
            swap(*i, *j);
            ++i;
            --j;
        }
    }
};