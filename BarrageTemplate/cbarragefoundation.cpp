#include "cbarragefoundation.h"
#include "ui_cbarragefoundation.h"

CBarrageFoundation::CBarrageFoundation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CBarrageFoundation)
{
    ui->setupUi(this);
}

CBarrageFoundation::~CBarrageFoundation()
{
    delete ui;
}
