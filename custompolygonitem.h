#ifndef CUSTOMPOLYGONITEM_H
#define CUSTOMPOLYGONITEM_H

#include <QGraphicsPolygonItem>
#include <math.h>
#include "scene.h"

class CustomPolygonItem: public QGraphicsPolygonItem
{
public:
    int btx,bty; //backtrack promenljive ako se seku sa ostalima ili nisu u potpunosti u tabli
    CustomPolygonItem(const QPolygonF &x);
protected:
    QVariant itemChange(GraphicsItemChange change,
                        const QVariant &value);
   void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
   void mousePressEvent(QGraphicsSceneMouseEvent * event);


};

#endif // CUSTOMPOLYGONITEM_H
