#include <iostream>
#include<thread>
#include<string>
#include<vector>
#include<algorithm>
#include<windows.h>
#include<list>
#include<mutex>

using namespace std;
// �����Ƕ���������Ż����õ���lock_guard����ֹ���������ǽ�����std::adopt_lock����ȡ����������
class myClass
{
public:
    void AddOrder()
    {
        for (int i = 0; i < 10000; i++)
        {
            cout << "addOrderִ�У�����һ��Ԫ��" << i << endl;
            std::lock(m_mutex1, m_mutex2);
            //std::adopt_lock���ã�ȡ������1��������Ϊ��һ���Ѿ�����1����������
            std::lock_guard<std::mutex> guard1(m_mutex1, std::adopt_lock);
            std::lock_guard<std::mutex> guard2(m_mutex2, std::adopt_lock);
            m_orderList.push_back(i);
        }
    }

    void RemoveOrder()
    {
        for (int i = 0; i < 10000; i++)
        {
            std::lock(m_mutex2, m_mutex1);
            std::lock_guard<std::mutex> guard1(m_mutex1, std::adopt_lock);
            std::lock_guard<std::mutex> guard2(m_mutex2, std::adopt_lock);
            if (!m_orderList.empty())
            {
                int i = m_orderList.front();
                m_orderList.pop_front();
                cout << "RemoveOrderִ�У�ɾ��һ��Ԫ��" << i << endl;
            }
        }
    }

private:
    std::list<int> m_orderList;
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