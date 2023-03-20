//
// Created by NUC on 2023/3/17.
//



#include<iostream>
#include<string>
#include <math.h>
// time系统时间头文件的包含:
#include <ctime>
using  namespace std;


/*
    while循环语句:
        循环条件表达式为true, 则执行循环语句.
    while(循环条件表达式){
        循环体
    }

    do-while循环语句:
    与while的区别在于do_while会先执行一次循环语句, 再判断循环条件.
    注意, do_while语句在while语句后面需要加上一个分号.
    do {
        循环语句
    } while(循环条件);


    for 循环: 满足循环条件, 执行循环语句
    for(起始表达式; 条件表达式; 末尾表达式) {
        循环体;
    }
    表达式之间使用;进行分割.
    起始表达式, 就是在循环之前, 只执行一次, 通常用来初始化.
    条件表达式为true, 则执行循环体的内容
    末尾表达式: 是每次循环之后需要执行的语句

    先执行起始表达式, 然后判断是否满足循环条件, 然后进入循环体, 当循环体完成之后, 执行末尾表达式,
    然后在判断是否满足循环条件.



 */

void while_study(){
    int num = 0;

    // while(表达式)循环, 表达式为true, 则执行循环.
    // 避免死循环的出现, 除非你需要这样一种结构.
    // 在程序执行的时候, 程序必须提供跳出循环的出口, 否则会出现死循环.
    while (num < 10) {
        cout << num << endl;
        num++;
    }
}


void gauss_number(){
    // 系统生成随机数:
    // 添加随机数种子: 利用当前系统的时间生成随机数, 防止每次随机数都一样.
    srand((unsigned int) time(NULL));

    // rand() 生成随机数.
//    rand() % 100 // 这样去写, 生成0~99的随机数
    int rand_num = (rand() % 100 + 1); // 生成随机数.
    // 生成伪随机数.
    cout << rand_num << endl;
    int gauss_value = 0; // 玩家猜测的数字

    // 玩家进行猜测.
    while (1) {
        cout << "请输入您要猜测的数字:" << ends;
        cin >> gauss_value;
        if (gauss_value > rand_num) {
            cout << "太大了" << endl;
        }else if (gauss_value < rand_num) {
            cout << "太小了" << endl;
        }else{
            cout << "猜对了!!!" << endl;

            // 猜对了, 退出
            break; // 利用break退出循环.
        }
    }

    // 判断玩家猜测

    // 猜对 -> 推出

    // 猜错 -> 提示大小.

}

void do_while_study(){
    int num = 0;

    do { // 先执行do中的语句. 然后在进行判断. 会先执行一次do.
        cout << num << endl;
        num++;
    }while(num < 10);
}


void do_while_instance_narcissistic_number(){
    // 水仙花数: 是一个三位数, 他的每个个位上的数字的三次幂之和等于它本身.
    // 例如: 1^3 + 5^3  + 3^3 = 153.
    // 利用dowhile, 求出所有的三位数水仙花数
    int num = 123;
    /*
     (num % 10) 个位
     (num / 10 % 10) 十位
     (num / 100) 百位.
     */
    int a=0, b=0, c=0;
    do {
        a = (num % 10), b = (num/10%10), c = (num/100);
        if (num == (a*a*a + b*b*b + c*c*c)) {
            cout << num << endl;
        }
        num++;
    }while (num < 1000);
}

void for_study(){
    for(int i = 0; i < 10; i++) {
        cout << i << endl;
    }
}

void for_instance_knock_desk(){

    // 7的倍数, 个位有7, 十位有7
    // 数字 % 7 == 0, 表示能被7整除, 这就是7的倍数.
    // 个位, 十位, 都讲过了. 不在赘述.
//    int num = 1;
    for (int i = 1; i <= 100; i++) {
        if ((i % 10) == 7 || (i / 10 ) == 7 ||  (i%7==0)) { // 使用||(逻辑或)进行并.
            // 因为指定是三位数, 所以直接/10就可以得到个位.
            cout << i << " 敲桌子!!!" << endl;
        }else {
            cout << i << endl;
        }
    }
}

void nest_loop() {
    /*
        嵌套循环: 在循环体中再嵌套一层循环, 解决一些实际问题.

     */

    // 打印一行:
//    for (int i = 0; i < 10; i++){
//        cout << "* "; // 不换行打印.
//    }
//    cout << endl; // 换行处理.

    // 外层执行一次, 内层执行一周.
    for (int i = 0; i < 10; i++){
        // 内层循环
        for (int j = 0; j < 10; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void  multiplication_table(){
    // 实现99乘法表:

    for (int i = 1; i < 10; i++){ // 行数
        for (int j = 1; j <= i; j++) { // 列<=当前的行数
            cout << j << "*" << i << " = " << i*j << " ";
        }
        cout << endl;
    }
}

void break_and_continue_goto(){
    /*
        break语句: 用于跳出选择结构或者循环结构. 使用方法.
        break使用的时机: 出现switch条件语句当中, 作用是终止case并跳出switch.
        出现循环语句中是, 跳出当前的循环语句.
        出现在嵌套循环中, 跳出最近的内层循环语句.


        continue: 在循环语句中, 跳过本次循环中余下尚未执行的语句, 继续执行下一次循环.
        循环语句: do_while, while, for.
        continue就是直接执行下一次的循环. 而不执行本次循环后续的语句了.
        continue不会终止循环.

        goto语句: 可以无条件的跳转代码
        语法: goto 标记; // goto标记
                标记: // 这就表示标记.
        如果标记的名称存在, 执行到goto语句时, 则会跳转到标记的位置.
        不常用, goto容易影响代码逻辑和结构.

     */

    cout << "1, ****" << endl;
    goto FLAG;
    cout << "2, ****" << endl;
    cout << "3, ****" << endl;
    cout << "4, ****" << endl;

    FLAG:
    cout << "5, ****" << endl;
    cout << "6, ****" << endl;










}


int main(){
//    while_study();
//    gauss_number();

//    do_while_study();
//    do_while_instance_narcissistic_number();

//    for_study();

//    for_instance_knock_desk();
//    nest_loop();
//    multiplication_table();

    break_and_continue_goto();
return 0;

}