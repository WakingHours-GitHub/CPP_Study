//
// Created by NUC on 2023/4/25.
//

#include<iostream>
#include<string>

using namespace std;

/*
    多态的基本概念。
    多态是C++面向对象的三大特征之一.
    多态分为两类:
        静态多态: 函数重载和运算符重载属于静态多态, 复用函数名
        动态多态: 派生类和虚函数实现运行时多态
    静态多态和动态多态的区别:
        静态多态的函数地址早绑定 - 编译阶段确定函数地址.
        动态多态的函数地址晚绑定 - 运行阶段确定函数地址. runtime运行时才知道确切的形态.

    动态多态:
        1. 有继承关系
        2. 子类重写父类的虚函数. 重写, 不是重载.

    动态多态的使用:
        父类的指针或者引用 指向子类对象.
    重写: 在继承关系下, 函数名, 返回类型, 参数列表完全相同 就叫重写.

    多态的底层原理:






 */


class Animal{
public:
    virtual void speak(){
        cout << "说话" << endl;
    }
};

class Cat: public Animal{
public:
    void speak(){
        cout << "cat说话" << endl;
    }
};

class Dog: public Animal{
public:
    void speak(){
        cout << "dog说话" << endl;
    }
};

// 执行说话的函数
// 地址早绑定, 因为我们在函数定义中已经绑定了类型, 所以传入进来的对象就是Animal类的.
void doSpeak(Animal &animal){ // 父类的引用(指针)指向子类的对象. 这就可以实现动态多态.
    animal.speak(); // 加上virtual, 此时函数就变成晚绑定地址了类型了.
}

// 如果需要执行传谁, 谁说话, 那么这个函数的地址就不能提前绑定, 需要在运行阶段进行绑定
// 即地址晚绑定, 需要使用virtual关键字, 变成虚函数.

void test01() {
    Cat cat;
    doSpeak(cat);

    Dog dog;
    doSpeak(dog);

}

void test02(){
    cout << sizeof(Animal) << endl; // 8 这其实是一个指针.
    // vfptr: virtual function pointer, 虚函数指针, 虚函数表指针.
    // 这个指针指向的是一个虚函数表. vftable, virtual function table.
    // 这个表内会记录不同作用域虚函数的地址. 虚函数就是前面有virtual标识符的函数.
    // 当子类重写父类函数的时候, 就会将父类的虚函数表覆盖掉, 替换为自己的虚函数表.
    // 所以从子类对象调用函数, 那么就会走子类的虚函数指针表.



}

int main() {
//    test01();
    test02();



    return 0;
}



