//
// Created by NUC on 2023/4/20.
//
#include<iostream>
#include<string>

using namespace std;



/*
    继承: 代码复用. 是非常有用的语法.
    语法: class 子类: 继承方式 父类{};
    子类也称为派生类. 父类也称为基类.
    子类中的成员, 包括从基类继承过来的, 以及自己类内部的增加的成员.
    继承过来的表示共性, 自己类内部的表示个性.


 */

// 使用继承实现页面:
class BasePage{
public:
     void header() const {
        cout <<"void BasePage::header() const"<<endl;
    }
    void footer() const {
        cout <<"void BasePage::footer() const"<<endl;
    }
    void left() const {
        cout << "void BasePage::left() const" << endl;
    }
};

class Cpp:public BasePage{ // 继承.
public:
    void content() const {
        cout << "void Cpp::content() const";
    }
};

class Python: public BasePage{
public:
    void content() const {
        cout << "void Python::content() const" << endl;
    }
};
// 不使用继承的技术:
class Java{
    friend ostream& operator<<(ostream& cout, Java& j);

public:
    void header() const {
        cout <<"void Java::header() const"<<endl;
    }
    void footer() const {
        cout <<"void Java::footer() const"<<endl;
    }
    void left() const {
        cout << "void Java::left() const" << endl;
    }
    void content() const {
        cout <<"void Java::content() const" << endl;
    }




};
ostream& operator<<(ostream &cout, Java &j){
    j.footer();
    j.content();
    j.content();
    return cout;
}

ostream& operator<<(ostream &cout, BasePage &basePage){
    basePage.header();
    //
    basePage.footer();

    return cout;
}


void test01(){
    cout << "java 创建视频列出" << endl;
    Java j; // 隐式创建.
    cout << j << endl; // 重载.

    Pytho


}





int main() {
    test01();



    return 0;

}





