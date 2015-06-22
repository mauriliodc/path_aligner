
#pragma once
#include <QMainWindow>
#include <QFileDialog>
#include <QDoubleSpinBox>
#include "build/ui_window.h"
#include <iostream>

#include "path.h"

namespace Ui
{
  class Window;
}

class Window : public QMainWindow
{
    Q_OBJECT
public:
  explicit Window (QWidget *parent = 0);
  ~Window ();
  Ui::Window *ui;
  Path* p;
  Path* laser;
protected:

private slots:  

  void on_fixed_frame_clicked();
  void on_target_frame_clicked();
  void on_t_x_valueChanged(double arg1);
  void on_t_y_valueChanged(double arg1);
  void on_t_z_valueChanged(double arg1);
  void on_r_x_valueChanged(double arg1);
  void on_r_y_valueChanged(double arg1);
  void on_r_z_valueChanged(double arg1);
  void on_print_clicked();
  void on_reset_button_clicked();
};
