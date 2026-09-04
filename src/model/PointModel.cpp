#include "PointModel.h"

#include <random>

PointModel::PointModel()
    : m_rng(std::random_device{}())
{
    generate();
}

void PointModel::generate()
{
    int num{};
    const float count = m_points.size()+1;
    for (auto &point : m_points)
    {
        point.x = ++num/count; //m_distribution(m_rng);
        point.y = m_distribution(m_rng);
    }
}

const std::array<Point, PointModel::PointCount> &PointModel::points() const noexcept
{
    return m_points;
}