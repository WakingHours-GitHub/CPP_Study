//
// Created by NUC on 2023/3/14.
//

#include <iostream>
#include <string>
using namespace std;
/*
    运算符: 用于执行代码的运算.




 */


int main() {
    int a = 10; // 都是整数类型.
    int b = 3;
    cout <<  a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl; // 3 // 两个整数做运算, 结果依然是整数.


    int a3 = 10;
    int b3 = 0;
//    cout << a3 / b3 << endl; // 报错, 两个数相除, 除数不可以为0.

    // 两个小数可以相除
    double d1 = 0.5;
    double d2 = 0.22;
    cout << d1 / d2 << endl; // 2.27273 // 6位有效数字.

    // 求余数.
    cout << a % b << endl;  // 1取余数.

    int a2 = 10, b2 = 20;
    cout << a2 % b2 << endl; // 10, 因为10无法除开20, 上0, 余10

//    cout << a3 % b3 << endl; // 报错, 除数不可以为0.

    // 两个小数之间是不可以做取余运算的. %两端必须是整数.
//    cout << d1 % d2 << endl; // 直接报错

    // 算数运算符: 递增, 递减的符号.
    // 1.前置递增: 先+1, 然后让表达式进行计算
    a = 10;


    ++a; // 让变量a加1
    cout << a <<endl;

    // 2.后置递增: 先进行表达式的运算, 然后让变量+1
    b = 10;
    b++;
    cout << b << endl;

    a2 = 10;
    b2 = ++a2 * 10;
    cout << a2 << " " << b2 << endl; // 11 110

    a3 = 10;
    b3 = a3++ * 10; // 先使用值参与运算, 然后在++
    // 也就是先使用10进行运算, 然后a3++. 所以a3为11, b3为100
    cout << a3 << " " << b3 << endl; // 11 100

    // --同理.


    // 赋值运算符:
    /*
        =
        +=
        -=
        *=
        /=
        %=

        A += B <==> A = A + B
     */
    int d = 10;
    d += 10; // d = d + 10
    cout << d << endl; // 20


    /*
        比较运算符, 返回bool类型的变量, 0, 1.
        ==  测试相等
        !=  测试不等
        <   小于
        >   大于
        <=  小于等于
        >=  大于等于

     */
    int e = 10;
    int f = 20;

    cout << (e == f) << endl; // <<优先级比较高, 所以我们使用()提升==运算的优先级.
    // 然后将结果<<输出出去. // 0
    cout << (e != f)  << endl; // 1
    cout << (e > f) << endl; // 0

    // 逻辑运算符: 用于根据表达式的值返回真值或假值.
    /*
        逻辑运算符有一下几个符号:
        !   非   !a      如果a为false, 那么!a则true, 反之同理.
        &&  与   a&&b    如果a,b都为true, 则结果为true,  否则为false. 这是短路与
        ||  或   a||b    如果a,b有一个为真, 则结果为真, 二者都为false的时候, 结果为false
     */
    // 在c++, 非零都是true, 则都是1.
    a = 10;
    cout << !a << endl; // 0

    cout << !!a << endl; // 1


    a = 10;
    b = 10;
    cout << (a && b) << endl; // 1 &&两个全为true, 才为true.

    a = 0;
    cout << (a && b) << endl; // 0  有假即假

    cout << (a || b) << endl; // 1

    a = b = 0;
    cout << (a || b) << endl; // 0










    return 0;
}