#include <iostream>
using namespace std;

int main()
{
    // �ֲ���������
    char var = 'A';

    //����
    //switch (var)
    //{
    //case 'A':
    //    int cnt = 0; // �������
    //    cout << "Excellent." << endl << cnt;
    //    break;  
    //case 'B':
    //case 'C':
    //    break;
    //
    //default:
    //    cout << "Bad." << endl;
    //}

    //���ǲ��ܶ��������ֻ����Ҫ�����������ڿ��ڣ�
    //��ȷ�������������caseλ��������֮�⣬���ⲻ���������case��ʹ�øñ���
    switch (var)
    {
    case 'A':
    {
        int cnt = 0; // �������
        cout << "Excellent." << endl << cnt;
    }
        break;
    case 'B':
    case 'C':
        break;

    default:
        cout << "Bad." << endl;
    }

    return 0;
}

