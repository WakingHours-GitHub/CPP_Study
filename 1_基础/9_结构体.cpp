//
// Created by NUC on 2023/3/27.
//
#include <iostream>
#include <string> // string.
#define ARRAY_SIZE(arr) (sizeof arr/ sizeof arr[0])
using namespace std;

/*
    结构体: 结构体属于用户自定义的数据类型, 允许用户存储不同的数据类型.
    结构体定义和使用:
        struct 结构体名 {
            结构体成员列表
        };
    通过结构体创建变量:
        struct 结构体名 变量名;
        struct 结构体名 变量名 = {成员1值, ...}
        定义结构体时顺便创建变量.

    结构体数组: 将自定义的结构体放到数组中方便维护.
        struct 结构体名 数组名[个数] = = {{}, ...}

    结构体指针: 通过指针访问结构体中的成员
        利用->符, 可以通过结构体指针访问结构体属性.

    结构体嵌套结构体: 结构体中的成员可以是另一个结构体


    结构体作为函数参数: 将结构体作为参数传递给函数.
        结构体作为参数想函数中传递.
        传递方式:
            值传递
            地址传递
        将结构体传入函数参数时, 通常使用地址传递, 这样速度较快.
        如果使用值传递则会创建一个结构体, 然后将结构体中的成员一一赋值.
        如果想要修改主函数中的数据, 则使用地址传递, 如果不想修改, 则使用值传递.

    结构体当中的const使用场景:
        使用const来防止误操作。










 */




// 演示:
// 创建学生数据类型. 创建具体的学生.
struct Student{
    // 成员列表 -> 就是内置数据类型的集合.
    string name; // 姓名
    int age;     // 年龄
    int score;  // 得分.
//    void print_str = print_struct(this);
}s3; // 创建结构体变量的时候直接创建结构体变量.

// 结构体嵌套结构体:
struct teacher{
    int id; // 教师编号
    string name; // 姓名
    int age; // 年龄
    struct Student stu; // 定义在前面, 然后声明.
};



void print_struct(void * str) {
    str = (Student *) str;

}

void definite_struct () {
    // 在创建结构体变量的时候, struct在c++中可以省略.
    // 通过学生类型创建具体的学生:
    Student s1; // 数据类型 变量名
    // 通过成员运算符'.'来访问属性.

    s1.name = "张三";
    s1.age = 19;
    s1.score = 100;
    cout << "name: " << s1.name << " age: " << s1.age << " score: " << s1.score << endl;

    // 定义的时候直接指定成员, 按照顺序为成员进行赋值.
    struct Student s2 = {"lipu", 12, 98};
    cout << "name: " << s2.name << " age: " << s2.age << " score: " << s2.score << endl;




}


void struct_array(){
    // 使用上述的结构体.
    Student stu_arr[] = { // struct关键字可以省略
            {"张三", 19, 100},
            {"李四", 29, 90},
            {"王五", 39, 99},
    };
    // 可以通过索引给结构体数组中的元素赋值
    stu_arr[2].name = "赵六"; // 同样可以通过索引取出这里面的元素.

    // 遍历结构体数组
    for (int i = 0; i < ARRAY_SIZE(stu_arr); i++) {
        cout << "name: " << stu_arr[i].name << " 年龄: " << stu_arr[i].age << " 分数: " << stu_arr[i].score << endl;
    }

}


void struct_point() {
    // creat student struct variable
    struct Student stu = {"张三", 18, 100};

    // 通过指针指向结构体变量.
    Student *p = &stu; // 返回对应类型的指针, 类型需要相同

//    stu.name
    // 通过指针指向结构体变量, 通过->操作符.
    cout << "name: " << p->name << " 年龄: " << p->age << " 分数: " << p->score << endl;
}

void struct_struct() {
    struct teacher t;
    t.id = 123;
    t.name = "离谱";
    t.age = 30;
    t.stu.name = "王五";
    t.stu.age = 12;
    t.stu.score  = 90;


    cout << "老师姓名: " << t.name << endl;
    cout << "所教学生的名字: " << t.stu.name << endl;



}


// 值传递:
void print_Student_1(struct Student s) {
    cout << "print student 1" << endl;
    s.age = 100; // 不会改变原来的数值. 只是改变当前局部变量的数值. 因为是值传递.
    cout << s.name <<" " << s.age << " " <<s.score << endl;


}

// 地址传递: 我们一般使用地址传递. 这样效率高. 不会赋值新的副本出来.
// 如果我们不希望再函数中改变这个内存空间的内容, 则我们需要使用const进行修饰.
void print_Student_2(const struct Student *s_p) { // 等同于 struct Student const *s_sp 都是修饰*s_p
    // const修饰的是*s_p其实也就是变量, 所以是不允许改变所指向内存的中的内容. 变成只读. 但是指针指向可以改变.
    cout << "print student 2" << endl;
    // 此时修改则会改变原始的变量, 因为是地址传递.

//    s_p -> age = 200; // 如果我们不希望s_p所指向的元素被修改, 那么我们希望使用const进行修饰.
    // const *p: 是
    cout << s_p -> name << " " << s_p -> age << " " << s_p->score << endl;


}

void struct_as_param() {
    // 创建一个结构体变量:
    struct Student s = {
            "张三", 20, 86,
    };
    cout << s.name << " " << s.age << " " << s.score << endl;

    print_Student_1(s);
    cout << s.name << " " << s.age << " " << s.score << endl; // 没有改变.

    print_Student_2(&s);
    cout << s.name << " " << s.age << " " << s.score << endl;



}


void const_struct() {
    Student s = {"张三", 15, 70};
    print_Student_2(&s); // 打印函数;



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