class Solution
{
public:
    int arrangeCoins(int n)
    {
        int left{0}, right{n}, ans{0};
        long long currSum{0};
        while (left <= right)
        {
            long long mid = left + (right - left) / 2;
            currSum = mid * (mid + 1) / 2;
            if (currSum == n)
            {
                return static_cast<int>(mid);
            }

            if (currSum < n)
            {
                // When left = right = mid = correct answer,
                // this branch will be entered (*)
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        // Since (*),
        // left is correct answer + 1, but right still equals correct answer
        return right;
    }
};
