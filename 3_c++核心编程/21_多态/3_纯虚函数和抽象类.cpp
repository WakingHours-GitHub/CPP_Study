//
// Created by NUC on 2023/4/27.
//

#include<iostream>
#include <string>
using namespace std;


/*
    在多态中, 通常父类中的虚函数的实现是毫无意义的, 主要都是调用子类重写的内容.
    因此可以将虚函数改为纯虚函数

    纯虚函数语法: virtual 返回值类型 函数名(参数列表) = 0;
    当类中有了纯虚函数, 这个类也被称为抽象类.

    抽象类特点:
        1. 抽象类无法实例化对象
        2. 子类必须重写抽象类中的纯虚函数, 否则也属于抽象类.



*/

class Base{
public:
    // 纯虚函数
    // 只要有一个纯虚函数, 则这个类称为抽象类
    virtual void func() = 0; // 纯虚函数
};

class Son: public Base{ // 继承.
    // 子类必须重写纯虚函数, 如果不重写则仍然是抽象类, 无法实例化操作.
    virtual void func(){
        cout << "void func() override" << endl;

    }
};


void test01() {
//    Base base; // 抽象类是无法实例化对象的
//    new Base(); // 抽象类是无法实例化对象的
    Son s;
    Base * base = new Son(); // 父类指针, 指向子类对象.
    base->func(); //





}

int main() {
    test01();

    return 0;
}





