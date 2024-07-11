QT       += core gui multimedia multimediawidgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    creat_job.cpp \
    firsttest.cpp \
    firsttest2.cpp \
    home.cpp \
    home_c.cpp \
    main.cpp \
    mainsecendtest.cpp \
    page_search.cpp \
    secendtest2.cpp \
    sign_company.cpp \
    yes_click.cpp

HEADERS += \
    account.h \
    comment.h \
    company.h \
    content.h \
    creat_job.h \
    direct.h \
    firsttest.h \
    firsttest2.h \
    home.h \
    home_c.h \
    job.h \
    like.h \
    mainsecendtest.h \
    page_search.h \
    person.h \
    post.h \
    secendtest2.h \
    sign_company.h \
    time1.h \
    yes_click.h

FORMS += \
    creat_job.ui \
    firsttest.ui \
    firsttest2.ui \
    home.ui \
    home_c.ui \
    mainsecendtest.ui \
    page_search.ui \
    secendtest2.ui \
    sign_company.ui \
    yes_click.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    1.qrc \
    99.qrc \
    999.qrc \
    Accenture.qrc \
    HANA.qrc \
    Hom.qrc \
    Hompicture.qrc \
    Image10.qrc \
    Image2.qrc \
    Image3.qrc \
    Image4.qrc \
    Image5.qrc \
    Image6.qrc \
    Image7.qrc \
    Image8.qrc \
    Image9.qrc \
    Job.qrc \
    Me.qrc \
    Message.qrc \
    Messaging.qrc \
    Messaging.qrc \
    Messaging.qrc \
    MyNetwork.qrc \
    arm.qrc \
    back.qrc \
    backgroundimage.qrc \
    bg.qrc \
    bg.qrc \
    bgc.qrc \
    image1.qrc \
    logo1.qrc \
    logo2.qrc \
    logo3.qrc \
    logoasli.qrc \
    logooo.qrc \
    mef.qrc \
    num1.qrc \
    picture1.qrc \
    picture1.qrc \
    picture1.qrc \
    picture2.qrc \
    pushbatton.qrc \
    reddd.qrc \
    sound.qrc \
    white.qrc

DISTFILES +=
