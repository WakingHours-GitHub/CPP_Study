//
// Created by NUC on 2023/3/23.
//
#include <iostream>
#include <string>
#include "swap.h" // 再包含一次头文件.

using namespace std;



/*
    将一段经常使用的哦代码封装起来, 以减少重复代码.
    一个较大的程序, 一般分为若干的程序块, 每个模块实现特有的功能.
    五个步骤:
        返回值类型, 函数名, 参数列表, 函数体, reutrn表达式.
    返回值类型 函数名 (参数列表) {
        函数体
        return表达式
    }

    函数的调用:
        函数名(参数)


    值传递: 就是函数调用时实参将数值转递给形参
        如果形参发生改变, 并不会影响实参. 因为是两个不同的独立空间, 在内存上不统一.

    如果一个函数不需要返回值, 声明的时候可以写void.

    函数的常见样式:
        无参无返
            定义: void test(){}
            调用: test()
        有参无返
            定义: void test(int a, ...) {}
            调用: test(a, ...)
        无参有返
            定义: 类型 test(){... return}
            调用: 类型 变量 = test()
        有参有返
            定义: 类型 test(a, ...) {... return }
            调用: 类型 变量 = test(a,...)

    函数的申明:
        告诉编译器函数名称以及如何调用函数. 函数的实际主体可以单独定义.

    函数的分文件编写.
        让代码结构更加清晰, 函数分文件编写一般有4个步骤.
        创建.h的头文件
        创建.cpp的源文件
        在头文件中写函数的声明
        在源文件中写函数的定义
        (这两个名字最好是相同的, 方便对应)




 */


// 比较函数声明.
// 提前告诉编译器函数的存在, 可以利用函数的声明.
// 不用制定变量, 但是必须指定类型.
// 声明可以写多次, 但是定义只能有一次.
//int max(int a, int b);
int max(int, int);


//void swap(int num1, int num2) {
//    int temp = num1;
//    num1 = num2;
//    num2 = temp;
//
////    return ; // 什么都不需要写, 也可以将return省略.
//}





// 这就是函数的定义:
// 函数定义的时候, num1和num2没有真的数据, 他只是一个形式上的参数, 简称形参.
int add(int num1, int num2) {
    int sum = num1 + num2;

    return sum;
}



int main() {
    int a = 2, b = 0;
    int c = add(a, b); // 这里a,b称之为实参.
    // num1, num2是形参. 占位符.
    // 实参传值给形参.
    cout << c << endl;
    swap(a, b);

    return 0;
}



// 函数的定义:
int max(int a, int b){
    return a > b ? a: b;
}

