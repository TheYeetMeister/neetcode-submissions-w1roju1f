class Solution {
    int ROW;
    int COL;
    void getOutwardSpiral(int i, int j, vector<vector<int>>& matrix, vector<int>& res) {
        int k = i;
        int m = j;
        
        for (; m < COL - j; ++m) {
            res.push_back(matrix[k][m]);
        }
        --m;

        ++k;
        for (;k < ROW - i; ++k) {
            res.push_back(matrix[k][m]);
        }
        --k;

        if (i == ROW - i - 1 || j == COL - j - 1) {
            return;
        }
        
        --m;
        for (; m >= j; --m) {
            res.push_back(matrix[k][m]);
        }
        ++m;

        --k;
        for (; k > i; --k) {
            res.push_back(matrix[k][m]);
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        ROW = matrix.size();
        COL = matrix[0].size();
        res.reserve(ROW * COL);

        int rL = 0, rR = ROW - 1;
        int cL = 0, cR = COL - 1;

        while (rL <= rR && cL <= cR) {
            getOutwardSpiral(rL, cL, matrix, res);

            ++rL;
            --rR;

            ++cL;
            --cR;
        }

        return res;
    }
};
