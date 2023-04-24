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



    问题: 继承中同名的静态成员在子类对象上如何访问.
    静态成员: 类内声明, 类外初始化.
    静态成员和非静态成员出现同名, 处理方式一致
        访问子类同名成员, 直接访问即可
        访问父类同名成员, 需要加上作用域.
    同名静态成员的处理方式和非静态处理方式一样, 只不过有两种访问方式(通过对象, 通过类名)
 */


class Base {
public:
    Base() : A(100) {}

    void func() {
        cout << "Base -> func" << endl;
    }

    // 重载
    void func(string name) {
        cout << "Base -> func: " << name << endl;
    }

    static void static_func() {
        cout << "Base -> static void static_func()" << endl;
    }

    static void static_func(string name) {
        cout << "Base -> static void static_func(string name)" << endl;
    }

    int A;
    static int S_A;
};

int Base::S_A = 10; // 类外初始化这个对象


class Son : public Base {
public:
    Son() : A(200) {}

    void func() {
        cout << "Son -> func" << endl;
    }

    static void static_func() {
        cout << "Son -> static void static_func()" << endl;
    }

    int A;
    static int S_A;
};

int Son::S_A = 20; // 为什么要加上int.


// 同名静态成员函数:
void test03() {
    Son s;
    s.static_func();
    s.Base::static_func();

    // 通过类访问:
    Son::static_func();
    // 父类会隐藏所有同名的函数, 无论是否重载, 都需要加作用域.
    Son::Base::static_func();

}

// 同名静态成员属性
void test02() {
    // 通过对象访问.
    Son s;
    cout << "Son: S_A: " << s.S_A << endl;
    cout << "Base: S_A: " << s.Base::S_A << endl;

    // 通过类名访问:
    cout << "Son: S_A " << Son::S_A << endl;
    cout << "Base::S_A: " << Base::S_A << endl; // 直接通过父类的方式访问S_A
    cout << "Son::Base::S_A: " << Son::Base::S_A << endl; // Son通过类名访问父类作用域下的S_A
    // 第一个:: 表示通过类名的方式访问, 第二个:: 表示访问父类作用域下.





}

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
//    test01();
    test02();


    return 0;


}