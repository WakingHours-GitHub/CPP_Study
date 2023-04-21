//
// Created by NUC on 2023/4/21.
//


/*
    从父类继承过来的成员, 那些属于子类对象.


    使用sizeof进行探究, 我们可以看到,
    不管父类中的权限是什么样的, 子类的都会继承下来


    父类中所有的非静态成员属性都会被子类继承下去, 所以子类的内存空间中有父类的成员.
    父类中的私有属性, 实际上是被编译器给隐藏了, 访问不到, 但是确实被继承了.

 */

class Base{
public:
    int A;
protected:
    int B;
private:
    int C;
};

// 利用开发人员命令提示工具查看对象模型
// 进入文件所在的路径.
// cl /d1 reportSingleClassLayout类名 文件名
