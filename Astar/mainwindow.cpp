#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qlabel.h"
#include "qgridlayout.h"
#include "mybutton.h"
#include "cube.h"
#include "ai.h"
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
    connect(StartPoint, SIGNAL(clicked()), this, SLOT(on_StartPoint_Clicked()));
    StartPoint->setStyleSheet("background-color: rgb(200,200,200)");

    BlockPoint = new QPushButton("Block Point", this);
    BlockPoint->move(250, 630);
    connect(BlockPoint, SIGNAL(clicked()), this, SLOT(on_BlockPoint_Clicked()));
    BlockPoint->setStyleSheet("background-color: rgb(200,200,200)");

    FinalPoint = new QPushButton("Final Point", this);
    FinalPoint->move(450, 630);
    connect(FinalPoint, SIGNAL(clicked()), this, SLOT(on_FinalPoint_Clicked()));
    FinalPoint->setStyleSheet("background-color: rgb(200,200,200)");

    FindRoadBtn = new QPushButton("Find Road", this);
    FindRoadBtn->move(450, 30);
    connect(FindRoadBtn, SIGNAL(clicked()), this, SLOT(on_FindRoadBtn_Clicked()));
    FindRoadBtn->setStyleSheet("background-color: rgb(51,136,255)");

    NewGameBtn = new QPushButton("New Game", this);
    NewGameBtn->move(450, 70);
    connect(NewGameBtn, SIGNAL(clicked()), this, SLOT(on_NewGameBtn_Clicked()));
    NewGameBtn->setStyleSheet("background-color: rgb(237,197,63)");

    TitleLabel = new QLabel("Astar-Algorithm", this);
    TitleLabel->move(30,30);
    TitleLabel->setStyleSheet("color:#00A67C");
    TitleLabel->setFont(QFont("Timers", 28, QFont::Bold));
    TitleLabel->adjustSize();

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
            Coord cd = {i,j};
            buttonArr[i][j] = new myButton(cd);
            buttonArr[i][j]->setStatus(-1);
            buttonArr[i][j]->setMaximumHeight(15);
            buttonArr[i][j]->setMinimumHeight(15);
            buttonArr[i][j]->setMaximumWidth(15);
            buttonArr[i][j]->setMinimumWidth(15);
            buttonArr[i][j]->setStyleSheet("background-color: rgb(255,125,60)");
            layout->addWidget(buttonArr[i][j],i,j);
            connect(buttonArr[i][j],SIGNAL(myClick(myButton*)),this,SLOT(on_button_Clicked(myButton*)));
        }
    }

    for (int i = 0; i < 40; i ++){
        for (int j = 0; j < 40; j ++){
            cubeArr[i][j] = new cube();
        }
    }
    for (int i = 0; i < 40; i ++){
        for (int j = 0; j < 40; j ++){
            cubeArr[i][j]->coord = {i,j};

            if(i == 0 && j > 0 && j < 39){
                cubeArr[i][j]->setUpPoint(NULL);
                cubeArr[i][j]->setLeftPoint(cubeArr[i][j-1]);
                cubeArr[i][j]->setDownPoint(cubeArr[i+1][j]);
                cubeArr[i][j]->setRightPoint(cubeArr[i][j+1]);
                cubeArr[i][j]->setLeft_UpPoint(NULL);
                cubeArr[i][j]->setRight_UpPoint(NULL);
                cubeArr[i][j]->setLeft_DownPoint(cubeArr[i+1][j-1]);
                cubeArr[i][j]->setRight_DownPoint(cubeArr[i+1][j+1]);
            }
            else if(j == 0 && i > 0 && i < 39){
                cubeArr[i][j]->setUpPoint(cubeArr[i-1][j]);
                cubeArr[i][j]->setLeftPoint(NULL);
                cubeArr[i][j]->setDownPoint(cubeArr[i+1][j]);
                cubeArr[i][j]->setRightPoint(cubeArr[i][j+1]);
                cubeArr[i][j]->setLeft_UpPoint(NULL);
                cubeArr[i][j]->setRight_UpPoint(cubeArr[i-1][j+1]);
                cubeArr[i][j]->setLeft_DownPoint(NULL);
                cubeArr[i][j]->setRight_DownPoint(cubeArr[i+1][j+1]);
            }
            else if(i == 39 && j > 0 && j < 39){
                cubeArr[i][j]->setUpPoint(cubeArr[i-1][j]);
                cubeArr[i][j]->setLeftPoint(cubeArr[i][j-1]);
                cubeArr[i][j]->setDownPoint(NULL);
                cubeArr[i][j]->setRightPoint(cubeArr[i][j+1]);
                cubeArr[i][j]->setLeft_UpPoint(cubeArr[i-1][j-1]);
                cubeArr[i][j]->setRight_UpPoint(cubeArr[i-1][j+1]);
                cubeArr[i][j]->setLeft_DownPoint(NULL);
                cubeArr[i][j]->setRight_DownPoint(NULL);
            }
            else if(j == 39 && i > 0 && i < 39){
                cubeArr[i][j]->setUpPoint(cubeArr[i-1][j]);
                cubeArr[i][j]->setLeftPoint(cubeArr[i][j-1]);
                cubeArr[i][j]->setDownPoint(cubeArr[i+1][j]);
                cubeArr[i][j]->setRightPoint(NULL);
                cubeArr[i][j]->setLeft_UpPoint(cubeArr[i-1][j-1]);
                cubeArr[i][j]->setRight_UpPoint(NULL);
                cubeArr[i][j]->setLeft_DownPoint(cubeArr[i+1][j-1]);
                cubeArr[i][j]->setRight_DownPoint(NULL);
            }
            else if(i == 0 && j == 0){
                cubeArr[i][j]->setUpPoint(NULL);
                cubeArr[i][j]->setLeftPoint(NULL);
                cubeArr[i][j]->setDownPoint(cubeArr[i+1][j]);
                cubeArr[i][j]->setRightPoint(cubeArr[i][j+1]);
                cubeArr[i][j]->setLeft_UpPoint(NULL);
                cubeArr[i][j]->setRight_UpPoint(NULL);
                cubeArr[i][j]->setLeft_DownPoint(NULL);
                cubeArr[i][j]->setRight_DownPoint(cubeArr[i+1][j+1]);
            }
            else if(i == 0 && j == 39){
                cubeArr[i][j]->setUpPoint(NULL);
                cubeArr[i][j]->setLeftPoint(cubeArr[i][j-1]);
                cubeArr[i][j]->setDownPoint(cubeArr[i+1][j]);
                cubeArr[i][j]->setRightPoint(NULL);
                cubeArr[i][j]->setLeft_UpPoint(NULL);
                cubeArr[i][j]->setRight_UpPoint(NULL);
                cubeArr[i][j]->setLeft_DownPoint(cubeArr[i+1][j-1]);
                cubeArr[i][j]->setRight_DownPoint(NULL);
            }
            else if(i == 39 && j == 0){
                cubeArr[i][j]->setUpPoint(cubeArr[i-1][j]);
                cubeArr[i][j]->setLeftPoint(NULL);
                cubeArr[i][j]->setDownPoint(NULL);
                cubeArr[i][j]->setRightPoint(cubeArr[i][j+1]);
                cubeArr[i][j]->setLeft_UpPoint(NULL);
                cubeArr[i][j]->setRight_UpPoint(cubeArr[i-1][j+1]);
                cubeArr[i][j]->setLeft_DownPoint(NULL);
                cubeArr[i][j]->setRight_DownPoint(NULL);
            }
            else if(i == 39 && j == 39){
                cubeArr[i][j]->setUpPoint(cubeArr[i-1][j]);
                cubeArr[i][j]->setLeftPoint(cubeArr[i][j-1]);
                cubeArr[i][j]->setDownPoint(NULL);
                cubeArr[i][j]->setRightPoint(NULL);
                cubeArr[i][j]->setLeft_UpPoint(cubeArr[i-1][j-1]);
                cubeArr[i][j]->setRight_UpPoint(NULL);
                cubeArr[i][j]->setLeft_DownPoint(NULL);
                cubeArr[i][j]->setRight_DownPoint(NULL);
            }
            else{
                cubeArr[i][j]->setUpPoint(cubeArr[i-1][j]);
                cubeArr[i][j]->setLeftPoint(cubeArr[i][j-1]);
                cubeArr[i][j]->setDownPoint(cubeArr[i+1][j]);
                cubeArr[i][j]->setRightPoint(cubeArr[i][j+1]);
                cubeArr[i][j]->setLeft_UpPoint(cubeArr[i-1][j-1]);
                cubeArr[i][j]->setRight_UpPoint(cubeArr[i-1][j+1]);
                cubeArr[i][j]->setLeft_DownPoint(cubeArr[i+1][j-1]);
                cubeArr[i][j]->setRight_DownPoint(cubeArr[i+1][j+1]);
            }
        }
    }
}

void MainWindow::on_StartPoint_Clicked(){
    situation = 0;
    cout << "situation: " << situation << endl;
}

void MainWindow::on_BlockPoint_Clicked(){
    situation = 1;
}

void MainWindow::on_FinalPoint_Clicked(){
    situation = 2;
}

void MainWindow::on_FindRoadBtn_Clicked(){

    int startpoint_x = -1;
    int startpoint_y = -1;
    int finalpoint_x = -1;
    int finalpoint_y = -1;
    cube *tempCube;
    Coord cd;
    for (int i = 0; i < 40; i ++){
        for (int j = 0; j < 40; j ++){
            cubeArr[i][j]->getStatus(buttonArr[i][j]->status);
            if (cubeArr[i][j]->status == 0){
                startpoint_x = i;
                startpoint_y = j;
            }
            if (cubeArr[i][j]->status == 2){
                finalpoint_x = i;
                finalpoint_y = j;
            }
        }
    }


    AI *ai = new AI();
    ai->newalgorithm(cubeArr,startpoint_x, startpoint_y, finalpoint_x, finalpoint_y);

    //track back the final road
    tempCube = cubeArr[finalpoint_x][finalpoint_y]->parent;
    cout << tempCube->coord.x << " " << tempCube->coord.y << endl;
    while(true){
        cd.x = tempCube->coord.x;
        cd.y = tempCube->coord.y;
        cout << "cd: " << cd.x << " " << cd.y << endl;
        buttonArr[cd.x][cd.y]->setStyleSheet("background-color: rgb(50,150,20)");
        tempCube = tempCube->parent;
        if(tempCube->status == 0){
            break;
        }
    }
}

void MainWindow::on_button_Clicked(myButton *p){
    p->setStatus(situation);
    if (situation == 0 && StartPointCount == 1){//choose the start point
        p->setStyleSheet("background-color: rgb(88,155,180)");
        StartPointCount ++;//only be clicked once
    }

    else if(situation == 1){//choose the block points
        p->setStyleSheet("background-color: rgb(200,200,230)");
        BlockPointCount ++;
    }

    else if(situation == 2 && FinalPointCount == 1){//choose the final point
        p->setStyleSheet("background-color: rgb(30,30,30)");
        FinalPointCount ++;
    }
}

void MainWindow::on_NewGameBtn_Clicked(){
    for (int i = 0; i < 40; i ++){
        for (int j = 0; j < 40; j ++){
            cubeArr[i][j]->getG(0);
            cubeArr[i][j]->getH(0);
            cubeArr[i][j]->getF();
            cubeArr[i][j]->parent = NULL;
            cubeArr[i][j]->getStatus(-1);
            buttonArr[i][j]->setStatus(-1);
            buttonArr[i][j]->setStyleSheet("background-color: rgb(255,125,60)");
        }
    }

    situation = -1;
    StartPointCount = 1;
    BlockPointCount = 0;
    FinalPointCount = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
