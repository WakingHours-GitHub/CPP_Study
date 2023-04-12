//
// Created by NUC on 2023/4/12.
//


#include<iostream>
#include<string>

/*
    初始化列表: C++提供了初始化列表的语法, 用来初始化属性.
    构造函数就是用作属性的初始化. 也可以使用初始化列表进行初始化
    语法: 构造函数(): 属性1(值1), 属性2(值2), ... {}





 */



class Person{
public:
    // 传统的构造函数.
    Person(int a, int b, int c){
        (*this).A = a;
        this->B = b;
        this->C = c;
    }

    // 初始化列表进行初始化属性:
    Person(): A(10), B(10), C(10){ // 初始化.
            // 需要注意:的位置.
    }
    Person(int a, int b): A(a), B(b){ // 这样也是可以的.

    }
    void str(){

    }

private:
    int A;
    int B;
    int C;
};

int main() {

















    return 0;



}
