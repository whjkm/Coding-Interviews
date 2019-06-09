#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
*˼·����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룻
*���ǿ��Կ����ڱ��������ʱ�򱣴�����ֵ��һ���������е�һ�����֣�һ���Ǵ�����
*�����Ǳ�������һ�����ֵ�ʱ�������һ�����ֺ�����֮ǰ�����������ͬ���������1��
*����ʹ�����1�����������Ϊ0��������Ҫ������һ�����֣����Ѵ�����Ϊ1��
*Ҫ�ҵ����־������һ�ΰѴ�����Ϊ1ʱ��Ӧ�����֡�
*/
/*class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int n = numbers.size();
        if(n == 0) return 0;
        int num = numbers[0], count = 1;
        for(int i=1; i < n; i++){
            if(numbers[i] == num)
                count++;
            else count--;
            if(count == 0){
                num = numbers[i];
                count = 1;
            }
        }
        //��֤�Ƿ񳬹���ԭ�����һ��
        count = 0;
        for(int i=0; i < n; i++){
            if(numbers[i] == num) count++;
        }
        if(count * 2 > n) return num;
        return 0;
    }
};
*/

/*
*˼·�����ÿ��ŵ�˼·����������һ�����������֮��һ��λ��������м䡣
*�������Ż��������˼·���ҵ��������λ������������ȫ����
*/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int length = numbers.size();
        if(numbers.empty() || length <= 0) return 0;
        int middle = length >> 1;
        int start = 0;
        int end = length - 1;
        int index = Partition(numbers, start, end);
        while(index != middle){
            if(index > middle){
                end = index - 1;
                index = Partition(numbers, start, end);
            }
            else{
                start = index + 1;
                index = Partition(numbers, start, end);
            }
        }
        int result = numbers[middle];
        //��֤�Ƿ񳬹���ԭ�����һ��
        int count = 0;
        for(int i=0; i < length; i++){
            if(numbers[i] == result) count++;
        }
        if(count * 2 > length) return result;
        return 0;
    }
    // ���Ż�������
    /*
    int Partition(vector<int> numbers, int start, int end){
        int pivot = numbers[start];
        while(start < end){
            while(start < end && pivot < numbers[end])
                end--;
            swap(numbers[start], numbers[end]);
            while(start < end && pivot >= numbers[start])
                start++;
            swap(numbers[start], numbers[end]);
        }
        return start;
    }*/
    // ��ָofferд��
    int Partition(vector<int> numbers, int start, int end){
        int index = RandInRange(start, end); // ����
        swap(numbers[index], numbers[end]);
        int small = start - 1;
        for(index = start; index < end; index++){
            if(numbers[index] < numbers[end]){
                ++small;
                if(small != index){
                    // ��С���������������ǰ��
                    swap(numbers[small], numbers[index]);
                }
            }
        }
        ++small;
        swap(numbers[small], numbers[end]);
        return small;
    }
    int RandInRange(int a, int b){
        int c;
        c = a + rand()%(b - a + 1);
        return c;
    }

};

int main()
{
    Solution s;
    vector<int> numbers = {1,2,3,2,2,2,5,4,2};
    cout << s.MoreThanHalfNum_Solution(numbers) << endl;
    return 0;
}
