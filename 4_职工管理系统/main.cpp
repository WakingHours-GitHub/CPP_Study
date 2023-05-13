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
//    // 测试代码:
//    worker *w = NULL;
//    w = new Manager(1, "张三", 1);
//    w->showInfo();

    WorkerManager wm; // 隐式调用.

    int choice = 0;

    while (1) {
        wm.showMenu();

        cout << "请输入您的选择: " << endl;
        cin >> choice; // 存储用户.

        switch (choice) {
            case 0: // 退出系统
                wm.exitSystem();
                break;
            case 1: // 增加职工


                break;
            case 2: // 显示职工

                break;
            case 3: // 删除职工

                break;
            case 4: // 修改职工

                break;
            case 5: // 排序职工

                break;
            case 6: // 排序

                break;
            case 7: // 清空文档

                break;


        }

    }


    return 0;
}