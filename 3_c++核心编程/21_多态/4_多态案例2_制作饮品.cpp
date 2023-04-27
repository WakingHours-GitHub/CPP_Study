//
// Created by NUC on 2023/4/27.
//

#include <iostream>
#include<string>
using namespace std;


class AbstractDrink{
public:
    // 煮水
    virtual void boil() = 0;
    // 冲泡
    virtual void brew() = 0;
    // 倒入杯中:
    virtual void pourInCup() = 0;
    // 加入辅助的佐料
    virtual void putSomething() = 0;

    // 制作音频:
    virtual void makeDrink() {
        boil();
        brew();
        pourInCup();
        putSomething();
    }
};

class Coffee: public AbstractDrink{
public:
    // 煮水.
    void boil() override{
        cout <<  "煮沸农夫山泉" << endl;
    }
    void brew() override{
        cout << "冲泡" << endl;
    }
    void pourInCup() override{
        cout << "将咖啡倒入杯中" << endl;
    }
    void putSomething() override{
        cout << "加入糖和牛奶" << endl;
    }
};

class Tea: public AbstractDrink{
public:
    // 煮水.
    void boil() override{
        cout <<  "煮沸山泉水" << endl;
    }
    void brew() override{
        cout << "冲泡" << endl;
    }
    void pourInCup() override{
        cout << "将茶倒入杯中" << endl;
    }
    void putSomething() override{
        cout << "加入柠檬" << endl;
    }
};


void doWork(AbstractDrink *drink){
    drink->makeDrink();


    delete drink; // 释放.
}

// 运算符重载
string operator*(string s, int num){
    string ch(s);
    for(int i=1; i < num; i++){
        s.append(ch);
    }
    return s;

}
void test01() {
    doWork(new Coffee);
    cout << ((string)"="*10) << endl;
    doWork(new Tea);

}


int main() {
    test01();

    return 0;
}








