#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

/*****
思路：
因为给定的数组是有序的，首先把target和右上角元素进行比较，如果相等就返回，
如果右上角元素的值大于target,说明target在这一行的下方，行数加1；
如果右上角元素的值小于target,说明target在左下方，列数减1。
*****/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size(), n = array[0].size();
        int i = 0, j = n-1;
        bool found = false;
        while(i < m && j >= 0){
            if(array[i][j] == target){
                found = true;
                break;
            }else if(array[i][j] > target){
                j--;
            }else{
                i++;
            }
        }
        return found;
    }
};

int main()
{
    Solution s;
    int a;
    vector<vector<int>> array;
    vector<int> v;
    for(int i=0; i<4; i++){
        v.clear();
        for(int j=0; j<4; j++){
            cin >> a;
            v.push_back(a);
        }
        array.push_back(v);
    }
    int target = 7;
    cout << s.Find(target, array) <<endl;
    return 0;
}
