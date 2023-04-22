//
// Created by NUC on 2023/4/22.
//
#include<iostream>
#include<string>

using namespace std;



// 继承中的构造和析构的顺序
/*
    继承中的构造和析构的顺序
    首先先构造父类, 再构造子类.
    析构与构造顺序相反.
 */

class Base{
public:
    Base(){
        cout << "Base()" << endl;
    }

    ~Base(){
        cout << "~Base()" << endl;
    }
};

class Son: public Base{
public:
    Son(){
        cout << "Son()" << endl;
    }

    ~Son(){
        cout << "~Son()" << endl;
    }
};


int main() {

    Son s;
    return 0;
}




