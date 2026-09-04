#pragma once

#include <array>
#include <random>

struct Point
{
    double x{};
    double y{};
};

class PointModel
{
public:
    static constexpr std::size_t PointCount = 1024;

    PointModel();

    void generate();

    const std::array<Point, PointCount> &points() const noexcept;

private:

    std::array<Point, PointCount> m_points{};

    std::mt19937 m_rng;

    std::uniform_real_distribution<double> m_distribution{0.0, 1.0};
};
