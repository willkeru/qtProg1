# QtCurveDemo

A small modular desktop application written in **C++17** using **Qt 6**.

The application generates and displays a curve based on 10 randomly generated points.  
Selecting **File → Open** generates a new random curve.

The project is intended as a simple example of a structured Qt application with separated model, GUI, menu, and application layers.

## Features

- Qt 6 desktop application
- C++17
- Modular project structure
- 10 randomly generated points
- Random curve regeneration
- OpenGL-backed rendering using `QOpenGLWidget`
- Antialiased drawing with `QPainter`
- Main menu:
  - **File → Open** — generate a new random curve
  - **File → Exit** — exit the application
  - **Help → About** — application information
- Status bar messages for menu actions
- CMake build system
- Ninja build support
- Prepared structure for application localization


## Requirements

### Operating system

The project should work on Linux systems with a recent Qt 6 installation.

The development environment used for the project:

- Debian 13
- GCC
- CMake
- Ninja
- Qt 6
- Visual Studio Code

### Dependencies

Install the required packages on Debian:

```bash
sudo apt update

sudo apt install \
    build-essential \
    cmake \
    ninja-build \
    qt6-base-dev \
    qt6-base-dev-tools \
    libxkbcommon-dev \
    libxkbcommon-x11-dev \
    gdb
