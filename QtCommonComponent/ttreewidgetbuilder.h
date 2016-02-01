#ifndef TTREEWIDGETBUILDER_H
#define TTREEWIDGETBUILDER_H

#include <QWidget>
#include <QTreeWidget>
#include <QMenu>

namespace Ui {
class TTreeWidgetBuilder;
}

class TTreeWidgetBuilder : public QWidget
{
    Q_OBJECT

public:
    explicit TTreeWidgetBuilder(QWidget *parent = 0);
    ~TTreeWidgetBuilder();

private:
    Ui::TTreeWidgetBuilder *ui;

    QTreeWidget *m_pTreeWidget;
    QMenu* m_pContentMenu;
};

#endif // TTREEWIDGETBUILDER_H
