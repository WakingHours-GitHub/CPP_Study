//
// Created by NUC on 2023/5/13.
//

#include "boss.h"


string Boss::getDeptName() {
    return string("ÀÏ°å");
}

Boss::Boss(int id, string name, int did) {
    this->id = id;
    this->name = name;
    this->departmentId = did;
}