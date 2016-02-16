#ifndef TTREEWIDGETBUILDER_H
#define TTREEWIDGETBUILDER_H

#include <QWidget>
#include <QTreeWidget>
#include <QMenu>


namespace Ui {
class TTreeWidgetBuilder;
}

template <typename T>
class TTreeWidgetBuilder : public QWidget
{
    Q_OBJECT

public:
    explicit TTreeWidgetBuilder(QWidget *parent = 0);
    ~TTreeWidgetBuilder();
public:
    void addItem(QTreeWidgetItem *pCurItem, QTreeWidgetItem *pParent);
private:
    Ui::TTreeWidgetBuilder *ui;

    QTreeWidget *m_pTreeWidget;
    QMenu* m_pContentMenu; //后续处理
};

#endif // TTREEWIDGETBUILDER_H
