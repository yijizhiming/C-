//��������
//��1�������ͷ���
//��2�����߳��ظ�������
//��3��˫�̶߳�������


//����������2��������A����B��Ҳ��2���̣߳��߳�1���߳�2���߳�1ִ��ʱ��
//��������A��Ȼ��Ҫȥ��ռB��ͬʱ�߳�2����������B��Ȼ��Ҫȥ��ռ��A,
//��ʱ�ͳ����������������ȴ���Դ���ֲ��ͷ��������Դ��

//���������std::lock()
//std::lock()�������ǣ�����2����ʱ��Ҫôͬʱ���ϣ�Ҫôͬʱ������
//���ǵ��߳�1ִ��ʱ����������A��Ȼ������B������ռ��ʱ��
//��ʱ��������B��Ȼ�����ͻ��A��Ҳ�ͷŵ���

#include <iostream>
#include<thread>
#include<string>
#include<vector>
#include<algorithm>
#include<windows.h>
#include<list>
#include<mutex>

using namespace std;

class myClass
{
public:
    void AddOrder()
    {
        for (int i = 0; i < 10000; i++)
        {
            cout << "addOrderִ�У�����һ��Ԫ��" << i << endl;
            std::lock(m_mutex1, m_mutex2);
            m_orderList.push_back(i);
            m_mutex1.unlock();
            m_mutex2.unlock();
        }
    }

    void RemoveOrder()
    {
        for (int i = 0; i < 10000; i++)
        {
            std::lock(m_mutex2, m_mutex1);
            if (!m_orderList.empty())
            {
                int i = m_orderList.front();
                m_orderList.pop_front();
                cout << "RemoveOrderִ�У�ɾ��һ��Ԫ��11111111111111111111" << i << endl;
            }
            m_mutex1.unlock();
            m_mutex2.unlock();
        }
    }

private:
    list<int> m_orderList;
    std::mutex m_mutex1;
    std::mutex m_mutex2;
};

int main()
{
    myClass my;

    std::thread obj1(&myClass::AddOrder, &my);
    std::thread obj2(&myClass::RemoveOrder, &my);
    obj1.join();
    obj2.join();

    system("pause");
}