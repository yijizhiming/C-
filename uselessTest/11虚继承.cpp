//ʹ����̳е�Ŀ�ģ���֤����������ͻ�ĳ�Ա��������������ֻ����һ�ݣ�
//��ʹ��ӻ����еĳ�Ա����������ֻ����һ�ݡ������μ̳й�ϵ�У�
//��ӻ����Ϊ����ֱ࣬�ӻ���ͼ�ӻ���֮��ļ̳й�ϵ��Ϊ��̳С�
//��̳л�ֱ������Ͳ�ε������๹�캯����ʼ�������
//ʵ�ַ�ʽ���ڼ̳з�ʽǰ����� virtual �ؼ��֡�

#include <iostream>
using namespace std;

// ��ӻ��࣬�������
class Base1
{
public:
    int var1;
};

// ֱ�ӻ��� 
class Base2 : virtual public Base1 // ��̳�
{
public:
    int var2;
};

// ֱ�ӻ��� 
class Base3 : virtual public Base1 // ��̳�
{
public:
    int var3;
};

// ������
class Derive : public Base2, public Base3
{
public:
    void set_var1(int tmp) { var1 = tmp; }
    void set_var2(int tmp) { var2 = tmp; }
    void set_var3(int tmp) { var3 = tmp; }
    void set_var4(int tmp) { var4 = tmp; }

private:
    int var4;
};

int main()
{
    Derive d;
    return 0;
}

