//
// Created by NUC on 2023/4/10.
//
#include<iostream>
#include<string>

using namespace std;


/*
    对象的初始化和清理也是两个非常重要的安全问题。
    利用 构造函数和析构函数 解决上述两个问题。
    如果自己不实现, 那么编译器也会提供一个空实现的构造函数和析构函数.
    编译器会自动调用构造函数和析构函数.

    构造函数: 主要作用在于创建对象时为对象的成员属性进行复制, 构造函数由编译器自动调用, 无需手动调用.
    析构函数: 主要作用在于对象销毁前系统自动调用, 执行一些清理工作.

    构造函数语法: 类名([参数列表]){}
        1. 构造函数, 没有返回值也不写void
        2. 函数名称与类名相同
        3. 构造函数可以有参数, 因此可以发生重载
        4. 程序在调用对象时会自动调用构造, 无需手动调用, 而且只会调用一次.
    析构函数语法: ~类名() {}
        1. 没有返回值, 也不写void
        2. 函数名称与类名相同, 需要在前面加上~
        3. 析构函数不可以有参数, 因此不可以发生重载
        4. 程序在对象销毁前会自动调用析构函数, 无需手动调用, 并且只会调用一次.


    构造函数的分类及其调用:
        两类分类方式:
            按照参数: 有参构造和无参构造(默认构造函数)
            按类型分: 普通构造和拷贝构造
        三种调用方式:
            括号法, 显示法, 隐式转换法
    // 不要利用拷贝构造函数, 初始化匿名对象. 会被认为重定义.




 */

// 对象的初始化和清理:
class Person{
    // 构造函数:
public:
//    Person(){} // 编译器创建的.
    // 构造函数:
    Person(){ // 无参构造
        cout << "Person()" << endl;
    }
    Person(string name){
        this -> name = name;
        cout << "Person(string name)" << endl;
    }
    // 拷贝构造函数: 拷贝, 就是通过拷贝出来一摸一样的对象出来.
    Person(const Person &p){ // const Person * const p, 就是指针, 和变量都不能改.
        // 将传递的对象, 直接拷贝一份, 返回新的对象.
        this -> name = p.name; // 引用 (*p).name.
        cout << "Person(const Person &p)" << endl;
    }


    // 析构函数: 对象释放的时候调用.
    ~Person(){
        cout << this->name << ": ~Person()" << endl;
    }


private:
    string name;


};

// 调用.
void test02(){
    // 1. 括号法
//    Person p1; // 默认构造无参构造函数, 不要加上小括号.
//    Person p2("lipu"); // 有参构造函数
//    Person p3(p2); // 拷贝构造函数. p2和p3里面的成员属性是相同的.

    // 下面这行代码, 编译器会认为是一个函数的声明. 不会认为是创建对象.
    // 因此在使用默认无参构造函数时, 不要加上().
//    Person p1();

    /*
        Person()
        Person(string name)
        Person(const Person &p)
        lipu: ~Person()
        lipu: ~Person()
        : ~Person()
     */


    // 2. 显示法.
    Person p1; // 默认构造
    Person p2 = Person("LIPU"); // 有参构造.
    Person p3 = Person(p2);
//     Person("LIPU"); // 单独拿出来, 这叫做匿名对象.
//     cout << "aaa" << endl;
     /*
        Person(string name)
        LIPU: ~Person() // 立刻析构.
        aaa
      */
    // 实际上这条语句创建了一个对象.
    // 匿名对象: 特点: 当前语句执行结束后, 系统就会立即回收匿名对象.

    // 注意事项:
    // 不要利用拷贝构造函数, 初始化匿名对象.
//    Person(p3); // 错误: Person(p3);是一个重定义.
    // 编译器会认为:　Person(p3) <==> Person p3; 这是对象的声明.

    // 3. 隐式转换法:
//    Person p4 = "LIPU_yinshi"; // 相当于写了Person p4 = Person("")
// 好像报错
    Person p5 = p3; // 隐士转换....

}

void test01(){

    Person p; // 在栈上的数据. 创建变量时, 调用变量的构造函数.
//    释放这个对象之前, 自动调用析构函数
}

int main() {
//    test01();
//    Person p; // 全局区.

//    system("pause"); // 堵塞.

    test02();

    // p释放, 调用析构.
    return 0;
}