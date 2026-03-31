/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool isOneVal(vector<vector<int>>& grid, pair<int, int> topLeft, pair<int, int> btmRight) {
        int i = topLeft.first;
        int j = topLeft.second;

        int k = btmRight.first;
        int m = btmRight.second;

        int val = grid[i][j];

        for (int a = i; a < k; ++a) {
            for(int b = j; b < m; ++b) {
                if (val != grid[a][b]) {
                    return false;
                }
            }
        }

        return true;
    }

    Node* dfs(vector<vector<int>>& grid, pair<int, int> leftTop, pair<int,int> btmRight) {
        if (isOneVal(grid, leftTop, btmRight)) {
            return new Node(grid[leftTop.first][leftTop.second], true);
        }
        int halfRow = (leftTop.first + btmRight.first) / 2;
        int halfCol = (leftTop.second + btmRight.second) / 2;

        Node* topLeft = dfs(grid, leftTop, {halfRow, halfCol});
        Node* bottomLeft= dfs(grid, {halfRow, leftTop.second}, {btmRight.first, halfCol});
        Node* topRight = dfs(grid, {leftTop.first, halfCol}, {halfRow, btmRight.second});
        Node* bottomRight = dfs(grid, {halfRow, halfCol}, btmRight);

        return new Node(0, false, topLeft, topRight, bottomLeft, bottomRight);
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        return dfs(grid, {0, 0}, {n, n});
    }
};