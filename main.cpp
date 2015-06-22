#include <QApplication>
#include "window.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Window Window;
    Window.show();
    return app.exec();
}
