//std::packaged_task�����þ����ṩһ����ͬ�߳�֮�������ͬ�����ƣ������Դ洢һ������������
//�����䷵��ֵ���ݸ���Ӧ��future�� �����future������һ���߳���Ҳ���԰�ȫ�ķ��ʵ����ֵ��
#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>

int countdown(int from, int to)
{
	std::cout << "sleep 3 seconds\n";
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << "awake\n";
	for (int i = from; i != to; --i)
	{
		std::cout << i << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	std::cout << "Lift off!\n";
	return from - to;
}

int main()
{
	std::packaged_task<int(int, int)> tsk(countdown);
	std::future<int> ret = tsk.get_future();
	std::thread th(std::move(tsk), 10, 0);
	// ...
	//th.join();
	std::cout << "wait...\n";
	int value = ret.get();// wait for the task to finish and get result
	std::cout << "The value is " << value << " \n";
	th.join();
	
	return 0;
}