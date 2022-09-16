//��ͨ����½���ʹ��std::lock_guard����Ϊstd::lock_guard������������
// �������������������wait�л����У�����ʹ��std::unique_lock��
//
//
//
//����������C++11�����һ��ͬ�����ƣ�����������һ���̻߳����̣߳�
//ֱ�����߳�֪ͨ���߳�ʱ�Żỽ�������������̣߳�����������Ҫ�������ʹ�ã�
//�����������������ܵ�std::unique_lock��
//
//mutex������ס����������һ�������������ʹ����ͬ��ȫ�ֱ������߳�ȥ���ͬһ�����������ǳ���


#include <iostream>
#include <thread>
#include <windows.h>
void func() {
    for (int i = 0; i < 100; ++i) {
        std::cout << "thread::func:" << i << std::endl;
    }
}
int main() {
    std::cout << "--------\n";
    std::thread my_thread(func);
    
    for (int i = 0; i < 10; ++i)
        std::cout << "main\n";
    //my_thread.detach();
    my_thread.join();
    for (int i = 0; i < 10; ++i)
        std::cout << "main\n";
    return 0;
}
