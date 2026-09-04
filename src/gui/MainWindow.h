#pragma once

#include <QMainWindow>

class PlotWidget;
class MenuController;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private Q_SLOTS:
    void open();
    void about();

private:
    PlotWidget *m_plotWidget{};
    MenuController *m_menuController{};
};
