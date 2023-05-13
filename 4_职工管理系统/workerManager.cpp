//
// Created by NUC on 2023/5/12.
//

#include "workerManager.h"


// 具体函数实现:

void WorkerManager::showMenu() { // 成员函数
    cout << "**********************" << endl;
    cout << "**欢迎使用职工管理系统!**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**0. 退出管理系统**" << endl;
    cout << "**********************" << endl;



}

void WorkerManager::exitSystem() {
    cout << "欢迎下次使用" << endl;
//    system("pause");
    exit(0); // 正常退出程序, 参数表示标识符.
}


WorkerManager::WorkerManager() {

}

WorkerManager::~WorkerManager() {

}