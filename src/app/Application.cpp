#include "Application.h"
#include <QSurfaceFormat>

#include "../gui/MainWindow.h"

Application::Application(int &argc, char **argv)
    : m_application(argc, argv)
{
}

int Application::run()
{
    QSurfaceFormat format;
    format.setSamples(4);

    QSurfaceFormat::setDefaultFormat(format);

    MainWindow window;

    window.show();

    return m_application.exec();
}
