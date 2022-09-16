//template <class Fn, class... Args>
//
//void call_once(once_flag& flag, Fn&& fn, Args&&...args);
//
//��Ҫ����ͷ�ļ���<mutex>
//
//������
//
//��1��flag����std::once_falg���󣨶���һ���ö��󴫽�ȥ���ɣ������ڿ��Ƶı�ǩ����ͬ��flag
// ִֻ��һ�Σ���������⣩
//
//��2��fn����Ҫִֻ��һ�εĺ������󡢡�
//
//��3��args�����ݸ�fn�����Ĳ�����������оʹ��ݣ�û�оͲ����ݡ�


#include<iostream>
#include<mutex>
#include<thread>
using namespace std;

//��������Ϊȫ�ֱ���
once_flag init_flag;

void init()
{
	cout << "data has inited" << endl;
}

void fun()
{
	//ÿ���̵߳�fun�����е�init_flag�ǲ�ͬ��,��������Ϊ�ֲ�����
	//once_flag init_flag;
	call_once(init_flag, init);
}

int main()
{
	thread t1(fun);
	thread t2(fun);
	t1.join();
	t2.join();
	system("pause");
	return 0;
}
