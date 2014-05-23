#include <QtWidgets>

#include "drop.h"

//! [0]
DropZone::DropZone(QGraphicsItem *parent)
    : QGraphicsObject(parent), /* color(Qt::lightGray),*/
      dragOver(false)
{
    setAcceptDrops(true);
}

void DropZone::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasImage()) {
        event->setAccepted(true);
        dragOver = true;
        update();
    } else {
        event->setAccepted(false);
    }
}
//! [0]

//! [1]
void DropZone::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}
//! [1]

//! [2]
void DropZone::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if (event->mimeData()->hasImage())
        image = qvariant_cast<QImage>(event->mimeData()->imageData());
    update();
}
//! [2]

//![3]
DropArea::DropArea(QGraphicsItem *parent)
    : DropZone(parent)
{
}
//! [3]

//! [4]
QRectF DropArea::boundingRect() const
{
    return QRectF(-125, -50, 100, 125);
}
//! [4]

//! [5]
void DropArea::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
  /*  painter->setBrush(Qt::white);
    painter->drawRect(-125, -50, 100, 125);
     painter->setBrush(dragOver ? Qt::black : Qt::lightGray);
     painter->drawRoundedRect(-10, -30, 20, 30, 25, 25, Qt::RelativeSize);
*/
    // if (pixmap.isNull()) {
    painter->setBrush(Qt::white);
    painter->drawRect(-125, -50, 100, 125);
       /* painter->setBrush(Qt::white);
        painter->drawEllipse(-7, -3 - 20, 7, 7);
        painter->drawEllipse(0, -3 - 20, 7, 7);
        painter->setBrush(Qt::black);
        painter->drawEllipse(-5, -1 - 20, 2, 2);
        painter->drawEllipse(2, -1 - 20, 2, 2);
        painter->setPen(QPen(Qt::black, 2));
        painter->setBrush(Qt::NoBrush);
        painter->drawArc(-6, -2 - 20, 12, 15, 190 * 16, 160 * 16);*/
   // } else {
        painter->scale(.4272, .3824);
        painter->drawPixmap(QPointF(-9.5 * 30, -20 * 3), pixmap);
    //}

}
//! [5]

//! [6]
void DropArea::dragEnterEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasImage()) {
        event->setAccepted(true);
        dragOver = true;
        update();
    } else {
        DropZone::dragEnterEvent(event);
    }
}
//! [6]

//! [7]
void DropArea::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    if (event->mimeData()->hasImage()) {
        dragOver = false;
        pixmap = qvariant_cast<QPixmap>(event->mimeData()->imageData());
        update();
    } else {
        DropZone::dropEvent(event);
    }
}
//! [7]

//![8]
Area::Area(QGraphicsItem *parent)
    : DropZone(parent)
{
    setFlag(ItemHasNoContents);

    QGraphicsObject *headItem = new DropArea(this);

    headItem->setPos(-10, 0);
   /* QParallelAnimationGroup *animation = new QParallelAnimationGroup(this);

    QPropertyAnimation *headAnimation = new QPropertyAnimation(headItem, "rotation");
    headAnimation->setStartValue(20);
    headAnimation->setEndValue(-20);
    QPropertyAnimation *headScaleAnimation = new QPropertyAnimation(headItem, "scale");
    headScaleAnimation->setEndValue(1.1);
    animation->addAnimation(headAnimation);
    animation->addAnimation(headScaleAnimation);

    for (int i = 0; i < animation->animationCount(); ++i) {
        QPropertyAnimation *anim = qobject_cast<QPropertyAnimation *>(animation->animationAt(i));
        anim->setEasingCurve(QEasingCurve::SineCurve);
        anim->setDuration(2000);
    }

    animation->setLoopCount(-1);
    animation->start();*/
//! [8]
}

//! [9]
QRectF Area::boundingRect() const
{
    return QRectF();
}

void Area::paint(QPainter *painter,
                  const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(painter);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
//! [9]
