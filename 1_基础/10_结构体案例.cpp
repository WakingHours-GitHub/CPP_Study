//
// Created by NUC on 2023/3/30.
//
#include <iostream>
#include <string>
#include <random>
#include <ctime>

#define LEN(arr) (sizeof arr/ sizeof arr[0])

using namespace std;


// ѧ���Ľṹ��:
struct Student{
    string sName;   // ����.
    int score;  // ����
};








// ��ʦ�Ľṹ��:
struct Teacher{
    string tName;
    struct Student sArray[5];
};


// 
void init_teacher_student(Teacher *t_array, int t_len, int s_len){
    string nameSeed = "ABCDE";
    for (int i = 0; i < t_len; i++){
        t_array[i].tName = (string)"teach_" + nameSeed[i]; // ����ʹ�����ַ�ʽ���г�ʼ��.
//        t_array[i].tName += nameSeed[i];

        for (int j = 0, random_int ; j < s_len; j++){
            random_int = rand() % 61 + 40; // 40~100
            (t_array+i) -> sArray[j].sName = (string)"student_" + to_string(j);
            (t_array + i) -> sArray[j].score = random_int;

        }

    }
}

void print_teacher_student(Teacher *t_array, int t_len, int s_len){
    for (int i = 0; i < t_len; i++) {
        cout << t_array[i].tName << ": " << endl;
        for (int j = 0; j < s_len; j++) {
            cout << "\tstudent name: " <<  (t_array+i) ->sArray[j].sName <<  "; student score: " <<  (t_array+i) -> sArray[j].score << endl;
        }
    }

}


void struct_instance_01() {
    // ����������ʦ������. ͨ���������и�ֵ, �Լ�ѧ����Ϣ
    Teacher tArray[3]; //
    int t_len = LEN(tArray), s_len = LEN(tArray->sArray);

    // ���������:
    srand((unsigned int)time(NULL)); // ��Ҫ����ctimeͷ�ļ�.

    init_teacher_student(tArray, t_len, s_len);
    print_teacher_student(tArray, t_len, s_len);



}



// ���һ��Ӣ�۵Ľṹ��, ������Ա���������䡢�Ա�; �����ṹ������, �������Ӣ��.
// Ȼ��ͨ��һ��ð������, �������������������. ���մ�ӡ.
struct hero{
    string name; // ����
    int age; // ����
    string gender; // �Ա�
};



void struct_instance_02() {


}



int main() {
    struct_instance_01();

    return 0;
}