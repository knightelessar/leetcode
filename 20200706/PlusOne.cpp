class Solution
{
    // work: 30 min
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry{0};
        int p{static_cast<int>(digits.size()) - 1};
        vector<int> res(digits);

        while (p >= 0)
        {
            int curr = digits[p] + carry + ((p == digits.size() - 1) ? 1 : 0);
            carry = curr >= 10 ? 1 : 0;
            res[p] = curr % 10;
            --p;
        }

        if (carry > 0)
        {
            vector<int> tmp{1};
            tmp.insert(end(tmp), begin(res), end(res));
            res = tmp;
        }
        return res;
    }
};
