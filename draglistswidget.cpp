#include "draglistswidget.h"

DragListsWidget::DragListsWidget(QWidget *parent): QListWidget(parent)
{
    setAcceptDrops(true);
}

void DragListsWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        startPos = event->pos();
    QListWidget::mousePressEvent(event);
}

void DragListsWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        int distance = (event->pos() - startPos).manhattanLength();
        if (distance >= QApplication::startDragDistance())
            performDrag();
    }
    QListWidget::mouseMoveEvent(event);
}

void DragListsWidget::dragEnterEvent(QDragEnterEvent *event)
{
    DragListsWidget *source =
            qobject_cast<DragListsWidget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DragListsWidget::performDrag()
{
    QListWidgetItem *item = currentItem();
    if (item) {
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(item->text());

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap(":/images/person.png"));
        if (drag->exec(Qt::MoveAction) == Qt::MoveAction)
            delete item;
    }
}

void DragListsWidget::dragMoveEvent(QDragMoveEvent *event)
{
    DragListsWidget *source =
            qobject_cast<DragListsWidget *>(event->source());
    if (source && source != this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void DragListsWidget::dropEvent(QDropEvent *event)
{
    DragListsWidget *source =
            qobject_cast<DragListsWidget *>(event->source());
    if (source && source != this) {
        addItem(event->mimeData()->text());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}
