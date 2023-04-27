//
// Created by NUC on 2023/4/27.
//

#include <iostream>
#include<string>
using namespace std;


class AbstractDrink{
public:
    // ��ˮ
    virtual void boil() = 0;
    // ����
    virtual void brew() = 0;
    // ���뱭��:
    virtual void pourInCup() = 0;
    // ���븨��������
    virtual void putSomething() = 0;

    // ������Ƶ:
    virtual void makeDrink() {
        boil();
        brew();
        pourInCup();
        putSomething();
    }
};

class Coffee: public AbstractDrink{
public:
    // ��ˮ.
    void boil() override{
        cout <<  "���ũ��ɽȪ" << endl;
    }
    void brew() override{
        cout << "����" << endl;
    }
    void pourInCup() override{
        cout << "�����ȵ��뱭��" << endl;
    }
    void putSomething() override{
        cout << "�����Ǻ�ţ��" << endl;
    }
};

class Tea: public AbstractDrink{
public:
    // ��ˮ.
    void boil() override{
        cout <<  "���ɽȪˮ" << endl;
    }
    void brew() override{
        cout << "����" << endl;
    }
    void pourInCup() override{
        cout << "���赹�뱭��" << endl;
    }
    void putSomething() override{
        cout << "��������" << endl;
    }
};


void doWork(AbstractDrink *drink){
    drink->makeDrink();


    delete drink; // �ͷ�.
}

// ���������
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








