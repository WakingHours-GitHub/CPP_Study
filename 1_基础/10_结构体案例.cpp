//
// Created by NUC on 2023/3/30.
//
#include <iostream>
#include <string>
#include <random>
#include <ctime>

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


// 
void init_teacher_student(Teacher *t_array, int t_len, int s_len){
    string nameSeed = "ABCDE";
    for (int i = 0; i < t_len; i++){
        t_array[i].tName = (string)"teach_" + nameSeed[i]; // 可以使用这种方式进行初始化.
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
    // 创建三个老师的数组. 通过函数进行赋值, 以及学生信息
    Teacher tArray[3]; //
    int t_len = LEN(tArray), s_len = LEN(tArray->sArray);

    // 随机数种子:
    srand((unsigned int)time(NULL)); // 需要包含ctime头文件.

    init_teacher_student(tArray, t_len, s_len);
    print_teacher_student(tArray, t_len, s_len);



}



// 设计一个英雄的结构体, 包括成员姓名、年龄、性别; 创建结构体数组, 存放五名英雄.
// 然后通过一个冒泡排序, 按照年龄进行升序排列. 最终打印.
struct hero{
    string name; // 姓名
    int age; // 年龄
    string gender; // 性别
};



void struct_instance_02() {


}



int main() {
    struct_instance_01();

    return 0;
}