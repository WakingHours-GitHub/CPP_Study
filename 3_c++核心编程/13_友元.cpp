//
// Created by NUC on 2023/4/14.
//

#include <iostream>
#include <string>
using namespace  std;


/*
    在程序里, 有些私有属性, 也想让类外的一些函数或者类进行访问, 就需要用到友元技术.
    友元的目的就是让一个函数或者类访问另外一个类中的私有成员.
    关键字: friend
    友元的三种实现:
        全局函数做友元
        类做友元
        成员函数做友元.




 */
class Building; // 声明类. 使用不报错.


// 成员函数做友元:
class GoodGay2{
public:
    GoodGay2();
    void visit(); // 因为在Building声明了友元, 所以visit可以访问Building中的私有属性
    void visit2(); // 但是visit2没有在Building声明友元, 所以不能访问私有属性.


    Building *building;

};


void test03() {
    GoodGay2 g2;
    g2.visit();

}

// 类做友元:

class GoodGay{
public:
    void visit(); // 使用参观函数, 访问Building中的属性.


    GoodGay();


    Building *building; // 内部维护一个指针.


};

void test02(){
    GoodGay gg; // 隐式构造, 实际上是调用了无参构造函数.
    gg.visit();
}


// 全局函数做友元:
class Building{
    // goodGay全局函数是Building好朋友, 可以访问Building中私有成员.
    friend void goodGay(Building *building); // 使用friend进行声明.

    // GoodGay类是本类的好朋友, 可以访问本类中的私有成员.
    friend class GoodGay;

    // 成员函数做友元: 就是将某类的成员函数使用friend进行修饰, 当然, 我们需要声明作用域.
    // 告诉编译器, GoodGay2下的visit成员函数作为本类的好朋友, 可以访问私有属性.
    friend void GoodGay2::visit();


public:
    string sittingRoom;
    // 构造函数.
//    Building(): sittingRoom("客厅"), bedRoom("卧室"){}; // 类内实现构造函数
    Building(); // 声明

    Building(string sittingRoom, string bedRoom): sittingRoom(sittingRoom), bedRoom(bedRoom){};

private:
    string bedRoom;
};


// 我们也可以在类外书写类内的函数, 类内声明, 类外实现, 只是作用域不同. 所以我们可以使用作用域然后实现函数.
Building::Building():sittingRoom("客厅"), bedRoom("卧室") {};

// 类外实现GoodGay的构造函数.
GoodGay::GoodGay():building(new Building) {}
void GoodGay::visit() {
    cout << "GoodGay::visit()" << endl;
    cout << this->building->sittingRoom << endl;

    // 类作为友元, 我们也可以通过这个类中的方法去访问私有属性.
    cout << this->building->bedRoom << endl;
}

// 实现GoodGay2的构造函数和visit函数
GoodGay2::GoodGay2(): building(new Building){};

void GoodGay2::visit() {
    cout << "GoodGay2::visit()" << endl;
    cout << this->building->sittingRoom << endl;

    // 访问私有睡醒
    cout << this->building->bedRoom << endl;
}

// 通过全局函数, 进行友元.
void goodGay(Building *building) {
    cout << building->sittingRoom << endl;

    // 将这个函数, 使用friend声明在Building类的内部. 就可以访问到私有的内容了.
    cout << building ->bedRoom << endl;// 这样就可以goodGay访问到类里面的私有变量了.

}



int main() {
//    test02();
    test03();
    return 0;
}