#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/****
˼·��������ɸѡ����˼�룬ÿ������������ǰ��ĳ������ԣ�2,3,5��������һ���õ��ģ�
�������Ǿ�ά��һ���ź���ĳ������У�ÿ�ν���ǰ��С�ĳ����������飬��3��ָ���¼��ǰ���������ĸ��õ��ġ�
****/

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
       if(index < 7) return index;
       vector<int> res(index);
       res[0] = 1;
       int p2 = 0, p3 = 0, p5 = 0;
       for(int i = 1; i < index; ++i){
          res[i] = min(min(res[p2]*2, res[p3]*3),res[p5]*5);
          if(res[i] == res[p2]*2) p2++;
          if(res[i] == res[p3]*3) p3++;
          if(res[i] == res[p5]*5) p5++;
       }
       return res[index - 1];
    }
};

int main()
{
    Solution s;
    cout << s.GetUglyNumber_Solution(1500) << endl;
    return 0;
}
