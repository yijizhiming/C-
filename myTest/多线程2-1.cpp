#include <iostream>
#include <thread>
#include <atomic>
using namespace std;
//aotomicԭ�ӵ� �����ָܷ�ģ���С��λ��
//
//�ٸ����ӣ�int num;
//
//num = num + 1;
//
//���Ƕ�֪������num = num + 1�������������Ҫ�ֽ�Ϊ������
//
//1���ѱ���num��ȡ��ĳһ���Ĵ���R�洢��
//
//2��CPU�ԼĴ���R��ֵ���м��㣬
//
//3��������ɺ�ֵ����ڴ�
//
//�ڶ��߳�ִ��num++��ʱ�� ��ǰnumΪ1 �߳�Aִ����ڶ��� ��ʱnumΪ2���ǻ�û�д����ڴ棬
//Ȼ���߳�B��ʼִ�е�һ�������ڴ���ȡ��num��num������1�������ͳ��������ˣ�
//�൱��A�̺߳�B�߳�һ��ִ��������num = num + 1������numȴֻ������1



long num = 0;

void addnum()
{
    for (int i = 0; i < 100000; i++)
        ++num;//����ȫ�ֱ������л������
}

int main()
{
    int nthreads = 2;
    thread t[2];
    for (int i = 0; i < nthreads; i++)
        t[i] = thread(addnum);

    for (auto& th : t)
        th.join();
    cout << num << endl;
    return 0;
}
