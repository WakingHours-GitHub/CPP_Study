//
// Created by NUC on 2023/4/13.
//

#include <iostream>
#include <string>
using namespace std;

/*
    静态成员:
        静态成员就是再成员变量和成员函数前加上关键字static, 称为静态成员
        静态成员分为:
            静态成员变量:
                所有对象共享一份数据
                再编译阶段分配内存. 相当于生成程序之前, 再全局区就已经生成了.
                类内声明, 类外初始化
            静态成员函数:
                所有对象共享一个函数
                静态成员函数只能访问静态成员变量.

        静态成员变量也是有访问权限的.


 */

class Person{
public:
    static int A;
    int C;

    // 静态成员函数, 也是有访问权限的.
    static void func(){
        cout << "static void func()" << endl;
        A = 100; // 静态成员函数可以访问静态成员变量
//        C=1; // 报错.// 因为C属于实例成员, 也就是属于对象, 那么对象有很多个. 所以C也有很多, 每个对象都是一样.
            // 所以不允许调用C
    }
private:
    // 静态成员变量也是有权限的.
    static int B;

    static void func2() { // 类外访问不到.
        cout << "static void func2()" << endl;

    }

};

int Person::A = 100; // 类外进行初始化
// 需要指定作用域. int A这是全局变量, 所以需要Person::A用来指定是Person的A.

//int Person::B = 200; // 报错, 私有权限, 访问不到


void test01(){
    Person p;

    cout << p.A << endl;

    Person p2;
    p2.A = 200;

    cout << p.A << endl;
}
void test02(){
    // 静态成员变量不属于某个对象上, 所有对象都共享同一份数据.
    // 因此静态成员变量有两种访问方式.
    // 通过对象进行访问.
    Person p;
    cout << p.A << endl;
    // 通过类名进行访问.
    cout << Person::A << endl;

//    cout << Person::B << endl;


}
// 访问静态成员函数:
void test03(){
    // 通过对象
    Person p;
    p.func();

    // 通过类访问.
    Person::func();

}
int main() {
//    test01();
//    test02();
    test03();





    return 0;








}