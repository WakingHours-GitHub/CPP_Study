//
// Created by NUC on 2023/4/24.
//
#include<iostream>
#include <string>
using namespace std;

/*
    菱形继承概念:
        两个派生类继承同一个基类, 然后又有一个子类继承这两个派生类. 这就是菱形继承.
    问题:
        两个派生类继承了基类的数据, 当最后的子类使用数据时, 就会产生二义性.
        最后的子类继承了上面的派生类, 继承了两份, 实际上我们只需要一份即可.
    使用作用域可以解决问题一,
    问题二需要使用virtual来解决, 这叫做虚继承.
    继承后, (继承了指针) 子类会有一个vbptr: virtual base pointer, 虚基类指针,
    这个指针会指向一个vbtable, 这是一份指针偏移表. 每一个类都有一个这样的表, 里面存储变量的偏移量.
    通过这个指针偏移表, 每个类都能够访问到唯一的那个变量. 只有一份.



 */

// 动物类
class Animal{
public:
    int Age;
};

// 利用虚继承, 解决菱形继承的问题.
// 继承之前, 加上关键字virtual变为虚继承
// Animal类称为虚基类.
// 羊类
class Sheep: virtual public Animal{};

// 驼类
class Tuo: virtual public Animal{};

// 羊驼类
class SheepTuo: public Sheep, public Tuo{};

void test01() {
    SheepTuo st; // tamen
    st.Sheep::Age = 10;
    st.Tuo::Age = 20;

    cout << "st.Sheep::Age=" << st.Sheep::Age << endl; // 10
    cout << "st.Tuo::Age=" << st.Tuo::Age << endl; // 20

    // 当添加完虚继承, 我们就只有一个数据了
    cout << "st.Sheep::Age=" << st.Sheep::Age << endl; // 20
    cout << "st.Tuo::Age=" << st.Tuo::Age << endl; // 20
    cout << st.Age << endl; // 可以访问了. 因为这份数据就只有一份了.



}

int main() {
    test01();

    return 0;
}

