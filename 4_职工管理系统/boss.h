//
// Created by NUC on 2023/5/13.
//

#ifndef CPP_STUDY_BOSS_H
#define CPP_STUDY_BOSS_H

#include "worker.h"


class Boss: public worker {
public:
    virtual string getDeptName();

    Boss(int id, string name, int did);
};


#endif //CPP_STUDY_BOSS_H
