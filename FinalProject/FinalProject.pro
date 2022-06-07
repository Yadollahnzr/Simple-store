QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcommet.cpp \
    addproduct.cpp \
    chart.cpp \
    comment.cpp \
    confirmcomment.cpp \
    deleteproduct.cpp \
    discount.cpp \
    editproduct.cpp \
    information.cpp \
    invoice.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow_2.cpp \
    product.cpp \
    purchase.cpp \
    register.cpp \
    seeproducts.cpp \
    showproduct.cpp \
    user.cpp \
    userfactors.cpp

HEADERS += \
    account.h \
    addcommet.h \
    addproduct.h \
    chart.h \
    comment.h \
    confirmcomment.h \
    deleteproduct.h \
    discount.h \
    editproduct.h \
    information.h \
    invoice.h \
    login.h \
    mainwindow.h \
    mainwindow_2.h \
    product.h \
    productlist.h \
    purchase.h \
    register.h \
    seeproducts.h \
    showproduct.h \
    user.h \
    userfactors.h \
    users.h

FORMS += \
    addcommet.ui \
    addproduct.ui \
    chart.ui \
    confirmcomment.ui \
    deleteproduct.ui \
    discount.ui \
    editproduct.ui \
    information.ui \
    login.ui \
    mainwindow.ui \
    mainwindow_2.ui \
    purchase.ui \
    register.ui \
    seeproducts.ui \
    showproduct.ui \
    userfactors.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
