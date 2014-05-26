#include <QtWidgets>
#include "drop.h"

DropZone::DropZone(QGraphicsItem *parent)
    : QGraphicsObject(parent), dragOver(false)
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

void DropZone::dragLeaveEvent(QGraphicsSceneDragDropEvent *event)
{
    Q_UNUSED(event);
    dragOver = false;
    update();
}

void DropZone::dropEvent(QGraphicsSceneDragDropEvent *event)
{
    dragOver = false;
    if (event->mimeData()->hasImage())
        image = qvariant_cast<QImage>(event->mimeData()->imageData());
    update();
}

DropArea::DropArea(QGraphicsItem *parent)
    : DropZone(parent)
{
}

QRectF DropArea::boundingRect() const
{
    return QRectF(-125, -50, 100, 125);
}

void DropArea::paint(QPainter *painter,
           const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::white);
    painter->drawRect(-125, -50, 100, 125);
    painter->scale(.4272, .3824);
    painter->drawPixmap(QPointF(-9.5 * 30, -60), pixmap);
}

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

Area::Area(QGraphicsItem *parent)
    : DropZone(parent)
{
    setFlag(ItemHasNoContents);
    QGraphicsObject *headItem = new DropArea(this);
    headItem->setPos(-10, 0);
}

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

