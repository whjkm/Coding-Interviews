#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int visited[100][100];
class Solution {
public:
    int direction[4][2]={{0,1},{1,0},{-1,0},{0,-1}};  // 方向数组
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(rows < 1 || cols < 1 || str == NULL)
            return false;
        vector<vector<char>> maps(rows, vector<char>(cols));
        int cnt = 0;
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                maps[i][j] = matrix[cnt++];
            }
        }
        //vector<vector<int>> visited(rows, vector<int>(cols, 0));
        memset(visited, 0, sizeof(visited));
        for(int row = 0; row < rows; ++row)
        {
            for(int col = 0; col < cols; ++col)
            {
                if(maps[row][col] == str[0])
                {
                    if(dfs(maps, str, rows, cols, row, col, 1))
                        return true;
                    //vector<vector<int>> visited(rows, vector<int>(cols, 0));
                    memset(visited, 0, sizeof(visited));
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> maps, char *str, int rows, int cols, int row, int col, int pathLength)
    {
        if(pathLength == strlen(str))
        {
            return true;
        }
        bool haspath = false;
        visited[row][col] = 1;
        for(int i = 0; i < 4; ++i)
        {
            int x = row + direction[i][0];
            int y = col + direction[i][1];
            if(x >= 0 && x < rows && y >= 0 && y < cols && maps[x][y] == str[pathLength] && visited[x][y] == 0)
            {
                haspath = dfs(maps, str, rows, cols, x, y, pathLength + 1);
                if(haspath)
                    return true;
                //visited[x][y] = 0;
            }
        }
        return false;
    }
};


// 回溯
/*
class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix == NULL || rows < 1 || cols < 1 || str == NULL)
            return false;
        bool *visited = new bool[rows * cols];
        memset(visited, 0, rows * cols);
        int pathLength = 0;
        for(int i = 0; i < rows; ++i)
        {
            for(int j = 0; j < cols; ++j)
            {
                if(dfs(matrix, str, visited, rows, cols, i, j, pathLength))
                {
                    return true;
                }
            }
        }
        delete[] visited;
        return false;
    }

    bool dfs(char *matrix, char *str, bool *visited, int rows, int cols, int row, int col, int &pathLength)
    {
        if(str[pathLength] == '\0')
        {
            return true;
        }
        bool hasPath = false;
        if(row >= 0 && row < rows && col >=0 && col < cols && matrix[row * cols + col] == str[pathLength]
           && !visited[row * cols + col])
        {
            ++pathLength;
            visited[row * cols + col] = true;

            hasPath = dfs(matrix, str, visited, rows, cols, row, col - 1, pathLength)
                    || dfs(matrix, str, visited, rows, cols, row - 1, col, pathLength)
                    || dfs(matrix, str, visited, rows, cols, row + 1, col, pathLength)
                    || dfs(matrix, str, visited, rows, cols, row, col + 1, pathLength);
            if(!hasPath)
            {
                --pathLength;  // 回溯
                visited[row * cols + col] = false;
            }
        }
        return hasPath;
    }
};
*/

int main()
{
    int direction[4][2]={{0,1},{1,0},{-1,0},{0,-1}};  // 方向数组
    for(int i = 0; i < 4; ++i)
    {
        cout << direction[i][0] << " ";
        cout << direction[i][1];
        cout << endl;
    }
    return 0;
}
