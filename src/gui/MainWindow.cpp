#include "MainWindow.h"

#include "PlotWidget.h"
#include "../menus/MenuController.h"

#include <QMessageBox>
#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Qt Curve Demo"));

    resize(800, 600);

    /*
     * Центральная область.
     */
    m_plotWidget = new PlotWidget(this);
    setCentralWidget(m_plotWidget);

    /*
     * Нижняя информационная строка.
     *
     * QAction::statusTip() будет автоматически
     * отображаться здесь.
     */
    statusBar()->showMessage(
        tr("Ready"));

    /*
     * Меню.
     */
    m_menuController = new MenuController(this);

    connect(
        m_menuController,
        &MenuController::openRequested,
        this,
        &MainWindow::open);

    connect(
        m_menuController,
        &MenuController::aboutRequested,
        this,
        &MainWindow::about);
}

void MainWindow::open()
{
    /*
     * В дальнейшем здесь можно будет открыть файл.
     * Пока Open просто генерирует новую кривую.
     */
    m_plotWidget->regenerate();

    statusBar()->showMessage(
        tr("New random curve generated"),
        2000);
}

void MainWindow::about()
{
    QMessageBox::about(
        this,
        tr("About"),
        tr(
            "Qt Curve Demo\n\n"
            "A simple Qt 6 / C++ application "
            "with OpenGL accelerated rendering."));
}
