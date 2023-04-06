//
// Created by NUC on 2023/4/6.
//

#include <iostream>
#include <string>
using namespace std;



/*
    引用: 给变量起别名. (类似指针, 但是不是指针, 比指针更安全)
    语法: 数据类型 &别名 = 原名;
    别名和原名共同指向那个内存空间.


    引用注意事项.
    引用必须初始化, 引用在初始化后, 不可以改变.
    这是引用和指针的区别.
    指针可以是不初始化(野指针), 并且指针可以随时指向其他地址.


    引用作函数参数:
    作用: 函数传参时, 可以利用引用的技术让形参能够修改实参.
    优点: 可以简化指针修改实参.


    综上: 通过引用传递参数的效果和指针传递是一样的. 同时引用更加安全, 简单, 清晰.

    引用做函数返回值.
    同其他类型一样, 引用是可以作为函数的返回值存在的.
    注意: 不要返回局部变量的引用
    用法: 函数调用可以作为左值.


    引用的本质:
        本质: 引用的本质在C++内部实现就是一个指针常量.
        指针常量: 就是指针的指向不可以修改, 但是指向的值可以改变.
            也就是: int* const p = &  ;
            int* const p -> 指针常量.
            const int *p -> 常量指针.

        因此引用本质上就是指针常量, 更安全的指针.
        int &ref = a; <==> int* const ref = &a; 自动等价(编译器做的替换)
        同理: 在使用引用时候:
        ref <==> *ref 自动解引用.
        这也就是为什么, 只有初始化时才能给引用赋值.
        就直接将ref当作a, 直接用就可以了.

        C++推荐使用引用技术, 因为语法方面, 安全.
        引用本质是指针常量, 但是所有的指针操作编译器都帮我们做了.

    常量引用:
        常量引用主要修饰形参, 防止误操作
        在函数列表中, 可以加const修饰形参, 防止形参改变实参.








 */




void reference_define(){
    int a = 10;

    // 创建引用:
//    int &b; // 错误的, 必须要初始化.
    int &b = a;

    int c = 20;
//    b = c; // 赋值操作, 这不是更改引用.


    cout << b << endl;
    cout << a << endl;

    b = 20;
    cout << b << endl;
    cout << a << endl;

}


// 交换函数: 使用引用传值:
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


void test_swap(){
    int a= 10, b =20;
    swap(a, b);
    cout << a << endl;
    cout << b << endl;
}

// 引用做函数返回值.
// 不要返回局部变量的引用
int& test_reference_as_return_01() {
    int a = 10; // 栈区. 生命周期在这个函数里

    return a; // 返回了栈区局部变量的引用。
}

// 函数调用可以作为左值.
int& test_reference_as_return_02() {
    static int a = 10; // 静态变量, 全局区. 全局区上的数据在程序结束后系统释放.

    return a; // 返回了全局区变量内容.
}




void test_return(){
//    int &ref = test_reference_as_return_01();
//    cout << ref << endl; // 报错

    int &ref = test_reference_as_return_02();
    cout << ref << endl; // 10
    cout << ref << endl; // 10

    // 函数作为左值.
    test_reference_as_return_02() = 20; // a的引用 = 20; 所以就是对a进行赋值了.
    // 如果函数的返回值是引用, 那么这个函数调用可以作为左值.
    cout << ref << endl; // 20






}





// 引用的本质: 就是一个指针常量.
void func(int &ref) { // 参数列表是引用, 转换为int* const ref = &a;
    ref = 100; // 直接对引用进行赋值. ref是引用, 转换为*ref = 100; 自动解引用, 然后赋值
}
void nature_of_reference() {
    int a = 10; // 栈区变量

    // 自动转换为int* const ref = &a; 指针常量是指针指向不可变, 因此也说明了引用只能初始化.
    int &ref = a;
    ref = a; // 内部发现ref是引用, 自动转换为*ref = 20; 自动解引用.

    cout << a << endl;
    cout << ref << endl;

}

// 常量引用:
void showValue(const int &ref) {
//    ref = 20; # 通过const修饰, 防止误操作.
    cout << ref << endl;
}
void const_reference() {
    int a = 10;
//    int &ref = 10; // 引用必须引一块合法的内存空间. 这个10是在临时变量区.
    // 加上const之后, 编译器将代码修改:
//    int temp = 10; const int &ref = temp;
    const int &ref = 10;
//    ref = 20; // const修饰, 只读, 不可以修改了.


    showValue(a);
    cout << "a: " << a << endl;

}

int main() {
//    reference_define();
//    test_swap();
//    test_return();
//nature_of_reference();

const_reference();



    return 0;
}