//
// Created by NUC on 2023/5/13.
//

#include "employee.h"




string Employee::getDeptName() {
    return string("Ô±¹¤");
}

Employee::Employee(int id, string name, int did) {
    this->id = id;
    this->name = name;
    this->departmentId = did;


}




