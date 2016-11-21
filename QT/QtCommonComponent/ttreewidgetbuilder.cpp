#include "ttreewidgetbuilder.h"

template <typename T>
TTreeWidgetBuilder<T>::TTreeWidgetBuilder(QWidget *parent):
    QWidget(parent),
    m_pTreeWidget(new QTreeWidget(parent))
{

}

template <typename T>
TTreeWidgetBuilder<T>::~TTreeWidgetBuilder()
{

}

template <typename T>
void TTreeWidgetBuilder<T>::addItem(QTreeWidgetItem *pCurItem, QTreeWidgetItem *pParent)
{
    Q_ASSERT(pParent != nullptr);
    if(pParent != nullptr)
        pParent->addChild(pCurItem);
}
