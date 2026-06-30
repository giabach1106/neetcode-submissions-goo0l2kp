class NumMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;  
        sum = vector<vector<int>> (matrix.size(), (vector<int> (matrix[0].size(), 0)));
        for (int i = 0; i < matrix.size(); i++) {
            sum[i][0] = matrix[i][0];
            for (int j = 1; j < matrix[i].size(); j++) {
                sum[i][j] = matrix[i][j] + sum[i][j - 1];
            } 
        } 
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for (int i = row1; i <= row2; i++) {
            res += sum[i][col2];
            if (col1 > 0) {
                res -= sum[i][col1 - 1];
            }
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */