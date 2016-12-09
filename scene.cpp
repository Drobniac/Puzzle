#include "scene.h"
#include "math.h"
#include <QDebug>


bool btflag=false;

Scene::Scene(QObject *parent) :
    QGraphicsScene(parent), gridSize(20)
{
    Q_ASSERT(gridSize > 0);

}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent)
{
      QGraphicsScene::mouseReleaseEvent(mouseEvent); // zivot je pretezak
    bool SviUnutra=true,PreklapajuSe=false;

    //qDebug()<<"scene release";
    QList<QGraphicsItem *> x=this->items();
    for(QList<QGraphicsItem *>::ConstIterator i=x.begin();i<x.end()-1;i++ ){
        if( ((*i)->pos().x()>=-60 && (*i)->pos().x()<=60) && ((*i)->pos().y()>=-60 && (*i)->pos().y()<=60) &&
                ((*i)->pos().x()+trunc((*i)->boundingRect().bottomRight().x()))<=60 && //trunc zato sto mutavi qt dodaje neko djubre od dimenzija ffs
                ((*i)->pos().y()+trunc((*i)->boundingRect().bottomRight().y()))>=-60 &&
                ((*i)->pos().x()+trunc((*i)->boundingRect().topLeft().x()))>=-60 && //trunc zato sto mutavi qt dodaje neko djubre od dimenzija ffs
                ((*i)->pos().y()+trunc((*i)->boundingRect().topLeft().y()))<=60 &&
                ((*i)->pos().x()+trunc((*i)->boundingRect().topRight().x()))<=60 && //trunc zato sto mutavi qt dodaje neko djubre od dimenzija ffs
                ((*i)->pos().y()+trunc((*i)->boundingRect().topRight().y()))>=-60 &&
                ((*i)->pos().x()+trunc((*i)->boundingRect().bottomLeft().x()))>=-60 && //trunc zato sto mutavi qt dodaje neko djubre od dimenzija ffs
                ((*i)->pos().y()+trunc((*i)->boundingRect().bottomLeft().y()))<=60
        )
            SviUnutra&=true;
        else
            SviUnutra&=false;
        for (QList<QGraphicsItem *>::ConstIterator j=x.begin();j<x.end()-1;j++ ) {
            if(j==i) continue;
            PreklapajuSe|=(*i)->collidesWithItem(*j);
        }


    }
    if(SviUnutra)
        qDebug()<<"Svi su unutra";
    else
        qDebug()<<"Neko viri";
    if(PreklapajuSe)
        qDebug()<<"Neki Objekti se seku";
    else
        qDebug()<<"Svi su netaknuti";

    if(SviUnutra && !PreklapajuSe) {
        qDebug()<<"Napravi Gratz i reset";
        emit gratz();
    }
}



void Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QPen pen;
    painter->setPen(pen);


    QVector<QPointF> points;
    for (qreal x = -60; x < 60; x += gridSize){

        for (qreal y = -60; y < 60; y += gridSize){
            points.append(QPointF(x,y));
            for(qreal ii=-60;ii<60;ii+=2){
                points.append(QPointF(ii,y));
                points.append(QPointF(x,ii));
            }
        }
    }
    painter->drawPoints(points.data(), points.size());
}
