#include "MainWindow.h"

#include "PlotWidget.h"
#include "../localization/TranslationManager.h"
#include "../menus/MenuController.h"

#include <QMessageBox>
#include <QStatusBar>

MainWindow::MainWindow(
    TranslationManager* translationManager,
    QWidget* parent
)
    : QMainWindow(parent)
{
    resize(800, 600);

    m_plotWidget = new PlotWidget(this);
    setCentralWidget(m_plotWidget);

    m_menuController = new MenuController(this);

    connect(
        m_menuController,
        &MenuController::openRequested,
        this,
        &MainWindow::open
    );

    connect(
        m_menuController,
        &MenuController::aboutRequested,
        this,
        &MainWindow::about
    );

    connect(
        m_menuController,
        &MenuController::languageChanged,
        translationManager,
        &TranslationManager::setLanguage
    );

    connect(
        translationManager,
        &TranslationManager::languageChanged,
        m_menuController,
        &MenuController::retranslateUi
    );

    connect(
        translationManager,
        &TranslationManager::languageChanged,
        this,
        &MainWindow::retranslateUi
    );

    retranslateUi();
}

void MainWindow::open()
{
    m_plotWidget->regenerate();

    statusBar()->showMessage(
        tr("New random curve generated"),
        2000
    );
}

void MainWindow::about()
{
    QMessageBox::about(
        this,
        tr("About"),
        tr(
            "Qt Curve Demo\n\n"
            "A simple Qt 6 / C++ application "
            "with OpenGL accelerated rendering."
        )
    );
}

void MainWindow::retranslateUi()
{
    setWindowTitle(tr("Qt Curve Demo"));

    statusBar()->showMessage(
        tr("Ready")
    );
}