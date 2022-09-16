//async��future������̨���񲢷���ֵ��ϣ���̷߳���һ�������
//
//async�Ǻ���ģ�壬��������һ���첽������������һ���첽����֮��������һ��future����
//future�Ǹ���ģ�塣����һ���첽��������Զ�����һ���̲߳���ʼִ�ж�Ӧ���߳���ں�����
//������һ��future����������صĶ�����ߺ����߳���ں��������صĽ����
//���ǿ���ͨ������future����ĳ�Ա����get��������ȡ�����futureҲ����Ϊ���ṩ��һ�ַ����첽��������Ļ��ƣ�
//������û�а취�����õ����������߳�ִ����ϾͿ����õ������get�����������õ�����ֵ��
//�Ϳ�������ȴ���ֵ�����⴫��һ��������async�����У��ò���������launch��ö�����ͣ���
//���ﵽһЩ�����Ŀ�ġ�asyncǿ���첽���������߳���ִ�С�
//
//launch����deferred��ʾ�߳���ں������ñ��ӳٵ�future��wait��������get������������ʱ��ִ�С�
//���wait������get����û�е��ã��̸߳����Ͼ�û�������������߳��е��õ��߳���ں�����
//launch����async�ڵ���async������ʱ��Ϳ�ʼ�����̣߳�
//async����Ĭ������launch����async���첽�������̣߳� | launch����deferred(ͬ�����������߳�)��ǣ�
//�������ĸ��ɳ��������
//
//packaged_task������ģ�壬�������װ���������ֿɵ�����ͨ��packaged_task���Ѹ��ֿɵ������װ������
//���㽫����Ϊ�߳���ں���������

#include<iostream>                                                                                        
#include<thread>
#include<future>
using namespace std;

//�߳���ں���                                                                    
int mythread(int mypar) {
	cout << mypar << endl;
	cout << "mythread() start" << "threadid = " << std::this_thread::get_id() << endl;
	std::chrono::milliseconds dura(5000);
	std::this_thread::sleep_for(dura);
	cout << "mythread() and" << std::this_thread::get_id() << endl;
	return 5;
}


 int main() {

	 cout << "main" << "thread = " << std::this_thread::get_id() << endl;
	 std::packaged_task<int(int)> mypt(mythread);  //�Ѻ�����mythreadͨ��packaged_task��װ����
	 std::thread t1(std::ref(mypt), 1);  //�߳�ֱ�ӿ�ʼִ�У��ڶ���������Ϊ�߳���ں����Ĳ���
	 t1.join();
	 std::future<int> result = mypt.get_future();  //future������������߳���ں����ķ��ؽ��
	 cout << result.get() << endl;
	 cout << "king hou" << endl;

	 return 0;

}