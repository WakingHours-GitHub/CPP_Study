//
// Created by NUC on 2023/4/8.
//

#include <iostream>
#include <string>

using namespace std;

/*
    ��Ͷ���:
    C++����������������: ��װ���̳С���̬.
    C++��Ϊ����Զ���, �������������Ժ���Ϊ.
    ������ͬ���ʵĶ���, ���Գ����һ����.

    ��װ:
        ��װ��C++����������������֮һ.
    ��װ������1:
        �����Ժ���Ϊ��Ϊһ������, ���������е�����.
        �����Ժ���Ϊ����Ȩ�޿���.
    ��װ��Ϊ��:
    �﷨:
        class ����{
            ����Ȩ��: ���� / ��Ϊ
        }

    ��װ������2:
        �������ʱ, ���Խ����Ժ���Ϊ���ڲ�ͬ��Ȩ����, ���Կ���.
        ����Ȩ��������:
        public      ����Ȩ��    �����ⶼ���Է���.
        protected   ����Ȩ��    ���ڿ��Է���, ���ⲻ���Է���. ������Է��ʸ���.
        private     ˽��Ȩ��    ���ڿ��Է���, ���ⲻ���Է���. ���಻���Է��ʸ���ĳ�Ա.

        protected��private��������Ҫ�����ڼ̳���.
        protected������, ������Է���. private������, ���಻���Է���.


    struct��class������:
    ��C++�е�struct��classΨһ�����������Ĭ�ϵķ���Ȩ�޲�ͬ.
    ����:
        structĬ��Ȩ��Ϊ����.
        classĬ��Ȩ��Ϊ˽��.

    ����Ա��������Ϊ˽��:
        ��ʵ�ʵĿ���������, ���Ƕ���ѡ�񽫳�Ա��������Ϊ˽��. privateȨ��.
        �ŵ�1: �����г�Ա��������Ϊ˽��, �����Լ����ƶ�дȨ��. ͨ��set,get����.
        �ŵ�2: ����дȨ��, ���ǿ��Լ�����ݵ���Ч��. (ͨ������(����)���п���)


 */


// ��ϰ����2: ���Բ�Ĺ�ϵ.
// ʹ��r�жϵ��Բ�Ĺ�ϵ.
// ���Բ��͵���.





// ��ϰ����1: �����������. Cube
// ������������������.
// �ֱ�����ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����.
// ��Ա����, ����һ�������Ϳ�����, �����������������Ľ��бȽ�. ʹ��ȫ�ֺ���, ��Ҫ������������.



class Cube{
public: // �����ӿ�
    // ���������:

    int calculateS() const { // const��ʾ���޸��κα���.
        return 2*L*W + 2*W*H + 2*L*H; // ���ر����.
    }
    int calculateV() const {
        return L*W*H;

    }
    bool comparison(Cube &other){
        return (bool)(this -> L == other.getL() && this->W == other.getW() && this->H==other.getH());
    }

    int getL() const {
        return L;
    }

    void setL(int l) {
        L = l;
    }

    int getW() const {
        return W;
    }

    void setW(int w) {
        W = w;
    }

    int getH() const{
        return H;
    }

    void setH(int h) {
        H = h;
    }



private:
    int L; // ��
    int W; // ��
    int H; // ��

};
// ����ȫ�ֺ����ж������������Ƿ����.
bool isSame(Cube &c1, Cube &c2){
    return (c1.getL() == c2.getL() && c1.getH() == c2.getH() && c1.getW() == c2.getW())? true: false;
}

void test_cube(){
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);
    cout << c1.calculateS() << endl;
    cout << c1.calculateV() << endl;

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(10);
    cout << c2.calculateS() << endl;
    cout << c2.calculateV() << endl;

    cout << isSame(c1, c2) << endl; // 1���.

    // ��Ա�����ж�:
    cout << c1.comparison(c2) << endl; // 1 ���.

}


// ��Ա��������Ϊ˽��:
// 1. �Լ����ƶ�дȨ��.
class Person_1{
private: // ˽��, �����ⲿ.
    string name;
    int age;
    int money;
    string lover;

public:
    // ͨ�����ù����ӿ�, ���ڲ��ı����������úͷ���.
    void setName(string name){
        this -> name = name;
    }
    string getName(){
        return this->name;
    }

    // ֻ��.
    int getMoney(){
        this->money = 0;
        return this->money;

    }

    // ֻд:
    void setLover(string lover){
        this -> lover = lover;
    }

    // ͨ������������ǵ��߼�:
    void setAge(int age){
        // �����ж�: ����������Ч��.
        if (age >= 0 && age <= 150){
            this -> age = age;
        }else{
            this->age=0;
            cout << "����������䷶Χ�����ϱ�׼" << endl;
        }
    }
    int getAge(){
        return this->age;
    }




};

void test06(){
    Person_1 p;
    p.setName("����");
    cout << p.getName() << endl;

    // ��������:
//    p.money ���ʲ���
    cout << p.getMoney() << endl;

    p.setLover("����2");
//    p.loaver ����.

    p.setAge(1000); // ��������
    p.setAge(10);
    cout << p.getAge() << endl;


}





//     struct��class������:
class C1{
    int m_A; // Ĭ��Ȩ����˽��Ȩ��. private
};
struct C2{
    int m_A; // Ĭ��Ȩ���ǹ���Ȩ��. public
};
void test04() {
    C1 c1;
//    c1.m_A; // ���ʲ���.
    C2 c2;
    c2.m_A; // �ܷ��ʵ�.
}





// ����Ȩ��: ����. public, protected, private.
class Person{
public: // ����Ȩ��:
    string name;
protected: // ����Ȩ��
    string car; // ����.
private: // ˽��Ȩ��.
    string password;

public:
    void func(){
        // �����ڷ�������.
        name = "����";
        car = "������";
        password = "123456";
    }

private:
    void func2(){
        // �����ڷ�������.
        name = "��";
        car = "�ϻ�";
        password = "1236";
    }

};

void test03(){
    Person p1; // ʵ�����������.

    // ���������.
    p1.name = "��˹";
//    p1.car ����Ȩ��. ���ʲ���, ����������������������
//    p1.password ˽��Ȩ��, ���ʲ���.

    p1.func();
//    p1.func2(); private�ķ���, Ҳ�����Է���.

}




// ���һ��Բ��, ��Բ���ܳ�:
// �ܳ���ʽ: 2*pi*r.
const double PI = 3.14;

class Circle { // Բ��.
    // ����Ȩ��
public: // ����Ȩ��.
    // ����: �ñ�����ʾ.
    int m_r;

    // ��Ϊ: ʹ��һ������������Ϊ.
    double calculateZC() {
        return 2 * PI * m_r;
    }


};

void test01() {
    // ͨ��Բ�� ���������Բ. ������������, �ͽ�������.
    Circle c1; // ʵ����, ͨ��һ���� ����һ������Ĺ��� -> ʵ����.
    // ����������Խ��и�ֵ: ʹ��.��Ա������.
    c1.m_r = 10;
    // ͬ��, ��Ϊ(����)Ҳͨ��.����
    cout << "�ܳ�: " << c1.calculateZC() << endl;


}

// ��ϰ:
// ���һ��ѧ����: ������������ѧ��, ����ʾ����:
class Student {
public: // ����Ȩ��.
    // ����/��Ϊ ͳһ��Ϊ��Ա.
    // ����: ��Ա����, ��Ա����
    // ��Ϊ: ��Ա����, ��Ա����.

    // ����:
    string name;
    string num_id;

    // setting����:
    // ��һ�ָ�ֵ��ʽ, ͨ����Ϊ�������Ը�ֵ.
    void setName(string name) {
        this->name = name;
    }

    void setNumid(string num_id) {
        this->num_id = num_id;
    }


    void show_info() {
        cout << "name: " << name << ", num_id: " << num_id << endl;
    }
};

void test02() {
    Student s;
    s.name = "����";
    s.num_id = "1234567689";
    s.show_info(); // name: ����, num_id: 1234567689

}


int main() {
//    test01();
//    test02();
//    test03();
//    test06();
    test_cube();

    return 0;
}








