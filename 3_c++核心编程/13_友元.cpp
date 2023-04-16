//
// Created by NUC on 2023/4/14.
//

#include <iostream>
#include <string>
using namespace  std;


/*
    �ڳ�����, ��Щ˽������, Ҳ���������һЩ������������з���, ����Ҫ�õ���Ԫ����.
    ��Ԫ��Ŀ�ľ�����һ�������������������һ�����е�˽�г�Ա.
    �ؼ���: friend
    ��Ԫ������ʵ��:
        ȫ�ֺ�������Ԫ
        ������Ԫ
        ��Ա��������Ԫ.




 */
class Building; // ������. ʹ�ò�����.


// ��Ա��������Ԫ:
class GoodGay2{
public:
    GoodGay2();
    void visit(); // ��Ϊ��Building��������Ԫ, ����visit���Է���Building�е�˽������
    void visit2(); // ����visit2û����Building������Ԫ, ���Բ��ܷ���˽������.


    Building *building;

};


void test03() {
    GoodGay2 g2;
    g2.visit();

}

// ������Ԫ:

class GoodGay{
public:
    void visit(); // ʹ�òιۺ���, ����Building�е�����.


    GoodGay();


    Building *building; // �ڲ�ά��һ��ָ��.


};

void test02(){
    GoodGay gg; // ��ʽ����, ʵ�����ǵ������޲ι��캯��.
    gg.visit();
}


// ȫ�ֺ�������Ԫ:
class Building{
    // goodGayȫ�ֺ�����Building������, ���Է���Building��˽�г�Ա.
    friend void goodGay(Building *building); // ʹ��friend��������.

    // GoodGay���Ǳ���ĺ�����, ���Է��ʱ����е�˽�г�Ա.
    friend class GoodGay;

    // ��Ա��������Ԫ: ���ǽ�ĳ��ĳ�Ա����ʹ��friend��������, ��Ȼ, ������Ҫ����������.
    // ���߱�����, GoodGay2�µ�visit��Ա������Ϊ����ĺ�����, ���Է���˽������.
    friend void GoodGay2::visit();


public:
    string sittingRoom;
    // ���캯��.
//    Building(): sittingRoom("����"), bedRoom("����"){}; // ����ʵ�ֹ��캯��
    Building(); // ����

    Building(string sittingRoom, string bedRoom): sittingRoom(sittingRoom), bedRoom(bedRoom){};

private:
    string bedRoom;
};


// ����Ҳ������������д���ڵĺ���, ��������, ����ʵ��, ֻ��������ͬ. �������ǿ���ʹ��������Ȼ��ʵ�ֺ���.
Building::Building():sittingRoom("����"), bedRoom("����") {};

// ����ʵ��GoodGay�Ĺ��캯��.
GoodGay::GoodGay():building(new Building) {}
void GoodGay::visit() {
    cout << "GoodGay::visit()" << endl;
    cout << this->building->sittingRoom << endl;

    // ����Ϊ��Ԫ, ����Ҳ����ͨ��������еķ���ȥ����˽������.
    cout << this->building->bedRoom << endl;
}

// ʵ��GoodGay2�Ĺ��캯����visit����
GoodGay2::GoodGay2(): building(new Building){};

void GoodGay2::visit() {
    cout << "GoodGay2::visit()" << endl;
    cout << this->building->sittingRoom << endl;

    // ����˽��˯��
    cout << this->building->bedRoom << endl;
}

// ͨ��ȫ�ֺ���, ������Ԫ.
void goodGay(Building *building) {
    cout << building->sittingRoom << endl;

    // ���������, ʹ��friend������Building����ڲ�. �Ϳ��Է��ʵ�˽�е�������.
    cout << building ->bedRoom << endl;// �����Ϳ���goodGay���ʵ��������˽�б�����.

}



int main() {
//    test02();
    test03();
    return 0;
}