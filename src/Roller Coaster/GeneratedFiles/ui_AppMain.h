/********************************************************************************
** Form generated from reading UI file 'AppMain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APPMAIN_H
#define UI_APPMAIN_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AppMainClass
{
public:
    QAction *aExit;
    QAction *aLoadPath;
    QAction *aSavePath;
    QAction *aWorld;
    QAction *aTop;
    QAction *aTrain;
    QAction *aLinear;
    QAction *aCardinal;
    QAction *aCubic;
    QAction *aLine;
    QAction *aTrack;
    QAction *aRoad;
    QAction *aClassicTrain;
    QAction *aSimple;
    QAction *aRollerCoaster;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *mainLayout;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupCamera;
    QComboBox *comboCamera;
    QGroupBox *groupCurve;
    QComboBox *comboCurve;
    QGroupBox *groupTrack;
    QComboBox *comboTrack;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_5;
    QGroupBox *groupCamera_4;
    QComboBox *comboCamera_4;
    QGroupBox *groupCamera_5;
    QComboBox *comboCamera_5;
    QGroupBox *groupCamera_6;
    QComboBox *comboCamera_6;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_3;
    QPushButton *moveBackword;
    QGroupBox *groupPlay;
    QPushButton *bPlay;
    QGroupBox *groupBox_4;
    QPushButton *moveForword;
    QSpacerItem *horizontalSpacer_8;
    QVBoxLayout *verticalLayout_12;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_13;
    QGroupBox *changeSpeed;
    QSlider *sSpeed;
    QSpacerItem *horizontalSpacer_14;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupCP;
    QPushButton *bAdd;
    QPushButton *bDelete;
    QGroupBox *groupBox;
    QPushButton *rcpxadd;
    QPushButton *rcpxsub;
    QGroupBox *groupBox_2;
    QPushButton *rcpzadd;
    QPushButton *rcpzsub;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_9;
    QGroupBox *groupBox_9;
    QPushButton *addCar;
    QPushButton *rmCar;
    QGroupBox *groupBox_10;
    QPushButton *mvForward;
    QPushButton *mvBackword;
    QGroupBox *groupTrack_2;
    QComboBox *comboStyle;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_11;
    QGroupBox *drawSleeper;
    QSlider *sleeperFrqt;
    QGroupBox *drawSleeper_2;
    QSlider *tension;
    QGroupBox *groupBox_5;
    QSlider *subdivision;
    QSpacerItem *horizontalSpacer_12;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuCamera;
    QMenu *menuCurve;
    QMenu *menuTrack;
    QMenu *menuVelocity;
    QMenu *menustyle;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *AppMainClass)
    {
        if (AppMainClass->objectName().isEmpty())
            AppMainClass->setObjectName(QString::fromUtf8("AppMainClass"));
        AppMainClass->resize(1063, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AppMainClass->sizePolicy().hasHeightForWidth());
        AppMainClass->setSizePolicy(sizePolicy);
        AppMainClass->setMinimumSize(QSize(985, 900));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\273\237\346\255\243\351\273\221\351\253\224"));
        AppMainClass->setFont(font);
        AppMainClass->setLayoutDirection(Qt::LeftToRight);
        AppMainClass->setAutoFillBackground(true);
        AppMainClass->setStyleSheet(QString::fromUtf8(""));
        AppMainClass->setDockNestingEnabled(false);
        aExit = new QAction(AppMainClass);
        aExit->setObjectName(QString::fromUtf8("aExit"));
        aLoadPath = new QAction(AppMainClass);
        aLoadPath->setObjectName(QString::fromUtf8("aLoadPath"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/openfile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        aLoadPath->setIcon(icon);
        aLoadPath->setIconVisibleInMenu(true);
        aSavePath = new QAction(AppMainClass);
        aSavePath->setObjectName(QString::fromUtf8("aSavePath"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/savefile.ico"), QSize(), QIcon::Normal, QIcon::Off);
        aSavePath->setIcon(icon1);
        aWorld = new QAction(AppMainClass);
        aWorld->setObjectName(QString::fromUtf8("aWorld"));
        aWorld->setCheckable(false);
        aWorld->setChecked(false);
        aTop = new QAction(AppMainClass);
        aTop->setObjectName(QString::fromUtf8("aTop"));
        aTop->setCheckable(true);
        aTrain = new QAction(AppMainClass);
        aTrain->setObjectName(QString::fromUtf8("aTrain"));
        aTrain->setCheckable(true);
        aLinear = new QAction(AppMainClass);
        aLinear->setObjectName(QString::fromUtf8("aLinear"));
        aLinear->setCheckable(false);
        aLinear->setChecked(false);
        aCardinal = new QAction(AppMainClass);
        aCardinal->setObjectName(QString::fromUtf8("aCardinal"));
        aCardinal->setCheckable(true);
        aCubic = new QAction(AppMainClass);
        aCubic->setObjectName(QString::fromUtf8("aCubic"));
        aCubic->setCheckable(true);
        aLine = new QAction(AppMainClass);
        aLine->setObjectName(QString::fromUtf8("aLine"));
        aLine->setCheckable(false);
        aLine->setChecked(false);
        aTrack = new QAction(AppMainClass);
        aTrack->setObjectName(QString::fromUtf8("aTrack"));
        aTrack->setCheckable(true);
        aRoad = new QAction(AppMainClass);
        aRoad->setObjectName(QString::fromUtf8("aRoad"));
        aRoad->setCheckable(true);
        aClassicTrain = new QAction(AppMainClass);
        aClassicTrain->setObjectName(QString::fromUtf8("aClassicTrain"));
        aSimple = new QAction(AppMainClass);
        aSimple->setObjectName(QString::fromUtf8("aSimple"));
        aRollerCoaster = new QAction(AppMainClass);
        aRollerCoaster->setObjectName(QString::fromUtf8("aRollerCoaster"));
        centralWidget = new QWidget(AppMainClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setMinimumSize(QSize(0, 0));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mainLayout = new QVBoxLayout();
        mainLayout->setSpacing(0);
        mainLayout->setObjectName(QString::fromUtf8("mainLayout"));
        mainLayout->setSizeConstraint(QLayout::SetMaximumSize);

        verticalLayout->addLayout(mainLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, -1, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        groupCamera = new QGroupBox(centralWidget);
        groupCamera->setObjectName(QString::fromUtf8("groupCamera"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupCamera->sizePolicy().hasHeightForWidth());
        groupCamera->setSizePolicy(sizePolicy2);
        groupCamera->setMinimumSize(QSize(120, 0));
        groupCamera->setMaximumSize(QSize(120, 110));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        groupCamera->setFont(font1);
        groupCamera->setAutoFillBackground(false);
        groupCamera->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupCamera->setAlignment(Qt::AlignCenter);
        comboCamera = new QComboBox(groupCamera);
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->addItem(QString());
        comboCamera->setObjectName(QString::fromUtf8("comboCamera"));
        comboCamera->setGeometry(QRect(10, 40, 96, 41));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboCamera->sizePolicy().hasHeightForWidth());
        comboCamera->setSizePolicy(sizePolicy3);
        comboCamera->setFont(font1);
        comboCamera->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));

        horizontalLayout_6->addWidget(groupCamera);

        groupCurve = new QGroupBox(centralWidget);
        groupCurve->setObjectName(QString::fromUtf8("groupCurve"));
        sizePolicy2.setHeightForWidth(groupCurve->sizePolicy().hasHeightForWidth());
        groupCurve->setSizePolicy(sizePolicy2);
        groupCurve->setMinimumSize(QSize(120, 0));
        groupCurve->setMaximumSize(QSize(120, 110));
        groupCurve->setFont(font1);
        groupCurve->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupCurve->setAlignment(Qt::AlignCenter);
        comboCurve = new QComboBox(groupCurve);
        comboCurve->addItem(QString());
        comboCurve->addItem(QString());
        comboCurve->addItem(QString());
        comboCurve->setObjectName(QString::fromUtf8("comboCurve"));
        comboCurve->setGeometry(QRect(10, 40, 96, 41));
        sizePolicy3.setHeightForWidth(comboCurve->sizePolicy().hasHeightForWidth());
        comboCurve->setSizePolicy(sizePolicy3);
        comboCurve->setFont(font1);
        comboCurve->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));

        horizontalLayout_6->addWidget(groupCurve);

        groupTrack = new QGroupBox(centralWidget);
        groupTrack->setObjectName(QString::fromUtf8("groupTrack"));
        sizePolicy2.setHeightForWidth(groupTrack->sizePolicy().hasHeightForWidth());
        groupTrack->setSizePolicy(sizePolicy2);
        groupTrack->setMinimumSize(QSize(120, 0));
        groupTrack->setMaximumSize(QSize(120, 110));
        groupTrack->setFont(font1);
        groupTrack->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupTrack->setAlignment(Qt::AlignCenter);
        comboTrack = new QComboBox(groupTrack);
        comboTrack->addItem(QString());
        comboTrack->addItem(QString());
        comboTrack->addItem(QString());
        comboTrack->setObjectName(QString::fromUtf8("comboTrack"));
        comboTrack->setGeometry(QRect(10, 40, 96, 41));
        sizePolicy3.setHeightForWidth(comboTrack->sizePolicy().hasHeightForWidth());
        comboTrack->setSizePolicy(sizePolicy3);
        comboTrack->setFont(font1);
        comboTrack->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));
        comboTrack->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);

        horizontalLayout_6->addWidget(groupTrack);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_2);

        horizontalLayout_6->setStretch(2, 10);

        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout_4->setContentsMargins(0, -1, -1, -1);
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        groupCamera_4 = new QGroupBox(centralWidget);
        groupCamera_4->setObjectName(QString::fromUtf8("groupCamera_4"));
        sizePolicy2.setHeightForWidth(groupCamera_4->sizePolicy().hasHeightForWidth());
        groupCamera_4->setSizePolicy(sizePolicy2);
        groupCamera_4->setMinimumSize(QSize(120, 0));
        groupCamera_4->setMaximumSize(QSize(120, 75));
        groupCamera_4->setFont(font1);
        groupCamera_4->setAutoFillBackground(false);
        groupCamera_4->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupCamera_4->setAlignment(Qt::AlignCenter);
        comboCamera_4 = new QComboBox(groupCamera_4);
        comboCamera_4->setObjectName(QString::fromUtf8("comboCamera_4"));
        comboCamera_4->setGeometry(QRect(10, 30, 96, 41));
        sizePolicy3.setHeightForWidth(comboCamera_4->sizePolicy().hasHeightForWidth());
        comboCamera_4->setSizePolicy(sizePolicy3);
        comboCamera_4->setFont(font1);
        comboCamera_4->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));

        horizontalLayout_4->addWidget(groupCamera_4);

        groupCamera_5 = new QGroupBox(centralWidget);
        groupCamera_5->setObjectName(QString::fromUtf8("groupCamera_5"));
        sizePolicy2.setHeightForWidth(groupCamera_5->sizePolicy().hasHeightForWidth());
        groupCamera_5->setSizePolicy(sizePolicy2);
        groupCamera_5->setMinimumSize(QSize(120, 0));
        groupCamera_5->setMaximumSize(QSize(120, 75));
        groupCamera_5->setFont(font1);
        groupCamera_5->setAutoFillBackground(false);
        groupCamera_5->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupCamera_5->setAlignment(Qt::AlignCenter);
        comboCamera_5 = new QComboBox(groupCamera_5);
        comboCamera_5->setObjectName(QString::fromUtf8("comboCamera_5"));
        comboCamera_5->setGeometry(QRect(10, 30, 96, 41));
        sizePolicy3.setHeightForWidth(comboCamera_5->sizePolicy().hasHeightForWidth());
        comboCamera_5->setSizePolicy(sizePolicy3);
        comboCamera_5->setFont(font1);
        comboCamera_5->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));

        horizontalLayout_4->addWidget(groupCamera_5);

        groupCamera_6 = new QGroupBox(centralWidget);
        groupCamera_6->setObjectName(QString::fromUtf8("groupCamera_6"));
        sizePolicy2.setHeightForWidth(groupCamera_6->sizePolicy().hasHeightForWidth());
        groupCamera_6->setSizePolicy(sizePolicy2);
        groupCamera_6->setMinimumSize(QSize(120, 0));
        groupCamera_6->setMaximumSize(QSize(120, 75));
        groupCamera_6->setFont(font1);
        groupCamera_6->setAutoFillBackground(false);
        groupCamera_6->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupCamera_6->setAlignment(Qt::AlignCenter);
        comboCamera_6 = new QComboBox(groupCamera_6);
        comboCamera_6->setObjectName(QString::fromUtf8("comboCamera_6"));
        comboCamera_6->setGeometry(QRect(10, 30, 96, 41));
        sizePolicy3.setHeightForWidth(comboCamera_6->sizePolicy().hasHeightForWidth());
        comboCamera_6->setSizePolicy(sizePolicy3);
        comboCamera_6->setFont(font1);
        comboCamera_6->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));

        horizontalLayout_4->addWidget(groupCamera_6);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_3);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, -1, 0, -1);
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(60, 0));
        groupBox_3->setMaximumSize(QSize(16777215, 110));
        groupBox_3->setFont(font1);
        groupBox_3->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupBox_3->setAlignment(Qt::AlignCenter);
        moveBackword = new QPushButton(groupBox_3);
        moveBackword->setObjectName(QString::fromUtf8("moveBackword"));
        moveBackword->setGeometry(QRect(10, 40, 60, 60));
        moveBackword->setContextMenuPolicy(Qt::DefaultContextMenu);
        moveBackword->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/backward.ico"), QSize(), QIcon::Normal, QIcon::Off);
        moveBackword->setIcon(icon2);
        moveBackword->setIconSize(QSize(40, 40));
        moveBackword->setAutoRepeat(false);
        moveBackword->setAutoExclusive(false);
        moveBackword->setAutoDefault(false);
        moveBackword->setFlat(true);

        horizontalLayout_10->addWidget(groupBox_3);

        groupPlay = new QGroupBox(centralWidget);
        groupPlay->setObjectName(QString::fromUtf8("groupPlay"));
        sizePolicy2.setHeightForWidth(groupPlay->sizePolicy().hasHeightForWidth());
        groupPlay->setSizePolicy(sizePolicy2);
        groupPlay->setMinimumSize(QSize(90, 0));
        groupPlay->setMaximumSize(QSize(200, 110));
        groupPlay->setFont(font1);
        groupPlay->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupPlay->setAlignment(Qt::AlignCenter);
        bPlay = new QPushButton(groupPlay);
        bPlay->setObjectName(QString::fromUtf8("bPlay"));
        bPlay->setGeometry(QRect(20, 40, 61, 61));
        sizePolicy2.setHeightForWidth(bPlay->sizePolicy().hasHeightForWidth());
        bPlay->setSizePolicy(sizePolicy2);
        QFont font2;
        font2.setFamily(QString::fromUtf8("Comic Sans MS"));
        font2.setPointSize(9);
        font2.setBold(true);
        font2.setWeight(75);
        bPlay->setFont(font2);
        bPlay->setAutoFillBackground(false);
        bPlay->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/play.png"), QSize(), QIcon::Normal, QIcon::Off);
        bPlay->setIcon(icon3);
        bPlay->setIconSize(QSize(40, 40));

        horizontalLayout_10->addWidget(groupPlay);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(60, 0));
        groupBox_4->setMaximumSize(QSize(16777215, 110));
        groupBox_4->setFont(font1);
        groupBox_4->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupBox_4->setAlignment(Qt::AlignCenter);
        moveForword = new QPushButton(groupBox_4);
        moveForword->setObjectName(QString::fromUtf8("moveForword"));
        moveForword->setGeometry(QRect(0, 40, 60, 60));
        moveForword->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"}"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/AppMain/Resources/Icons/forward.ico"), QSize(), QIcon::Normal, QIcon::Off);
        moveForword->setIcon(icon4);
        moveForword->setIconSize(QSize(40, 40));
        moveForword->setFlat(true);

        horizontalLayout_10->addWidget(groupBox_4);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);


        verticalLayout_11->addLayout(horizontalLayout_10);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(-1, 20, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_13);

        changeSpeed = new QGroupBox(centralWidget);
        changeSpeed->setObjectName(QString::fromUtf8("changeSpeed"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(changeSpeed->sizePolicy().hasHeightForWidth());
        changeSpeed->setSizePolicy(sizePolicy4);
        changeSpeed->setMinimumSize(QSize(219, 0));
        changeSpeed->setMaximumSize(QSize(109998, 90));
        changeSpeed->setFont(font1);
        changeSpeed->setLayoutDirection(Qt::LeftToRight);
        changeSpeed->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        changeSpeed->setAlignment(Qt::AlignCenter);
        changeSpeed->setFlat(false);
        changeSpeed->setCheckable(true);
        sSpeed = new QSlider(changeSpeed);
        sSpeed->setObjectName(QString::fromUtf8("sSpeed"));
        sSpeed->setGeometry(QRect(0, 30, 231, 22));
        QSizePolicy sizePolicy5(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(sSpeed->sizePolicy().hasHeightForWidth());
        sSpeed->setSizePolicy(sizePolicy5);
        sSpeed->setMinimumSize(QSize(77, 0));
        sSpeed->setMaximumSize(QSize(16777215, 16777215));
        sSpeed->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"	background-color: #505050;\n"
"    height: 3px; \n"
"    margin: 2px 0;\n"
" }\n"
" QSlider::handle:horizontal {\n"
"	image: url(:/AppMain/slider_handle.png);\n"
"	width: 15px;\n"
"	margin: -5px 0;\n"
" }"));
        sSpeed->setMinimum(1);
        sSpeed->setMaximum(100);
        sSpeed->setSingleStep(2);
        sSpeed->setValue(50);
        sSpeed->setSliderPosition(50);
        sSpeed->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(changeSpeed);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_14);


        verticalLayout_12->addLayout(horizontalLayout_2);


        verticalLayout_11->addLayout(verticalLayout_12);


        horizontalLayout_5->addLayout(verticalLayout_11);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, -1, -1, -1);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, -1, -1, -1);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        groupCP = new QGroupBox(centralWidget);
        groupCP->setObjectName(QString::fromUtf8("groupCP"));
        sizePolicy2.setHeightForWidth(groupCP->sizePolicy().hasHeightForWidth());
        groupCP->setSizePolicy(sizePolicy2);
        groupCP->setMinimumSize(QSize(120, 0));
        groupCP->setMaximumSize(QSize(120, 110));
        groupCP->setFont(font1);
        groupCP->setMouseTracking(false);
        groupCP->setAutoFillBackground(false);
        groupCP->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupCP->setAlignment(Qt::AlignCenter);
        groupCP->setFlat(false);
        groupCP->setCheckable(false);
        bAdd = new QPushButton(groupCP);
        bAdd->setObjectName(QString::fromUtf8("bAdd"));
        bAdd->setGeometry(QRect(10, 40, 44, 44));
        sizePolicy2.setHeightForWidth(bAdd->sizePolicy().hasHeightForWidth());
        bAdd->setSizePolicy(sizePolicy2);
        bAdd->setFont(font2);
        bAdd->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/AppMain/madd.png"), QSize(), QIcon::Normal, QIcon::Off);
        bAdd->setIcon(icon5);
        bAdd->setIconSize(QSize(14, 14));
        bDelete = new QPushButton(groupCP);
        bDelete->setObjectName(QString::fromUtf8("bDelete"));
        bDelete->setGeometry(QRect(60, 40, 44, 44));
        sizePolicy2.setHeightForWidth(bDelete->sizePolicy().hasHeightForWidth());
        bDelete->setSizePolicy(sizePolicy2);
        bDelete->setFont(font2);
        bDelete->setFocusPolicy(Qt::ClickFocus);
        bDelete->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/AppMain/mdelete.png"), QSize(), QIcon::Normal, QIcon::Off);
        bDelete->setIcon(icon6);
        bDelete->setIconSize(QSize(12, 12));

        horizontalLayout_7->addWidget(groupCP);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(120, 0));
        groupBox->setMaximumSize(QSize(120, 110));
        QPalette palette;
        QBrush brush(QColor(249, 249, 249, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        groupBox->setPalette(palette);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        rcpxadd = new QPushButton(groupBox);
        rcpxadd->setObjectName(QString::fromUtf8("rcpxadd"));
        rcpxadd->setGeometry(QRect(10, 40, 44, 44));
        sizePolicy2.setHeightForWidth(rcpxadd->sizePolicy().hasHeightForWidth());
        rcpxadd->setSizePolicy(sizePolicy2);
        rcpxadd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpxadd->setIcon(icon5);
        rcpxadd->setIconSize(QSize(14, 14));
        rcpxsub = new QPushButton(groupBox);
        rcpxsub->setObjectName(QString::fromUtf8("rcpxsub"));
        rcpxsub->setGeometry(QRect(60, 40, 44, 44));
        rcpxsub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpxsub->setIcon(icon6);
        rcpxsub->setIconSize(QSize(12, 12));

        horizontalLayout_7->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(120, 0));
        groupBox_2->setMaximumSize(QSize(120, 110));
        groupBox_2->setFont(font1);
        groupBox_2->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        rcpzadd = new QPushButton(groupBox_2);
        rcpzadd->setObjectName(QString::fromUtf8("rcpzadd"));
        rcpzadd->setGeometry(QRect(10, 40, 44, 44));
        sizePolicy2.setHeightForWidth(rcpzadd->sizePolicy().hasHeightForWidth());
        rcpzadd->setSizePolicy(sizePolicy2);
        rcpzadd->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzadd->setIcon(icon5);
        rcpzadd->setIconSize(QSize(14, 14));
        rcpzsub = new QPushButton(groupBox_2);
        rcpzsub->setObjectName(QString::fromUtf8("rcpzsub"));
        rcpzsub->setGeometry(QRect(60, 40, 44, 44));
        rcpzsub->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rcpzsub->setIcon(icon6);
        rcpzsub->setIconSize(QSize(12, 12));

        horizontalLayout_7->addWidget(groupBox_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_7->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        groupBox_9 = new QGroupBox(centralWidget);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setMinimumSize(QSize(120, 75));
        groupBox_9->setMaximumSize(QSize(120, 75));
        groupBox_9->setFont(font1);
        groupBox_9->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupBox_9->setAlignment(Qt::AlignCenter);
        addCar = new QPushButton(groupBox_9);
        addCar->setObjectName(QString::fromUtf8("addCar"));
        addCar->setGeometry(QRect(10, 30, 44, 44));
        sizePolicy2.setHeightForWidth(addCar->sizePolicy().hasHeightForWidth());
        addCar->setSizePolicy(sizePolicy2);
        addCar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        addCar->setIcon(icon5);
        addCar->setIconSize(QSize(14, 14));
        rmCar = new QPushButton(groupBox_9);
        rmCar->setObjectName(QString::fromUtf8("rmCar"));
        rmCar->setGeometry(QRect(60, 30, 44, 44));
        rmCar->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        rmCar->setIcon(icon6);
        rmCar->setIconSize(QSize(12, 12));

        horizontalLayout_8->addWidget(groupBox_9);

        groupBox_10 = new QGroupBox(centralWidget);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(120, 75));
        groupBox_10->setMaximumSize(QSize(120, 75));
        groupBox_10->setFont(font1);
        groupBox_10->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupBox_10->setAlignment(Qt::AlignCenter);
        mvForward = new QPushButton(groupBox_10);
        mvForward->setObjectName(QString::fromUtf8("mvForward"));
        mvForward->setGeometry(QRect(10, 30, 44, 44));
        sizePolicy2.setHeightForWidth(mvForward->sizePolicy().hasHeightForWidth());
        mvForward->setSizePolicy(sizePolicy2);
        mvForward->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        mvForward->setIcon(icon5);
        mvForward->setIconSize(QSize(14, 14));
        mvBackword = new QPushButton(groupBox_10);
        mvBackword->setObjectName(QString::fromUtf8("mvBackword"));
        mvBackword->setGeometry(QRect(60, 30, 44, 44));
        mvBackword->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(172, 172, 172, 255), stop:1 rgba(0, 0, 0, 203));\n"
"     padding-top: 10px;\n"
"     padding-left: 5px;\n"
"}"));
        mvBackword->setIcon(icon6);
        mvBackword->setIconSize(QSize(12, 12));

        horizontalLayout_8->addWidget(groupBox_10);

        groupTrack_2 = new QGroupBox(centralWidget);
        groupTrack_2->setObjectName(QString::fromUtf8("groupTrack_2"));
        sizePolicy2.setHeightForWidth(groupTrack_2->sizePolicy().hasHeightForWidth());
        groupTrack_2->setSizePolicy(sizePolicy2);
        groupTrack_2->setMinimumSize(QSize(120, 75));
        groupTrack_2->setMaximumSize(QSize(120, 75));
        groupTrack_2->setFont(font1);
        groupTrack_2->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupTrack_2->setAlignment(Qt::AlignCenter);
        comboStyle = new QComboBox(groupTrack_2);
        comboStyle->addItem(QString());
        comboStyle->addItem(QString());
        comboStyle->addItem(QString());
        comboStyle->setObjectName(QString::fromUtf8("comboStyle"));
        comboStyle->setGeometry(QRect(10, 30, 96, 41));
        sizePolicy3.setHeightForWidth(comboStyle->sizePolicy().hasHeightForWidth());
        comboStyle->setSizePolicy(sizePolicy3);
        comboStyle->setFont(font1);
        comboStyle->setStyleSheet(QString::fromUtf8(" QComboBox {\n"
"	background-color: rgb(80, 80, 80);\n"
"	color: rgb(240, 240, 240);\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"QComboBox:on {\n"
"	background-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.499001, fy:0.000500999, stop:0 rgba(152, 152, 152, 217), stop:1 rgba(0, 0, 0, 232));\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"	image: url(:/AppMain/down_arrow.ico);\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"     border-left-color: rgb(240, 240, 240);\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"     selection-background-color: rgb(80, 80, 80);\n"
"}"));
        comboStyle->setSizeAdjustPolicy(QComboBox::AdjustToContentsOnFirstShow);
        comboStyle->setFrame(true);

        horizontalLayout_8->addWidget(groupTrack_2);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout_6->addLayout(verticalLayout_7);


        horizontalLayout_5->addLayout(verticalLayout_6);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalLayout->setContentsMargins(0, 30, 0, 0);
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_11);

        drawSleeper = new QGroupBox(centralWidget);
        drawSleeper->setObjectName(QString::fromUtf8("drawSleeper"));
        sizePolicy2.setHeightForWidth(drawSleeper->sizePolicy().hasHeightForWidth());
        drawSleeper->setSizePolicy(sizePolicy2);
        drawSleeper->setMinimumSize(QSize(321, 0));
        drawSleeper->setMaximumSize(QSize(1999999, 90));
        drawSleeper->setFont(font1);
        drawSleeper->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        drawSleeper->setAlignment(Qt::AlignCenter);
        drawSleeper->setCheckable(true);
        sleeperFrqt = new QSlider(drawSleeper);
        sleeperFrqt->setObjectName(QString::fromUtf8("sleeperFrqt"));
        sleeperFrqt->setEnabled(true);
        sleeperFrqt->setGeometry(QRect(30, 40, 266, 20));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(sleeperFrqt->sizePolicy().hasHeightForWidth());
        sleeperFrqt->setSizePolicy(sizePolicy6);
        sleeperFrqt->setMinimumSize(QSize(266, 0));
        sleeperFrqt->setMaximumSize(QSize(260, 20));
        sleeperFrqt->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"	background-color: #505050;\n"
"    height: 3px; \n"
"    margin: 2px 0;\n"
" }\n"
" QSlider::handle:horizontal {\n"
"	image: url(:/AppMain/slider_handle.png);\n"
"	width: 15px;\n"
"	margin: -5px 0;\n"
" }"));
        sleeperFrqt->setMinimum(0);
        sleeperFrqt->setMaximum(15);
        sleeperFrqt->setPageStep(11);
        sleeperFrqt->setValue(6);
        sleeperFrqt->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(drawSleeper);

        drawSleeper_2 = new QGroupBox(centralWidget);
        drawSleeper_2->setObjectName(QString::fromUtf8("drawSleeper_2"));
        sizePolicy2.setHeightForWidth(drawSleeper_2->sizePolicy().hasHeightForWidth());
        drawSleeper_2->setSizePolicy(sizePolicy2);
        drawSleeper_2->setMinimumSize(QSize(321, 0));
        drawSleeper_2->setMaximumSize(QSize(1999999, 90));
        drawSleeper_2->setFont(font1);
        drawSleeper_2->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        drawSleeper_2->setAlignment(Qt::AlignCenter);
        drawSleeper_2->setCheckable(false);
        tension = new QSlider(drawSleeper_2);
        tension->setObjectName(QString::fromUtf8("tension"));
        tension->setGeometry(QRect(30, 40, 266, 20));
        sizePolicy6.setHeightForWidth(tension->sizePolicy().hasHeightForWidth());
        tension->setSizePolicy(sizePolicy6);
        tension->setMinimumSize(QSize(266, 0));
        tension->setMaximumSize(QSize(16777215, 20));
        tension->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"	background-color: #505050;\n"
"    height: 3px; \n"
"    margin: 2px 0;\n"
" }\n"
" QSlider::handle:horizontal {\n"
"	image: url(:/AppMain/slider_handle.png);\n"
"	width: 15px;\n"
"	margin: -5px 0;\n"
" }"));
        tension->setMinimum(1);
        tension->setMaximum(99);
        tension->setPageStep(11);
        tension->setValue(50);
        tension->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(drawSleeper_2);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(321, 75));
        groupBox_5->setMaximumSize(QSize(16777215, 90));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Comic Sans MS"));
        font3.setPointSize(10);
        font3.setBold(true);
        font3.setWeight(75);
        font3.setKerning(true);
        groupBox_5->setFont(font3);
        groupBox_5->setLayoutDirection(Qt::LeftToRight);
        groupBox_5->setStyleSheet(QString::fromUtf8("border-radius: 5px;"));
        groupBox_5->setAlignment(Qt::AlignCenter);
        subdivision = new QSlider(groupBox_5);
        subdivision->setObjectName(QString::fromUtf8("subdivision"));
        subdivision->setGeometry(QRect(30, 40, 266, 20));
        sizePolicy6.setHeightForWidth(subdivision->sizePolicy().hasHeightForWidth());
        subdivision->setSizePolicy(sizePolicy6);
        subdivision->setMinimumSize(QSize(266, 0));
        subdivision->setMaximumSize(QSize(16777215, 20));
        subdivision->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"	background-color: #505050;\n"
"    height: 3px; \n"
"    margin: 2px 0;\n"
" }\n"
" QSlider::handle:horizontal {\n"
"	image: url(:/AppMain/slider_handle.png);\n"
"	width: 15px;\n"
"	margin: -5px 0;\n"
" }"));
        subdivision->setMinimum(1);
        subdivision->setMaximum(900);
        subdivision->setPageStep(11);
        subdivision->setValue(600);
        subdivision->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(groupBox_5);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);


        verticalLayout->addLayout(horizontalLayout);

        AppMainClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AppMainClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1063, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuCamera = new QMenu(menuBar);
        menuCamera->setObjectName(QString::fromUtf8("menuCamera"));
        menuCurve = new QMenu(menuBar);
        menuCurve->setObjectName(QString::fromUtf8("menuCurve"));
        menuTrack = new QMenu(menuBar);
        menuTrack->setObjectName(QString::fromUtf8("menuTrack"));
        menuVelocity = new QMenu(menuBar);
        menuVelocity->setObjectName(QString::fromUtf8("menuVelocity"));
        menustyle = new QMenu(menuBar);
        menustyle->setObjectName(QString::fromUtf8("menustyle"));
        AppMainClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(AppMainClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AppMainClass->setStatusBar(statusBar);
        mainToolBar = new QToolBar(AppMainClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AppMainClass->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCamera->menuAction());
        menuBar->addAction(menuTrack->menuAction());
        menuBar->addAction(menuCurve->menuAction());
        menuBar->addAction(menustyle->menuAction());
        menuBar->addAction(menuVelocity->menuAction());
        menuFile->addAction(aLoadPath);
        menuFile->addAction(aSavePath);
        menuFile->addSeparator();
        menuFile->addAction(aExit);
        menuCamera->addAction(aWorld);
        menuCamera->addAction(aTop);
        menuCamera->addAction(aTrain);
        menuCurve->addAction(aLinear);
        menuCurve->addAction(aCardinal);
        menuCurve->addAction(aCubic);
        menuTrack->addAction(aLine);
        menuTrack->addAction(aTrack);
        menuTrack->addAction(aRoad);
        menustyle->addAction(aClassicTrain);
        menustyle->addAction(aSimple);
        menustyle->addAction(aRollerCoaster);
        mainToolBar->addAction(aLoadPath);
        mainToolBar->addAction(aSavePath);

        retranslateUi(AppMainClass);

        comboCurve->setCurrentIndex(2);
        comboTrack->setCurrentIndex(1);
        moveBackword->setDefault(false);
        comboStyle->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AppMainClass);
    } // setupUi

    void retranslateUi(QMainWindow *AppMainClass)
    {
        AppMainClass->setWindowTitle(QApplication::translate("AppMainClass", "AppMain", nullptr));
        aExit->setText(QApplication::translate("AppMainClass", "Exit", nullptr));
        aLoadPath->setText(QApplication::translate("AppMainClass", "Load Path", nullptr));
        aSavePath->setText(QApplication::translate("AppMainClass", "Save Path", nullptr));
        aWorld->setText(QApplication::translate("AppMainClass", "World", nullptr));
        aTop->setText(QApplication::translate("AppMainClass", "Top", nullptr));
        aTrain->setText(QApplication::translate("AppMainClass", "Train", nullptr));
        aLinear->setText(QApplication::translate("AppMainClass", "Linear", nullptr));
        aCardinal->setText(QApplication::translate("AppMainClass", "Cardinal", nullptr));
        aCubic->setText(QApplication::translate("AppMainClass", "Cubic", nullptr));
        aLine->setText(QApplication::translate("AppMainClass", "Line", nullptr));
        aTrack->setText(QApplication::translate("AppMainClass", "Track", nullptr));
        aRoad->setText(QApplication::translate("AppMainClass", "Road", nullptr));
        aClassicTrain->setText(QApplication::translate("AppMainClass", "ClassicTrain", nullptr));
        aSimple->setText(QApplication::translate("AppMainClass", "Simple", nullptr));
        aRollerCoaster->setText(QApplication::translate("AppMainClass", "RollerCoaster", nullptr));
        groupCamera->setTitle(QApplication::translate("AppMainClass", "Camera", nullptr));
        comboCamera->setItemText(0, QApplication::translate("AppMainClass", "World", nullptr));
        comboCamera->setItemText(1, QApplication::translate("AppMainClass", "Top", nullptr));
        comboCamera->setItemText(2, QApplication::translate("AppMainClass", "Train", nullptr));

        groupCurve->setTitle(QApplication::translate("AppMainClass", "Curve", nullptr));
        comboCurve->setItemText(0, QApplication::translate("AppMainClass", "Linear", nullptr));
        comboCurve->setItemText(1, QApplication::translate("AppMainClass", "Cardinal", nullptr));
        comboCurve->setItemText(2, QApplication::translate("AppMainClass", "Cubic", nullptr));

        comboCurve->setCurrentText(QApplication::translate("AppMainClass", "Cubic", nullptr));
        groupTrack->setTitle(QApplication::translate("AppMainClass", "Track", nullptr));
        comboTrack->setItemText(0, QApplication::translate("AppMainClass", "Line", nullptr));
        comboTrack->setItemText(1, QApplication::translate("AppMainClass", "Track", nullptr));
        comboTrack->setItemText(2, QApplication::translate("AppMainClass", "Road", nullptr));

        comboTrack->setCurrentText(QApplication::translate("AppMainClass", "Track", nullptr));
        groupCamera_4->setTitle(QApplication::translate("AppMainClass", "empt", nullptr));
        groupCamera_5->setTitle(QApplication::translate("AppMainClass", "empt", nullptr));
        groupCamera_6->setTitle(QApplication::translate("AppMainClass", "empt", nullptr));
        groupBox_3->setTitle(QApplication::translate("AppMainClass", "Backword", nullptr));
        moveBackword->setText(QString());
        groupPlay->setTitle(QApplication::translate("AppMainClass", "Play", nullptr));
        bPlay->setText(QString());
        groupBox_4->setTitle(QApplication::translate("AppMainClass", "Forword", nullptr));
        moveForword->setText(QString());
#ifndef QT_NO_ACCESSIBILITY
        changeSpeed->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        changeSpeed->setTitle(QApplication::translate("AppMainClass", "Speed", nullptr));
        groupCP->setTitle(QApplication::translate("AppMainClass", "Ctrl Point", nullptr));
        bAdd->setText(QString());
        bDelete->setText(QString());
        groupBox->setTitle(QApplication::translate("AppMainClass", "Rotate CP X", nullptr));
        rcpxadd->setText(QString());
        rcpxsub->setText(QString());
        groupBox_2->setTitle(QApplication::translate("AppMainClass", "Rotate CP Z", nullptr));
        rcpzadd->setText(QString());
        rcpzsub->setText(QString());
        groupBox_9->setTitle(QApplication::translate("AppMainClass", "Car Number", nullptr));
        addCar->setText(QString());
        rmCar->setText(QString());
        groupBox_10->setTitle(QApplication::translate("AppMainClass", "Jump", nullptr));
        mvForward->setText(QString());
        mvBackword->setText(QString());
        groupTrack_2->setTitle(QApplication::translate("AppMainClass", "style", nullptr));
        comboStyle->setItemText(0, QApplication::translate("AppMainClass", "ClassicTrain", nullptr));
        comboStyle->setItemText(1, QApplication::translate("AppMainClass", "Simple", nullptr));
        comboStyle->setItemText(2, QApplication::translate("AppMainClass", "RollerCoaster", nullptr));

        comboStyle->setCurrentText(QApplication::translate("AppMainClass", "ClassicTrain", nullptr));
        drawSleeper->setTitle(QApplication::translate("AppMainClass", "Sleeper", nullptr));
        drawSleeper_2->setTitle(QApplication::translate("AppMainClass", "Tension", nullptr));
        groupBox_5->setTitle(QApplication::translate("AppMainClass", "Subdivision", nullptr));
        menuFile->setTitle(QApplication::translate("AppMainClass", "File", nullptr));
        menuCamera->setTitle(QApplication::translate("AppMainClass", "Camera", nullptr));
        menuCurve->setTitle(QApplication::translate("AppMainClass", "Curve", nullptr));
        menuTrack->setTitle(QApplication::translate("AppMainClass", "Track", nullptr));
        menuVelocity->setTitle(QApplication::translate("AppMainClass", "Velocity", nullptr));
        menustyle->setTitle(QApplication::translate("AppMainClass", "Style", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AppMainClass: public Ui_AppMainClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPMAIN_H
