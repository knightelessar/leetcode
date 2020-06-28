class Solution {
    // work 9:45 - 11:20
    using mapType = unordered_map<int, size_t>;
    template<typename T>
    void myPrint(const T &con)
    {
        for (const auto &x: con)
        {
            cout << "<" << x.first << ", " << x.second << ">" << " ";
        }
        cout << endl;
    }

public:
    int numSquares(int n) {
        mapType paths;
        int res = backtrack(n, paths);
        return res;
    }
    
    size_t backtrack(int n, mapType& paths)
    {
        if (isSquare(n))
        {
            return 1;
        }
        
        if (paths.find(n) != end(paths))
        {
            return paths[n];
        }
        
        int maxSqrt = sqrt(n);
        size_t minNum{numeric_limits<size_t>::max()};
        int chosenK{0};
        for (int k{maxSqrt}; k > 0; --k)
        {
            size_t minReduced = backtrack(n - k * k, paths);
            if (minReduced + 1 < minNum)
            {
                minNum = minReduced + 1;
                chosenK = k;
            }
            else
            {
                continue;
            }
        }
        cout << "n = " << n << ", minNum = " << minNum << ", chosenK = " << chosenK << endl;
        myPrint(paths);
        paths[n] = minNum;
        return minNum;
    }
    
    bool isSquare(int n)
    {
        return static_cast<int>(sqrt(n)) * static_cast<int>(sqrt(n)) == n;
    }
};
