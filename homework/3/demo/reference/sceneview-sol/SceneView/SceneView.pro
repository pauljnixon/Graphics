# -------------------------------------------------
# Project created by QtCreator 2010-08-22T14:12:19
# -------------------------------------------------
QT += opengl
TARGET = CS175-Camera
TEMPLATE = app
SOURCES += \
    brush/SmudgeBrush.cpp \
    brush/QuadraticBrush.cpp \
    brush/LinearBrush.cpp \
    brush/ConstantBrush.cpp \
    brush/Brush.cpp \
    camera/OrbitingCamera.cpp \
    camera/CamtransCamera.cpp \
    lib/tinyxmlparser.cpp \
    lib/tinyxmlerror.cpp \
    lib/tinyxml.cpp \
    lib/tinystr.cpp \
    lib/CS123XmlSceneParser.cpp \
    math/CS123Matrix.cpp \
    scenegraph/ShapesScene.cpp \
    scenegraph/SceneviewScene.cpp \
    scenegraph/Scene.cpp \
    scenegraph/RayScene.cpp \
    scenegraph/OpenGLScene.cpp \
    ui/SupportCanvas3D.cpp \
    ui/SupportCanvas2D.cpp \
    ui/Settings.cpp \
    ui/mainwindow.cpp \
    ui/Databinding.cpp \
    ui/Canvas3D.cpp \
    ui/Canvas2D.cpp \
    main.cpp \
    brush/TA_HarmonyBrush.cpp \
    brush/TA_GaussianBrush.cpp \
    ta_shapes/teapot.cpp \
    ta_shapes/SphereMesh.cpp \
    ta_shapes/SierpinskiMesh.cpp \
    ta_shapes/ParameterizedMesh.cpp \
    ta_shapes/ObjMesh.cpp \
    ta_shapes/MobiusStripMesh.cpp \
    ta_shapes/Mesh.cpp \
    ta_shapes/glm.cpp \
    ta_shapes/CylinderMesh.cpp \
    ta_shapes/CubeMesh.cpp \
    ta_shapes/ConeMesh.cpp \
    camera/TACamera.cpp

HEADERS += \
    brush/SmudgeBrush.h \
    brush/QuadraticBrush.h \
    brush/LinearBrush.h \
    brush/ConstantBrush.h \
    brush/Brush.h \
    camera/OrbitingCamera.h \
    camera/CamtransCamera.h \
    camera/Camera.h \
    lib/tinyxml.h \
    lib/tinystr.h \
    lib/CS123XmlSceneParser.h \
    lib/CS123SceneData.h \
    lib/CS123ISceneParser.h \
    lib/CS123Common.h \
    math/CS123Algebra.h \
    math/CS123Matrix.h \
    math/CS123Matrix.inl \
    math/CS123Vector.h \
    math/CS123Vector.inl \
    scenegraph/ShapesScene.h \
    scenegraph/SceneviewScene.h \
    scenegraph/Scene.h \
    scenegraph/RayScene.h \
    scenegraph/OpenGLScene.h \
    ui/SupportCanvas3D.h \
    ui/SupportCanvas2D.h \
    ui/Settings.h \
    ui/mainwindow.h \
    ui/Databinding.h \
    ui/Canvas3D.h \
    ui/Canvas2D.h \
    ui_mainwindow.h \
    brush/TA_HarmonyBrush.h \
    brush/TA_GaussianBrush.h \
    ta_shapes/Vector.h \
    ta_shapes/SphereMesh.h \
    ta_shapes/SierpinskiMesh.h \
    ta_shapes/ParameterizedMesh.h \
    ta_shapes/ObjMesh.h \
    ta_shapes/MobiusStripMesh.h \
    ta_shapes/Mesh.h \
    ta_shapes/glm.h \
    ta_shapes/CylinderMesh.h \
    ta_shapes/CubeMesh.h \
    ta_shapes/ConeMesh.h \
    camera/TACamera.h
FORMS += ui/mainwindow.ui
INCLUDEPATH += brush camera lib math scenegraph ui
DEPENDPATH += brush camera lib math scenegraph ui
DEFINES += TIXML_USE_STL
OTHER_FILES +=

# Don't add the -pg flag unless you know what you are doing. It makes QThreadPool freeze on Mac OS X
QMAKE_CXXFLAGS_RELEASE -= -O2
QMAKE_CXXFLAGS_RELEASE += -O3
QMAKE_CXXFLAGS_WARN_ON -= -Wall
QMAKE_CXXFLAGS_WARN_ON += -Waddress -Warray-bounds -Wc++0x-compat -Wchar-subscripts -Wformat\
                          -Wmain -Wmissing-braces -Wparentheses -Wreorder -Wreturn-type \
                          -Wsequence-point -Wsign-compare -Wstrict-aliasing -Wstrict-overflow=1 -Wswitch \
                          -Wtrigraphs -Wuninitialized -Wunused-label -Wunused-variable \
                          -Wvolatile-register-var -Wno-extra
# QMAKE_CXX_FLAGS_WARN_ON += -Wunknown-pragmas -Wunused-function -Wmain

macx {
    QMAKE_CXXFLAGS_WARN_ON -= -Warray-bounds -Wc++0x-compat
}
