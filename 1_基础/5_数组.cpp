//
// Created by NUC on 2023/3/20.
//

#include <iostream>
#include <string>
using namespace  std;

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

/*
    ����: ��ν�������һ������, ����������ͬ���͵�����Ԫ��.
    �ص�:
        �����е�ÿ������Ԫ�ض�����ͬ����������
        ���������������ڴ�λ����ɵ�.

    һά����:
        ���ֶ��巽ʽ:
            �������� ������[���鳤��];
            �������� ������[���鳤��] = {value1, value2...};
            �������� ������[] = {value1, value2, ...};
        ��������Ҫ�ͱ���������. �����±��Ǵ�0��ʼ������.

        һά����������;:
            ����ͳ�������������ڴ浱�еĳ���.
            ���Ի�ȡ�������ڴ��е��׵�ַ.
                �������ͱ�ʾ��ַ.

 */



void array_definite(){
    int arr[5];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    cout << arr[0] << endl;


    int arr1[5] = {1, 2 ,3 ,}; // ����ڳ�ʼ��ʱ, ���ݲ���, ���ʹ��0�������.
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << endl;
    }

    int arr2[] = {1, 2, 3 ,4, 5, 6,7,};

    for (int i = 0; i < 7; i++){
        cout << arr2[i] << endl;
    }

    cout << "���鳤��" << ARRAY_SIZE(arr2) << endl;
}



void array_name() {
    int arr[10];
    for (int i = 0; i < ARRAY_SIZE(arr); arr[i] = i++);
    for (int i = 0; i < ARRAY_SIZE(arr); i++){
        cout << arr[i] << endl;
    }

    cout << "sizeof arr: " << sizeof arr << endl; // ��������ռ�õ��ڴ�ռ�
    cout << "sizeof arr[0]: " << sizeof arr[0] << endl; // ÿ��Ԫ��ռ�õ��ڴ�ռ�
    cout << "num of array: " << sizeof arr / sizeof arr[0] << endl; // ������Ԫ�ظ���Ϊ.

    cout << "�����׵�ַ, ʮ�����ƣ�" << arr<< ", ʮ���ƣ�" << "" << endl;
    cout << "�����е�һ��Ԫ�صĵ�ַΪ��" << &arr[0] << endl;
    // �������־��൱��������׵�ַ, ͬʱ����ĵ�һ��Ԫ�����ڵ��ڴ�λ�þ��ǵ�һ���׵�ַ.
    cout << "�����еڶ���Ԫ�صĵ�ַ" << &arr[1] << endl;
    // ����֮���ǽ������ӵ�. ��һ�����е��ڴ�ռ䵱��.
    // ��������һ������, �����Խ��и�ֵ�Ĳ���. Ҳ����const���͵ı���
//    arr = 100; // ��������һ������, �����Խ��и�ֵ����.


}


void _1_d_instance() {
//    "��һ���������ҵ���������"

    // �ڱ�:
    int weight_array[] = {300, 200, 400, 500, 690};
    int max = weight_array[0]; // �ڱ�.
    for (int i = 1; i < ARRAY_SIZE(weight_array); i++) {
        if (max < weight_array[i]) {
            max = weight_array[i];
        }
    }
    cout << "���ص�����: " << max << endl;

//    std::cout <<
}

void reverse_array(){
    // ʵ������Ԫ������
    int arr[9] = {0, };
    for(int i = 0; i < ARRAY_SIZE(arr); i++){
        arr[i] = i;
    }
    for(int i = 0; i < ARRAY_SIZE(arr); i++){
        cout << arr[i] << " ";
    }

    // ��һ���㷨.
    for(int i = 0, temp = 0; i < ARRAY_SIZE(arr)/2; i++) {
        temp = arr[i];
        arr[i] = arr[ARRAY_SIZE(arr)-i-1];
        arr[ARRAY_SIZE(arr)-i-1] = temp;

    }
    cout << endl;
    for(int i = 0; i < ARRAY_SIZE(arr); i++){
        cout << arr[i] << " ";
    }

    // �ڶ����㷨
    // ���left < right��ô���ǲſ�ʼ����, ���=��˵�����м�, �������, ��˵����û����, ������������Ƕ�������.
    // ������˵���ֲ�֪��ѭ�����εĴ���, Ӧ��ʹ��whileѭ��.
    for(int left=0, right = ARRAY_SIZE(arr)-1, temp = 0; left < right; left++, right--){
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    cout << endl;
    for(int i = 0; i < ARRAY_SIZE(arr); i++){
        cout << arr[i] << " ";
    } // �ֳɹ���������.


}


void  bubbling_sort() {

}


int main() {
//    array_definite();

//    array_name();

//    _1_d_instance();
    reverse_array();
//
    return 0;
}