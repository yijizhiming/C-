#include <iostream>
#include <string>
using namespace std;

class A {
public:
    A(int size) : size_(size) {
        data_ = new int[size];
        for (int i = 0; i < size; ++i)
            data_[i] = i;
    }
    A() {}
    A(const A& a) {
        size_ = a.size_;
        data_ = new int[size_];
        cout << "copy " << endl;
    }
    A(A&& a) {
        this->data_ = a.data_;
        this->size_ = a.size_;
        a.data_ = nullptr;
        cout << "move " << endl;
    }
    ~A() {
        if (data_ != nullptr) {
            delete[] data_;
        }
    }
    int* data_;
    int size_;
};

int main() {
    A a(10);
    cout << a.data_[0] << endl;
    A b = a;
    cout << a.data_[0] << endl;
    A c = std::move(a); // �����ƶ����캯��
    cout << a.size_ << endl;
    cout << c.size_ << endl;
    //cout << a.data_[0] << endl;//������䲻��ִ�У���Ϊ���ڴ�ռ������Ȩת������c
    cout << c.data_[0] << endl;
    
  /*  ����

        Test(1)��1����ֵ��ģ����T&& t����Ϊ�������ã���ֵ1����Test�����б������ֵ���ã�
        ���ǵ���PrintV()ʱ��t�������ֵ����Ϊ�������һ��ӵ�����ֵı��������Դ�ӡlvalue��
        ��PrintV(std::forward<T>(t))ʱ�򣬻��������ת��������ԭ��������ת�������Դ�ӡrvalue��
        PrintV(std::move(t))�������ʻ��ӡrvalue��

        Test(a)��a����ֵ��ģ����T&& ����Ϊ�������ã���ֵa����Test�����б������ֵ���ã�
        �����д����д�ӡ��

        Test(std::forward<T>(a))��ת��Ϊ��ֵ������ֵ��������T��T����ֵ�Ǿ�ת��Ϊ��ֵ��
        T����ֵ�Ǿ�ת��Ϊ��ֵ��
  */


    return 0;
}