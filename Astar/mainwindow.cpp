#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qlabel.h"
#include "button.h"
#include "qgridlayout.h"
#include <cmath>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(600,700);
    ui->setupUi(this);

    StartPoint = new QPushButton("Start Point", this);
    StartPoint->move(50, 630);
    //connect(StartPoint, SIGNAL(clicked()), this, SLOT(on_StartPoint_Clicked()));
    StartPoint->setStyleSheet("background-color: rgb(88,155,180)");
    BlockPoint = new QPushButton("Block Point", this);
    BlockPoint->move(250, 630);
    //connect(BlockPoint, SIGNAL(clicked()), this, SLOT(on_BlockPoint_Clicked()));
    BlockPoint->setStyleSheet("background-color: rgb(200,200,230)");
    FinalPoint = new QPushButton("Final Point", this);
    FinalPoint->move(450, 630);
    //connect(FinalPoint, SIGNAL(clicked()), this, SLOT(on_FinalPoint_Clicked()));
    FinalPoint->setStyleSheet("background-color: rgb(150,40,20)");

    // layout belongs to buttonArea
    // buttonArea belongs to layoutofWidget
    // layoutofWidget is layout of centralWidget
    QGridLayout *layout = new QGridLayout;
    QGridLayout *layoutofWidget = new QGridLayout;
    QWidget *buttonArea = new QWidget;
    buttonArea->move(0,0);
    buttonArea->setFixedSize(500,500);
    buttonArea->setLayout(layout);
    layoutofWidget->addWidget(buttonArea);
    ui->centralWidget->setLayout(layoutofWidget);

    for(int i = 0; i < 40; i ++){
        for (int j = 0; j < 40; j ++){
            buttonArr[i][j] = new button();
            buttonArr[i][j]->setMaximumHeight(15);
            buttonArr[i][j]->setMinimumHeight(15);
            buttonArr[i][j]->setMaximumWidth(15);
            buttonArr[i][j]->setMinimumWidth(15);
            buttonArr[i][j]->setPoint(i, j);
            buttonArr[i][j]->setStyleSheet("background-color: rgb(255,125,60)");
            layout->addWidget(buttonArr[i][j],i,j);
            //connect(buttonArr[i][j],SIGNAL(clicked(bool)),this,SLOT(on_button_Clicked(button*)));
        }
    }
}

void MainWindow::on_StartPoint_Clicked(){
    situation = 0;
}

void MainWindow::on_BlockPoint_Clicked(){
    situation = 1;
}

void MainWindow::on_FinalPoint_Clicked(){
    situation = 2;
}
/*
void MainWindow::on_button_Clicked(button *p){
    int x, y;
    p->getCoordinate(x, y);
    buttonArr[x][y]->setStatus(situation);

    if (situation == 0 && startPointCount == 1){//choose the start point
        buttonArr[x][y]->setStyleSheet("background-color: rgb(88,155,180)");
        startPointCount ++;//only be clicked once
    }

    else if(situation == 1){//choose the block points
        buttonArr[x][y]->setStyleSheet("background-color: rgb(200,200,230)");
        BlockPointCount ++;
    }

    else{//choose the final point
        buttonArr[x][y]->setStyleSheet("background-color: rgb(150,40,20)");
    }
}*/

MainWindow::~MainWindow()
{
    delete ui;
}
