//
// Created by NUC on 2023/1/16.
//

#include <iostream>
#include <string> // 使用c++风格字符串, 需要包含这个string


#define WEEK 7 // 定义一个常量.
using namespace std;

/*
 * 变量: 就是给一段指定的内存空间起名, 方便我们操作这段内存.
 * 变量创建的语法:
 *      数据类型 变量名 = 变量初始值 // 初始化
 * 常量: 用于记录程序中不更改的数据
 *      C++定义常量的两种方法:
 *      #define宏常量: #define 常量名 常量值
 *          通常在文件上方定义, 表示一个常量
 *
 *      const修饰的变量: const 数据类型 变量名 = 常量值
 *          通常在变量定义前加上关键字const, 修饰为变量, 不可修改.
 *
 * 不要使用关键字给变量或者常量起名字. 因为会报错.
 *
 * 标识符命名规则:
 *      标识符不能是关键字.
 *      只能由字母, 数字, 下划线组成.
 *      第一个字符必须由字母或者下划线
 *      标识符中字母区分大小写
 * 建议: 给变量起名字的时候最好能够做到见名知意.
 */

/*
 * main是程序的入口, 并且每一个程序有且有且只有这样一个函数.
 */
int main() {
    cout << "hello C plus plus" << endl; // 像屏幕输出内容. // 这是单行注释.
    /* 这是多行注释. 解释代码, 方便其他人员能够看懂.  */


    int a = 10; // 这就是创建变量的语法.
    cout << "a=" << a << endl; // 打印变量.


    cout << "一周总共有" << WEEK << "天" << endl;


    // const修饰的变量
    const int month = 12;
//    month = 19; 错误, const修饰的变量也称之为常量.

    // 标识符不可以是关键字
//    int int = 10; # error.

    // 标识符只能由字母, 数字, 下划线组成
    int abc = 19;
    int _abc = 10;
    int _123abc = 19;
//    int 1_ab_ = 10; 报错

    // 区分大小写
    int aaa = 100;
    int AAA = 200;
    cout << &aaa << endl;
    cout << &AAA << endl;


    // create a variable
    short num1 = 10;
    int num2 = 10;
    long num3 = 10;
    long long num4 = 10;
    // 整形： short < int <= long < long long.
    cout << num1 << endl;


    // sizeof key word
    // 利用sizeof关键字可以统计数据类型或者变量所占内存大小。
    // sizeof(数据类型/变量)

    // 实型
//    float 7个有效数字
//  double: 15~16有效数字。、
// 3.14: 3位有效数字。
    float f1 = 3.14f; // f表示是一个单精度类型
    // 默认情况下, 编译器会将浮点型作为double类型.
    // 所以我们需要使用f进行指定位float类型.
    cout << f1 << endl;


    double d1 = 3.1415926;
    cout << d1 << endl; // 默认表示6个有效数字, 也就是3.14158
    // 默认情况下, 输出一个小数, 会显示出6位有效数字.
    cout << sizeof(double) << endl; // 8
    cout << sizeof(float) << endl; // 4

    // 科学计数法:
    float f2 = 3e2; // 3 * 10^2
    cout << f2 << endl; // 300

    float f3 = 3e-2; // e*0.1^2
    cout << f3 << endl;

    // 字符型: 用于表示单个字符.
    // 注意: 单引号中, 只允许放一个字符. 不允许使用""双引号.
    // 只占用一个字节. 是将对应的ASCII编码放到存储单元中.
    char ch = 'a'; //
    // ch中实际存储的还是数字, 只不过表示出来是一个字符.

    cout << ch << endl; // a


    cout << (int) ch << endl; // 97 # 字符型强转int.
    // a: 97, A: 65, 0: 49.

    cout << sizeof(char) << endl; // 1

//    char ch2 = "b"; // 创建字符型变量的时候要使用单引号.
//    char ch2 = 'abcdef' // 创建字符型变量时, 单引号内只能有一个字符.
    // 0-31分配给了控制字符, 用于控制打印机等一些外围设备.
    // 32-126, 分配到了键盘上能找到的字符, 当查看或者打印文档时就会出现.

    // 转义字符: 两个字符, 以/开头.
    /*
     转义字符, 含义, ASCII码值
     \a : 警报 007
     \b, 退格, BS, 将当前指针以到前面一格. 008
     \f, 换页
     \n
     \r, //回车CR. 表示将位置移到本行开头.
     \t, 表示水平制表., 下一个TAB位置.
     \\ 表示/字符.

     */

    // 转义字符:
    cout << "Hello World\n" << endl;

    cout << "// hel" << endl; // // hel

    cout << "hel \t lipu" << endl; // hel      lipu
    // 好处, 使用\t可以用来对齐.


    // 字符串型: 用于表示一串字符.
    // 使用""双引号, 括号引用起来.
    /*
     * 两种风格:
     *  C风格字符串: chat 变量名[] = "字符串值"
     *  注意, 需要加上[], 如果不加, 则表示单个字符.
     *  同时使用双引号""进行引起来.
     *
     *  C++风格: string 变量名 = "字符串值"
     *  需要包含一个头文件: #include<string>
     *
     *
     *
     */

    // C风格
    cout << "hello world" << endl;

    char str[] = "Hello World"; // 使用变量名进行保存这个字符串
//    char str[] = 'hello'
    cout << str << endl;


    string str2 = "Hello World";
    // 如果使用c++风格字符串, 需要包含string.h头文件.
    cout << str << endl;


    // 布尔数据类型: bool
    // true: 真(本质是1)
    // false: 假(本质是0)
    // bool占用一个字节大小.
    bool flag = true;
    cout << flag << endl; // 1 本质是1. 非零都是true.

    bool flag2 = false;
    cout << flag2 << endl; // 0

    cout << sizeof(bool) << endl; // 1 // bool所占的类型空间.

    // 数据的输入. : 用于从键盘中获取数据.
    // cin关键字.
    // cin >> 变量.
    // 然后学习一下不同的数据类型如何输入.

    // 整型:
//    int a;
    a = 0; // 初始化.
    cout << "please cin to a: " <<endl;
    cin >> a;

    cout << "value of a is: " << a << endl;

    float f = 3.14f;
    cout << "please cin to float type value: " << endl;
    cin >> f; // >>右运算符.
    cout << "浮点型变量f: " << f << endl;


    char c = 'a';
    cout << "please cin to chat type value: " << endl;
    cin >> c; // >>右运算符.
    cout << "字符型变量c: " << c << endl;

    string str_1 = "ZERO";
    cout << "please cin in string type value" << endl;
    cin >> str_1;
    cout << "str_1: " << str_1 << endl;



    flag = false;
    cout << "please cin to bool type variable " << endl;
    cin >> flag; // 赋值, 我们应该赋予0, 1这样的值.,
    // bool类型, 只要是非零的值, 都表示为真.
    cout << flag << endl;


























    return 0;

}
