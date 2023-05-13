//
// Created by NUC on 2023/5/13.
//
#pragma
#ifndef CPP_STUDY_MANAGER_H
#define CPP_STUDY_MANAGER_H


#include "worker.h"

using namespace std;

class Manager: public worker {
public:
    virtual string getDeptName();

    Manager(int id, string name, int did);
};


#endif //CPP_STUDY_MANAGER_H
