cmake_minimum_required(VERSION 3.24)

project(QtCurveDemo
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    OpenGL
    OpenGLWidgets
    LinguistTools
)

qt_add_executable(QtCurveDemo
    src/main.cpp

    src/app/Application.h
    src/app/Application.cpp

    src/gui/MainWindow.h
    src/gui/MainWindow.cpp
    src/gui/PlotWidget.h
    src/gui/PlotWidget.cpp

    src/menus/MenuController.h
    src/menus/MenuController.cpp

    src/localization/Language.h
    src/localization/TranslationManager.h
    src/localization/TranslationManager.cpp

    src/model/PointModel.h
    src/model/PointModel.cpp
)

qt_add_translations(QtCurveDemo
    TS_FILES
        resources/translations/app_ru.ts
        resources/translations/app_en.ts
    RESOURCE_PREFIX "/translations"
)

target_link_libraries(QtCurveDemo
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)

target_compile_definitions(QtCurveDemo
    PRIVATE
    QT_NO_KEYWORDS
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(QtCurveDemo PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()
