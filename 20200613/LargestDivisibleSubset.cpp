using mVec = shared_ptr<vector<int>>;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // Each divisable subset
        auto N = nums.size();
        if (N == 0) return vector<int>();
        auto EDS = shared_ptr<mVec[]>(new mVec[N]);
        for (size_t i{0}; i < N; ++i)
        {
            EDS[i] = mVec(new vector<int>());
        }

        sort(begin(nums), end(nums));

        // Construct all EDS
        for (size_t i{0}; i < N; ++i)
        {
            mVec maxSubset = mVec(new vector<int>());
            for (size_t j{0}; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 
                    && maxSubset->size() < EDS[j]->size())
                {
                    maxSubset = EDS[j];
                }
            }
            EDS[i]->insert(end(*EDS[i]), begin(*maxSubset), end(*maxSubset));
            EDS[i]->push_back(nums[i]);
        }

        size_t maxEDSIdx{0};
        size_t maxSize{0};
        for (size_t i{0}; i < N; ++i)
        {
            if (EDS[i]->size() > maxSize)
            {
                maxSize = EDS[i]->size();
                maxEDSIdx = i;
            }
        }
        return *EDS[maxEDSIdx];
    }
};
