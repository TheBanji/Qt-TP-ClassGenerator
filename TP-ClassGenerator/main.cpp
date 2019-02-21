#include <QApplication>
#include "window.h"

int main (int argc, char *argv[]) {
    QApplication app(argc, argv);
    window fenetre;
    fenetre.show();
    return app.exec();
}
