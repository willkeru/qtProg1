#include "Application.h"
#include <QSurfaceFormat>

#include "../gui/MainWindow.h"

#include <QSettings>

Application::Application(int& argc, char** argv)
    : m_application(argc, argv)
    , m_translationManager(&m_application)
{
}

int Application::run()
{
    QSurfaceFormat format;
    format.setSamples(4);

    QSettings settings;

    const QString language =
        settings.value("language", "en").toString();

    if (language == "ru")
    {
        m_translationManager.setLanguage(
            Language::Russian
        );
    }

    MainWindow window(&m_translationManager);

    window.show();

    return m_application.exec();
}
