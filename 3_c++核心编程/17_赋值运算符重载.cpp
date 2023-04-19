//
// Created by NUC on 2023/4/19.
//
#include <iostream>
#include <string>

using namespace std;


/*
    C++编译器至少会给一个类添加4个函数,
        1. 默认构造函数(无参, 函数体为空)
        2. 默认析构函数(无参, 函数体为空)
        3. 默认拷贝构造函数, 对属性进行拷贝.
        4. 赋值运算符 operator=, 对属性进行值拷贝.

    如果类中属性指向堆区, 那么做赋值操作的时候也会出现深浅拷贝的问题.






 */

class Person{

public:
    int *age;


    Person(int age){
        this->age = new int(age); // 堆区开辟内存. 手动创建, 手动释放.
    }

    Person(const Person& p){
        cout << "Person(const Person& p)" << endl;
        this->age = new int(*p.age);
    }

    ~Person(){
        if (!this->age){
            delete this->age; // 手动释放.
        }
        this->age = NULL;
    }


    // =运算符重载
    Person& operator=(Person &p){
        // 自己改成深拷贝
        // 首先先判断是否有属性在堆区, 如果有则先释放干净, 然后再深拷贝
        if (this->age){ // this->age != NULL
            delete this->age; // 释放.
            this->age = NULL; // set NULL.
        }
        // 然后我们再重新再堆区创建对象, 这就是深拷贝.
        this->age = new int(*p.age);


        // 增加链式编程的逻辑
        return *this; // 返回对象本体.
        // 老生常谈的问题, 如果返回Peron对象, 那么则是调用构造函数返回一个新的对象,
        // 只有返回*this才是返回调用对象的本身.





    }
//private:
};


void test01(){
    Person p1(18);
    cout << "*(p1.age): " << (*(p1.age)) << endl; // 18

    Person p2(20);
    cout << "*(p2.age): " << (*(p2.age)) << endl;

    // 需要重写拷贝构造函数.
    Person p3 = p1; // 赋值操作 // 没有实现operator=时, 是浅拷贝, 仅仅赋值的是地址值.
    //
    cout << "*(p3.age): " << (*(p3.age)) << endl;


    Person p4(1);
    p4 = p1 = p2; // 链式编程
    // p3.operator=(p1)
    // p4.operator=(p3).
    cout << "*(p1.age): " << (*(p1.age)) << endl;

    cout << "*(p4.age): " << (*(p4.age)) << endl;
}




int main() {
    test01();



    return 0;



}