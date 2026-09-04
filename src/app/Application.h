#pragma once

#include <QApplication>

#include "../localization/TranslationManager.h"

class Application
{
public:
    Application(int& argc, char** argv);

    int run();

private:
    QApplication m_application;
    TranslationManager m_translationManager;
};