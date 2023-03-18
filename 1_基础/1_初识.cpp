//
// Created by NUC on 2023/1/16.
//

#include <iostream>
#include <string> // ʹ��c++����ַ���, ��Ҫ�������string


#define WEEK 7 // ����һ������.
using namespace std;

/*
 * ����: ���Ǹ�һ��ָ�����ڴ�ռ�����, �������ǲ�������ڴ�.
 * �����������﷨:
 *      �������� ������ = ������ʼֵ // ��ʼ��
 * ����: ���ڼ�¼�����в����ĵ�����
 *      C++���峣�������ַ���:
 *      #define�곣��: #define ������ ����ֵ
 *          ͨ�����ļ��Ϸ�����, ��ʾһ������
 *
 *      const���εı���: const �������� ������ = ����ֵ
 *          ͨ���ڱ�������ǰ���Ϲؼ���const, ����Ϊ����, �����޸�.
 *
 * ��Ҫʹ�ùؼ��ָ��������߳���������. ��Ϊ�ᱨ��.
 *
 * ��ʶ����������:
 *      ��ʶ�������ǹؼ���.
 *      ֻ������ĸ, ����, �»������.
 *      ��һ���ַ���������ĸ�����»���
 *      ��ʶ������ĸ���ִ�Сд
 * ����: �����������ֵ�ʱ������ܹ���������֪��.
 */

/*
 * main�ǳ�������, ����ÿһ��������������ֻ������һ������.
 */
int main() {
    cout << "hello C plus plus" << endl; // ����Ļ�������. // ���ǵ���ע��.
    /* ���Ƕ���ע��. ���ʹ���, ����������Ա�ܹ�����.  */


    int a = 10; // ����Ǵ����������﷨.
    cout << "a=" << a << endl; // ��ӡ����.


    cout << "һ���ܹ���" << WEEK << "��" << endl;


    // const���εı���
    const int month = 12;
//    month = 19; ����, const���εı���Ҳ��֮Ϊ����.

    // ��ʶ���������ǹؼ���
//    int int = 10; # error.

    // ��ʶ��ֻ������ĸ, ����, �»������
    int abc = 19;
    int _abc = 10;
    int _123abc = 19;
//    int 1_ab_ = 10; ����

    // ���ִ�Сд
    int aaa = 100;
    int AAA = 200;
    cout << &aaa << endl;
    cout << &AAA << endl;


    // create a variable
    short num1 = 10;
    int num2 = 10;
    long num3 = 10;
    long long num4 = 10;
    // ���Σ� short < int <= long < long long.
    cout << num1 << endl;


    // sizeof key word
    // ����sizeof�ؼ��ֿ���ͳ���������ͻ��߱�����ռ�ڴ��С��
    // sizeof(��������/����)

    // ʵ��
//    float 7����Ч����
//  double: 15~16��Ч���֡���
// 3.14: 3λ��Ч���֡�
    float f1 = 3.14f; // f��ʾ��һ������������
    // Ĭ�������, �������Ὣ��������Ϊdouble����.
    // ����������Ҫʹ��f����ָ��λfloat����.
    cout << f1 << endl;


    double d1 = 3.1415926;
    cout << d1 << endl; // Ĭ�ϱ�ʾ6����Ч����, Ҳ����3.14158
    // Ĭ�������, ���һ��С��, ����ʾ��6λ��Ч����.
    cout << sizeof(double) << endl; // 8
    cout << sizeof(float) << endl; // 4

    // ��ѧ������:
    float f2 = 3e2; // 3 * 10^2
    cout << f2 << endl; // 300

    float f3 = 3e-2; // e*0.1^2
    cout << f3 << endl;

    // �ַ���: ���ڱ�ʾ�����ַ�.
    // ע��: ��������, ֻ�����һ���ַ�. ������ʹ��""˫����.
    // ֻռ��һ���ֽ�. �ǽ���Ӧ��ASCII����ŵ��洢��Ԫ��.
    char ch = 'a'; //
    // ch��ʵ�ʴ洢�Ļ�������, ֻ������ʾ������һ���ַ�.

    cout << ch << endl; // a


    cout << (int) ch << endl; // 97 # �ַ���ǿתint.
    // a: 97, A: 65, 0: 49.

    cout << sizeof(char) << endl; // 1

//    char ch2 = "b"; // �����ַ��ͱ�����ʱ��Ҫʹ�õ�����.
//    char ch2 = 'abcdef' // �����ַ��ͱ���ʱ, ��������ֻ����һ���ַ�.
    // 0-31������˿����ַ�, ���ڿ��ƴ�ӡ����һЩ��Χ�豸.
    // 32-126, ���䵽�˼��������ҵ����ַ�, ���鿴���ߴ�ӡ�ĵ�ʱ�ͻ����.

    // ת���ַ�: �����ַ�, ��/��ͷ.
    /*
     ת���ַ�, ����, ASCII��ֵ
     \a : ���� 007
     \b, �˸�, BS, ����ǰָ���Ե�ǰ��һ��. 008
     \f, ��ҳ
     \n
     \r, //�س�CR. ��ʾ��λ���Ƶ����п�ͷ.
     \t, ��ʾˮƽ�Ʊ�., ��һ��TABλ��.
     \\ ��ʾ/�ַ�.

     */

    // ת���ַ�:
    cout << "Hello World\n" << endl;

    cout << "// hel" << endl; // // hel

    cout << "hel \t lipu" << endl; // hel      lipu
    // �ô�, ʹ��\t������������.


    // �ַ�����: ���ڱ�ʾһ���ַ�.
    // ʹ��""˫����, ������������.
    /*
     * ���ַ��:
     *  C����ַ���: chat ������[] = "�ַ���ֵ"
     *  ע��, ��Ҫ����[], �������, ���ʾ�����ַ�.
     *  ͬʱʹ��˫����""����������.
     *
     *  C++���: string ������ = "�ַ���ֵ"
     *  ��Ҫ����һ��ͷ�ļ�: #include<string>
     *
     *
     *
     */

    // C���
    cout << "hello world" << endl;

    char str[] = "Hello World"; // ʹ�ñ��������б�������ַ���
//    char str[] = 'hello'
    cout << str << endl;


    string str2 = "Hello World";
    // ���ʹ��c++����ַ���, ��Ҫ����string.hͷ�ļ�.
    cout << str << endl;


    // ������������: bool
    // true: ��(������1)
    // false: ��(������0)
    // boolռ��һ���ֽڴ�С.
    bool flag = true;
    cout << flag << endl; // 1 ������1. ���㶼��true.

    bool flag2 = false;
    cout << flag2 << endl; // 0

    cout << sizeof(bool) << endl; // 1 // bool��ռ�����Ϳռ�.

    // ���ݵ�����. : ���ڴӼ����л�ȡ����.
    // cin�ؼ���.
    // cin >> ����.
    // Ȼ��ѧϰһ�²�ͬ�����������������.

    // ����:
//    int a;
    a = 0; // ��ʼ��.
    cout << "please cin to a: " <<endl;
    cin >> a;

    cout << "value of a is: " << a << endl;

    float f = 3.14f;
    cout << "please cin to float type value: " << endl;
    cin >> f; // >>�������.
    cout << "�����ͱ���f: " << f << endl;


    char c = 'a';
    cout << "please cin to chat type value: " << endl;
    cin >> c; // >>�������.
    cout << "�ַ��ͱ���c: " << c << endl;

    string str_1 = "ZERO";
    cout << "please cin in string type value" << endl;
    cin >> str_1;
    cout << "str_1: " << str_1 << endl;



    flag = false;
    cout << "please cin to bool type variable " << endl;
    cin >> flag; // ��ֵ, ����Ӧ�ø���0, 1������ֵ.,
    // bool����, ֻҪ�Ƿ����ֵ, ����ʾΪ��.
    cout << flag << endl;


























    return 0;

}
