//
// Created by NUC on 2023/4/17.
//
/*

    重载++运算符,




 */

#include <iostream>
#include <string>
using namespace std;

class MyNum{
    friend ostream& operator<<(ostream& cout, MyNum& myNum);
public:
    MyNum(): num(0){};
    MyNum(int num): num(num){};

    // 重载前置++运算符, 先++再返回表达式
    MyNum& operator++(){
        this->num++;
        return *this;
    }

    // 重载后置++运算符, 先返回表达式, 然后再++
    // 需要再参数列表中添加一个(int)然后进行重载. 这里int是占位符. 编译器就会认为这是后置运算符的重载.
    // 必须是int用于区分前置和后置递增, 其他的,double都不好使.
    MyNum operator++(int){
        // 后置递增, 先返回表达式, 再递增.
        MyNum temp(*this); // MyNum temp = Person(*this); 调用拷贝构造函数(将所有的属性赋值过去)

        this->num++; // 自己递增
        return temp; // 这里就是返回一个对象了
    }







private:
    int num;

};

// 重载MyNum的<<操作符.
ostream& operator<<(ostream& cout, MyNum& myNum){
    cout << myNum.num;

    return cout;
}


void test(){
    MyNum myNum(0);
    cout << ++(++myNum) << endl;
    cout << myNum << endl;

}


void test_build_in_type(){
    int a = 0;
    cout << a++ << endl;
    cout << a << endl;

    cout << ++a << endl;
    cout << a << endl;


}

int main() {
//    test_build_in_type();
    test();

    return 0;
}



