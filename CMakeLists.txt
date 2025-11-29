cmake_minimum_required(VERSION 3.16)

project(akropolis_app VERSION 0.1 LANGUAGES CXX)

include_directories(
    abstract
    jeu
    plateau
    regles
    exceptions
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        # --- JEU ---
        jeu/Partie.cpp
        jeu/Partie.h
        jeu/Joueur.cpp
        jeu/Joueur.h

        # --- PLATEAU (Tout est ici ?) ---
        plateau/Chantier.cpp
        plateau/Chantier.h
        plateau/Cite.cpp
        plateau/Cite.h
        plateau/Hexagone.cpp
        plateau/Hexagone.h
        plateau/Tuile.cpp
        plateau/Tuile.h
        plateau/Coordonnee.cpp
        plateau/Coordonnee.h

        # --- QUARTIERS (Si ils sont dans plateau, on change le chemin) ---
        plateau/Jardin.cpp
        plateau/Jardin.h
        plateau/Caserne.cpp
        plateau/Caserne.h
        plateau/Temple.cpp
        plateau/Temple.h
        plateau/Marche.cpp
        plateau/Marche.h
        plateau/Habitation.cpp
        plateau/Habitation.h
        plateau/Place.h
        plateau/Place.cpp
        plateau/ChaineHabitation.cpp
        plateau/ChaineHabitation.h

        # --- ABSTRACT ---
        abstract/Construction.cpp
        abstract/Construction.h
        abstract/Quartier.h
        abstract/Quartier.cpp

        # --- EXCEPTIONS ---
        exceptions/JoueurException.h
        exceptions/JoueurException.cpp
        exceptions/Recouvrir.cpp
        exceptions/Recouvrir.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(akropolis_app
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET akropolis_app APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(akropolis_app SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(akropolis_app
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(akropolis_app PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.akropolis_app)
endif()
set_target_properties(akropolis_app PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS akropolis_app
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(akropolis_app)
endif()
