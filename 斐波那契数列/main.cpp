#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

//��̬�滮����f(n+1)��״̬����f(n)��״̬��
class Solution{
public:
    int Fibonacci(int n) {
        int f = 0, g = 1;
        while(n-- > 0){
            g += f;        //f(n+1)
            f = g - f;     //f(n)
        }
        return f;
    }
};

/*
//��̬�滮�ⷨ��������洢����������ظ����㡣
class Solution {
public:
    int Fibonacci(int n) {
        if(n < 0){
            return 0;
        }
        vector<int> result(n+1,0);
        result[1] = 1;
        for(int i=2; i<=n; i++){
            result[i] = result[i-2] + result[i-1];
        }
        return result[n];
    }
};
*/

/*
//����,ѭ��
class Solution {
public:
    int Fibonacci(int n) {
        int result = n;   // nΪ0,1�����
        if(n < 0){
            result = 0;
        }
        int f0 = 0, f1 = 1;
        for(int i=2; i<=n; i++){
            result = f0 + f1;
            f0 = f1;
            f1 = result;
        }
        return result;
    }
};
*/


/*
// �ݹ�
class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        return Fibonacci(n-1) + Fibonacci(n-2);
    }
};
*/
int main()
{
    Solution s;
    cout << s.Fibonacci(39) << endl;
    return 0;
}
