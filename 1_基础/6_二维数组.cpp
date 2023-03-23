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
        二维数组有四种定义方式.
        行数可以省略, 但是列数绝对不能省略.
     */
    int arr[2][3] = { // 更推荐这种定义方式, 非常直观. 知道这个数组的大小.
            {1, 2, 3},
            {4, 5 ,6},
    };
    int arr2[][3] = { // 必须要有列数, 编译器可以自动计算.
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
        二维数组名:
            可以用来查看二维数组所占用的空间
            获取二维数组的首地址

     */
    // 可以查看占用内存空间的大小
    int arr[2][3] = {1, 2, 3, 4, 5, 6,};
    for (int i = 0; i < LEN(arr) * LEN(arr[0]); i++) {
        **(arr+i) = i; // 使用指针进行赋值.
    }
    for (int i = 0; i < SIZE(arr) ; i++) {
        cout << **(arr+i) << " ";
    }

    cout << endl;

    // 使用sizeof进行测算内存空间.
    cout << sizeof arr << endl; // 24
    cout << sizeof arr[0] << endl; // 12 这就是二维数组第一行的内存空间.
    cout << sizeof arr[0][0] << endl; // 4, 这就是二维数组中第一个数据所占用的内存空间.

    // 通过上述的三个操作, 我们就可以测算出来二维数组的行和宽.
    cout << "二维数组所占的行数: " << sizeof arr / sizeof arr[0] << endl;
    cout << "二维数组所占用的列数: " << sizeof arr[0] / sizeof arr[0][0] << endl;
    // 这就是两行三列的数组.


    // 查看二维数组的首地址:
    cout << "二维数组的首地址 " << arr << endl;
    cout << "二维数组第一行的首地址 " << arr[0] << endl;
    cout << "二维数组第一个元素首地址" << &arr[0] << endl;
    // 首地址和第一行和第一个元素的首地址都是一样的.

    cout << "第二行 " << arr[1] << endl; // 差12个.
















}


int main() {
//    _2d_array_definite();
    _2d_array_name();

    return 0;
}