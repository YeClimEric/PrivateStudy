#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QListWidget>

#include <QStyledItemDelegate>
#include <QSpinBox>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QLabel* label;
    QListWidget* listWidget;
};

class SpinBoxDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    SpinBoxDelegate(QObject* parent = 0): QStyledItemDelegate(parent){}
    //返回用于进行编辑的控件
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        QSpinBox* editor = new QSpinBox(parent);
        editor->setMinimum(0);
        editor->setMaximum(100);
        return editor;
    }
    //赋值
    void setEditorData(QWidget *editor, const QModelIndex &index) const
    {
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QSpinBox* spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
    }
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
    {
        QSpinBox* spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
    }
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {
        editor->setGeometry(option.rect);
    }

};

#endif // MAINWINDOW_H
