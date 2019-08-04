#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

// ��������ģ��
class Solution {
public:
    int LastRemaining_Solution(int n, int m){
        if(n < 1 || m < 1)
            return -1;
        vector<int> numbers(n, 0);
        // iΪÿ��ɾ�������֣�count ģ��Բ����step��¼ÿ�ֵĲ�����
        int i = -1, count = n, step = 0;
        while(count > 0)
        {
            i++;
            if(i >= n) i = 0;  // ѭ��
            if(numbers[i] == -1) continue;  // ɾ����Ԫ�ر��Ϊ-1;
            step ++;
            if(step == m)    // �ҵ�Ҫɾ��������
            {
                numbers[i] = -1;
                step = 0;   // ��ʼ�µ�һ��
                count --;   // Բ�����ּ�1
            }
        }
        return i;
    }
};

/***
list����ģ��ԲȦ
***/
/*
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        list<int> numbers;
        for(int i = 0; i < n; ++i)
            numbers.push_back(i);
        list<int>::iterator current = numbers.begin();
        while(numbers.size() > 1)
        {
            for(int i = 0; i < m - 1; ++i)
            {
                current ++;
                if(current == numbers.end())   // ɨ�赽����β��
                    current = numbers.begin();
            }
            list<int>::iterator next = ++current;
            if(next == numbers.end())
                next = numbers.begin();
            -- current;
            numbers.erase(current);
            current = next;
        }
        return *(current);
    }
};
*/

/***
Լɪ�򻷣�
��f[i]��ʾi��������Ϸ��m�˳����ʤ���ߵı�ţ����Ľ����Ȼ��f[n]��
���ƹ�ʽ
f[1]=0;
f[i]=(f[i-1]+m)%i;  (i>1)
***/
/*
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n < 1 || m < 1)
            return -1;
        int last = 0;
        for(int i = 2; i <= n; ++i)
        {
            last = (last + m) % i;
        }
        return last;
    }
};
*/

int main()
{
    Solution s;
    cout << s.LastRemaining_Solution(5, 3) << endl;
    return 0;
}
