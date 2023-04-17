//
// Created by NUC on 2023/4/17.
//

#include <iostream>
#include <string>
using namespace std;



/*
    左移运算符重载, 可以输出自定义的数据类型


    重载左移运算符, 并且使用友元技术. 可以实现输出自定义的数据类型.





 */

class Person{

    friend ostream& operator<<(ostream &cout, Person &p);
public:
    Person():A(0), B(0){};
    Person(int a, int b):A(a), B(b){};

    // 利用成员函数重载, 左移运算符
//    void operator<<(cout){ // p.operator<<(cout) <==> p<<cout., 这是显然不对的.
//    }
    // 因此, 我们不会利用成员函数重载<<运算符, 因为无法实现cout在左侧.


private:
    int A;
    int B;
};

// 只能利用全局函数重载左移运算符.
//void operator<<(cout, p)  // 本质: operator<<(cout, p) <==> cout << p
// 那么cout是什么数据类型. 可以查看cout的定义, 是ostream(输出流对象) cout: 标准输出流对象
ostream& operator<<(ostream &cout, Person &p){
    // 这里的cout只是一个变量名, 你可以改变成为任何都可以.
    // 然后里面直接打印你想要输出的东西即可.
    cout << p.A << " " << p.B; // 这里要求, 必须是p的属性是public才能访问到, 如果是private, 则需要使用友元, 或者提供访问接口.
    // 再Person类中声明友元, 这样再这个函数中就能够访问私有属性了.
    // 牛逼,一环套一环.
    return cout; // 返回这个对象
}

void test01(){
    Person p(10, 20);

//    cout << p; // 没有与这些操作数类型的<<运算符. // 需要重载<<运算符

    // 重载完<<符号后, 后面加上<<endl;又报错了. 这其实是链式编程的思想.
    // 所以, 如果<<返回的还是cout, 那么此时就又可以调用<<了. 即链式编程.
    cout << p << endl; //
    // cout << p; <==> cout.operator<<(p) 但是我们没办法在cout中重载, 所以使用全局函数
    // ==> cout = *(osteam<<& (cout, p)), 所以返回的是在里面创建的cout对象.
    // 然后这个cout对象再<<endl; 返回cout实现链式编程



}
int main() {

    test01();






    return 0;
}