//
// Created by NUC on 2023/5/6.
//

#include<iostream>
#include<fstream> // 包含头文件
#include<string>
using namespace std;

/*
    通过文件可以将数据持久化
    C++对文件操作需要包含头文件<fstream>
    文件类型分为两种:
        文本文件:   以ASCII码形式存储
        二进制文件:  以二进制形式存储在计算机中.
    操作文件三大类:
        ofstream: 写操作
        ifstream: 读操作
        fstream : 读写操作

    文本文件:
    写文件:
        包含头文件: #include<fstream>
        创建流对象: ofstream ofs;
        打开文件: ofs.open("文件路径", 打开方式);
        写数据: ofs << "写入的数据";
        关闭文件: ofs.close();
    文件打开方式:
        ios::in     读文件
        ios::out    写文件
        ios::ate    初始位置: 文件尾
        ios::app    追加方式写文件
        ios::trunc  如果文件存在, 先删除, 再创建 (重新创建)
        ios::binary 二进制方式.
    文件打开方式可以配合使用, 利用|操作符.
    利用二进制方式写文件: ios::binary | ios::out

 */

// 写文件
void test01(){
    // 创建流对象
    ofstream ofs;
    // 指定打开方式
    ofs.open("./test.txt", ios::out); // out: 程序 -> file. 所以是out

    // 4. 些内容
    ofs << "离谱的一" << endl;
    ofs << "离谱的二" << endl;
    ofs << "离谱的三" << endl;

    // 关闭文件:
    ofs.close();


}

// 读文件
void test02(){
    ifstream ifs; // 创建读流对象

    // 打开文件
    ifs.open("./test.txt", ios::in); // in, file->program
    if (!ifs.is_open()){ // 判断是否打开成功
        cout << "file open failure" << endl;
        return;
    }

    // 读取数据:
    // 第一种
    char buf[1024] = {0};
    while (ifs >> buf) { // 指针.
        cout << buf << endl;
    }

    // 第二种:
    char buf2[1024] = {0};
    // ifs.getline(存放在哪, count大小)
    while(ifs.getline(buf2, sizeof buf2)){
        cout << buf2 << endl;
    }

    // 第三种:
    string buf3;
    // getline(ifs, string_buf)
    while (getline(ifs, buf3)){
        cout << buf3 << endl;
    }

    // 第四种: // 一个一个读
    char c;
    while((c = ifs.get()) != EOF ){ // 如果没有读取EOF就是文件结尾标志.
        cout << c; // 效率低.
    }



    ifs.close(); // 关闭.

}

int main() {
//    test01();
    test02();

    return 0;
}