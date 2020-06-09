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
        vector<vector<int>> del(s.size() + 1);
        for (size_t i{0}; i <= s.size(); ++i)
        {
            dist[i].insert(begin(dist[i]), t.size() + 1, 0);
            cout << "row.size = " << dist[i].size() << endl;
        }
        cout << "dist[0].size() = " << dist[0].size() << endl; 
        cout << "dist[0].empty() = " << dist[0].empty() << endl; 
        cout << "dist[1].size() = " << dist[0].size() << endl; 
        cout << "dist[1].empty() = " << dist[0].empty() << endl; 
        for (size_t i{0}; i <= s.size(); ++i)
        {
            del[i].insert(begin(del[i]), t.size() + 1, 0);
        }
        cout << "initilization done" << endl;
        
        // Levenstein distance
        // Boundary condition
        cout << "before first column init" << endl;
        for (size_t i{0}; i <= s.size(); ++i)
        {
            cout << "dist[" << i << "][0] = " << i << endl;
            dist[i][0] = i;
        }
        cout << "after first column init" << endl;
        cout << "before first row init" << endl;
        for (size_t j{0}; j <= t.size(); ++j)
        {
            dist[0][j] = j;
        }
        cout << "after first row init" << endl;

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
                dist[i][j] = min(min(dLeft, dTop) + 1, dTopLeft + (isCharSame ? 0 : 1) );
                if (!isCharSame && dLeft == min(min(dLeft, dTop), dTopLeft))
                {
                    // A delete operation from target t to source s
                    del[i][j] = 1;
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

        cout << "del array" << endl;
        cout << "x" << " " << "_" << " ";
        for (size_t j{0}; j < t.size(); ++j)
        {
            cout << t[j] << " ";
        }
        cout << endl;
        cout << "_" << " ";
        for (size_t j{0}; j < del[0].size(); ++j)
        {
            cout << del[0][j] << " ";
        }
        cout << endl;
        for (size_t i{1}; i < del.size(); ++i)
        {
            cout << s[i-1] << " ";
            for (size_t j{0}; j < del[0].size(); ++j)
            {
                cout << del[i][j] << " ";
            }
            cout << endl;
        }

        cout << "after induction cases" << endl;
        size_t editDist = dist[s.size()][t.size()];
        cout << "edit distance = " << editDist << endl;
        cout << "after get edit distance" << endl;

        // Check the del operations and Levenstein distance
        cout << "before counting number of delete operations" << endl;
        size_t nDiagDel{0};
        for (size_t i{0}; i <= min(s.size(), t.size()); ++i)
        {
            if (del[i][i] == 1)
            {
                nDiagDel++;
            }
        }
        cout << "number of diagnal delete operations = " << nDiagDel << endl;
        cout << "after counting number of delete operations" << endl;
        
        return (editDist == (t.size() - s.size()))
            && (nDiagDel == (t.size() - s.size()));
    }
};
