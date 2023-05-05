//
// Created by NUC on 2023/5/4.
//
#include<iostream>
#include<string>


/*
    ��̬ʹ��ʱ, ������������Կ��ٵ�����, ��ô����ָ�����ͷ�ʱ�޷����õ��������������.
    �����ʽ: �������е�����������Ϊ����������, ���ߴ��鹹����.

    �������ʹ����鹹����:
        ���Խ������ָ���ͷ��������
        ����Ҫ�о���ĺ���ʵ��.
    �������ʹ����鹹����:
        ����Ǵ�������, �������ڳ�����, �޷�ʵ��������.





 */

class Animal{
public:
    Animal(){
        std::cout << " Animal()" << std::endl;
    }

    // �������������Խ�� ����ָ���ͷ��������ʱ���Ͻ�������.
//    virtual ~Animal(){
//        std::cout << "~Animal()" << std::endl;
//    }

    // ������������.
    virtual ~Animal() = 0; // ����
    // ���˴����鹹֮��, ��ô�����Ҳ���ڳ������޷�ʵ��������

    virtual void speak() = 0; // ���麯��
};

// Animal�Ĵ����鹹��ʵ��, ���������Animal����������.
Animal:: ~Animal(){
    std::cout << "Animal:: ~Animal()" << std::endl;
}



class Cat: public Animal{
public:

    virtual void speak(){ // ����ʵ�ָ���Ĵ��麯��
        std::cout << *name <<": Сè��˵��" << std::endl;

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

    // ����ָ��������ʱ, ������������е���������, ������������ж���������, �򲻻ᱻ�ͷ�.
    delete cat;


}


int main() {
    test01();


    return 0;
}