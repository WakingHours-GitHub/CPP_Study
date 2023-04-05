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

// ��ʾ��ϵ��
void print_Person(Person *p){
    cout << p->m_name << "\t" << (p->m_sex?"��":"Ů") << "\t" << p->m_age << "\t"
    << p->m_phone << "\t" << p->m_address <<endl;

}

void display_directory(Directory *d_p){
    // �����ж�ͨѶ�ʵ��������Ƿ�Ϊ0
    if (d_p -> size <= 0){
        cout << "��ǰ�ļ�¼Ϊ��" << endl;
    }else{
        for (int i = 0; i < d_p->size; i++){
            print_Person((Person *)d_p + i);
        }
    }
}

// �����ϵ��
int add_Person(Directory *p){ // ���õ�ַ���ݿ��������β�
    // �ж�ͨѶ���Ƿ��Ѿ�����:
    if (p->size == MAX){
        cout << "ͨѶ���Ѿ�����, �����޷����" << endl;
        return 0;
    }else{
        cout << "����������: ";
        cin >> p->personAray[p->size].m_name;
        cout << endl;

        while (true){
            cout << "�������Ա�: (1��ʾ��, 0��ʾŮ): ";
            cin >> p->personAray[p->size].m_sex;
            if (p->personAray[p->size].m_sex == 1 || p->personAray[p->size].m_sex == 0){
                break;
            }else{
                cout << "��������, ����������" << endl;
            }
        }


        cout << "����������: ";
        cin >> p->personAray[p->size].m_age; // Ҳ���Խ����ж�, ʹ֮��һ������ķ�Χ.

        cout << "������绰��: ";
        cin >> p->personAray[p->size].m_phone;

        cout << "�������ַ: ";
        cin >> p->personAray[p->size].m_address;
        print_Person(&p->personAray[p->size]);

        p->size++; // ����++.

//        system("cls"); // ��������

        return 1;
    }
}

// �����ϵ���Ƿ����: ���ڷ�������, �����ڷ���-1.
int is_Exist(Directory *d_p, string name){
    // ������������:
    for (int i = 0; i < d_p->size; i++){
        if (d_p->personAray[i].m_name == name)
            return i; // Ĭ���ҵ���һ��Ԫ�ص������ͷ���.
    }
    return -1; // �������������û���ҵ��򷵻�-1.

}
// ɾ����ϵ��.
void delete_Person(Directory *d_p){
    cout << "��ɾ����ϵ�˵�����: " << endl;
    string name;
    cin >> name;
    int index = is_Exist(d_p, name);
    if (index != -1){ // ����, ��������
        for (int i = index; i < d_p->size; i++){
            d_p->personAray[i] = d_p->personAray[i+1];
            // �ṹ�帳ֵ���ǽ���Ա����һһ��ֵ��ȥ. �ٶȽ���.
        }
        cout << "ɾ���ɹ�" << endl;
    }else{
        cout << "���޴���!" << endl;
    }
    d_p->size--; // ��������.
}



// ������ϵ��.
void find_person(Directory *d_p){
    cout << "���������ϵ�˵�����: " << endl;
    string name;
    cin >> name;
    int index = is_Exist(d_p, name);
    if (index != -1){
        print_Person((Person *)(d_p) + index);

    }else{
        cout << "���޴���" << endl;
    }
}


// x�޸���ϵ��:


// ������е���ϵ��
void cleanPerson(Directory *d_p){
    // ֱ��ʹ���߼����, ��һ���߼��ϵ���ղ���
    d_p -> size = 0;
    cout << "ͨѶ���Ѿ����" << endl;
}

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
                display_directory(&directory);
                break;
            case 3: { // ɾ����ϵ�� ���ʹ�δ���, ��ô��Ҫʹ��{}����������.
                delete_Person(&directory);
            }


                break;
            case 4: // ������ϵ��
                find_person(&directory);
                break;
            case 5: // �޸���ϵ��
                break;
            case 6: // �����ϵ��
                cleanPerson(&directory);
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