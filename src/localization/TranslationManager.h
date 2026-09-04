#pragma once

#include <QApplication>
#include <QTranslator>

class TranslationManager
{
public:
    explicit TranslationManager(QApplication &application);

    bool setLanguage(const QString &language);

private:
    QApplication &m_application;
    QTranslator m_translator;
};
