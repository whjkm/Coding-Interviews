#include <iostream>

using namespace std;

//使用虚函数
class A;
A* Array[2];
class A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};
class B: public A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n]->Sum(n-1) + n;
    }
};
//使用虚函数来构造递归，在基类种定义虚函数Sum(n)返回0，
//通过将指针数组的两个元素分别绑定到基类和派生类，其中基类的Sum()
//结束递归，!!n来构造true(1) false(0)来对指针数组进行访问
class Solution {
public:
    int Sum_Solution(int n) {
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;
        int value = Array[1] ->Sum(n);
        return value;
    }
};


// 利用公式，gcc特性
/*
class Solution {
public:
    int Sum_Solution(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};
*/

// 短路求值原理，跳出递归
/*
class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};
*/

/***
利用构造函数求解
***/
/*
class Temp
{
public:
    Temp() {++N; Sum += N;}
    static void Reset() {N = 0; Sum = 0;}
    static unsigned int GetSum() {return Sum;}

private:
    static unsigned int N;
    static unsigned int Sum;

};
//设置一个静态变量N和sum，在构造函数中进行累加运算；
//然后构造一个以辅助类为类型、大小为n的数组，重复调用此构造函数n次来实现n次的累加运算
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;

class Solution {
public:
    int Sum_Solution(int n) {
        Temp::Reset();
        Temp *a = new Temp[n];
        delete []a;
        a = NULL;

        return Temp::GetSum();
    }
};
*/

int main()
{
    Solution s;
    cout << s.Sum_Solution(100) << endl;
    return 0;
}
