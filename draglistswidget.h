#ifndef DRAGLISTSWIDGET_H
#define DRAGLISTSWIDGET_H

#include <QListWidget>
#include <QMouseEvent>
#include <QApplication>

class DragListsWidget : public QListWidget
{
    Q_OBJECT
public:
    DragListsWidget(QWidget *parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);

private:
    void performDrag();
    QPoint startPos;
};

#endif // DRAGLISTSWIDGET_H
