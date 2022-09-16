//std::async�����ȴ����߳�ִ��is_prime(4444444443)�� ���񴴽�֮��std::async��������һ��std::future����
//
//���̼߳ȿ�ʹ��std::future::get��ȡ�����������ù����У�������δ��ɣ������߳�������������ɡ�
//
//���߳�Ҳ��ʹ��std::future::wait_for�ȴ�������أ�wait_for�����ó�ʱʱ�䣬
//����ڳ�ʱʱ��֮��������ɣ��򷵻�std::future_status::ready״̬��
//����ڳ�ʱʱ��֮��������δ��ɣ��򷵻�std::future_status::timeout״̬��


#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>

bool is_prime(int x)
{
	for (int i = 2; i < x; i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	// call function asynchronously;
	std::future<bool> fut = std::async(is_prime, 4444444443);

	// do something while waiting for function to set future.
	std::cout << "checking,please wait...\n";
	std::chrono::milliseconds span(100);
	
	while (fut.wait_for(span) == std::future_status::timeout)
	{
		std::cout << '.' << std::flush;
	}
	bool x = fut.get();
	std::cout << "\n4444444443 " << (x ? "is" : "is not") << " prime.\n";

	return 0;
}