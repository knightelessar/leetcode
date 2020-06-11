class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if (A.empty() || B.empty())
        {
            return 0;
        }
        
        // Known dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]
        // where dp[i][j] is uncrossed lines between A[0:i] and B[0:j]
        using managedRow = unique_ptr<int[]>;
        auto managedMat = unique_ptr<managedRow[]>(new managedRow[A.size()]);

        for (size_t i{0}; i < A.size(); ++i)
        {
            managedMat[i] = unique_ptr<int[]>(new int[B.size()]);
        }
        
        for (size_t i{0}; i < A.size(); ++i)
        {
            for (size_t j{0}; j < B.size(); ++j)
            {
                managedMat[i][j] = 0;
            }
        }
        
        // Initialize boundary conditions
        managedMat[0][0] = A[0] == B[0] ? 1 : 0;
        bool occupied{managedMat[0][0] == 1};
        for (size_t i{1}; i < A.size(); ++i)
        {
            if (A[i] == B[0] && !occupied)
            {
                managedMat[i][0] = managedMat[i - 1][0] + 1;
                occupied = true;
            }
            else
            {
                managedMat[i][0] = managedMat[i - 1][0];
            }
        }
        occupied = managedMat[0][0] == 1;
        for (size_t j{1}; j < B.size(); ++j)
        {
            if (A[0] == B[j] && !occupied)
            {
                managedMat[0][j] = managedMat[0][j - 1] + 1;
                occupied = true;
            }
            else
            {
                managedMat[0][j] = managedMat[0][j - 1];
            }
        }
        
        // Induction cases
        for (size_t i{1}; i < A.size(); ++i)
        {
            for (size_t j{1}; j < B.size(); ++j)
            {
                int topLeft = managedMat[i - 1][j - 1] + (A[i] == B[j] ? 1 : 0);
                int left = managedMat[i][j - 1];
                int top = managedMat[i - 1][j];
                managedMat[i][j] = max(max(left, top), topLeft);
            }
        }

        return managedMat[A.size() - 1][B.size() - 1];
    }
};
