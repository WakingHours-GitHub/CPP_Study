//
// Created by NUC on 2023/5/13.
//

#pragma once

#ifndef CPP_STUDY_WORKER_H
#define CPP_STUDY_WORKER_H

#include <iostream>
#include <string>

using namespace std;

class worker {
public:



    // 显示个人信息
    virtual void showInfo(){
        cout << "id: " << id << ", name: " << name << ", departmentID: " << getDeptName() << endl;
    }

    virtual string getDeptName() = 0;


    // 个人信息
    int id;
    string name;
    int departmentId;



};


#endif //CPP_STUDY_WORKER_H
