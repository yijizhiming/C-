#include <iostream>
using namespace std;

//�������һ������ final �ؼ��֣��øùؼ������ε��಻�ܱ��̳С�
//�����������������Ԫ����̳к�˽�й��캯����ʵ��
//��������̳���ʹ��virtual��̳У���������Ŀ����������ֱ�Ӹ�����үү�Ĺ��죬
//������үү�Ĺ����������˽�еģ����������죬�������ӾͲ��ܹ����Լ���
//��Ҳ���ǲ��ü̳��ˣ���Ϊ���ӱ����ʱ����ֱ�Ӹ���үү�Ĺ���ȴ��û�����죩
//
//�ڿ������үү�Ĺ����������˽�еģ���ζ�Ÿ���Ҳ���ܹ����ˣ�
//���԰Ѹ�����Ϊүү����Ԫ���Ϳ��Լ�������үү�Ĺ��������������
//�Ϳ��Թ��츸���ˣ����׸�����үү�����ҿ���ͨ����Ԫ��ϵ���죩

template <typename T>
class Base {
    friend T;
private:
    Base() {
        cout << "base" << endl;
    }
    ~Base() {}
};

class B :virtual public Base<B> {   //һ��ע�� ��������̳�
public:
    B() {
        cout << "B" << endl;
    }
};

class C :public B {
public:
    C() {}     // error: 'Base<T>::Base() [with T = B]' is private within this context
};


int main() {
    B b;
    return 0;
}
