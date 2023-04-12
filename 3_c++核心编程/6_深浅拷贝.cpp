//
// Created by NUC on 2023/4/12.
//


#include<iostream>
#include<string>

using namespace std; // 声明变量作用域.

/*
     深拷贝于浅拷贝: 经典的面试问题.
        浅拷贝: 简单的赋值拷贝操作, 就是=操作符
        深拷贝: 在堆区重新申请空间, 进行拷贝操作.
                使用new操作符.
    综上, 如果有属性在堆区开辟的, 那么一定要自己提供拷贝构造函数, 防止浅拷贝带来的问题.

 */

class Person{
public:
    Person(){
        cout << "Person()" << endl;
    }
    Person(int age){
        Person::m_age = age;
    }
    Person(int age, int height){
        cout << "Person(int age, int height)" << endl;
        Person::m_age = age;
        m_height = new int(height); // 堆区的数据.
    }
    // 自己实现拷贝构造函数, 解决浅拷贝带来的问题.
    Person(const Person &p){
        cout << "Person(const Person &p)" << endl;
        m_age = p.m_age;
        m_height = new int (*p.m_height); // 重新开辟空间.

    }

    ~Person(){ // 那么我们就需要手动管理我们的内存.
        // 将堆区开辟的数据进行释放:
        if (!m_height) {
            delete m_height; // 释放所指向的空间. 其实就是调用了这个对象的析构函数
            // 而free不会, 仅仅是释放对象所占用的内存.
            m_height = NULL;
        }

        cout << " ~Person()" << endl;
    }

    void str(){
        cout << m_age << " "<< m_height << endl;
    }

private:
    int m_age = 0;
    int *m_height = NULL;
};



void test01(){
    Person p1(10, 100);
    Person p2(p1); // z
    // 这里我们没有实现拷贝函数, 所以默认的拷贝函数仅仅是值拷贝(浅拷贝). 字节拷贝, 所以这个m_height里面保存的是地址.
    // 那么将地址拷贝给p2, 所以p2和p1指向的是同一块堆区空间, 释放时就会出错. 解决: 使用深拷贝.
    p1.str();
    p2.str();
    // Person(int age, int height)
    //10 0x1f99a9218d0
    //10 0x1f99a9218d0
    // ~Person()
    // ~Person()



    // 深拷贝:
    Person p3(p1);
    p3.str();



}


int main() {

    test01();


    return 0;
}