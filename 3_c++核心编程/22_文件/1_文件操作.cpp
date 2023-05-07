//
// Created by NUC on 2023/5/6.
//

#include<iostream>
#include<fstream> // ����ͷ�ļ�
#include<string>
using namespace std;

/*
    ͨ���ļ����Խ����ݳ־û�
    C++���ļ�������Ҫ����ͷ�ļ�<fstream>
    �ļ����ͷ�Ϊ����:
        �ı��ļ�:   ��ASCII����ʽ�洢
        �������ļ�:  �Զ�������ʽ�洢�ڼ������.
    �����ļ�������:
        ofstream: д����
        ifstream: ������
        fstream : ��д����

    �ı��ļ�:
    д�ļ�:
        ����ͷ�ļ�: #include<fstream>
        ����������: ofstream ofs;
        ���ļ�: ofs.open("�ļ�·��", �򿪷�ʽ);
        д����: ofs << "д�������";
        �ر��ļ�: ofs.close();
    �ļ��򿪷�ʽ:
        ios::in     ���ļ�
        ios::out    д�ļ�
        ios::ate    ��ʼλ��: �ļ�β
        ios::app    ׷�ӷ�ʽд�ļ�
        ios::trunc  ����ļ�����, ��ɾ��, �ٴ��� (���´���)
        ios::binary �����Ʒ�ʽ.
    �ļ��򿪷�ʽ�������ʹ��, ����|������.
    ���ö����Ʒ�ʽд�ļ�: ios::binary | ios::out

 */

// д�ļ�
void test01(){
    // ����������
    ofstream ofs;
    // ָ���򿪷�ʽ
    ofs.open("./test.txt", ios::out); // out: ���� -> file. ������out

    // 4. Щ����
    ofs << "���׵�һ" << endl;
    ofs << "���׵Ķ�" << endl;
    ofs << "���׵���" << endl;

    // �ر��ļ�:
    ofs.close();


}

// ���ļ�
void test02(){
    ifstream ifs; // ������������

    // ���ļ�
    ifs.open("./test.txt", ios::in); // in, file->program
    if (!ifs.is_open()){ // �ж��Ƿ�򿪳ɹ�
        cout << "file open failure" << endl;
        return;
    }

    // ��ȡ����:
    // ��һ��
    char buf[1024] = {0};
    while (ifs >> buf) { // ָ��.
        cout << buf << endl;
    }

    // �ڶ���:
    char buf2[1024] = {0};
    // ifs.getline(�������, count��С)
    while(ifs.getline(buf2, sizeof buf2)){
        cout << buf2 << endl;
    }

    // ������:
    string buf3;
    // getline(ifs, string_buf)
    while (getline(ifs, buf3)){
        cout << buf3 << endl;
    }

    // ������: // һ��һ����
    char c;
    while((c = ifs.get()) != EOF ){ // ���û�ж�ȡEOF�����ļ���β��־.
        cout << c; // Ч�ʵ�.
    }



    ifs.close(); // �ر�.

}

int main() {
//    test01();
    test02();

    return 0;
}