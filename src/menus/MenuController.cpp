#include "MenuController.h"

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>

MenuController::MenuController(QMainWindow *window)
    : QObject(window)
{
    createMenus(window);
}

void MenuController::createMenus(QMainWindow *window)
{
    auto *menuBar = window->menuBar();

    m_fileMenu = menuBar->addMenu(tr("File"));
    m_helpMenu = menuBar->addMenu(tr("Help"));

    m_openAction = m_fileMenu->addAction(tr("Open"));
    m_openAction->setStatusTip(
        tr("Generate a new set of random points"));

    m_exitAction = m_fileMenu->addAction(tr("Exit"));
    m_exitAction->setStatusTip(
        tr("Exit the application"));

    m_aboutAction = m_helpMenu->addAction(tr("About"));
    m_aboutAction->setStatusTip(
        tr("About this application"));

    connect(
        m_openAction,
        &QAction::triggered,
        this,
        &MenuController::openRequested);

    connect(
        m_aboutAction,
        &QAction::triggered,
        this,
        &MenuController::aboutRequested);

    connect(
        m_exitAction,
        &QAction::triggered,
        window,
        &QWidget::close);
}
