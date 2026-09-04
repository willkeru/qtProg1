#pragma once

#include <QMainWindow>
#include "../localization/Language.h"

class PlotWidget;
class MenuController;
class TranslationManager;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(
        TranslationManager* translationManager,
        QWidget* parent = nullptr
    );

private Q_SLOTS:
    void open();
    void about();
    void retranslateUi();

private:
    PlotWidget* m_plotWidget{};
    MenuController* m_menuController{};
};
