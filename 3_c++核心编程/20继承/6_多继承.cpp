//
// Created by NUC on 2023/4/23.
//

#include<iostream>
#include<string>

using namespace std;

/*
    C++允许一个类继承多个类
    语法:
        class 子类: 继承方式 父类1, 继承方式 父类, ... {};
    多继承可能引发父类有同名成员出现, 需要加作用域区分. 跟前面一样.

    C++在实际开发中不太建议使用多继承. 子类使用时需要加上作用域.



 */
class Base1{
public:
    int A = 100;

};
class Base2{
public:
    int A = 200;
    int B = 200;
};
class Son: public Base1, public Base2{
public:
    int C = 300;
    int D = 400;
};


void test01() {
    Son s;
    cout << "s.Base1::A: " << s.Base1::A <<  endl;
    cout << "s.Base2s::A: " << s.Base2::A <<  endl;

}






int main() {
    test01();



    return 0;
}