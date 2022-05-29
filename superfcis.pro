QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Buy.cpp \
    Cart.cpp \
    Customer.cpp \
    CustomerMenu.cpp \
    CustomerSignup.cpp \
    LoginMenu.cpp \
    Product.cpp \
    Search.cpp \
    Seller.cpp \
    SellerMenu.cpp \
    SellerSignup.cpp \
    SuperMarket.cpp \
    main.cpp \
    mainwindow.cpp \
    ratingsystem.cpp \
    recipet.cpp \
    selleredit.cpp

HEADERS += \
    Buy.h \
    Cart.h \
    Customer.h \
    CustomerMenu.h \
    CustomerSignup.h \
    LoginMenu.h \
    Product.h \
    Search.h \
    Seller.h \
    SellerMenu.h \
    SellerSignup.h \
    SuperMarket.h \
    mainwindow.h \
    ratingsystem.h \
    recipet.h \
    selleredit.h

FORMS += \
    SellerSignup.ui \
    buy.ui \
    customermenu.ui \
    customersignup.ui \
    loginmenu.ui \
    mainwindow.ui \
    ratingsystem.ui \
    recipet.ui \
    search.ui \
    selleredit.ui \
    sellermenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
