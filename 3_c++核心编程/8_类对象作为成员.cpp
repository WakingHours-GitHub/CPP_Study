//
// Created by NUC on 2023/4/13.
//
// do real Sigma
#include <iostream>
#include <string>
using namespace std;

/*
    C++类中的成员可以是另一个类的对象, 我们称该成员为对象成员.

    当其他类的对象作为本类的成员, 先构造类对象, 然后再构造自身类.
    析构, 谁先被创建, 谁最后被释放. stack的原理.




 */


class Phone{

public:
    Phone(string brand){
        cout << "Phone(string brand)" << endl;
        this->brand = brand;
    }

    ~Phone(){
        cout << "~Phone()" << endl;
    }
private:
    string brand; // 手机品牌.
};


// 类对象作为类成员.
class Person{
public:
    // 这里对p传入了string, 但是后面却没有任何报错, 这是隐士转换法.
    // Phone p = string_p <==> Phone p = Person(string_p). 返回对象.
    Person(string name, string string_p): name(name), p(string_p){
        cout << "Person(string name, string string_p): name(name), p(string_p)" << endl;
    };


    ~Person(){
        cout << " ~Person()" << endl;
    }

public:
    string name;
    Phone p;
};




void test01() {
    Person p("张三", "苹果MAX");
    /*
     可见, 先调用Phone的构造函数, 然后才是Person的构造函数.
     释放是同理的, 是栈的原理, 谁先被创建, 那么谁最后被释放.
     Phone(string brand)
    Person(string name, string string_p): name(name), p(string_p)
     ~Person()
    ~Phone()
     */

}



int main() {
    test01();

    return 0;
}





