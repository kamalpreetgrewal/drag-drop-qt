#ifndef DRAG_H
#define DRAG_H

#include <QGraphicsItem>

//! [0]
class ImageItem : public QGraphicsItem
{
public:
    ImageItem();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    QImage image;
};
//![0]
#endif // DRAG_H
