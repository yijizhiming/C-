#include <iostream>
using namespace std;

template<typename T>
class A {
public:
    void function() {
        cout << "һ��" << endl;
    }
};

template<typename T>
class A<T*> { // ����������ȷ����Ϊƫ�ػ���
public:
    void function() {
        cout << "ƫ��" << endl;
    }
};

int main() {
    A<int*> a;
    a.function();
    cout << "*********" << endl;
    A<int> b;
    b.function();
    cout << "*********" << endl;
    A<int**> c;
    c.function();
    return 0;
}

/*
ƫ��
һ��
ƫ��
*/