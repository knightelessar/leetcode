class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() > t.size())
        {
            return false;
        }

        // Edit distance 2D array of s.size() + 1 rows
        // and t.size() + 1 columns
        vector<vector<int>> dist(s.size() + 1);
        for (size_t i{0}; i <= s.size(); ++i)
        {
            dist[i].insert(begin(dist[i]), t.size() + 1, 0);
        }
        
        // Simplified Levenshtein delete distance
        // Boundary condition
        for (size_t i{0}; i <= s.size(); ++i)
        {
            dist[i][0] = 0;
        }
        for (size_t j{0}; j <= t.size(); ++j)
        {
            dist[0][j] = 0;
        }

        // Induction cases
        cout << "before induction cases" << endl;
        for (size_t i{1}; i <= s.size(); ++i)
        {
            for (size_t j{1}; j <= t.size(); ++j)
            {
                int dLeft = dist[i][j-1];
                int dTop = dist[i-1][j];
                bool isCharSame = s[i-1] == t[j-1];
                int dTopLeft = dist[i-1][j-1];
                if (isCharSame)
                {
                    dist[i][j] = dTopLeft + 1;
                }
                else
                {
                    dist[i][j] = max(dLeft, dTop);
                }
            }
        }

        // Print the dist array
        // x _ t a g e t
        // _ 0 1 2 3 4 5
        // t 0 1 2 3 4 5
        // g 1
        // t 
        cout << "dist array" << endl;
        cout << "x" << " " << "_" << " ";
        for (size_t j{0}; j < t.size(); ++j)
        {
            cout << t[j] << " ";
        }
        cout << endl;
        cout << "_" << " ";
        for (size_t j{0}; j < dist[0].size(); ++j)
        {
            cout << dist[0][j] << " ";
        }
        cout << endl;
        for (size_t i{1}; i < dist.size(); ++i)
        {
            cout << s[i-1] << " ";
            for (size_t j{0}; j < dist[0].size(); ++j)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }

        cout << "after induction cases" << endl;

        bool isConsumed{false};
        for (auto x: dist[s.size()])
        {
            if (x == s.size())
            {
                isConsumed = true;
                break;
            }
        }

        return isConsumed;
    }
};
