//
// Created by NUC on 2023/3/30.
//
#include <iostream>
#include <string>
#define LEN(arr) (sizeof arr/ sizeof arr[0])

using namespace std;


// 学生的结构体:
struct Student{
    string sName;   // 姓名.
    int score;  // 分数
};








// 老师的结构体:
struct Teacher{
    string tName;
    struct Student sArray[5];
};


void init_teacher_student(Teacher *t_array, int t_len, int s_len){
    for (int i = 0; i < t_len; i++){
        t_array -> tName = "teach_" + to_string(i);
        for (int j = 0; j < s_len; j++){
            t_array ->sArray[i].sName = "student_" + to_string(j);
            t_array -> sArray[i].score = 100+j;

        }

    }
}

void print_teacher_student(Teacher *t_array, int t_len, int s_len){
    for (int i = 0; i < t_len; i++) {
        cout << t_array->tName << ": " << endl;
        for (int j = 0; j < s_len; j++) {
            cout << "student name: " << t_array->sArray[i].sName <<  "student score: " << t_array->sArray[i].score << endl;
        }
    }

}


void struct_instance_01() {
    // 创建三个老师的数组. 通过函数进行赋值, 以及学生信息
    Teacher tArray[3]; //
    int t_len = LEN(tArray), s_len = LEN(tArray->sArray);
    init_teacher_student(tArray, t_len, s_len);
    print_teacher_student(tArray, t_len, s_len);



}

int main() {
    struct_instance_01();

    return 0;
}