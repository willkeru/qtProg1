#pragma once

#include <QObject>
#include <QTranslator>

#include "Language.h"

class TranslationManager : public QObject
{
    Q_OBJECT

public:
    explicit TranslationManager(QObject* parent = nullptr);

    Language language() const noexcept;

    bool setLanguage(Language language);

Q_SIGNALS:
    void languageChanged(Language language);

private:
    QTranslator m_translator;
    Language m_language{Language::English};
};