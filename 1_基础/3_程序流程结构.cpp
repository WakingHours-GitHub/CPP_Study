//
// Created by NUC on 2023/3/16.
//

#include<iostream>
#include<string>

using namespace std;

/*
    ˳��ṹ, ѡ��ṹ, ѭ���ṹ.
    ѭ���ṹ: ����˳��ִ��, ��������ת.
    ѡ��ṹ: ���������Ƿ�����, ��ѡ���Ե�ִ����Ӧ�Ĺ���.
    ѭ���ṹ: ���������Ƿ�����, ѭ�����ִ��ĳ�δ���.

    ѡ��ṹ:
    if���: ִ���������������.
    if��������ʽ: ���и�ʽif���, ���и�ʽ��if���, ��������if���.
    ����if�﷨:
        if(�������ʽ) {
            ���ʽ����ִ�е����.
        }
    ����if�﷨:
        if (�������ʽ){
            ������ʽִ�е����
        }else{
            ��������ʽ ִ�е����.
        }
    ������if���:
        if (����){
            ����1�����ִ��
        }else if(������){ // python������elif ���ʽ :
            ����һ������, ������������. ִ��
        }...{
            �ȵ�.
        }else{ // ������ϵ�����ȫ������, ��ô�����һ��else���а���, ���else���п���.
            ��������ִ�е����.
        }

    Ƕ��if��䣺

    ��Ŀ�����: ͨ����Ŀ�����ʵ�ּ򵥵��߼��ж�.
        �������ʽ? ���ʽ1: ���ʽ2
        �����������ʽ��ֵ, ���Ϊtrue, ��ִ�б��ʽ1. ���Ϊfalse��ִ�б��ʽ2.
        ���ҽ����ʽ�Ľ������. ͬʱ���Է���һ������, Ȼ�����������ʹ��.





 */

void if_study(){
    // ѡ��ṹ, ����if���.
    // �û��������, �������>600, ����Ļ�����
    int score = 0;
    cout << "�������㿼�÷���" << endl;
    cin >> score;
    cout << score << endl;
    // ע������: if�������治Ҫ���Ϸֺ�. �����;��ʾһ�����Ľ���.
    if (score >= 640) {
        cout << "�����迼����һ����ѧ. " << endl;
    }

    if (score >= 600) {
        cout << "�㿼����һ����ѧ" << endl;
    } else {
        cout << "��û�п��ϴ�ѧ" << endl;
    }

    // ��������if���.
    if (score >= 600) {
        cout << "������һ����ѧ" << endl;
    } else if (score >= 400) { // 400 <= x <= 600
        cout << "�����˶�����ѧ" << endl;
    } else if (score >= 300) {
        cout << "��ϲ��������������ѧ" << endl;
    } else {
        cout << "�����Ǵ�������, ��û���ϴ�ѧ" << endl;
    }

    // Ƕ��if���.
    if (score >= 600) {
        // Ƕ�׽��л���.
        if (score >= 650) {
            cout << "�㿼�����廪" << endl;
        }else if (score >= 600) {
            cout << "�㿼���˱���" << endl;
        }else{
            cout << "�㿼�����˴�" << endl;
        }
    }else if (score >= 500){
        cout << "�㿼���˶���" << endl;
    }else if (score >= 400) {
        cout << "�㿼����������ѧ" << endl;
    }else{
        cout << "��û����!" << endl;
    }

}

void instance(){ // ����.
    // ������ֻС������
    int num1 = 0, num2 = 0, num3 = 0;
    cin >> num1;
    cin >> num2;
    cin >> num3;
    cout << num1<< " "<< " " << num2 << " " << num3 << endl;

    if (num1 > num2) {
        if (num1 > num3){
            cout << "С��A����: " << num1 << endl;
        }else{
            cout << "С��C����: " << num3 << endl;
        }
    }else{
        if (num2 > num3){
            cout << "С��B����: " << num2 << endl;
        }else{
            cout << "С��C����: " << num3 << endl;
        }
    }





}

void third_operator(){
    // ��Ŀ�����.
    // ������������, a, b, c.
    int a = 10, b = 20, c = 0;
    c = (a > b ? a : b);
    cout << c << endl;

    // ��C++��, ��Ŀ��������ص��Ǳ���, ���Լ�����ֵ.
    (a>b?a:b) = 100; // ˭��, �͸�˭��ֵ100.
    // ��Ŀ������Ľ�����Է���һ������, ���Լ�����ֵ.
    cout << b << endl; // 100

}

void switch_construct(){
    /*

        switch(���ʽ){
            case ���1: ִ�����; break;
            case ���2: ִ�����; break;
            ...
            default: ִ�����; break;
        }
        ���ݱ��ʽ�Ľ��, ��ȥѡ���֧(case����Ľ��), Ȼ��ִ�����, ���ͨ��break����.
        ���case��û��, ��ô�����default ִ�к�������.

        // ������ʽֻ������, ����int �Լ�char. �ַ���Ҳ����. ������һ������.
        �ŵ�ṹ����, ִ��Ч�ʸ�.
        �����дbreak, ������һֱ����ִ��.

     */

    // ��һ����Ӱ��ֵĲ���
    // 10~9: ����.

    int score = 0; // definite

    cin >> score; // cin score.
    cout << "�������ķ���: " << score << endl;

    switch (score) { // ������ʽֻ������, ����int �Լ�char. �ַ���Ҳ����.
        case 10:
        case 9:
            cout << "����!" << endl;
            break;
        case 8:
        case 7:
            cout << "�߷�!" << endl;
            break;
        case 6:
        case 5:
            cout << "һ��" << endl;
            break; // �����дbreak, ������һֱ����ִ��.
        default: // ���ǰ�漸����������, ��������default.
            cout << "��Ƭ" << endl;
            break;
    }
}

int main() {
//    instance();

//    third_operator();

    switch_construct();
    return 0;
}