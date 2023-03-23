//
// Created by NUC on 2023/3/22.
//

#include <iostream>
#include <string>
using namespace std;
#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0][0]))

void _2d_array_definite(){
    /*
        ��ά���������ֶ��巽ʽ.
        ��������ʡ��, �����������Բ���ʡ��.
     */
    int arr[2][3] = { // ���Ƽ����ֶ��巽ʽ, �ǳ�ֱ��. ֪���������Ĵ�С.
            {1, 2, 3},
            {4, 5 ,6},
    };
    int arr2[][3] = { // ����Ҫ������, �����������Զ�����.
            1, 2, 3, 4, 5,6,
    };
    for (int i = 0; i < LEN(arr); i++) {
        for (int j = 0; j < LEN(arr[0]); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;

    }







}

void _2d_array_name() {
    /*
        ��ά������:
            ���������鿴��ά������ռ�õĿռ�
            ��ȡ��ά������׵�ַ

     */
    // ���Բ鿴ռ���ڴ�ռ�Ĵ�С
    int arr[2][3] = {1, 2, 3, 4, 5, 6,};
    for (int i = 0; i < LEN(arr) * LEN(arr[0]); i++) {
        **(arr+i) = i; // ʹ��ָ����и�ֵ.
    }
    for (int i = 0; i < SIZE(arr) ; i++) {
        cout << **(arr+i) << " ";
    }

    cout << endl;

    // ʹ��sizeof���в����ڴ�ռ�.
    cout << sizeof arr << endl; // 24
    cout << sizeof arr[0] << endl; // 12 ����Ƕ�ά�����һ�е��ڴ�ռ�.
    cout << sizeof arr[0][0] << endl; // 4, ����Ƕ�ά�����е�һ��������ռ�õ��ڴ�ռ�.

    // ͨ����������������, ���ǾͿ��Բ��������ά������кͿ�.
    cout << "��ά������ռ������: " << sizeof arr / sizeof arr[0] << endl;
    cout << "��ά������ռ�õ�����: " << sizeof arr[0] / sizeof arr[0][0] << endl;
    // ������������е�����.


    // �鿴��ά������׵�ַ:
    cout << "��ά������׵�ַ " << arr << endl;
    cout << "��ά�����һ�е��׵�ַ " << arr[0] << endl;
    cout << "��ά�����һ��Ԫ���׵�ַ" << &arr[0] << endl;
    // �׵�ַ�͵�һ�к͵�һ��Ԫ�ص��׵�ַ����һ����.

    cout << "�ڶ��� " << arr[1] << endl; // ��12��.
















}


int main() {
//    _2d_array_definite();
    _2d_array_name();

    return 0;
}