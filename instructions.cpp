#include "instructions.h"

Instructions::Instructions(QWidget *parent) : QWidget(parent)
{

}

//#include "instructions.h"

//Instructions::Instructions(QWidget *parent)
//    : QWidget(parent)
//{
//    title = new QLabel("INSTRUCTIONS");
//    backToHome = new QPushButton("BACK");
//    fullwindow = new QVBoxLayout();
//    fullwindow->addWidget(backToHome);
//    setLayout(fullwindow);
//}

//void Instructions::setPartner(QWidget* partner) {
//    if (partner == 0)
//        return;
//    if (mPartner != partner) {
//        if (mPartner != 0) {
//            disconnect(backToHome, SIGNAL(clicked()), this, SLOT(hide()));
//            disconnect(backToHome, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
//        }
//        mPartner = partner;
//        connect(backToHome, SIGNAL(clicked()), this, SLOT(hide()));
//        connect(backToHome, SIGNAL(clicked()), mPartner, SLOT(showMaximized()));
//    }
//}
