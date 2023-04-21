//
// Created by NUC on 2023/4/20.
//

#include <iostream>
#include <string>
using namespace std;

/*
    class 子类: 继承方式 父类 {};
    继承方式一共有三种: 根据三种权限.
        父类的private, 子类都访问不到
        公共继承: public  -> 父类的成员是什么权限, 子类的还是什么权限.
        保护继承: protect -> 父类的成员变量, public, protect都变为子类的protect权限的成员变量
        私有继承: private -> 父类的成员变量, public, protect, 都变成为子类的private权限.





 */

// 继承方式: 公共继承
class Base{
public: // 公共权限, 类内类外都可以访问

    int A;

    Base():A(0), B(0), C(0){}

protected: // 保护旋前, 类内可以访问, 类外不可以访问, 继承能够访问.
    int B;
private: // 私有权限, 类内可以访问, 类外不能访问, 继承也不能访问
    int C;
};

// 公共继承:
class PublicSon: public Base{ // 继承的语法.
public:
    void func(){
        cout << this->A << endl; // public, 可以访问得到. 这个属性还是public
        cout << this->B << endl; // protected, 子类可以访问到, 这个属性在子类中还是protected
//        cout << this->C << endl; // private权限, 访问不到.

    }
};

void testPublic(){
    PublicSon ps;
    ps.A;
//    ps.B;
    // 只能访问到A
}


// 保护继承:
class ProtectedSon: protected Base{
public:
    void func(){
        cout << this->A << endl; // public,可以访问得到, 这个属性在子类变为protected
        cout << this->B << endl; // 同理
//        cout << this->C << endl; // 访问不到
    }
};

void testProtected(){
    ProtectedSon ps;
    // AB都不可以访问到.
    ps.func();

}

// 私有继承:
class PrivateSon: private Base{
public:
    void func(){
        cout << this->A << endl;
        cout << this->B << endl;
//        cout << this->C << endl; //
    // A,B都可以访问. A,B,都在子类中都便成为private,
    }
};
class PrivateSonSon: public PrivateSon{
public:
    void func(){
        // 什么都访问不到, 因为在子类中, 已经变成private了.
    }
};

int main() {




    return 0;
}


