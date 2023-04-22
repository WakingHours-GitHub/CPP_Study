//
// Created by NUC on 2023/4/22.
//

#include<iostream>
#include<string>

using namespace std;


/*
    继承同名成员的处理方式.
    当子类和父类出现同名的成员, 如何通过子类对象访问到子类或者父类中同名的数据呢.

    访问子类同名成员 直接访问即可
    访问父类同名成员, 需要加作用域. 语法: 子类.父类作用域::属性(成员, 函数) // 这尼玛什么语法
    遵循就近原则.
    如果子类中出现了和父类同名的成员函数, 那么编译器会隐藏所有的同名函数, 因此需要加上作用域.

    总结:
        子类对象可以直接访问到子类中的同名成员
        子类对象加作用域可以访问父类的同名成员
        当子类与父类拥有同名的成员函数时, 子类会隐藏父类中的同名函数, 加作用域可以访问父类中的同名函数.


 */


class Base{
public:
    Base(): A(100){}
    void func(){
        cout << "Base -> func" << endl;
    }
    // 重载
    void func(string name){
        cout << "Base -> func: " << name << endl;
    }
    int A;
};

class Son: public Base{
public:
    Son(): A(200) {}

    void func(){
        cout << "Son -> func" << endl;
    }
    int A;

};

void test01() {
    Son s;
    cout << s.A << endl; // 就近原则, 先访问自身,
    // 如果通过子类对象 访问到父类中的同名成员, 需要加作用域
    cout << s.Base::A << endl; // 使用Base作用域下的A

    //
    s.func(); // 调用子类的func函数

    s.Base::func(); // 调用父类的func函数

    // 如果子类中出现了和父类同名的成员函数,
    // 子类的成员会屏蔽父类的所有同名成员.
//    s.func("lipu"); // 不能直接访问, 需要加作用域
    s.Base::func("lipu");

}


int main() {
    test01();



    return 0;



}