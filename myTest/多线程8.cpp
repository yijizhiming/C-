//c++11����thread_local����thread_local���εı�������thread���ڣ�
//ÿһ���̶߳�ӵ�в�ֻӵ��һ���ñ����Ķ���ʵ����һ��������Ҫ��֤�̰߳�ȫ�ĺ����С�
//����һ���߳�˽�б�����һ���߳�ӵ����ֻӵ��һ����ʵ����������static

#include <iostream>
#include <thread>
#include <string>

class A {
public:
    A() {}
    ~A() {}

    void test(const std::string& name) {
        thread_local int count = 0;
        ++count;
        std::cout << name << ": " << count << std::endl;
    }
};

void func(const std::string& name) {
    A a1;
    a1.test(name);
    a1.test(name);
    A a2;
    a2.test(name);
    a2.test(name);
}

int main() {
    std::thread(func, "thread1").join();
    std::thread(func, "thread2").join();
    return 0;
}