#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/****
思路： 定义一种新的比较规则，如果nm < mn, 我们定义 n小于m。
然后按照新的规则对数组进行排序，依次将数组中的元素进行拼接。

sort中的比较函数compare要声明为静态成员函数或全局函数，
不能作为普通成员函数，否则会报错。
因为：非静态成员函数是依赖于具体对象的，
而std::sort这类函数是全局的，
因此无法在sort中调用非静态成员函数。
静态成员函数或者全局函数是不依赖于具体对象的,
可以独立访问，无须创建任何对象实例就可以访问。
同时静态成员函数不可以调用类的非静态成员。
****/

/*
class Solution {
public:
    static bool cmp(int a, int b){
        string A = "";
        string B = "";
        A = to_string(a) + to_string(b);
        B = to_string(b) + to_string(a);
        return A < B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        if(numbers.size() == 0) return res;
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i = 0; i < numbers.size(); ++i){
            res += to_string(numbers[i]);
        }
        return res;
    }
};*/

/*
class Solution {
public:
    static string itos(int x){
        return (x > 9 ? itos(x / 10) : "") + char(x % 10 + '0');
    }
    static bool cmp(int a, int b){
        return itos(a) + itos(b) < itos(b) + itos(a);
    }
    string PrintMinNumber(vector<int> numbers) {
        string res = "";
        if(numbers.size() == 0) return res;
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i = 0; i < numbers.size(); ++i){
            res += itos(numbers[i]);
        }
        return res;
    }
};
*/

/*
lamda函数的写法
*/
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
       string res = "";
       if(numbers.size() == 0) return res;
       sort(numbers.begin(), numbers.end(),[](const int &a, const int &b)
            {return to_string(a) + to_string(b) < to_string(b) + to_string(a);});
       for(int i = 0; i < numbers.size(); ++i)
          res += to_string(numbers[i]);
       return res;
    }
};


int main()
{
    Solution s;
    vector<int> numbers = {3,32,321};
    cout << s.PrintMinNumber(numbers) << endl;
    return 0;
}
