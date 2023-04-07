//
// Created by NUC on 2023/4/7.
//


#include <iostream>
#include <string>
using namespace  std;


/*
    函数的默认参数:
        在C++中, 函数参数列表中的形参是可以有默认值的.
        语法: 返回值类型 函数名 (参数=默认值) {函数体}
        如果我们自己传入了数据, 就用自己的数据, 如果没有, 就使用默认值.

    注意:
        1. 普通参数放在前面, 默认参数放在后面, 默认参数后不允许再出现普通参数.
           int func(int a, int b = 20, int c = 30, int d) // 报错.

        2. 如果函数声明有默认参数, 那么函数实现就不能有默认参数.
            声明和实现只能有一个默认参数.


    函数占位参数:
        C++中函数的形参列表里可以有占位参数, 用来做占位, 调用函数时必须填补该位置.
        语法: 返回值类型 函数名(数据类型) {}
        现阶段占位参数意义不大, 但是后续会用到. 后面再学.
        在函数里面用不到... 后面有用.
        占位参数还可以有默认参数.
            void func4(int a, int = 10) // 占位参数还可以有默认参数.


    函数重载: overload
        函数名可以相同, 提高复用性.
        函数重载满足的条件:
            同一个作用域下
            函数名相同, 返回值相同.
            函数参数类型不同, 或者个数不同, 或者顺序不同. 也就是参数列表不同.
    注意: 函数的返回值不可以作为重载的条件.

    函数重载的注意事项:
        引用作为重载条件, 传递引用也能作为重载条件, 但是有一些细节需要注意.
        函数重载碰到默认参数.





 */

// 函数的默认值:
// 如果传入了值, 那么就是用传入的值, 如果没有传入值, 那么就是用默认值.
int func(int a, int b = 20, int c = 30) {
    return a + b + c;

}

int func2(int a=10, int b=10);

//int func2(int a=20, int b = 1){ // 报错, func2重定义了默认参数, 这种写法是错误的.
//}

int func2(int a, int b) { // 正确.
    return a+b;
}
void test01(){
    cout << func(10, 30) << endl;
    cout << func2() << endl;
}

// 占位参数:
void func3(int a, int){ // a是普通参数, 单独一个数据类型就是占位参数
    cout << "this is func3 function" << endl;
}
void func4(int a, int = 10){ // 占位参数还可以有默认参数.
    cout << "this is func3 function" << endl;
}


void test02() {
    func3(10, 10); //
    func4(10); // 默认占位参数.
}



// 函数重载:
void func5() {
    cout << "func5调用" << endl;
}

// 同一个作用域, 函数名相同, 参数列表不同, 就是重载.
void func5(string str) {
    cout << str << "func5调用" << endl;
}
void func5(double d) {
    cout << d << endl;
}
//int func5(double d){ // 报错. 函数的返回值不可以作为函数重载的条件.
//}
void test03() {
    // 通过函数参数进行调用重载的方式.
    func5(); // 调用没参数的那个
    func5("test: "); // 调用有参数的那个
}

// 函数重载的注意事项:
// 1. 引用作为重载的条件
void func6(int &a){ // int &a = 10, 不合法.
    cout << "func6 int &a" << endl;
}
void func6(const int &a){ // int temp=10; const int &a = temp;
    cout << "func6 const int &a" << endl;
}
void test04() {
    // 加const和不加const对于引用来说是有区分的. 可以作为函数重载.
    int a = 10;
    func6(a); // func6 int &a 变量, 可读可写. 所以调用int &a

    // 如果是常量:
    const int b = 10;
    func6(b); // func6 const int &a

    // 或者是这样:
    func6(10); // 直接传递一个常量10也是: func6 const int &a
    // 还记得常量和引用之间的联系吗. int &a = 10, 这是错误的.
    // 但是const int &a = 10; 编译器会给我们做优化. 所以只能走这个.


}

// 函数重载碰到默认参数:
void func7(int a, int b=10){
    cout << "func7(int a, int b)" << endl;
}
// 可以重载. 参数个数不同. 语法可以通过
void func7(int a){
    cout << "func7(int a)" << endl;
}
void test05(){
//    func7(10); // 运行时出错. 因为上面那个有一个默认函数, 所以传递一个参数,可以走上面也可以走下面函数.
    // 因此会报错. 我们尽量避免这方式出现.,
    func7(10, 20); // 传递两个参数是没问题的. func7(int a, int b)

}
int main() {
//    test01();
//    test02();
//    test03();
//    test04();
    test05();





    return 0;
}