#pragma once

#include <QObject>

#include "../localization/Language.h"

class QMainWindow;
class QMenu;
class QAction;
class QActionGroup;

class MenuController : public QObject
{
    Q_OBJECT

public:
    explicit MenuController(QMainWindow *window);

public Q_SLOTS:
    void retranslateUi();
    void setLanguage(Language language);

Q_SIGNALS:
    void openRequested();
    void aboutRequested();
    void languageChanged(Language language);

private:
    void createMenus(QMainWindow *window);

    QMainWindow *m_window{};

    QMenu *m_fileMenu{};
    QMenu *m_helpMenu{};
    QMenu *m_languageMenu{};

    QAction *m_openAction{};
    QAction *m_exitAction{};
    QAction *m_aboutAction{};

    QAction *m_englishAction{};
    QAction *m_russianAction{};

    QActionGroup *m_languageGroup{};
};