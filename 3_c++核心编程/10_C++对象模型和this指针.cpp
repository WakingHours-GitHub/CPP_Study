//
// Created by NUC on 2023/4/13.
//

#include<iostream>
#include <string>
using namespace std;

/*
    C++对象模型和this指针.

    成员变量和成员函数分开存储.
        再C++中, 类内的成员变量和成员函数是分开存储的, 只有非静态成员才是属于类的对象.

    this指针:
        我们知道C++中, 成员变量和成员函数是分开存储的.
        每一个非静态成员函数只会诞生一份函数实例, 也就是说不同对象会公用一块代码.
        也就是说, 这一块代码是如何区分是哪个对象调用自己的呢.

        C++通过提供特殊的对象指针, this指针, 解决上述问题
        this指针是隐含每一个非静态成员变量函数内的一种指针.
        this指针不需要定义, 直接使用即可.

        用途:
            当形参和成员变量同名时, 可以通过this来区分.
            在类的非静态函数中返回对象本身, 可以return *this.



 */

class Person{

public:

    int A; // 非静态成员变量, 属于类的对象上.
    static int B; // 静态成员变啊零, 不属于类对象.
    void func(){}; // 非静态成员函数, 不属于类对象.
    static void func2(){}; // 静态成员函数, 不属于类对象.

    Person():A(10){};
    Person(int A){
        this->A = A; // 可以通过this解决名称冲突的问题.
//        this指针指向的调用的对象
    }

    Person(const Person &p){
        cout << "Person(const Person &p)" << endl;
        this->A=p.A;
        this->B=p.B;
    }

    Person& PersonAddAge(const Person &p){
        this -> A += p.A;
        return *this; // 返回调用的对象. 返回的是一个对象, 那么我们可以继续调用, 这就是链式编程实现的原理.
//        Person * const p = &(*this) 返回原理. *this就是这个对象, 然后再加上引用就是指针
        // 函数调用处, Person p = *(p)直接解引用. 拿到的就是所指向的对象. 这样一来就可以实现链式编程的思想了.
        // 如果是Person, 那么就是直接返回的是一个对象. 那么就会调用拷贝构造函数创建一个新的对象.
    }



};
int Person::B = 10;


void test03() {
    Person p1(10);
    Person p2(20);

    Person p3 = p1.PersonAddAge(p2); // *this此时就是p1. 那么就会调用拷贝函数.
    // 相当于p1.PersonAddAge(p2); Person p3 = Person(*(&p1)); 所以会调用拷贝函数.
    cout << p1.A << endl; // 30

    cout << p3.A << endl; // 30

    // 通过返回*this这种方式, 就能够实现链式编程的原理.
    // 这就是链式编程的思想! 就是追加.
    p1.PersonAddAge(p2).PersonAddAge(p2); // 仍然是对p1进行相加.
    // 如果返回的是Person, 那么p1.PersonAddAge()返回的就是一个新对象, 然后以后追加都是在这个新对象上进行增加, 这样就当时了连是变成的思想了.
    // 所以我们需要返回Person &是引用. 则会一直返回调用的本身的对象.
    cout << p1.A << endl; // 70


}


void test01(){
    Person p;
    // 空对象占用内存空间为1
    // C++编译器会给每个空对象也分配一个字节空间, 是为了区分空对象所占内存的位置.
    // 每个空对象应该有一个独一无二的地址
    cout << sizeof(p) << endl; // 1
}

void test02(){
    Person p;
    cout << sizeof(p) << endl; // 4

}



int main(){

//    test01();
//    test02();
    test03();




    return 0;







}