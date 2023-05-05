//
// Created by NUC on 2023/5/4.
//
#include<iostream>
#include<string>


/*
    多态使用时, 如果子类有属性开辟到推区, 那么父类指针在释放时无法调用到子类的析构函数.
    解决方式: 将父类中的析构函数改为虚析构函数, 或者纯虚构函数.

    虚析构和纯虚虚构共性:
        可以解决父类指针释放子类对象
        都需要有具体的函数实现.
    虚析构和纯虚虚构区别:
        如果是纯虚析构, 该类属于抽象类, 无法实例化对象.





 */

class Animal{
public:
    Animal(){
        std::cout << " Animal()" << std::endl;
    }

    // 利用虚析构可以解决 父类指针释放子类对象时不赶紧的问题.
//    virtual ~Animal(){
//        std::cout << "~Animal()" << std::endl;
//    }

    // 纯虚析构函数.
    virtual ~Animal() = 0; // 声明
    // 有了纯虚虚构之后, 那么这个类也属于抽象类无法实例化对象

    virtual void speak() = 0; // 纯虚函数
};

// Animal的纯虚虚构的实现, 否则调不到Animal的析构函数.
Animal:: ~Animal(){
    std::cout << "Animal:: ~Animal()" << std::endl;
}



class Cat: public Animal{
public:

    virtual void speak(){ // 子类实现父类的纯虚函数
        std::cout << *name <<": 小猫在说话" << std::endl;

    }


    Cat(std::string name){
        std::cout << "Cat(std::string name)" << std::endl;
        this->name = new std::string(name);
    }

    ~Cat(){
        std::cout << "~Cat()" << std::endl;
        if (this->name) {
            delete this->name;
            this->name = NULL;
        }
    }

    std::string *name;
};


void test01() {
    Animal *cat = new Cat("tom");
    cat->speak();

    // 父类指针在析构时, 不会调用子类中的析构函数, 导致子类如果有堆区的数据, 则不会被释放.
    delete cat;


}


int main() {
    test01();


    return 0;
}