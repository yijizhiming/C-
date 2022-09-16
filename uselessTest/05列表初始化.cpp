#include <iostream>
using namespace std;
class A
{
private:
    int val;
public:
    A()
    {
        cout << "A()" << endl;
    }
    A(int tmp)
    {
        val = tmp;
        cout << "A(int " << val << ")" << endl;
    }
    A& operator= (const A& a)
    {
        if (this == &a)
        {
            return *this;
        }
        this->val = a.val;
        cout << "A& operator= (const& A) " << endl;
        return *this;
    }
};

class Test1
{
private:
    A ex;

public:
    Test1() : ex(1) // ��Ա�б��ʼ����ʽ
    {
    }
};

class Test2
{
private:
    A ex;

public:
    Test2() // �������и�ֵ�ķ�ʽ
    {
        ex = A(2);
    }
};
int main()
{
    Test1 ex1;
    cout << endl;
    Test2 ex2;
    return 0;
}


  