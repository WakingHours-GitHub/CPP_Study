//
// Created by NUC on 2023/4/19.
//
#include<iostream>
#include<string>

using namespace std;

/*
    函数调用运算符()也能重载
    由于重载后的使用方式非常像函数的调用, 因此称之为仿函数
    仿函数没有固定写法, 非常灵活.


    仿函数非常灵活, 没有固定的写法, 就是将对象调用函数.
    函数返回值, 参数列表, 都可以更改.


    相当于是对象(), 对象能够直接当函数调用. 实际上参数会传递给operator()函数.
    这个类似于python中的__call__()函数.


 */

class MyPrint{
public:
    string operator()(const string& test){
        cout << test << endl;
        return NULL;
    }
};

void test02(){
    // 匿名函数对象
    cout << MyPrint()("lipu") << endl;
    // MyPrint(),创建了一个匿名对象. 这个对象的特点就是立即创建, 立即使用, 立即销毁.

}
void test01(){
   MyPrint myPrint;

   myPrint("lipu");
}

int main() {


    test01();



    return 0;
}