#include "PlotWidget.h"

#include <QPainter>
#include <QPainterPath>

PlotWidget::PlotWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
    setMinimumSize(200, 150);

    /*
     * Просим Qt использовать OpenGL framebuffer.
     * QOpenGLWidget сам управляет OpenGL context.
     */
}

void PlotWidget::regenerate()
{
    m_model.generate();

    // Запрашиваем перерисовку.
    update();
}

void PlotWidget::initializeGL()
{
    glClearColor(0.08f, 0.08f, 0.10f, 1.0f);
}

void PlotWidget::resizeGL(int width, int height)
{
    glViewport(0, 0, width, height);
}

void PlotWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);

    const QRectF area = rect().adjusted( 8, 8, -8, -8);

    painter.setPen(QPen(Qt::gray, 1.0));

    painter.drawRect(area);

    const auto &points = m_model.points();

    if (points.empty())
        return;

    /*
     * Переводим нормализованные координаты
     * [0..1] в координаты окна.
     *
     * Ось Y инвертируется, поскольку Qt
     * использует начало координат сверху.
     */

    auto toScreen = [&](const Point &p)
    {
        return QPointF(
            area.left() + p.x * area.width(),
            area.bottom() - p.y * area.height());
    };

    /*
     * Кривая через 10 точек.
     */

    QPainterPath path;

    path.moveTo(toScreen(points[0]));

    for (std::size_t i = 1; i < points.size(); ++i)
    {
        path.lineTo(toScreen(points[i]));
    }

    painter.setPen(
        QPen(
            QColor(80, 180, 255),
            1.5,
            Qt::SolidLine
            // Qt::RoundCap,
            // Qt::RoundJoin
        ));

    painter.drawPath(path);

    painter.setBrush(QColor(255, 180, 60));
    painter.setPen(Qt::NoPen);

    constexpr double radius = 2.5;

    for (const auto &point : points)
    {
        const QPointF p = toScreen(point);

        painter.drawEllipse(
            p,
            radius,
            radius);
    }
}
