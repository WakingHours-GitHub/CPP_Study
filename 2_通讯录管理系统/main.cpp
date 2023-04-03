//
// Created by NUC on 2023/4/1.
//


#include <iostream>
#include <string>

using namespace std;

// 人员结构体变量
#define MAX 1000
struct Person{
    string m_name; // 名字
    int m_sex; // 性别
    int m_age; // 年龄
    string m_phone; // 电话号
    string m_address; // 地址。
};

// 通讯录结构体变量
struct Directory{
    Person personAray[MAX];
    int size = 0; // 初始化为0
};


// 添加联系人
int add_Person(Directory *p){ // 利用地址传递可以修饰形参
    // 判断通讯率是否已经满了:
    if (p->size == MAX){
        cout << "通讯率已经满了, 所以无法添加" << endl;
        return 0;
    }else{
        struct Person person;

        cout << "请输入姓名: ";
        cin >> person.m_name;
        cout << endl;

        while (true){
            cout << "请输入性别: (1表示男, 0表示女): ";
            cin >> person.m_sex;
            if (person.m_sex == 1 || person.m_sex == 0){
                break;
            }else{
                cout << "输入有误, 请重新输入" << endl;
            }
            cout << endl;
        }


        cout << "请输入年龄: ";
        cin >> person.m_age;
        cout << endl;

        cout << "请输入电话号: ";
        cin >> person.m_phone;
        cout << endl;

        cout << "请输入地址: ";
        cin >> person.m_address;
        cout << endl;

        // 将成员添加到通讯率的数组当中
        p -> personAray[p->size] = person; // 这里面指向刚刚创建好的Person

        return 1;
    }
}

// 显示联系人


// 函数显示页面.
void showMenu() {
    cout << "**************************" << endl;
    cout << "*****  1: 添加联系人  *****" << endl;
    cout << "*****  2: 显示联系人  *****" << endl;
    cout << "*****  3: 删除联系人  *****" << endl;
    cout << "*****  4: 查找联系人  *****" << endl;
    cout << "*****  5: 修改联系人  *****" << endl;
    cout << "*****  6: 清空联系人  *****" << endl;
    cout << "*****  0: 退出通讯录  *****" << endl;
    cout << "**************************" << endl;



}

int main() {

    int option = 0;
    Directory directory;

    while (true){
        showMenu();
        cin >> option; // 写入
        switch (option) {
            case 1: // 添加联系人
                if (add_Person(&directory)){
                    cout << "添加成功" << endl;
                }else{
                    cout << "添加失败" << endl;
                }
                break;
            case 2: // 显示联系人
                break;
            case 3: // 删除联系人
                break;
            case 4: // 查找联系人
                break;
            case 5: // 修改联系人
                break;
            case 6: // 清空联系人
                break;
            case 0: // 退出通讯率管理系统.
                cout << "欢迎下次使用" << endl;
                return 0; // 直接退出系统。
//                break;

            default:

                break;

        }
    }



    return 0;
}