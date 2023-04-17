//
// Created by NUC on 2023/4/16.
//

#include <iostream>
#include <string>

using namespace std;


/*

    运算符重载: 对已有的运算符重新进行定义, 赋予其另外一种功能, 以适应不同的数据类型.

    对于内置数据类型, 编译器知道如何对其进行运算. 但是如果是自定义的类呢? 所以就有了运算符重载
    当然我们可以使用自身的成员函数用来定义这个操作, 不过运算符重载更加方便.
    编译器起了一个通用的名称: operator*, 这样在使用运算符的时候, 就会自动调用对应的operator函数.
    例:
        Person p3 = p1 + p2; <==> Person p3 = p2.operator+(p2); 一个道理.
        本质就是成员函数重载了运算符操作.

    也可以使用全局函数重载运算符.

    也就可以通过使用成员函数和全局函数进行重载运算符.






    加号运算符重载


    总结:
        对于内置的数据类型的表达式的运算符是不可以改变的(已经被定义好)
        不要滥用运算符重载.




 */

// 加号运算符重载



class Person {
public:
    Person() : A(0), B(0) {};

    Person(int a, int b) : A(a), B(b) {};


    // 通过成员函数重载+号
    Person operator+(Person &p) const{
        return Person(this->A+p.A, this->B+p.B);
    }

    Person operator+(int num) const{
        return Person(this->A+num, this->B+num);
    }

    void str() {
        cout << this->A << ", " << this->B << endl;
    }

    int A;
    int B;

};

// 通过全局函数重载操作符
//Person operator+(Person &p1, Person &p2) {
//    return Person(p1.A + p2.A, p1.B + p2.B);
//}


void test01() {
    Person p1(20, 20), p2(10, 10);
    Person p3 = p1 + p2; // 运算符重载.
    // 成员函数的本质: Person p3 = p1.operator+(p2)
    // 成员函数的本质: Person p3 = operator+(p1, p2)


    p3.str();

    // 运算符重载也可以发生函数重载, 使其可以复用我们的函数名.
    Person p4 = p1 + 100; // Person和int类型相加, 我们可以使用运算符重载我们的运算符操作.
    p4.str(); // 120, 120


}

int main() {
    test01();


    return 0;
}