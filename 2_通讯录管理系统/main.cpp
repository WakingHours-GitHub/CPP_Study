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

// 显示联系人
void print_Person(Person *p){
    cout << p->m_name << "\t" << (p->m_sex?"男":"女") << "\t" << p->m_age << "\t"
    << p->m_phone << "\t" << p->m_address <<endl;

}

void display_directory(Directory *d_p){
    // 首先判断通讯率当中人数是否为0
    if (d_p -> size <= 0){
        cout << "当前的记录为空" << endl;
    }else{
        for (int i = 0; i < d_p->size; i++){
            print_Person((Person *)d_p + i);
        }
    }
}

// 添加联系人
int add_Person(Directory *p){ // 利用地址传递可以修饰形参
    // 判断通讯率是否已经满了:
    if (p->size == MAX){
        cout << "通讯率已经满了, 所以无法添加" << endl;
        return 0;
    }else{
        cout << "请输入姓名: ";
        cin >> p->personAray[p->size].m_name;
        cout << endl;

        while (true){
            cout << "请输入性别: (1表示男, 0表示女): ";
            cin >> p->personAray[p->size].m_sex;
            if (p->personAray[p->size].m_sex == 1 || p->personAray[p->size].m_sex == 0){
                break;
            }else{
                cout << "输入有误, 请重新输入" << endl;
            }
        }


        cout << "请输入年龄: ";
        cin >> p->personAray[p->size].m_age; // 也可以进行判断, 使之有一个合理的范围.

        cout << "请输入电话号: ";
        cin >> p->personAray[p->size].m_phone;

        cout << "请输入地址: ";
        cin >> p->personAray[p->size].m_address;
        print_Person(&p->personAray[p->size]);

        p->size++; // 人数++.

//        system("cls"); // 清屏操作

        return 1;
    }
}

// 检测联系人是否存在: 存在返回索引, 不存在返回-1.
int is_Exist(Directory *d_p, string name){
    // 遍历所有人名:
    for (int i = 0; i < d_p->size; i++){
        if (d_p->personAray[i].m_name == name)
            return i; // 默认找到第一个元素的索引就返回.
    }
    return -1; // 如果遍历结束都没有找到则返回-1.

}
// 删除联系人.
void delete_Person(Directory *d_p){
    cout << "请删除联系人的姓名: " << endl;
    string name;
    cin >> name;
    int index = is_Exist(d_p, name);
    if (index != -1){ // 存在, 返回索引
        for (int i = index; i < d_p->size; i++){
            d_p->personAray[i] = d_p->personAray[i+1];
            // 结构体赋值就是将成员变量一一赋值过去. 速度较慢.
        }
        cout << "删除成功" << endl;
    }else{
        cout << "查无此人!" << endl;
    }
    d_p->size--; // 减少人数.
}



// 查找联系人.
void find_person(Directory *d_p){
    cout << "输入查找联系人的姓名: " << endl;
    string name;
    cin >> name;
    int index = is_Exist(d_p, name);
    if (index != -1){
        print_Person((Person *)(d_p) + index);

    }else{
        cout << "查无此人" << endl;
    }
}


// x修改联系人:


// 清空所有的联系人
void cleanPerson(Directory *d_p){
    // 直接使用逻辑清空, 做一个逻辑上的清空操作
    d_p -> size = 0;
    cout << "通讯率已经清空" << endl;
}

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
                display_directory(&directory);
                break;
            case 3: { // 删除联系人 如果使段代码, 那么需要使用{}进行括起来.
                delete_Person(&directory);
            }


                break;
            case 4: // 查找联系人
                find_person(&directory);
                break;
            case 5: // 修改联系人
                break;
            case 6: // 清空联系人
                cleanPerson(&directory);
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