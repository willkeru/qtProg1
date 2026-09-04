#include "MenuController.h"

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QActionGroup>

MenuController::MenuController(QMainWindow *window)
    : QObject(window), m_window(window)
{
    createMenus(window);
}

void MenuController::createMenus(QMainWindow *window)
{
    auto *menuBar = window->menuBar();

    m_fileMenu = menuBar->addMenu(QString());

    m_helpMenu = menuBar->addMenu(QString());

    m_languageMenu = m_helpMenu->addMenu(QString());

    m_openAction = m_fileMenu->addAction(QString());
    m_exitAction = m_fileMenu->addAction(QString());

    m_aboutAction = m_helpMenu->addAction(QString());

    m_englishAction = m_languageMenu->addAction(QString());
    m_russianAction = m_languageMenu->addAction(QString());

    m_languageGroup = new QActionGroup(this);
    m_languageGroup->setExclusive(true);

    m_languageGroup->addAction(m_englishAction);
    m_languageGroup->addAction(m_russianAction);

    m_englishAction->setCheckable(true);
    m_russianAction->setCheckable(true);

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
        m_window,
        &QWidget::close);

    connect(
        m_languageGroup,
        &QActionGroup::triggered,
        this,
        [this](QAction *action)
        {
            if (action == m_englishAction)
            {
                Q_EMIT languageChanged(Language::English);
            }
            else if (action == m_russianAction)
            {
                Q_EMIT languageChanged(Language::Russian);
            }
        });

    retranslateUi();
}

void MenuController::setLanguage(Language language)
{
    const bool russian =
        language == Language::Russian;

    m_russianAction->setChecked(russian);
    m_englishAction->setChecked(!russian);
}

void MenuController::retranslateUi()
{
    m_fileMenu->setTitle(tr("File"));
    m_helpMenu->setTitle(tr("Help"));
    m_languageMenu->setTitle(tr("Language"));

    m_openAction->setText(tr("Open"));
    m_openAction->setStatusTip(
        tr("Generate a new set of random points"));

    m_exitAction->setText(tr("Exit"));
    m_exitAction->setStatusTip(
        tr("Exit the application"));

    m_aboutAction->setText(tr("About"));
    m_aboutAction->setStatusTip(
        tr("About this application"));

    m_englishAction->setText(tr("English"));
    m_russianAction->setText(tr("Russian"));
}