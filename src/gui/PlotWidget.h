#pragma once

#include <QOpenGLWidget>

#include "../model/PointModel.h"

class PlotWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit PlotWidget(QWidget *parent = nullptr);

    void regenerate();

protected:
    void initializeGL() override;
    void resizeGL(int width, int height) override;
    void paintGL() override;

private:
    PointModel m_model;
};