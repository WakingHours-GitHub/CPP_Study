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

class Building{
    // goodGay全局函数是Building好朋友, 可以访问Building中私有成员.
    friend void goodGay(Building *building);

public:
    string sittingRoom;
    // 构造函数.
    Building(): sittingRoom("客厅"), bedRoom("卧室"){};

    Building(string sittingRoom, string bedRoom): sittingRoom(sittingRoom), bedRoom(bedRoom){};







private:
    string bedRoom;
};


// 通过全局函数, 进行友元.
void goodGay(Building *building) {
    cout << building->sittingRoom << endl;
    cout << building ->bedRoom << endl;// 这样就可以goodGay访问到类里面的私有变量了.

}



int main() {


    return 0;
}