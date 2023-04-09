//
// Created by NUC on 2023/4/8.
//

#include <iostream>
#include <string>

using namespace std;

/*
    类和对象:
    C++面向对象的三大特性: 封装、继承、多态.
    C++认为万物皆对象, 对象上有其属性和行为.
    具有相同性质的对象, 可以抽象成一个类.

    封装:
        封装是C++面向对象的三大特性之一.
    封装的意义1:
        将属性和行为作为一个整体, 表现生活中的事物.
        将属性和行为加以权限控制.
    封装成为类:
    语法:
        class 类名{
            访问权限: 属性 / 行为
        }

    封装的意义2:
        类在设计时, 可以将属性和行为放在不同的权限下, 加以控制.
        访问权限有三种:
        public      公共权限    类内外都可以访问.
        protected   保护权限    类内可以访问, 类外不可以访问. 子类可以访问父类.
        private     私有权限    类内可以访问, 类外不可以访问. 子类不可以访问父类的成员.

        protected和private的区别主要体现在继承上.
        protected的属性, 子类可以访问. private的属性, 子类不可以访问.


    struct和class的区别:
    在C++中的struct和class唯一的区别就在于默认的访问权限不同.
    区别:
        struct默认权限为共有.
        class默认权限为私有.

    将成员属性设置为私有:
        在实际的开发过程中, 我们都会选择将成员属性设置为私有. private权限.
        优点1: 将所有成员属性设置为私有, 可以自己控制读写权限. 通过set,get方法.
        优点2: 对于写权限, 我们可以检测数据的有效性. (通过函数(代码)进行控制)


 */


// 练习案例2: 点和圆的关系.
// 使用r判断点和圆的关系.
// 设计圆类和点类.





// 练习案例1: 设计立方体类. Cube
// 求出立方体的面积和体积.
// 分别利用全局函数和成员函数判断两个立方体是否相等.
// 成员函数, 传递一个函数就可以了, 就是这个本身和其他的进行比较. 使用全局函数, 需要传递两个函数.



class Cube{
public: // 公共接口
    // 立方体面积:

    int calculateS() const { // const表示不修改任何变量.
        return 2*L*W + 2*W*H + 2*L*H; // 返回表面积.
    }
    int calculateV() const {
        return L*W*H;

    }
    bool comparison(Cube &other){
        return (bool)(this -> L == other.getL() && this->W == other.getW() && this->H==other.getH());
    }

    int getL() const {
        return L;
    }

    void setL(int l) {
        L = l;
    }

    int getW() const {
        return W;
    }

    void setW(int w) {
        W = w;
    }

    int getH() const{
        return H;
    }

    void setH(int h) {
        H = h;
    }



private:
    int L; // 长
    int W; // 宽
    int H; // 高

};
// 利用全局函数判断两个立方体是否相等.
bool isSame(Cube &c1, Cube &c2){
    return (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())? true: false;
}

void test_cube(){
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);
    cout << c1.calculateS() << endl;
    cout << c1.calculateV() << endl;

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);
    cout << c2.calculateS() << endl;
    cout << c2.calculateV() << endl;

    cout << isSame(c1, c2) << endl; // 1相等.

    // 成员函数判断:
    cout << c1.comparison(c2) << endl; // 1 相等.

}


// 成员属性设置为私有:
// 1. 自己控制读写权限.
class Person_1{
private: // 私有, 屏蔽外部.
    string name;
    int age;
    int money;
    string lover;

public:
    // 通过设置公共接口, 对内部的变量进行设置和访问.
    void setName(string name){
        this -> name = name;
    }
    string getName(){
        return this->name;
    }

    // 只读.
    int getMoney(){
        this->money = 0;
        return this->money;

    }

    // 只写:
    void setLover(string lover){
        this -> lover = lover;
    }

    // 通过代码控制我们的逻辑:
    void setAge(int age){
        // 进行判断: 检验数据有效性.
        if (age >= 0 && age <= 150){
            this -> age = age;
        }else{
            this->age=0;
            cout << "您输入的年龄范围不符合标准" << endl;
        }
    }
    int getAge(){
        return this->age;
    }




};

void test06(){
    Person_1 p;
    p.setName("离谱");
    cout << p.getName() << endl;

    // 对于年龄:
//    p.money 访问不到
    cout << p.getMoney() << endl;

    p.setLover("离谱2");
//    p.loaver 报错.

    p.setAge(1000); // 错误数据
    p.setAge(10);
    cout << p.getAge() << endl;


}





//     struct和class的区别:
class C1{
    int m_A; // 默认权限是私有权限. private
};
struct C2{
    int m_A; // 默认权限是公共权限. public
};
void test04() {
    C1 c1;
//    c1.m_A; // 访问不到.
    C2 c2;
    c2.m_A; // 能访问到.
}





// 访问权限: 三种. public, protected, private.
class Person{
public: // 公共权限:
    string name;
protected: // 保护权限
    string car; // 汽车.
private: // 私有权限.
    string password;

public:
    void func(){
        // 在类内访问属性.
        name = "张三";
        car = "拖拉机";
        password = "123456";
    }

private:
    void func2(){
        // 在类内访问属性.
        name = "张";
        car = "拖机";
        password = "1236";
    }

};

void test03(){
    Person p1; // 实例化具体对象.

    // 在类外访问.
    p1.name = "里斯";
//    p1.car 保护权限. 访问不到, 在类外根本看不到这个属性
//    p1.password 私有权限, 访问不到.

    p1.func();
//    p1.func2(); private的方法, 也不可以访问.

}




// 设计一个圆类, 求圆的周长:
// 周长公式: 2*pi*r.
const double PI = 3.14;

class Circle { // 圆类.
    // 访问权限
public: // 公共权限.
    // 属性: 用变量表示.
    int m_r;

    // 行为: 使用一个函数代表行为.
    double calculateZC() {
        return 2 * PI * m_r;
    }


};

void test01() {
    // 通过圆类 创建具体的圆. 这个具体的事物, 就叫做对象.
    Circle c1; // 实例化, 通过一个类 创建一个对象的过程 -> 实例化.
    // 给对象的属性进行赋值: 使用.成员操作符.
    c1.m_r = 10;
    // 同样, 行为(函数)也通过.调用
    cout << "周长: " << c1.calculateZC() << endl;


}

// 练习:
// 设计一个学生类: 属性是姓名和学号, 和显示函数:
class Student {
public: // 公共权限.
    // 属性/行为 统一称为成员.
    // 属性: 成员属性, 成员变量
    // 行为: 成员函数, 成员方法.

    // 属性:
    string name;
    string num_id;

    // setting方法:
    // 另一种赋值方式, 通过行为来给属性赋值.
    void setName(string name) {
        this->name = name;
    }

    void setNumid(string num_id) {
        this->num_id = num_id;
    }


    void show_info() {
        cout << "name: " << name << ", num_id: " << num_id << endl;
    }
};

void test02() {
    Student s;
    s.name = "张三";
    s.num_id = "1234567689";
    s.show_info(); // name: 张三, num_id: 1234567689

}


int main() {
//    test01();
//    test02();
//    test03();
//    test06();
    test_cube();

    return 0;
}








