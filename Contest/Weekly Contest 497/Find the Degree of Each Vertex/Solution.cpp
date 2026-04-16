// Problem Link : https://leetcode.com/problems/find-the-degree-of-each-vertex/description/

class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {

        int n = matrix.size();
        vector<int> vt(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 
            matrix[i].size(); j++) {
                if(matrix[i][j]==1)
                    vt[i]++;
            }
        }
      return vt; 
    }
};
