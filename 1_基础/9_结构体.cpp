//
// Created by NUC on 2023/3/27.
//
#include <iostream>
#include <string> // string.
#define ARRAY_SIZE(arr) (sizeof arr/ sizeof arr[0])
using namespace std;

/*
    �ṹ��: �ṹ�������û��Զ������������, �����û��洢��ͬ����������.
    �ṹ�嶨���ʹ��:
        struct �ṹ���� {
            �ṹ���Ա�б�
        };
    ͨ���ṹ�崴������:
        struct �ṹ���� ������;
        struct �ṹ���� ������ = {��Ա1ֵ, ...}
        ����ṹ��ʱ˳�㴴������.

    �ṹ������: ���Զ���Ľṹ��ŵ������з���ά��.
        struct �ṹ���� ������[����] = = {{}, ...}

    �ṹ��ָ��: ͨ��ָ����ʽṹ���еĳ�Ա
        ����->��, ����ͨ���ṹ��ָ����ʽṹ������.

    �ṹ��Ƕ�׽ṹ��: �ṹ���еĳ�Ա��������һ���ṹ��


    �ṹ����Ϊ��������: ���ṹ����Ϊ�������ݸ�����.
        �ṹ����Ϊ�����뺯���д���.
        ���ݷ�ʽ:
            ֵ����
            ��ַ����
        ���ṹ�崫�뺯������ʱ, ͨ��ʹ�õ�ַ����, �����ٶȽϿ�.
        ���ʹ��ֵ������ᴴ��һ���ṹ��, Ȼ�󽫽ṹ���еĳ�Աһһ��ֵ.
        �����Ҫ�޸��������е�����, ��ʹ�õ�ַ����, ��������޸�, ��ʹ��ֵ����.

    �ṹ�嵱�е�constʹ�ó���:
        ʹ��const����ֹ�������










 */




// ��ʾ:
// ����ѧ����������. ���������ѧ��.
struct Student{
    // ��Ա�б� -> ���������������͵ļ���.
    string name; // ����
    int age;     // ����
    int score;  // �÷�.
//    void print_str = print_struct(this);
}s3; // �����ṹ�������ʱ��ֱ�Ӵ����ṹ�����.

// �ṹ��Ƕ�׽ṹ��:
struct teacher{
    int id; // ��ʦ���
    string name; // ����
    int age; // ����
    struct Student stu; // ������ǰ��, Ȼ������.
};



void print_struct(void * str) {
    str = (Student *) str;

}

void definite_struct () {
    // �ڴ����ṹ�������ʱ��, struct��c++�п���ʡ��.
    // ͨ��ѧ�����ʹ��������ѧ��:
    Student s1; // �������� ������
    // ͨ����Ա�����'.'����������.

    s1.name = "����";
    s1.age = 19;
    s1.score = 100;
    cout << "name: " << s1.name << " age: " << s1.age << " score: " << s1.score << endl;

    // �����ʱ��ֱ��ָ����Ա, ����˳��Ϊ��Ա���и�ֵ.
    struct Student s2 = {"lipu", 12, 98};
    cout << "name: " << s2.name << " age: " << s2.age << " score: " << s2.score << endl;




}


void struct_array(){
    // ʹ�������Ľṹ��.
    Student stu_arr[] = { // struct�ؼ��ֿ���ʡ��
            {"����", 19, 100},
            {"����", 29, 90},
            {"����", 39, 99},
    };
    // ����ͨ���������ṹ�������е�Ԫ�ظ�ֵ
    stu_arr[2].name = "����"; // ͬ������ͨ������ȡ���������Ԫ��.

    // �����ṹ������
    for (int i = 0; i < ARRAY_SIZE(stu_arr); i++) {
        cout << "name: " << stu_arr[i].name << " ����: " << stu_arr[i].age << " ����: " << stu_arr[i].score << endl;
    }

}


void struct_point() {
    // creat student struct variable
    struct Student stu = {"����", 18, 100};

    // ͨ��ָ��ָ��ṹ�����.
    Student *p = &stu; // ���ض�Ӧ���͵�ָ��, ������Ҫ��ͬ

//    stu.name
    // ͨ��ָ��ָ��ṹ�����, ͨ��->������.
    cout << "name: " << p->name << " ����: " << p->age << " ����: " << p->score << endl;
}

void struct_struct() {
    struct teacher t;
    t.id = 123;
    t.name = "����";
    t.age = 30;
    t.stu.name = "����";
    t.stu.age = 12;
    t.stu.score  = 90;


    cout << "��ʦ����: " << t.name << endl;
    cout << "����ѧ��������: " << t.stu.name << endl;



}


// ֵ����:
void print_Student_1(struct Student s) {
    cout << "print student 1" << endl;
    s.age = 100; // ����ı�ԭ������ֵ. ֻ�Ǹı䵱ǰ�ֲ���������ֵ. ��Ϊ��ֵ����.
    cout << s.name <<" " << s.age << " " <<s.score << endl;


}

// ��ַ����: ����һ��ʹ�õ�ַ����. ����Ч�ʸ�. ���ḳֵ�µĸ�������.
// ������ǲ�ϣ���ٺ����иı�����ڴ�ռ������, ��������Ҫʹ��const��������.
void print_Student_2(const struct Student *s_p) { // ��ͬ�� struct Student const *s_sp ��������*s_p
    // const���ε���*s_p��ʵҲ���Ǳ���, �����ǲ�����ı���ָ���ڴ���е�����. ���ֻ��. ����ָ��ָ����Ըı�.
    cout << "print student 2" << endl;
    // ��ʱ�޸����ı�ԭʼ�ı���, ��Ϊ�ǵ�ַ����.

//    s_p -> age = 200; // ������ǲ�ϣ��s_p��ָ���Ԫ�ر��޸�, ��ô����ϣ��ʹ��const��������.
    // const *p: ��
    cout << s_p -> name << " " << s_p -> age << " " << s_p->score << endl;


}

void struct_as_param() {
    // ����һ���ṹ�����:
    struct Student s = {
            "����", 20, 86,
    };
    cout << s.name << " " << s.age << " " << s.score << endl;

    print_Student_1(s);
    cout << s.name << " " << s.age << " " << s.score << endl; // û�иı�.

    print_Student_2(&s);
    cout << s.name << " " << s.age << " " << s.score << endl;



}


void const_struct() {
    Student s = {"����", 15, 70};
    print_Student_2(&s); // ��ӡ����;



}





int main() {
//    definite_struct();
//    struct_array();
//    struct_point();
//    struct_struct();

//    struct_as_param();
    const_struct();


    return 0;


}