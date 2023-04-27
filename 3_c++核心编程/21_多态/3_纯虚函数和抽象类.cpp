//
// Created by NUC on 2023/4/27.
//

#include<iostream>
#include <string>
using namespace std;


/*
    �ڶ�̬��, ͨ�������е��麯����ʵ���Ǻ��������, ��Ҫ���ǵ���������д������.
    ��˿��Խ��麯����Ϊ���麯��

    ���麯���﷨: virtual ����ֵ���� ������(�����б�) = 0;
    ���������˴��麯��, �����Ҳ����Ϊ������.

    �������ص�:
        1. �������޷�ʵ��������
        2. ���������д�������еĴ��麯��, ����Ҳ���ڳ�����.



*/

class Base{
public:
    // ���麯��
    // ֻҪ��һ�����麯��, ��������Ϊ������
    virtual void func() = 0; // ���麯��
};

class Son: public Base{ // �̳�.
    // ���������д���麯��, �������д����Ȼ�ǳ�����, �޷�ʵ��������.
    virtual void func(){
        cout << "void func() override" << endl;

    }
};


void test01() {
//    Base base; // ���������޷�ʵ���������
//    new Base(); // ���������޷�ʵ���������
    Son s;
    Base * base = new Son(); // ����ָ��, ָ���������.
    base->func(); //





}

int main() {
    test01();

    return 0;
}





