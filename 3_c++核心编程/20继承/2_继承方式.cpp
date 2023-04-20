//
// Created by NUC on 2023/4/20.
//

/*
    class 子类: 继承方式 父类 {};
    继承方式一共有三种: 根据三种权限.
        父类的private, 子类都访问不到
        公共继承: public -> 父类的成员是什么权限, 子类的还是什么权限.
        保护继承: protect -> 父类的成员变量, public, protect都变为子类的protect权限的成员变量
        私有继承: private -> 父类的成员变量, public, protect, 都变成为子类的private权限.

 */

// 继承方式: 公共继承
class Base1{
public:
    int A;
protected:
    int B;
private:
    int C;

};


int main() {




    return 0;
}


