#ifndef FICHAG_H
#define FICHAG_H

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsEllipseItem>
#include <QDebug>
#include <QPolygonF>

#include "tablero.h"

class FichaG : public QGraphicsItem
{
public:
    bool change;
    bool Released;
    bool Pressed;
    int lastX;
    int lastY;
    bool* turno;

    int idx;    //posición en x
    int idy;    //posición en y

    Tablero t;

    QVector<QPoint> location;

    FichaG(QVector<QPoint>, int lastX, int lastY, int idx, int idy, Tablero &t, bool *turno);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void verify(QGraphicsSceneMouseEvent *event);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

};

#endif // FICHAG_H
