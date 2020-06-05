class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        vector<vector<int>> dist(len1 + 1, vector<int>(len2 + 1, 0));
        
        // Base case: distance between partial strings and empty string
        for (int i{0}; i < len1 + 1; ++i) {
            dist[i][0] = i;
        }
        
        for (int j{0}; j < len2 + 1; ++j) {
            dist[0][j] = j;
        }
        
        // Inductive case:
        // Check word1[1..i] against
        for (int i{1}; i < len1 + 1; ++i) {
            // word2[1..j]
            for (int j{1}; j < len2 + 1; ++j) {
                // word1[1..(i-1)] against word2[1..j]
                int distParW1 = dist[i-1][j];
                // word1[1..i] against word2[1..(j-1)]
                int distParW2 = dist[i][j-1];
                // word1[1..(i-1)] against word2[1..(j-1)]
                int distParW1ParW2 = dist[i-1][j-1];
                bool isLastCharSame = (word1[i-1] == word2[j-1]);
                dist[i][j] = min(min(distParW1 + 1, distParW2 + 1),
                                isLastCharSame ? distParW1ParW2 : distParW1ParW2 + 1);
            }
        }
        
        
        return dist[len1][len2];
    }
};
