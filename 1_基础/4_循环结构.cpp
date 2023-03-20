//
// Created by NUC on 2023/3/17.
//



#include<iostream>
#include<string>
#include <math.h>
// timeϵͳʱ��ͷ�ļ��İ���:
#include <ctime>
using  namespace std;


/*
    whileѭ�����:
        ѭ���������ʽΪtrue, ��ִ��ѭ�����.
    while(ѭ���������ʽ){
        ѭ����
    }

    do-whileѭ�����:
    ��while����������do_while����ִ��һ��ѭ�����, ���ж�ѭ������.
    ע��, do_while�����while��������Ҫ����һ���ֺ�.
    do {
        ѭ�����
    } while(ѭ������);


    for ѭ��: ����ѭ������, ִ��ѭ�����
    for(��ʼ���ʽ; �������ʽ; ĩβ���ʽ) {
        ѭ����;
    }
    ���ʽ֮��ʹ��;���зָ�.
    ��ʼ���ʽ, ������ѭ��֮ǰ, ִֻ��һ��, ͨ��������ʼ��.
    �������ʽΪtrue, ��ִ��ѭ���������
    ĩβ���ʽ: ��ÿ��ѭ��֮����Ҫִ�е����

    ��ִ����ʼ���ʽ, Ȼ���ж��Ƿ�����ѭ������, Ȼ�����ѭ����, ��ѭ�������֮��, ִ��ĩβ���ʽ,
    Ȼ�����ж��Ƿ�����ѭ������.



 */

void while_study(){
    int num = 0;

    // while(���ʽ)ѭ��, ���ʽΪtrue, ��ִ��ѭ��.
    // ������ѭ���ĳ���, ��������Ҫ����һ�ֽṹ.
    // �ڳ���ִ�е�ʱ��, ��������ṩ����ѭ���ĳ���, ����������ѭ��.
    while (num < 10) {
        cout << num << endl;
        num++;
    }
}


void gauss_number(){
    // ϵͳ���������:
    // ������������: ���õ�ǰϵͳ��ʱ�����������, ��ֹÿ���������һ��.
    srand((unsigned int) time(NULL));

    // rand() ���������.
//    rand() % 100 // ����ȥд, ����0~99�������
    int rand_num = (rand() % 100 + 1); // ���������.
    // ����α�����.
    cout << rand_num << endl;
    int gauss_value = 0; // ��Ҳ²������

    // ��ҽ��в²�.
    while (1) {
        cout << "��������Ҫ�²������:" << ends;
        cin >> gauss_value;
        if (gauss_value > rand_num) {
            cout << "̫����" << endl;
        }else if (gauss_value < rand_num) {
            cout << "̫С��" << endl;
        }else{
            cout << "�¶���!!!" << endl;

            // �¶���, �˳�
            break; // ����break�˳�ѭ��.
        }
    }

    // �ж���Ҳ²�

    // �¶� -> �Ƴ�

    // �´� -> ��ʾ��С.

}

void do_while_study(){
    int num = 0;

    do { // ��ִ��do�е����. Ȼ���ڽ����ж�. ����ִ��һ��do.
        cout << num << endl;
        num++;
    }while(num < 10);
}


void do_while_instance_narcissistic_number(){
    // ˮ�ɻ���: ��һ����λ��, ����ÿ����λ�ϵ����ֵ�������֮�͵���������.
    // ����: 1^3 + 5^3  + 3^3 = 153.
    // ����dowhile, ������е���λ��ˮ�ɻ���
    int num = 123;
    /*
     (num % 10) ��λ
     (num / 10 % 10) ʮλ
     (num / 100) ��λ.
     */
    int a=0, b=0, c=0;
    do {
        a = (num % 10), b = (num/10%10), c = (num/100);
        if (num == (a*a*a + b*b*b + c*c*c)) {
            cout << num << endl;
        }
        num++;
    }while (num < 1000);
}

void for_study(){
    for(int i = 0; i < 10; i++) {
        cout << i << endl;
    }
}

void for_instance_knock_desk(){

    // 7�ı���, ��λ��7, ʮλ��7
    // ���� % 7 == 0, ��ʾ�ܱ�7����, �����7�ı���.
    // ��λ, ʮλ, ��������. ����׸��.
//    int num = 1;
    for (int i = 1; i <= 100; i++) {
        if ((i % 10) == 7 || (i / 10 ) == 7 ||  (i%7==0)) { // ʹ��||(�߼���)���в�.
            // ��Ϊָ������λ��, ����ֱ��/10�Ϳ��Եõ���λ.
            cout << i << " ������!!!" << endl;
        }else {
            cout << i << endl;
        }
    }
}

void nest_loop() {
    /*
        Ƕ��ѭ��: ��ѭ��������Ƕ��һ��ѭ��, ���һЩʵ������.

     */

    // ��ӡһ��:
//    for (int i = 0; i < 10; i++){
//        cout << "* "; // �����д�ӡ.
//    }
//    cout << endl; // ���д���.

    // ���ִ��һ��, �ڲ�ִ��һ��.
    for (int i = 0; i < 10; i++){
        // �ڲ�ѭ��
        for (int j = 0; j < 10; j++){
            cout << "* ";
        }
        cout << endl;
    }
}

void  multiplication_table(){
    // ʵ��99�˷���:

    for (int i = 1; i < 10; i++){ // ����
        for (int j = 1; j <= i; j++) { // ��<=��ǰ������
            cout << j << "*" << i << " = " << i*j << " ";
        }
        cout << endl;
    }
}

void break_and_continue_goto(){
    /*
        break���: ��������ѡ��ṹ����ѭ���ṹ. ʹ�÷���.
        breakʹ�õ�ʱ��: ����switch������䵱��, ��������ֹcase������switch.
        ����ѭ���������, ������ǰ��ѭ�����.
        ������Ƕ��ѭ����, ����������ڲ�ѭ�����.


        continue: ��ѭ�������, ��������ѭ����������δִ�е����, ����ִ����һ��ѭ��.
        ѭ�����: do_while, while, for.
        continue����ֱ��ִ����һ�ε�ѭ��. ����ִ�б���ѭ�������������.
        continue������ֹѭ��.

        goto���: ��������������ת����
        �﷨: goto ���; // goto���
                ���: // ��ͱ�ʾ���.
        �����ǵ����ƴ���, ִ�е�goto���ʱ, �����ת����ǵ�λ��.
        ������, goto����Ӱ������߼��ͽṹ.

     */

    cout << "1, ****" << endl;
    goto FLAG;
    cout << "2, ****" << endl;
    cout << "3, ****" << endl;
    cout << "4, ****" << endl;

    FLAG:
    cout << "5, ****" << endl;
    cout << "6, ****" << endl;










}


int main(){
//    while_study();
//    gauss_number();

//    do_while_study();
//    do_while_instance_narcissistic_number();

//    for_study();

//    for_instance_knock_desk();
//    nest_loop();
//    multiplication_table();

    break_and_continue_goto();
return 0;

}