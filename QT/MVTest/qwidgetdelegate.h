#ifndef QWIDGETDELEGATE_H
#define QWIDGETDELEGATE_H

#include <QWidget>
#include <QStyledItemDelegate>

class QWidgetDelegate : public QStyledItemDelegate
{
public:
    QWidgetDelegate();
//    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
//    void setEditorData(QWidget *editor, const QModelIndex &index) const;
//    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
//    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void paint(QPainter *painter,const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // QWIDGETDELEGATE_H
