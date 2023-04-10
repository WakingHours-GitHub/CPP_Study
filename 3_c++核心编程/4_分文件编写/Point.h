//
// Created by NUC on 2023/4/10.
//

#pragma once // 检查是否是重复引用了

#ifndef CPP_STUDY_POINT_H
#define CPP_STUDY_POINT_H


class Point {
public:
    void setX(int); // 函数声明
    int getX();
private:
    int x;
    int y;
};


#endif //CPP_STUDY_POINT_H
