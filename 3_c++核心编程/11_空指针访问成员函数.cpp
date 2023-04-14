//
// Created by NUC on 2023/4/14.
//

#include <iostream>
#include<string>
using namespace std;
/*
    // 空指针调用成员函数：
    C++中空指针也是可以调用成员函数的, 但是也是要注意有没有用到this指针.
    如果用到this指针, 需要加判断代码保证健壮性


    空指针是可以访问成员的, 但是前提是没使用到this指针.




 */


class Person{

    void printClass() const {
        cout << "Person class" << endl;
    }

    void printAge() {
        if (!this) { // this == NULL
            return;  // 直接返回, 进行判断.
        }
        cout << this->age << endl; // 其实访问成员的时候, 默认都加了一个this->
    }

    int age;
};


void test01(){

    Person *p = NULL;
//    p->printClass();
//    p->printClass();

}


int main() {


    test01();

    return 0;
}

