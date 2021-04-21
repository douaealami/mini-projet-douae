#-------------------------------------------------
#
# Project created by QtCreator 2020-11-27T18:17:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mini-projet-douae
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    utilisateur.cpp \
    windowlogin.cpp \
    dbhelper.cpp \
    utilisateurdao.cpp \
    QGuiUtils.cpp \
    clientwindow.cpp \
    departement.cpp \
    departementdao.cpp \
    departementwindow.cpp \
    creerclientwindow.cpp \
    clientdao.cpp \
    categorie.cpp \
    categoriedao.cpp \
    categoriewindow.cpp \
    creercategoriewindow.cpp \
    produit.cpp \
    produitdao.cpp \
    produitwindow.cpp \
    creerproduitwindow.cpp \
    commande.cpp \
    commandedao.cpp \
    commandewindow.cpp \
    creercommandewindow.cpp \
    facturewindow.cpp \
    facture.cpp \
    creerfacturewindow.cpp \
    facturedao.cpp

HEADERS  += mainwindow.h \
    windowlogin.h \
    clientwindow.h \
    departementwindow.h \
    creerclientwindow.h \
    categoriewindow.h \
    creercategoriewindow.h \
    produitwindow.h \
    creerproduitwindow.h \
    commandewindow.h \
    creercommandewindow.h \
    facturewindow.h \
    creerfacturewindow.h

FORMS    += mainwindow.ui \
    windowlogin.ui \
    clientwindow.ui \
    departementwindow.ui \
    creerclientwindow.ui \
    categoriewindow.ui \
    creercategoriewindow.ui \
    produitwindow.ui \
    creerproduitwindow.ui \
    commandewindow.ui \
    creercommandewindow.ui \
    facturewindow.ui \
    creerfacturewindow.ui
