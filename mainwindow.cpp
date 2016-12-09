#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include "scene.h"
#include "customrectitem.h"
#include "custompolygonitem.h"
#include <vector>
#include <QDebug>
#include "dialog.h"

std::vector <CustomPolygonItem *> glb;

Scene *scene;

void MainWindow::nesto(void){
    Dialog win;
    qDebug()<<"pobeda je emitovana";
    win.setWindowTitle("Svaka čast!");
    win.exec();
    reset();
}

void MainWindow::reset(void) {
    int broj=0;
    for(std::vector<CustomPolygonItem *>::const_iterator i=glb.begin();i<glb.end();i++, broj++){
        switch(broj) {
        case 0: (*i)->setPos(-80,-119); break;
        case 1: (*i)->setPos(-8,-130); break;
        case 2: (*i)->setPos(94,-131); break;
        case 3: (*i)->setPos(130,-75); break;
        case 4: (*i)->setPos(121,1); break;
        case 5: (*i)->setPos(124,67); break;
        case 6: (*i)->setPos(30,107); break;
        case 7: (*i)->setPos(-52,-118); break;
        case 8: (*i)->setPos(-140,90); break;
        case 9: (*i)->setPos(-149,21); break;
        case 10: (*i)->setPos(-151,-77); break;
        case 11: (*i)->setPos(-78,-118); break;
        }
    }

    //qDebug()<<"ALLAHU AKBAR~!!!"<<glb.size();

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene=new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(-10,-10,20,20);
    Dialog dialog;
    dialog.setModal(true);
    QPolygonF p,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;

    p.append(QPoint(0,0));
    p.append(QPoint(20,0));
    p.append(QPoint(20,20));
    p.append(QPoint(0,20));

    p2.append(QPoint(0,0));
    p2.append(QPoint(-40,0));
    p2.append(QPoint(-40,-40));
    p2.append(QPoint(-21,-40));
    p2.append(QPoint(-21,-19));
    p2.append(QPoint(0,-19));

    p3.append(QPoint(0,0));
    p3.append(QPoint(20,0));
    p3.append(QPoint(20,40));
    p3.append(QPoint(0,40));

    p4.append(QPoint(21,0));
    p4.append(QPoint(21,41));
    p4.append(QPoint(0,41));
    p4.append(QPoint(0,60));
    p4.append(QPoint(40,60));
    p4.append(QPoint(40,0));

    p5.append(QPoint(21,0));
    p5.append(QPoint(21,21));
    p5.append(QPoint(0,21));
    p5.append(QPoint(0,40));
    p5.append(QPoint(39,40));
    p5.append(QPoint(39,19));
    p5.append(QPoint(60,19));
    p5.append(QPoint(60,0));

    p6.append(QPoint(0,0));
    p6.append(QPoint(0,20));
    p6.append(QPoint(40,20));
    p6.append(QPoint(40,0));

    p7.append(QPoint(0,0));
    p7.append(QPoint(40,0));
    p7.append(QPoint(40,40));
    p7.append(QPoint(0,40));

    p8.append(QPoint(0,0));
    p8.append(QPoint(60,0));
    p8.append(QPoint(60,20));
    p8.append(QPoint(0,20));

    p9.append(QPoint(21,0));
    p9.append(QPoint(21,21));
    p9.append(QPoint(0,21));
    p9.append(QPoint(0,40));
    p9.append(QPoint(40,40));
    p9.append(QPoint(40,0));

    p10.append(QPoint(0,0));
    p10.append(QPoint(0,60));
    p10.append(QPoint(19,60));
    p10.append(QPoint(19,39));
    p10.append(QPoint(40,39));
    p10.append(QPoint(40,0));

    p11.append(QPoint(21,0));
    p11.append(QPoint(21,21));
    p11.append(QPoint(0,21));
    p11.append(QPoint(0,60));
    p11.append(QPoint(40,60));
    p11.append(QPoint(40,0));





    CustomPolygonItem *pitem=new CustomPolygonItem(QPolygonF(p));
    CustomPolygonItem *pitem2=new CustomPolygonItem(QPolygonF(p2));
    CustomPolygonItem *pitem3=new CustomPolygonItem(QPolygonF(p3));
    CustomPolygonItem *pitem4=new CustomPolygonItem(QPolygonF(p4));
    CustomPolygonItem *pitem5=new CustomPolygonItem(QPolygonF(p5));
    CustomPolygonItem *pitem6=new CustomPolygonItem(QPolygonF(p6));
    CustomPolygonItem *pitem7=new CustomPolygonItem(QPolygonF(p7));
    CustomPolygonItem *pitem8=new CustomPolygonItem(QPolygonF(p8));
    CustomPolygonItem *pitem9=new CustomPolygonItem(QPolygonF(p9));
    CustomPolygonItem *pitem10=new CustomPolygonItem(QPolygonF(p10));
    CustomPolygonItem *pitem11=new CustomPolygonItem(QPolygonF(p11));


    glb.push_back(pitem);glb.push_back(pitem2);glb.push_back(pitem3);glb.push_back(pitem4);
    glb.push_back(pitem5);glb.push_back(pitem6);glb.push_back(pitem7);glb.push_back(pitem8);
    glb.push_back(pitem9);glb.push_back(pitem10);glb.push_back(pitem11);
    connect(scene,SIGNAL(gratz()),this,SLOT(nesto()));
    reset();
    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(reset()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(close()));
    pitem->setBrush(Qt::red);
    pitem2->setBrush(Qt::green);
    pitem3->setBrush(Qt::blue);
    pitem4->setBrush(Qt::yellow);
    pitem5->setBrush(Qt::cyan);
    pitem6->setBrush(Qt::darkMagenta);
    pitem7->setBrush(Qt::darkYellow);
    pitem8->setBrush(Qt::darkGreen);
    pitem9->setBrush(Qt::darkRed);
    pitem10->setBrush(Qt::black);
    pitem11->setBrush(Qt::magenta);

    pitem->setPen(Qt::NoPen);
    pitem2->setPen(Qt::NoPen);
    pitem3->setPen(Qt::NoPen);
    pitem4->setPen(Qt::NoPen);
    pitem5->setPen(Qt::NoPen);
    pitem6->setPen(Qt::NoPen);
    pitem7->setPen(Qt::NoPen);
    pitem8->setPen(Qt::NoPen);
    pitem9->setPen(Qt::NoPen);
    pitem10->setPen(Qt::NoPen);
    pitem11->setPen(Qt::NoPen);


    QGraphicsRectItem *gridtabla= new QGraphicsRectItem(-60,-60,120,120);
    gridtabla->setBrush(QBrush(QColor(0,50,20,100)));
    scene->addItem(gridtabla);

    scene->addItem(pitem);
    scene->addItem(pitem2);
    scene->addItem(pitem3);
    scene->addItem(pitem4);
    scene->addItem(pitem5);
    scene->addItem(pitem6);
    scene->addItem(pitem7);
    scene->addItem(pitem8);
    scene->addItem(pitem9);
    scene->addItem(pitem10);
    scene->addItem(pitem11);



}
MainWindow::~MainWindow()
{
    delete ui;
}




