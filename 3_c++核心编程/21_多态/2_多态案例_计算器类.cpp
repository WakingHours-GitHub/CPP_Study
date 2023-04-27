//
// Created by NUC on 2023/4/26.
//
// 分别利用普通写法和多态技术实现计算器类.

#include<iostream>
#include<string>
using namespace std;

/*
    普通的方法
    如果想要拓展新的功能, 则需要修改源码, 这种方法不提倡.
    在真正的开发中提倡开闭原则.
    开闭原则: 对拓展进行开发, 对修改进行关闭.
    所以利用多态进行改写.


    多态的好处:
        组织结构清晰. 只需要看子类的结构. '
        可读性强.
        对于前期和后期拓展以及维护性强.
 */


// 普通写法:
class Calculator_common{
public:
    Calculator_common(int num1, int num2): num1(num1), num2(num2){}
    int getResult(string oper){
        if (oper == "+"){
            return num1 + num2;
        }else if (oper == "*"){
            return num1 * num2;
        }else if (oper == "-"){
            return num1 - num2;
        }
        // 如果想要拓展新的功能, 则需要拓展源码. 这是不被提倡的.
        //

        return NULL;
    }

    int num1, num2;
};

// 使用多态的方式:
// 多态的好处:
// 组织结构清晰. 只需要看子类的结构. '
// 可读性强.
// 对于前期和后期拓展以及维护性强.
// 首先实现一个(抽象)基类, 这里面什么功能都不写, 只是定义一种规范.
class AbstractCalculator{
public:
    virtual int getResult(){ // 定义一种规范.
        return NULL;
    }
    int num1, num2;
};

// 加法计算器类
class AddCalculator: public AbstractCalculator{
public:
    int getResult(){
        return num1+num2;
    }
};
// 减法计算器类
class SubCalculator: public AbstractCalculator{
public:
    int getResult(){
        return num1 - num2;
    }
};



void test02(){
    // 多态使用条件:
    // 父类指针或者引用指向子类对象.

    // 假发运算:
    AbstractCalculator *abc = new AddCalculator();
    abc->num1 = 10;
    abc->num2 = 20;
    cout << abc->getResult() << endl;

    // 堆区数据, 手动开辟, 手动销毁
    delete abc; // 释放这个地址的内容, 不释放这个变量.


}

void test01(){
    Calculator_common c(10, 20); // 隐式调用.

    cout << c.getResult("*") << endl;

}
int main() {
//    test01();
    test02();



    return 0;
}