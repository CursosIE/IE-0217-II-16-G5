#include "fichag.h"

FichaG::FichaG(QVector<QPoint> location, int lastX, int lastY, int idx, int idy, Tablero &t, bool *turno) {
    change= false;
    Pressed= false;
    Released= false;

    this->location= location;
    this->lastX= lastX;
    this->lastY= lastY;
    this->turno= turno;
    this->idx= idx;
    this->idy= idy;

    this->t= t;

    setFlag(ItemIsFocusable);
}

QRectF FichaG::boundingRect() const {
    return QRectF(lastX, lastY, 34, 24);
}

void FichaG::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    painter->drawPolygon(location);

    QPolygonF poly(location);
    QPainterPath path;
    path.addPolygon(poly);

    if (change) {
        if(*turno){
            t.ponazul(idx, idy);
            if (t.tablero[idx][idy].azul==true) {
                brush.setColor(Qt::blue);
            }
            if(*t.tablero[idx][idy].conectainicio==true && *t.tablero[idx][idy].conectafinal==true){
                cout<<"Ganó Azul"<<endl;
            }
            *turno=false;
        }
        else if (!*turno) {
            t.ponroja(idx, idy);
            if (t.tablero[idx][idy].rojo==true) {
                brush.setColor(Qt::red);
            }
            *turno=true;
            if(*t.tablero[idx][idy].conectainicio==true && *t.tablero[idx][idy].conectafinal==true){
                cout<<"Ganó Rojo"<<endl;
            }
        }
        ~t;
        change= false;
    }
    /*else{
       brush.setColor(Qt::black);
    }*/

    painter->fillPath(path, brush);
}

void FichaG::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    Pressed= true;
}

void FichaG::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    Released= true;
    verify(event);
}

void FichaG::verify(QGraphicsSceneMouseEvent *event) {
    if (Pressed && Released) {

        change= true;
        //update();
        QGraphicsItem::mousePressEvent(event);
        QGraphicsItem::mouseReleaseEvent(event);
        Pressed= false;
        Released= false;
    }
}
