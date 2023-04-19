//
// Created by NUC on 2023/4/19.
//


#include <string>
#include <iostream>

using namespace std;

/*
    关系运算符重载.
    重载关系运算符, 可以让自定义类型对象进行对比操作.

    重载关系运算符.

 */

class Person{
public:
    string name;
    int age;
    Person(string name, int age):name(name), age(age){};

    // 重载关系运算符操作:
    bool operator==(Person &p){
        if(this->name == p.name && this->age == p.age)
            return true;
        else
            return false;
    }

    bool operator!=(Person &p){
        if(this->name != p.name || this->age != p.age)
            return true;
        else
            return false;
    }
};

void test01(){
    Person p1("lipu", 10);
    Person p2("lipu", 10);

    cout << (p1 == p2) << endl; // 1
}



int main(){
    test01();






    return 0;



}








