#pragma once

#include <QObject>

class QMainWindow;
class QMenu;
class QAction;

class MenuController : public QObject
{
    Q_OBJECT

public:
    explicit MenuController(QMainWindow *window);

Q_SIGNALS:
    void openRequested();
    void aboutRequested();

private:
    void createMenus(QMainWindow *window);

    QMenu *m_fileMenu{};
    QMenu *m_helpMenu{};

    QAction *m_openAction{};
    QAction *m_exitAction{};
    QAction *m_aboutAction{};
};
