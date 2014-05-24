#ifndef DRAG_H
#define DRAG_H

#include <QGraphicsItem>
#include <QFrame>

//! [0]
class ImageItem : public QGraphicsItem
{
public:
    ImageItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    float x1,y1,x2,y2;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QImage image;
    QList<QImage> ImageList;
    QVector<QImage> img_array;

};
//![0]

#endif // DRAG_H
