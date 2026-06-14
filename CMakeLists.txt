cmake_minimum_required(VERSION 3.16)

project(Pinjam_Powerbank VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(appPinjam_Powerbank
    main.cpp
)

qt_add_qml_module(appPinjam_Powerbank
    URI Pinjam_Powerbank
    QML_FILES
        Main.qml
        SOURCES
        SOURCES user.h user.cpp
        SOURCES powerbank.h powerbank.cpp
        SOURCES loan.h loan.cpp
        SOURCES loanmanager.h loanmanager.cpp
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appPinjam_Powerbank PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appPinjam_Powerbank
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appPinjam_Powerbank
    PRIVATE Qt6::Quick
)

install(TARGETS appPinjam_Powerbank
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
