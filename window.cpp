#include "window.h"

Window::Window (QWidget *parent) : QMainWindow (parent),ui (new Ui::Window)
{
    ui->setupUi(this);
    p=0;
    laser=0;
}

Window::~Window(){
    delete ui;
}


void Window::on_fixed_frame_clicked()
{
    QString odometryFilename = QFileDialog::getOpenFileName(this,tr("Open ODOMETRY log file"),"~",tr("All files (*.*)"));
    if(odometryFilename.length()>0){
        QStringList l = odometryFilename.split("/");
        p = new Path(odometryFilename.toStdString());
        p->color.r=1.0f;
        this->ui->Scene->_drawables.push_back(p);
    }
    else{
        std::cout <<"[BUTTON 1][ON FILE OPEN] no file selected"<<std::endl;
    }
}

void Window::on_target_frame_clicked()
{
    QString odometryFilename = QFileDialog::getOpenFileName(this,tr("Open ODOMETRY log file"),"~",tr("All files (*.*)"));
    if(odometryFilename.length()>0){
        QStringList l = odometryFilename.split("/");
        laser = new Path(odometryFilename.toStdString());
        laser->color.r=1.0f;
        laser->color.g=1.0f;
        this->ui->Scene->_drawables.push_back(laser);
    }
    else{
        std::cout <<"[BUTTON 2][ON FILE OPEN] no file selected"<<std::endl;
    }
}

void Window::on_t_x_valueChanged(double arg1)
{
    if(laser==0)return;
    laser->transform.translation().x()=(float)arg1;
    this->ui->Scene->updateGL();
}

void Window::on_t_y_valueChanged(double arg1)
{
    if(laser==0)return;
    laser->transform.translation().y()=(float)arg1;
    this->ui->Scene->updateGL();
}

void Window::on_t_z_valueChanged(double arg1)
{
    if(laser==0)return;
    laser->transform.translation().z()=(float)arg1;
    this->ui->Scene->updateGL();
}

void Window::on_r_x_valueChanged(double arg1)
{
    if(laser==0)return;
    Eigen::Matrix3f m;
    m = Eigen::AngleAxisf(arg1, Eigen::Vector3f::UnitX())
            * Eigen::AngleAxisf(this->ui->r_y->value(),  Eigen::Vector3f::UnitY())
            * Eigen::AngleAxisf(this->ui->r_z->value(), Eigen::Vector3f::UnitZ());

    laser->transform.linear() = m;
    this->ui->Scene->updateGL();
}

void Window::on_r_y_valueChanged(double arg1)
{
    if(laser==0)return;
    Eigen::Matrix3f m;
    m = Eigen::AngleAxisf(this->ui->r_x->value(), Eigen::Vector3f::UnitX())
            * Eigen::AngleAxisf(arg1,  Eigen::Vector3f::UnitY())
            * Eigen::AngleAxisf(this->ui->r_z->value(), Eigen::Vector3f::UnitZ());

    laser->transform.linear() = m;
    this->ui->Scene->updateGL();
}

void Window::on_r_z_valueChanged(double arg1)
{
    if(laser==0)return;
    Eigen::Matrix3f m;
    m = Eigen::AngleAxisf(this->ui->r_x->value(), Eigen::Vector3f::UnitX())
            * Eigen::AngleAxisf(this->ui->r_y->value(),  Eigen::Vector3f::UnitY())
            * Eigen::AngleAxisf(arg1, Eigen::Vector3f::UnitZ());

    laser->transform.linear() = m;
    this->ui->Scene->updateGL();
}

void Window::on_print_clicked()
{
    std::cout<<"Translation:"<<std::endl;
    std::cout<< laser->transform.translation().transpose()<<std::endl<< std::endl;
    std::cout<<"Rotation quaternion:"<<std::endl;
    std::cout<<  Eigen::Quaternionf(laser->transform.linear()).x()<< " "
                 <<Eigen::Quaternionf(laser->transform.linear()).y()<< " "
                 <<Eigen::Quaternionf(laser->transform.linear()).z()<< " "
                 <<Eigen::Quaternionf(laser->transform.linear()).w()<< std::endl<< std::endl;

    Eigen::Vector3f ea = laser->transform.linear().matrix().eulerAngles(0, 1, 2);
    std::cout<<"RPY:"<<std::endl;
    std::cout<<ea.transpose()<<std::endl<< std::endl;
}

void Window::on_reset_button_clicked()
{
    if(laser==0)return;
    laser->transform.translation().x()=0.0f;
    laser->transform.translation().y()=0.0f;
    laser->transform.translation().z()=0.0f;
    Eigen::Matrix3f m;
    m = Eigen::AngleAxisf(0.0f, Eigen::Vector3f::UnitX())
            * Eigen::AngleAxisf(0.0f,  Eigen::Vector3f::UnitY())
            * Eigen::AngleAxisf(0.0f, Eigen::Vector3f::UnitZ());

    laser->transform.linear() = m;
    this->ui->Scene->updateGL();
}
