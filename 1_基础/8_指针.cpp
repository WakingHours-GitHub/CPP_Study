//
// Created by NUC on 2023/3/25.
//

#include <iostream>
#include <string>
//#include <celib.h>
#include <stdlib.h>
using namespace std;


/*
    指针的作用: 可以通过指针简介访问内存.
        内存编号是从0开始记录的. 一般使用十六进制数字进行表示.
        可以利用指针变量保存地址.

    指针变量保存的就是地址.
    可以通过一个指针保存一个地址.
    问题是: 如何定义, 如何使用指针.


    指针变量指向内存中编号为0的空间.
    这是一个特殊的空间. 0~255之间的内存编号是系统占用的, 因此不可以访问.
    作用: 初始化指针变量
    注意: 空指针指向的内存空间是不可以访问的.

    野指针: 指针变量指向非法的内存空间.
        就是没有初始化, 里面的值随机赋值. 此时使用指针则可能发生错误.

    const修饰指针: 三种情况:
        const修饰指针 -> 常量指针
        const修饰常量 -> 指针常量
        const既修饰指针, 也修饰常量.
        我们注意关注const后面的整体, 谁是整体, 就修饰谁.



 */


void point_definite() {
    // 定义指针: 数据类型 * 变量名 = 地址.
    int a = 10;
    int *p = &a; // 定义指针, 并且p指向a.
    // 区分概念: p是一个指针, 存放的是地址. *p是一个变量, 他的类型是int.
//    & 取地址.
    cout << &a << endl;
    cout << p << endl;
    // 指针就是地址编号.

     // 使用指针:
     // 通过解引用的方式来找到指针指向的内存中的数据.
     // *p 就表示找到p指向内存中的数据.
     cout << *p << endl; // 10
     *p = 100; // 通过*p进行修改 *p就表示a.
     cout << a << endl;


}


void point_sizeof() {
    int *p = NULL; // 空指针.
    // 32位os, 4个字节. 64位os, 8个字节. 不管什么类型的指针, 都是占用8个字节.
    cout << sizeof p << endl; // 8
    cout << sizeof (int *) << endl;
    cout << sizeof (double *) << endl;

}

void point_null_other(){
    int *p = NULL; // 初始化.
//    cout << *p << endl; // 不可以访问.
    // 读取访问权限冲突.
    // 野指针就是未初始化的指针.
    // 通常这时使用的是一个随机的数. 此时使用指针, 则可能造成给程序出错.






}


void const_point() {
    int a = 10, b = 20;

    // 修饰指针 -> 常量指针.
    // const修饰的是*p, 是常量的指针.
    const int *p = &a; // 指针的指向可以修改. 但是指针指向的值不可以修改.
//    *p = 30; // 报错
    p = &b; // 可以修改.
    cout << *p << endl;

    // 指针常量, const修饰的是p.
    int * const p2 = &a; // 指针常量. 指针的指向不可以改, 指针的值可以改.
    cout << *p2 << endl; // 20
    *p2 = 30;
//    p2 = &b; // 不可以改变.
    cout << *p2 << endl; // 30


    // 既修饰也修饰
    const int * const p3 = &a; // 指向和值都不可能修改.
    // 只有在初始化的时候定义.

    cout << *p3 << endl; // 30.



}


int * range(int end, int start=0){
    int *p_arr = (int *) malloc((end - start)*4);
    for (int i = start; i < end; i++){
        *(p_arr + i) = i;

    }
    return p_arr;
}

void point_array() {
    /*
        指针和数组
        目的: 利用指针访问数组中的元素.

     */
    int *arr = (int *)range(10);
    for (int i = 0; i< 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << arr[0] << endl;

    int *p = arr; // 数组名就是数组的首地址. 无需使用&

    // 利用指针访问第一个元素:
    cout << "利用指针访问第一个数据: " << *p << endl;
    // 指针移动int(四个字节)也就是步长.
    p++;
    cout << *p << endl; // 1

    int *p2 = arr;
    for (int i = 0; i < 10; i++) {
        cout << *(p2++) << " ";
    }



}


// 实现两个数组进行交换:
void swap_value(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
void swap_address(int * const a, int * const b){
    // 使用地址找到传递过来的实参数据, 然后进行交换. 通过地址我们就可以交换了.

    int temp = *a;
    *a = *b;
    *b = temp;




}

void point_function(){
    // 利用指针作为函数参数的时候, 可以改变实参的值.

    int a = 10, b = 20;
    // 如果是地址传递, 可以修改实参.
    swap_address(&a, &b);

    cout << a << " " << b << endl; // 交换成功.
}

int main() {
//    point_definite();

//    point_sizeof();
//    point_null_other();
//    const_point();
//    point_array();
    point_function();

    return 0;
}
