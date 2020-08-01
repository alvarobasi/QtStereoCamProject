/********************************************************************************
** Form generated from reading UI file 'QtStereoCamProject.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSTEREOCAMPROJECT_H
#define UI_QTSTEREOCAMPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "QtImageManager.h"

QT_BEGIN_NAMESPACE

class Ui_QtStereoCamProjectClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFrame *line;
    CQtImageManager *camLeft_openGLWidget;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QFrame *line_2;
    CQtImageManager *camRight_openGLWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *takePic_pushButton;
    QPushButton *startCapture_pushButton;
    QPushButton *calibrateCameras_pushButton;
    QPushButton *computeDisparityMap_pushButton;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QSlider *focus_verticalSlider;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QSlider *brightness_verticalSlider;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_3;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpinBox *width_spinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_5;
    QSpinBox *height_spinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QDoubleSpinBox *size_doubleSpinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtStereoCamProjectClass)
    {
        if (QtStereoCamProjectClass->objectName().isEmpty())
            QtStereoCamProjectClass->setObjectName(QStringLiteral("QtStereoCamProjectClass"));
        QtStereoCamProjectClass->resize(946, 668);
        centralWidget = new QWidget(QtStereoCamProjectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_7 = new QVBoxLayout(centralWidget);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 15));

        verticalLayout->addWidget(label);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        camLeft_openGLWidget = new CQtImageManager(centralWidget);
        camLeft_openGLWidget->setObjectName(QStringLiteral("camLeft_openGLWidget"));

        verticalLayout->addWidget(camLeft_openGLWidget);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 15));

        verticalLayout_2->addWidget(label_2);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        camRight_openGLWidget = new CQtImageManager(centralWidget);
        camRight_openGLWidget->setObjectName(QStringLiteral("camRight_openGLWidget"));

        verticalLayout_2->addWidget(camRight_openGLWidget);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout_7->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        takePic_pushButton = new QPushButton(centralWidget);
        takePic_pushButton->setObjectName(QStringLiteral("takePic_pushButton"));
        takePic_pushButton->setMaximumSize(QSize(60, 30));

        horizontalLayout_5->addWidget(takePic_pushButton);

        startCapture_pushButton = new QPushButton(centralWidget);
        startCapture_pushButton->setObjectName(QStringLiteral("startCapture_pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(startCapture_pushButton->sizePolicy().hasHeightForWidth());
        startCapture_pushButton->setSizePolicy(sizePolicy);
        startCapture_pushButton->setMaximumSize(QSize(16777215, 30));
        startCapture_pushButton->setCheckable(true);

        horizontalLayout_5->addWidget(startCapture_pushButton);

        calibrateCameras_pushButton = new QPushButton(centralWidget);
        calibrateCameras_pushButton->setObjectName(QStringLiteral("calibrateCameras_pushButton"));
        calibrateCameras_pushButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_5->addWidget(calibrateCameras_pushButton);

        computeDisparityMap_pushButton = new QPushButton(centralWidget);
        computeDisparityMap_pushButton->setObjectName(QStringLiteral("computeDisparityMap_pushButton"));
        computeDisparityMap_pushButton->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_5->addWidget(computeDisparityMap_pushButton);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMaximumSize(QSize(16777215, 15));

        verticalLayout_5->addWidget(label_7);

        focus_verticalSlider = new QSlider(centralWidget);
        focus_verticalSlider->setObjectName(QStringLiteral("focus_verticalSlider"));
        focus_verticalSlider->setMaximumSize(QSize(16777215, 100));
        focus_verticalSlider->setMinimum(0);
        focus_verticalSlider->setMaximum(50);
        focus_verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout_5->addWidget(focus_verticalSlider);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMaximumSize(QSize(16777215, 15));

        verticalLayout_6->addWidget(label_8);

        brightness_verticalSlider = new QSlider(centralWidget);
        brightness_verticalSlider->setObjectName(QStringLiteral("brightness_verticalSlider"));
        brightness_verticalSlider->setMaximumSize(QSize(16777215, 100));
        brightness_verticalSlider->setMaximum(255);
        brightness_verticalSlider->setValue(50);
        brightness_verticalSlider->setOrientation(Qt::Vertical);

        verticalLayout_6->addWidget(brightness_verticalSlider);


        horizontalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(200, 15));

        verticalLayout_3->addWidget(label_3);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setMaximumSize(QSize(16777215, 5));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_3);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(60, 15));

        horizontalLayout_2->addWidget(label_4);

        width_spinBox = new QSpinBox(centralWidget);
        width_spinBox->setObjectName(QStringLiteral("width_spinBox"));
        width_spinBox->setMaximumSize(QSize(50, 20));
        width_spinBox->setValue(9);

        horizontalLayout_2->addWidget(width_spinBox);


        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMaximumSize(QSize(60, 15));

        horizontalLayout_3->addWidget(label_5);

        height_spinBox = new QSpinBox(centralWidget);
        height_spinBox->setObjectName(QStringLiteral("height_spinBox"));
        height_spinBox->setMaximumSize(QSize(50, 20));
        height_spinBox->setValue(6);

        horizontalLayout_3->addWidget(height_spinBox);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMaximumSize(QSize(100, 15));

        horizontalLayout_4->addWidget(label_6);

        size_doubleSpinBox = new QDoubleSpinBox(centralWidget);
        size_doubleSpinBox->setObjectName(QStringLiteral("size_doubleSpinBox"));
        size_doubleSpinBox->setMaximumSize(QSize(60, 20));
        size_doubleSpinBox->setValue(24.23);

        horizontalLayout_4->addWidget(size_doubleSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_4);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_7->addLayout(horizontalLayout_5);

        QtStereoCamProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtStereoCamProjectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 946, 21));
        QtStereoCamProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtStereoCamProjectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtStereoCamProjectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtStereoCamProjectClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtStereoCamProjectClass->setStatusBar(statusBar);

        retranslateUi(QtStereoCamProjectClass);

        QMetaObject::connectSlotsByName(QtStereoCamProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtStereoCamProjectClass)
    {
        QtStereoCamProjectClass->setWindowTitle(QApplication::translate("QtStereoCamProjectClass", "QtStereoCamProject", nullptr));
        label->setText(QApplication::translate("QtStereoCamProjectClass", "Left Camera", nullptr));
        label_2->setText(QApplication::translate("QtStereoCamProjectClass", "Right Camera", nullptr));
        takePic_pushButton->setText(QApplication::translate("QtStereoCamProjectClass", "Take Pic", nullptr));
        startCapture_pushButton->setText(QApplication::translate("QtStereoCamProjectClass", "Start Capture", nullptr));
        calibrateCameras_pushButton->setText(QApplication::translate("QtStereoCamProjectClass", "Calibrate Cameras", nullptr));
        computeDisparityMap_pushButton->setText(QApplication::translate("QtStereoCamProjectClass", "Disparity Map", nullptr));
        label_7->setText(QApplication::translate("QtStereoCamProjectClass", "Focus", nullptr));
        label_8->setText(QApplication::translate("QtStereoCamProjectClass", "Brightness", nullptr));
        label_3->setText(QApplication::translate("QtStereoCamProjectClass", "Chessboard Parameters", nullptr));
        label_4->setText(QApplication::translate("QtStereoCamProjectClass", "Width", nullptr));
        label_5->setText(QApplication::translate("QtStereoCamProjectClass", "Height", nullptr));
        label_6->setText(QApplication::translate("QtStereoCamProjectClass", "Square Size (mm)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtStereoCamProjectClass: public Ui_QtStereoCamProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSTEREOCAMPROJECT_H
