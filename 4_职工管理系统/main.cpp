//
// Created by NUC on 2023/5/12.
//
#include <iostream>
#include "workerManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"


using namespace std;


int main() {
//    // ���Դ���:
//    worker *w = NULL;
//    w = new Manager(1, "����", 1);
//    w->showInfo();

    WorkerManager wm; // ��ʽ����.

    int choice = 0;

    while (1) {
        wm.showMenu();

        cout << "����������ѡ��: " << endl;
        cin >> choice; // �洢�û�.

        switch (choice) {
            case 0: // �˳�ϵͳ
                wm.exitSystem();
                break;
            case 1: // ����ְ��


                break;
            case 2: // ��ʾְ��

                break;
            case 3: // ɾ��ְ��

                break;
            case 4: // �޸�ְ��

                break;
            case 5: // ����ְ��

                break;
            case 6: // ����

                break;
            case 7: // ����ĵ�

                break;


        }

    }


    return 0;
}