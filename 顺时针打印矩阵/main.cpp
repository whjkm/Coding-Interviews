#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
思路：用四个坐标定位一次循环需要打印的数据，每次循环打印出一圈；
*/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> res;

        if(row == 0 && col == 0) return res;
        int left = 0, right = col - 1, top = 0, bottom = row - 1;
        while(left <= right && top <= bottom){
            //left to right
            for(int i = left; i <= right; ++i) res.push_back(matrix[top][i]);
            //top to bottom
            for(int i = top + 1; i <= bottom; ++i) res.push_back(matrix[i][right]);

            if(top != bottom){
                //right to left
                for(int i = right - 1; i >= left; --i) res.push_back(matrix[bottom][i]);
            }

            if(left != right){
                //bottom to top
                for(int i = bottom - 1; i > top; --i) res.push_back(matrix[i][left]);
            }
            left++, top++, right--, bottom--;
        }
        return res;
    }
};

int main()
{
    vector<vector<int>> matrix;
    vector<int> tmp,res;
    Solution s;
    int num;
    for(int i=0; i<4; ++i){
        tmp.clear();
        for(int j=0; j<4; ++j){
           cin >> num;
           tmp.push_back(num);
        }
        matrix.push_back(tmp);
    }
    res = s.printMatrix(matrix);
    for(int i=0; i < res.size(); ++i)
        cout << res[i] << endl;
    return 0;
}
