//
// Created by NUC on 2023/3/20.
//

#include <iostream>
#include <string>
using namespace  std;

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof(arr[0]))

/*
    数组: 所谓数组就是一个集合, 里面存放了相同类型的数据元素.
    特点:
        数组中的每个数据元素都是相同的数据类型
        数组是由连续的内存位置组成的.

    一维数组:
        三种定义方式:
            数据类型 数组名[数组长度];
            数据类型 数组名[数组长度] = {value1, value2...};
            数据类型 数组名[] = {value1, value2, ...};
        数组名不要和变量名混用. 数组下标是从0开始索引的.

        一维数组名的用途:
            可以统计整个数组在内存当中的长度.
            可以获取数组在内存中的首地址.
                数组名就表示地址.

 */



void array_definite(){
    int arr[5];
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    cout << arr[0] << endl;


    int arr1[5] = {1, 2 ,3 ,}; // 如果在初始化时, 数据不够, 则会使用0进行填充.
    for (int i = 0; i < 5; i++) {
        cout << arr1[i] << endl;
    }

    int arr2[] = {1, 2, 3 ,4, 5, 6,7,};

    for (int i = 0; i < 7; i++){
        cout << arr2[i] << endl;
    }

    cout << "数组长度" << ARRAY_SIZE(arr2) << endl;
}



void array_name() {
    int arr[10];
    for (int i = 0; i < ARRAY_SIZE(arr); arr[i] = i++);
    for (int i = 0; i < ARRAY_SIZE(arr); i++){
        cout << arr[i] << endl;
    }

    cout << "sizeof arr: " << sizeof arr << endl; // 整个数组占用的内存空间
    cout << "sizeof arr[0]: " << sizeof arr[0] << endl; // 每个元素占用的内存空间
    cout << "num of array: " << sizeof arr / sizeof arr[0] << endl; // 数组中元素个数为.

    cout << "数组首地址, 十六进制：" << arr<< ", 十进制：" << "" << endl;
    cout << "数组中第一个元素的地址为：" << &arr[0] << endl;
    // 数组名字就相当于数组的首地址, 同时数组的第一个元素所在的内存位置就是第一个首地址.
    cout << "数组中第二个元素的地址" << &arr[1] << endl;
    // 数组之间是紧密连接的. 在一个先行的内存空间当中.
    // 数组名是一个常量, 不可以进行赋值的操作. 也就是const类型的变量
//    arr = 100; // 数组名是一个常量, 不可以进行赋值操作.


}


void _1_d_instance() {
//    "在一段数组中找到最大的数组"

    // 哨兵:
    int weight_array[] = {300, 200, 400, 500, 690};
    int max = weight_array[0]; // 哨兵.
    for (int i = 1; i < ARRAY_SIZE(weight_array); i++) {
        if (max < weight_array[i]) {
            max = weight_array[i];
        }
    }
    cout << "最重的猪是: " << max << endl;

//    std::cout <<
}

void reverse_array(){
    // 实现数组元素逆置
    int arr[9] = {0, };
    for(int i = 0; i < ARRAY_SIZE(arr); i++){
        arr[i] = i;
    }
    for(int i = 0; i < ARRAY_SIZE(arr); i++){
        cout << arr[i] << " ";
    }

    // 第一种算法.
    for(int i = 0, temp = 0; i < ARRAY_SIZE(arr)/2; i++) {
        temp = arr[i];
        arr[i] = arr[ARRAY_SIZE(arr)-i-1];
        arr[ARRAY_SIZE(arr)-i-1] = temp;

    }
    cout << endl;
    for(int i = 0; i < ARRAY_SIZE(arr); i++){
        cout << arr[i] << " ";
    }

    // 第二种算法
    // 如果left < right那么我们才开始互换, 如果=则说明在中间, 如果大于, 则说明还没换完, 这两种情况我们都不互换.
    // 正常来说这种不知道循环几次的代码, 应该使用while循环.
    for(int left=0, right = ARRAY_SIZE(arr)-1, temp = 0; left < right; left++, right--){
        temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
    }
    cout << endl;
    for(int i = 0; i < ARRAY_SIZE(arr); i++){
        cout << arr[i] << " ";
    } // 又成功互换回来.


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