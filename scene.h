#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QPainter>
#include <QApplication>
#include <QGraphicsItem>

extern bool btflag;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);
    int getGridSize() const {return this->gridSize;}
protected:
    void drawBackground (QPainter* painter, const QRectF &rect);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * mouseEvent);
private:
    int gridSize;

signals:
    void gratz(void);
};

#endif // SCENE_H
