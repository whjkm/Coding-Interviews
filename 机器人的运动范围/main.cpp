#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

//BFS
class Solution
{
public:
    int movingCount(int threshold, int rows, int cols)
    {
        vector<vector<bool>> visited(rows);
        for(auto& row : visited)
        {
            row.resize(cols, false);
        }
        queue<pair<int, int>> que;
        if(getDigitSum(0) + getDigitSum(0) <= threshold)
        {
            que.push(make_pair(0,0));
            visited[0][0] = true;
        }
        int cnt = 0;
        while(!que.empty())
        {
            ++cnt;
            int x, y;
            tie(x, y) = que.front();
            que.pop();
            if(x + 1 < rows && !visited[x+1][y] &&
               getDigitSum(x + 1) + getDigitSum(y) <= threshold)
            {
                visited[x+1][y] = true;
                que.push(make_pair(x+1,y));
            }
            if(y + 1 < cols && !visited[x][y+1] &&
               getDigitSum(x) + getDigitSum(y + 1) <= threshold)
            {
                visited[x][y+1] = true;
                que.push(make_pair(x, y+1));
            }
        }
        return cnt;
    }
    int getDigitSum(int number)
    {
        int sum = 0;
        while(number != 0)
        {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};


/***DFS
从（0.0）开始出发，每成功走一步标记当前位置为true, 然后从当前位置往4个方向探索。
***/
/*
class Solution {
int visited[100][100];
int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int num;
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold < 0)
        {
            return 0;
        }
        num = 1;
        memset(visited, 0, sizeof(visited));
        dfs(threshold, rows, cols, 0, 0);
        return num;
    }
    void dfs(int threshold, int rows, int cols, int row, int col)
    {
        visited[row][col] = 1;
        for(int i = 0; i < 4; ++i)
        {
            int x = row + direction[i][0];
            int y = col + direction[i][1];
            if(x >= 0 && x < rows && y >= 0 && y < cols && !visited[x][y]
               && (getDigitSum(x) + getDigitSum(y)) <= threshold)
            {
                num ++;
                dfs(threshold, rows, cols, x, y);
            }
        }
    }

    int getDigitSum(int number)
    {
        int sum = 0;
        while(number != 0)
        {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};
*/


int main()
{
    Solution s;
    cout << s.movingCount(18, 50, 50) << endl;
    return 0;
}
