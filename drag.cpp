
/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>

#include "drag.h"

//! [0]
ImageItem::ImageItem()
   : image(":/images/1.jpg")
{
   setToolTip(QString("Click and drag this image onto the robot!"));
   setCursor(Qt::OpenHandCursor);
   setAcceptedMouseButtons(Qt::LeftButton);
}
//! [0]

//! [1]
QRectF ImageItem::boundingRect() const
{
   return QRectF(100, -100, 100, 100);
}
//! [1]

//! [2]
void ImageItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
   Q_UNUSED(option);
   Q_UNUSED(widget);
   /* painter->setPen(Qt::NoPen);
   painter->setBrush(Qt::darkGray);
   painter->drawEllipse(-12, -12, 30, 30);
   painter->setPen(QPen(Qt::black, 1));
   painter->setBrush(QBrush(color));
   painter->drawEllipse(-15, -15, 30, 30);*/
   painter->setBrush(Qt::white);
   painter->drawRect(100, -100, 100, 100);
   painter->drawImage(boundingRect(),image);
}
//! [2]

//! [3]
void ImageItem::mousePressEvent(QGraphicsSceneMouseEvent *)
{
   setCursor(Qt::ClosedHandCursor);
}
//! [3]

//! [4]
void ImageItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
   if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
       .length() < QApplication::startDragDistance()) {
       return;
   }

   QDrag *drag = new QDrag(event->widget());
   QMimeData *mime = new QMimeData;
   drag->setMimeData(mime);

       mime->setImageData(image);

       drag->setPixmap(QPixmap::fromImage(image).scaled(50, 50));
       drag->setHotSpot(QPoint(15, 30));

   drag->exec();
   setCursor(Qt::OpenHandCursor);
}
//! [4]

//![5]
void ImageItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
   setCursor(Qt::OpenHandCursor);
}
//! [5]