#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/****
˼·�� ����һ���µıȽϹ������nm < mn, ���Ƕ��� nС��m��
Ȼ�����µĹ������������������ν������е�Ԫ�ؽ���ƴ�ӡ�

sort�еıȽϺ���compareҪ����Ϊ��̬��Ա������ȫ�ֺ�����
������Ϊ��ͨ��Ա����������ᱨ��
��Ϊ���Ǿ�̬��Ա�����������ھ������ģ�
��std::sort���ຯ����ȫ�ֵģ�
����޷���sort�е��÷Ǿ�̬��Ա������
��̬��Ա��������ȫ�ֺ����ǲ������ھ�������,
���Զ������ʣ����봴���κζ���ʵ���Ϳ��Է��ʡ�
ͬʱ��̬��Ա���������Ե�����ķǾ�̬��Ա��
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
lamda������д��
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
