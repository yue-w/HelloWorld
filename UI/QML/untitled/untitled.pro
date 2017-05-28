TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    callcppfromqml.cpp \
    uidata.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =


# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    callcppfromqml.h \
    uidata.h



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Core/x64/release/ -lCore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Core/x64/debug/ -lCore
else:unix: LIBS += -L$$PWD/../../../Core/x64/ -lCore

INCLUDEPATH += $$PWD/../../../Core/x64/Debug
DEPENDPATH += $$PWD/../../../Core/x64/Debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Core/x64/release/libCore.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Core/x64/debug/libCore.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../Core/x64/release/Core.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../Core/x64/debug/Core.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../Core/x64/libCore.a

DISTFILES +=
