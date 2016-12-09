#include "custompolygonitem.h"
#include "QDebug"
#include <QGraphicsSceneMouseEvent>
CustomPolygonItem::CustomPolygonItem(const QPolygonF &x):QGraphicsPolygonItem(x)
{
    setFlags(QGraphicsItem::ItemIsSelectable |
            QGraphicsItem::ItemIsMovable |
            QGraphicsItem::ItemSendsGeometryChanges);
    setZValue(0);

    //QPointF glevo=this->boundingRect().topLeft();
    //QPointF ddesno=this->boundingRect().bottomRight();
    //setTransformOriginPoint( ((glevo.x()+ddesno.x())/2), ((glevo.y()+ddesno.y())/2) );
    //setScale(0.99);
}

QVariant CustomPolygonItem::itemChange(GraphicsItemChange change,
const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        if(QApplication::mouseButtons() == Qt::LeftButton &&
                qobject_cast<Scene*> (scene())){
            Scene* customScene = qobject_cast<Scene*> (scene());
            int gridSize = customScene->getGridSize();
            qDebug()<<newPos.x()<<" "<<newPos.y() ;
            if( (newPos.x()>-100 && newPos.x()<100) && (newPos.y()>-80 && newPos.y()<100) &&
                 (newPos.x()+this->boundingRect().bottomRight().x())>-100 && (newPos.x()+this->boundingRect().bottomRight().x())<100 &&
                 (newPos.y()+this->boundingRect().bottomRight().y())<100 && (newPos.y()+this->boundingRect().bottomRight().y())>-100 &&
                 (newPos.x()+this->boundingRect().topLeft().x())>-100 && (newPos.x()+this->boundingRect().topLeft().x())<100 &&
                 (newPos.y()+this->boundingRect().topLeft().y())<100 && (newPos.y()+this->boundingRect().topLeft().y())>-100 &&
                 (newPos.x()+this->boundingRect().bottomLeft().x())<100 && (newPos.x()+this->boundingRect().bottomLeft().x())>-100 &&
                 (newPos.y()+this->boundingRect().bottomLeft().y())<100 && (newPos.y()+this->boundingRect().bottomLeft().y())>-100 &&
                 (newPos.x()+this->boundingRect().topRight().x())>-100 && (newPos.x()+this->boundingRect().topRight().x())<100 &&
                 (newPos.y()+this->boundingRect().topRight().y())<100 && (newPos.y()+this->boundingRect().topRight().y())>-100
                    ){
                qreal xV = round(newPos.x()/gridSize)*gridSize;
                qreal yV = round(newPos.y()/gridSize)*gridSize;
                return QPointF(xV, yV);
            }
            else if(newPos.x()>130 || newPos.x()<-150 || newPos.y()<-140 || newPos.y()>120){
                return QPointF( (newPos.x()>0?fmin(newPos.x(),130):fmax(newPos.x(),-150)) , (newPos.y()>0?fmin(newPos.y(),120):fmax(newPos.y(),-140)));// linja koda == pro
            }
            else
                return QPointF(newPos.x(),newPos.y());
        }
        else
            return newPos;
    }
    else
        return QGraphicsItem::itemChange(change, value);
}



void CustomPolygonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event){
    QGraphicsItem::mouseReleaseEvent(event); //zivot je tezak
//    qDebug()<<this->pos();
    this->setZValue(0);
//    if(btflag==true) {
//        this->setPos(btx,bty);
//    }
    QList<QGraphicsItem *> x=scene()->items();
    QGraphicsItem *tabla=x.back();
    for(QList<QGraphicsItem *>::ConstIterator i=x.begin();i<x.end()-1;i++ ){
        if(this==*i) continue;
        if(this->collidesWithItem(*i))
            this->setPos(btx,bty);

    }
    if( ((tabla->contains(this->pos() + this->boundingRect().bottomLeft())) && !(tabla->contains(this->pos() + this->boundingRect().topRight()))) ||
        (!(tabla->contains(this->pos() + this->boundingRect().bottomLeft())) && (tabla->contains(this->pos() + this->boundingRect().topRight()))) ||
        ((tabla->contains(this->pos() + this->boundingRect().topLeft())) && !(tabla->contains(this->pos() + this->boundingRect().bottomRight()))) ||
        (!(tabla->contains(this->pos() + this->boundingRect().topLeft())) && (tabla->contains(this->pos() + this->boundingRect().bottomRight())))
      )
        this->setPos(btx,bty);

}

void CustomPolygonItem::mousePressEvent(QGraphicsSceneMouseEvent * event){
    QGraphicsItem::mousePressEvent(event); //zivot je tezak
//    qDebug()<<this->transformOriginPoint()<<" "<< this->boundingRect().topLeft() << " " << this->boundingRect().bottomRight();
        this->setZValue(69);
    btx=this->pos().x();
    bty=this->pos().y();

}


