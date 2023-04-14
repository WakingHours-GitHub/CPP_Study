//
// Created by NUC on 2023/4/14.
//

#include <iostream>
#include <string>

using namespace std;



/*
    const修饰成员函数.
        常函数:
            成员函数后加上const后我们称这个函数为常函数
            常函数内不可以修改成员属性
            成员属性声明时加关键字mutable后, 在常函数中依然可以修改
        常对象:
            声明对象前加const称该对象为常对象
            常对象只能调用常函数.

 */

class Person{

public:
    int A;
    mutable int B; // 特殊变量, 加上mutable(可变的), 即使在常函数中, 也可以修改这个变量的值.
public:

    Person():A(0), B(0){};
    // 成员函数里面有一个this指针. 指向所调用的对象.
    // this指针的本质 是指针常量, 也就是指针的指向是不可以改变的. Person * const this;
    // 如果在加一个const, 就是const Person * const this; 就是常量指针常量.
    // 在成员函数后面, 加上了一个const就是修饰this指针的. 此时this指针即是常量指针, 也是指针常量.
    void showPerson() const { // 加上一个const, 我们就不能修改this所指向的值了.
        cout << "showPerson() " << endl;
//        this -> A = 10; // 不可以修改.
//        this = NULL; // this指针不可以修改指针的指向.
    }

    void func() {

    }
};

Person person;

// 常对象:
void test02(){

    const Person p; // 在对象之前加上const, 变为常对象
//    p.A = 10; // 不可以修改.
    p.B = 20; // 特殊, 可以修改.

    // 常对象, 只能调用常函数.
    p.showPerson();
//    p.func() // 报错 常对象不可以调用普通成员函数, 因为普通成员函数可以修改属性.

}

int main(){
    test02();




    return 0;
}