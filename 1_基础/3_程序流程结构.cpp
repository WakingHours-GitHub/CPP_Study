//
// Created by NUC on 2023/3/16.
//

#include<iostream>
#include<string>

using namespace std;

/*
    顺序结构, 选择结构, 循环结构.
    循环结构: 程序顺序执行, 不发生跳转.
    选择结构: 依据条件是否满足, 有选择性的执行相应的功能.
    循环结构: 依据条件是否满足, 循环多次执行某段代码.

    选择结构:
    if语句: 执行满足条件的语句.
    if的三种形式: 单行格式if语句, 多行格式的if语句, 多条件的if语句.
    单行if语法:
        if(条件表达式) {
            表达式成立执行的语句.
        }
    多行if语法:
        if (条件表达式){
            满足表达式执行的语句
        }else{
            不满足表达式 执行的语句.
        }
    多条件if语句:
        if (条件){
            条件1满足的执行
        }else if(条件二){ // python里面是elif 表达式 :
            条件一不满足, 而条件而满足. 执行
        }...{
            等等.
        }else{ // 如果以上的条件全不满足, 那么最后有一个else进行包括, 这个else可有可无.
            都不满足执行的语句.
        }

    嵌套if语句：

    三目运算符: 通过三目运算符实现简单的逻辑判断.
        条件表达式? 表达式1: 表达式2
        测试条件表达式的值, 如果为true, 则执行表达式1. 如果为false则执行表达式2.
        并且将表达式的结果返回. 同时可以返回一个变量, 然后继续被用作使用.





 */

void if_study(){
    // 选择结构, 单行if语句.
    // 用户输入分数, 如果分数>600, 在屏幕上输出
    int score = 0;
    cout << "请输入你考得分数" << endl;
    cin >> score;
    cout << score << endl;
    // 注意事项: if条件后面不要加上分号. 如果加;表示一个语句的结束.
    if (score >= 640) {
        cout << "你他妈考上了一本大学. " << endl;
    }

    if (score >= 600) {
        cout << "你考上了一本大学" << endl;
    } else {
        cout << "你没有考上大学" << endl;
    }

    // 多条件的if语句.
    if (score >= 600) {
        cout << "考上了一本大学" << endl;
    } else if (score >= 400) { // 400 <= x <= 600
        cout << "考上了二本大学" << endl;
    } else if (score >= 300) {
        cout << "恭喜您考上了三本大学" << endl;
    } else {
        cout << "你真是春春废物, 你没考上大学" << endl;
    }

    // 嵌套if语句.
    if (score >= 600) {
        // 嵌套进行划分.
        if (score >= 650) {
            cout << "你考上了清华" << endl;
        }else if (score >= 600) {
            cout << "你考上了北大" << endl;
        }else{
            cout << "你考上了人大" << endl;
        }
    }else if (score >= 500){
        cout << "你考上了二本" << endl;
    }else if (score >= 400) {
        cout << "你考上了三本大学" << endl;
    }else{
        cout << "你没考上!" << endl;
    }

}

void instance(){ // 案例.
    // 创建三只小猪重量
    int num1 = 0, num2 = 0, num3 = 0;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cout << num1<< " "<< " " << num2 << " " << num3 << endl;

    if (num1 > num2) {
        if (num1 > num3){
            cout << "小猪A最重: " << num1 << endl;
        }else{
            cout << "小猪C最重: " << num3 << endl;
        }
    }else{
        if (num2 > num3){
            cout << "小猪B最重: " << num2 << endl;
        }else{
            cout << "小猪C最重: " << num3 << endl;
        }
    }





}

void third_operator(){
    // 三目运算符.
    // 创建三个变量, a, b, c.
    int a = 10, b = 20, c = 0;
    c = (a > b ? a : b);
    cout << c << endl;

    // 在C++中, 三目运算符返回的是变量, 可以继续赋值.
    (a>b?a:b) = 100; // 谁大, 就给谁赋值100.
    // 三目运算符的结果可以返回一个变量, 可以继续赋值.
    cout << b << endl; // 100

}

void switch_construct(){
    /*

        switch(表达式){
            case 结果1: 执行语句; break;
            case 结果2: 执行语句; break;
            ...
            default: 执行语句; break;
        }
        根据表达式的结果, 来去选择分支(case后面的结果), 然后执行语句, 最后通过break跳出.
        如果case都没有, 那么则进入default 执行后面的语句.

        // 这个表达式只能整数, 类似int 以及char. 字符型也可以. 不能是一个区间.
        优点结构清晰, 执行效率高.
        如果不写break, 则程序会一直向下执行.

     */

    // 给一个电影打分的操作
    // 10~9: 经典.

    int score = 0; // definite

    cin >> score; // cin score.
    cout << "您给出的分数: " << score << endl;

    switch (score) { // 这个表达式只能整数, 类似int 以及char. 字符型也可以.
        case 10:
        case 9:
            cout << "经典!" << endl;
            break;
        case 8:
        case 7:
            cout << "高分!" << endl;
            break;
        case 6:
        case 5:
            cout << "一般" << endl;
            break; // 如果不写break, 则程序会一直向下执行.
        default: // 如果前面几个都不满足, 则最后进入default.
            cout << "烂片" << endl;
            break;
    }
}

int main() {
//    instance();

//    third_operator();

    switch_construct();
    return 0;
}