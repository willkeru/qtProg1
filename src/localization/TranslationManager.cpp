#include "TranslationManager.h"

TranslationManager::TranslationManager(QApplication &application)
    : m_application(application)
{ }

bool TranslationManager::setLanguage(const QString &language)
{
    m_application.removeTranslator(&m_translator);

    if (language.isEmpty())
        return true;

    if (!m_translator.load(
            QString(":/translations/app_%1.qm").arg(language)))
    {
        return false;
    }

    m_application.installTranslator(&m_translator);

    return true;
}
