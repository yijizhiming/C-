//promise��future
//future��promise���������ڲ�ͬ�߳�֮�䴫�����ݡ�ʹ��ָ��Ҳ����������ݵĴ��ݣ�����ָ��ǳ�Σ�գ�
// ��Ϊ������������ָֹ��ķ��ʣ�����ָ��ķ�ʽ���ݵ������ǹ̶��ģ���������������ͣ�
// ��ô����Ҫ�����йصĽӿڣ��Ƚ��鷳��promise֧�ַ��͵Ĳ��������ӷ����̴���
//
//�����߳�1��Ҫ�߳�2�����ݣ���ô���ʹ�÷�ʽ���£�
//
//�߳�1��ʼ��һ��promise�����һ��future����promise���ݸ��߳�2���൱���߳�2���߳�1��һ����ŵ��
// future�൱��һ������һ����ŵ��������ȡδ���߳�2���ݵ�ֵ
//�߳�2��ȡ��promise����Ҫ�����promise�����йص����ݣ�֮���߳�1��future�Ϳ��Ի�ȡ�����ˡ�
//����߳�1��Ҫ��ȡ���ݣ����߳�2δ�������ݣ����߳�1������ֱ���߳�2�����ݵ��
//
//�߳�1ֻҪ��⵽���ݵ��get�Ϳ��Է��أ��߳�2��״̬���Խ���Ҳ���ܼ������С�
//��������������������������������
//��Ȩ����������ΪCSDN������qq_24127015����ԭ�����£���ѭCC 4.0 BY - SA��ȨЭ�飬
// ת���븽��ԭ�ĳ������Ӽ���������
//ԭ�����ӣ�https ://blog.csdn.net/qq_24127015/article/details/104819447




#include <vector>
#include <thread>
#include <future>
#include <numeric>
#include <iostream>
#include <chrono>

// ����һ��vector����ĺͣ�������һ��promise������һ����ŵ����Ҫ�������ֵ
void accumulate(std::vector<int>::iterator first,
	std::vector<int>::iterator last,
	std::promise<int> accumulate_promise)
{
	int sum = std::accumulate(first, last, 0);
	std::cout << "set promise\n";
	std::cout << "wait 5 seconds" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	accumulate_promise.set_value(sum);// Notify future
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

void do_work(std::promise<void> barrier)
{
	std::cout << "set promise2\n";
	std::cout << "wait 5 seconds" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(5));
	barrier.set_value();
	std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main()
{
	// Demonstrate using promise<int> to transmit a result between threads.
	std::vector<int> numbers = { 1,2,3,4,5,6 };
	std::promise<int> accumulate_promise;
	std::future<int> accumulate_future = accumulate_promise.get_future();
	std::thread work_thread(accumulate, numbers.begin(), numbers.end(), std::move(accumulate_promise));
	std::cout << "waiting... \n";
	accumulate_future.wait();
	std::cout << "ready\n";
	std::cout << "result=" << accumulate_future.get() << "\n";
	work_thread.join();

	std::promise<void> barrier;
	std::future<void> barrier_future = barrier.get_future();
	std::thread new_work_thread(do_work, std::move(barrier));
	
	std::cout << "waiting2... \n";
	barrier_future.wait();
	std::cout << "ready2... \n";
	new_work_thread.join();
	
	return 0;
}