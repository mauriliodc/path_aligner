#include "path.h"


Path::Path(){

}

Path::Path(std::string filename){
    std::ifstream infile(filename.c_str());
    int i =0;
    while(!infile.eof())
    {
        float secs,nsecs,x,y,theta,w;
        std::string frameid;
        infile >> secs;
        infile >> nsecs;
        infile >> frameid;
        infile >> x;
        infile >> y;
        infile >> theta;
        infile >> w;
        if(i==0){
            this->transform.translation()<<x,y,0;
            Eigen::Vector4f rot(0,0,theta,w);
            this->transform.linear() = Eigen::Quaternionf(rot.w(),rot.x(),rot.y(),rot.z()).toRotationMatrix();
        }
        this->poses.push_back(transform.inverse()*Eigen::Vector3f(x,y,0));

        i++;
    }
    this->transform=Eigen::Matrix4f::Identity();
    std::cout<< "readen "<<i<<" poses"<<std::endl;
}


Path::~Path(){

}

void Path::draw(){
    glColor3f(color.r,color.g,color.b);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for(int i =0;i<poses.size();i++){
        Eigen::Vector3f v = poses.at(i);
        v=transform.inverse()*v;
        glVertex3f(v.x(),v.y(),v.z());
    }
    glEnd();
    glColor3f(1.0f,1.0f,1.0f);
}
