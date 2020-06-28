class Solution {
    // work 22:23 - 23:24
    using adjList_T = vector<string>;
    using graph_T = unordered_map<string, adjList_T>;
    graph_T g;
    unordered_map<string, vector<bool>> visitMap;
    size_t nTrips{0};
    vector<string> result;

    template<typename T>
    void myp(const T &con)
    {
        for (const auto &e: con)
        {
            cout << e << " ";
        }
        cout << endl;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> itin;
        this->nTrips = tickets.size();
        for (const auto &e: tickets)
        {
            if (this->g.find(e[0]) == end(this->g))
            {
                adjList_T list{e[1]};
                this->g[e[0]] = list;
            }
            else
            {
                this->g[e[0]].push_back(e[1]);
            }
        }

        for (auto &p: this->g)
        {
            sort(begin(p.second), end(p.second));
            cout << p.first << " -> ";
            myp(p.second);
            visitMap[p.first] = vector<bool>(p.second.size(), false);
        }

        cout << "Main routine" << endl;
        string city{"JFK"};
        itin.push_back(city);

        backtrack(itin, "JFK");
        return this->result;
    }

    bool backtrack(vector<string> &itin, const string &src)
    {
        if (itin.size() == this->nTrips + 1)
        {
            this->result = itin;
            return true;
        }

        for (size_t i{0}; i < this->g[src].size(); ++i)
        {
            if (!this->visitMap[src][i])
            {
                itin.push_back(g[src][i]);
                visitMap[src][i] = true;

                bool ret = backtrack(itin, g[src][i]);

                visitMap[src][i] = false;
                itin.pop_back();

                if (ret)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
