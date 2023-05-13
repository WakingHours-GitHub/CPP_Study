//
// Created by NUC on 2023/5/13.
//

#pragma once

#ifndef CPP_STUDY_EMPLOYEE_H
#define CPP_STUDY_EMPLOYEE_H


#include <iostream>
#include "worker.h"

class Employee: public worker{
public:
    virtual string getDeptName();

    Employee(int id, string name, int did);

};


#endif //CPP_STUDY_EMPLOYEE_H
