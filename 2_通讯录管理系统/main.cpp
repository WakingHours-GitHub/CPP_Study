//
// Created by NUC on 2023/4/1.
//


#include <iostream>
#include <string>

using namespace std;

// ��Ա�ṹ�����
#define MAX 1000
struct Person{
    string m_name; // ����
    int m_sex; // �Ա�
    int m_age; // ����
    string m_phone; // �绰��
    string m_address; // ��ַ��
};

// ͨѶ¼�ṹ�����
struct Directory{
    Person personAray[MAX];
    int size = 0; // ��ʼ��Ϊ0
};


// �����ϵ��
int add_Person(Directory *p){ // ���õ�ַ���ݿ��������β�
    // �ж�ͨѶ���Ƿ��Ѿ�����:
    if (p->size == MAX){
        cout << "ͨѶ���Ѿ�����, �����޷����" << endl;
        return 0;
    }else{
        struct Person person;

        cout << "����������: ";
        cin >> person.m_name;
        cout << endl;

        while (true){
            cout << "�������Ա�: (1��ʾ��, 0��ʾŮ): ";
            cin >> person.m_sex;
            if (person.m_sex == 1 || person.m_sex == 0){
                break;
            }else{
                cout << "��������, ����������" << endl;
            }
            cout << endl;
        }


        cout << "����������: ";
        cin >> person.m_age;
        cout << endl;

        cout << "������绰��: ";
        cin >> person.m_phone;
        cout << endl;

        cout << "�������ַ: ";
        cin >> person.m_address;
        cout << endl;

        // ����Ա��ӵ�ͨѶ�ʵ����鵱��
        p -> personAray[p->size] = person; // ������ָ��ոմ����õ�Person

        return 1;
    }
}

// ��ʾ��ϵ��


// ������ʾҳ��.
void showMenu() {
    cout << "**************************" << endl;
    cout << "*****  1: �����ϵ��  *****" << endl;
    cout << "*****  2: ��ʾ��ϵ��  *****" << endl;
    cout << "*****  3: ɾ����ϵ��  *****" << endl;
    cout << "*****  4: ������ϵ��  *****" << endl;
    cout << "*****  5: �޸���ϵ��  *****" << endl;
    cout << "*****  6: �����ϵ��  *****" << endl;
    cout << "*****  0: �˳�ͨѶ¼  *****" << endl;
    cout << "**************************" << endl;



}

int main() {

    int option = 0;
    Directory directory;

    while (true){
        showMenu();
        cin >> option; // д��
        switch (option) {
            case 1: // �����ϵ��
                if (add_Person(&directory)){
                    cout << "��ӳɹ�" << endl;
                }else{
                    cout << "���ʧ��" << endl;
                }
                break;
            case 2: // ��ʾ��ϵ��
                break;
            case 3: // ɾ����ϵ��
                break;
            case 4: // ������ϵ��
                break;
            case 5: // �޸���ϵ��
                break;
            case 6: // �����ϵ��
                break;
            case 0: // �˳�ͨѶ�ʹ���ϵͳ.
                cout << "��ӭ�´�ʹ��" << endl;
                return 0; // ֱ���˳�ϵͳ��
//                break;

            default:

                break;

        }
    }



    return 0;
}