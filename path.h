#ifndef PATH_H
#define PATH_H

#include "actor.h"
#include "string.h"
#include <fstream>
#include <iostream>
#include <vector>

class Path : public Actor{
public:
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    Path();
    Path(std::string filename);
    ~Path();

    void draw();

    struct _color{
        float r;
        float g;
        float b;
        float a;
    } color;

    std::vector<Eigen::Vector3f> poses;
};

#endif
