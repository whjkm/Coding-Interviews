#include <iostream>

using namespace std;

//ʹ���麯��
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
//ʹ���麯��������ݹ飬�ڻ����ֶ����麯��Sum(n)����0��
//ͨ����ָ�����������Ԫ�طֱ�󶨵�����������࣬���л����Sum()
//�����ݹ飬!!n������true(1) false(0)����ָ��������з���
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


// ���ù�ʽ��gcc����
/*
class Solution {
public:
    int Sum_Solution(int n) {
        bool a[n][n+1];
        return sizeof(a)>>1;
    }
};
*/

// ��·��ֵԭ�������ݹ�
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
���ù��캯�����
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
//����һ����̬����N��sum���ڹ��캯���н����ۼ����㣻
//Ȼ����һ���Ը�����Ϊ���͡���СΪn�����飬�ظ����ô˹��캯��n����ʵ��n�ε��ۼ�����
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
