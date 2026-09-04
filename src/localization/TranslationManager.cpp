#include "TranslationManager.h"

#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

TranslationManager::TranslationManager(QObject *parent)
    : QObject(parent)
{
}

Language TranslationManager::language() const noexcept
{
    return m_language;
}

bool TranslationManager::setLanguage(Language language)
{
    if (language == m_language)
        return true;

    QCoreApplication::removeTranslator(&m_translator);

    if (language == Language::Russian)
    {
        const bool loaded =
            m_translator.load(":/translations/app_ru.qm");

        qDebug() << "Loading Russian translation:"
                 << loaded;

        if (!loaded)
        {
            // Restore previous state if translation cannot be loaded.
            if (m_language == Language::Russian)
                QCoreApplication::installTranslator(&m_translator);

            return false;
        }

        QCoreApplication::installTranslator(&m_translator);
    }

    m_language = language;

    QSettings settings;
    settings.setValue(
        "language",
        language == Language::Russian ? "ru" : "en");

    Q_EMIT languageChanged(m_language);

    return true;
}