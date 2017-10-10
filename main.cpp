#include <QApplication>
#include "View/Window.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Window window;

    window.resize(640, 480);
    window.setWindowTitle("Highlife");
    window.show();

    return app.exec();
}