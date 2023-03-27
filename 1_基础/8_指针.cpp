//
// Created by NUC on 2023/3/25.
//

#include <iostream>
#include <string>
//#include <celib.h>
#include <stdlib.h>
using namespace std;


/*
    ָ�������: ����ͨ��ָ��������ڴ�.
        �ڴ����Ǵ�0��ʼ��¼��. һ��ʹ��ʮ���������ֽ��б�ʾ.
        ��������ָ����������ַ.

    ָ���������ľ��ǵ�ַ.
    ����ͨ��һ��ָ�뱣��һ����ַ.
    ������: ��ζ���, ���ʹ��ָ��.


    ָ�����ָ���ڴ��б��Ϊ0�Ŀռ�.
    ����һ������Ŀռ�. 0~255֮����ڴ�����ϵͳռ�õ�, ��˲����Է���.
    ����: ��ʼ��ָ�����
    ע��: ��ָ��ָ����ڴ�ռ��ǲ����Է��ʵ�.

    Ұָ��: ָ�����ָ��Ƿ����ڴ�ռ�.
        ����û�г�ʼ��, �����ֵ�����ֵ. ��ʱʹ��ָ������ܷ�������.

    const����ָ��: �������:
        const����ָ�� -> ����ָ��
        const���γ��� -> ָ�볣��
        const������ָ��, Ҳ���γ���.
        ����ע���עconst���������, ˭������, ������˭.



 */


void point_definite() {
    // ����ָ��: �������� * ������ = ��ַ.
    int a = 10;
    int *p = &a; // ����ָ��, ����pָ��a.
    // ���ָ���: p��һ��ָ��, ��ŵ��ǵ�ַ. *p��һ������, ����������int.
//    & ȡ��ַ.
    cout << &a << endl;
    cout << p << endl;
    // ָ����ǵ�ַ���.

     // ʹ��ָ��:
     // ͨ�������õķ�ʽ���ҵ�ָ��ָ����ڴ��е�����.
     // *p �ͱ�ʾ�ҵ�pָ���ڴ��е�����.
     cout << *p << endl; // 10
     *p = 100; // ͨ��*p�����޸� *p�ͱ�ʾa.
     cout << a << endl;


}


void point_sizeof() {
    int *p = NULL; // ��ָ��.
    // 32λos, 4���ֽ�. 64λos, 8���ֽ�. ����ʲô���͵�ָ��, ����ռ��8���ֽ�.
    cout << sizeof p << endl; // 8
    cout << sizeof (int *) << endl;
    cout << sizeof (double *) << endl;

}

void point_null_other(){
    int *p = NULL; // ��ʼ��.
//    cout << *p << endl; // �����Է���.
    // ��ȡ����Ȩ�޳�ͻ.
    // Ұָ�����δ��ʼ����ָ��.
    // ͨ����ʱʹ�õ���һ���������. ��ʱʹ��ָ��, �������ɸ��������.






}


void const_point() {
    int a = 10, b = 20;

    // ����ָ�� -> ����ָ��.
    // const���ε���*p, �ǳ�����ָ��.
    const int *p = &a; // ָ���ָ������޸�. ����ָ��ָ���ֵ�������޸�.
//    *p = 30; // ����
    p = &b; // �����޸�.
    cout << *p << endl;

    // ָ�볣��, const���ε���p.
    int * const p2 = &a; // ָ�볣��. ָ���ָ�򲻿��Ը�, ָ���ֵ���Ը�.
    cout << *p2 << endl; // 20
    *p2 = 30;
//    p2 = &b; // �����Ըı�.
    cout << *p2 << endl; // 30


    // ������Ҳ����
    const int * const p3 = &a; // ָ���ֵ���������޸�.
    // ֻ���ڳ�ʼ����ʱ����.

    cout << *p3 << endl; // 30.



}


int * range(int end, int start=0){
    int *p_arr = (int *) malloc((end - start)*4);
    for (int i = start; i < end; i++){
        *(p_arr + i) = i;

    }
    return p_arr;
}

void point_array() {
    /*
        ָ�������
        Ŀ��: ����ָ����������е�Ԫ��.

     */
    int *arr = (int *)range(10);
    for (int i = 0; i< 10; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << arr[0] << endl;

    int *p = arr; // ����������������׵�ַ. ����ʹ��&

    // ����ָ����ʵ�һ��Ԫ��:
    cout << "����ָ����ʵ�һ������: " << *p << endl;
    // ָ���ƶ�int(�ĸ��ֽ�)Ҳ���ǲ���.
    p++;
    cout << *p << endl; // 1

    int *p2 = arr;
    for (int i = 0; i < 10; i++) {
        cout << *(p2++) << " ";
    }



}


// ʵ������������н���:
void swap_value(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
void swap_address(int * const a, int * const b){
    // ʹ�õ�ַ�ҵ����ݹ�����ʵ������, Ȼ����н���. ͨ����ַ���ǾͿ��Խ�����.

    int temp = *a;
    *a = *b;
    *b = temp;




}

void point_function(){
    // ����ָ����Ϊ����������ʱ��, ���Ըı�ʵ�ε�ֵ.

    int a = 10, b = 20;
    // ����ǵ�ַ����, �����޸�ʵ��.
    swap_address(&a, &b);

    cout << a << " " << b << endl; // �����ɹ�.
}

int main() {
//    point_definite();

//    point_sizeof();
//    point_null_other();
//    const_point();
//    point_array();
    point_function();

    return 0;
}
