//
// Created by NUC on 2023/5/13.
//

#include "manager.h"

string Manager::getDeptName() {
    return string("¾­Àí");
}

Manager::Manager(int id, string name, int did) {
    this->id = id;
    this->name = name;
    this->departmentId = did;

}