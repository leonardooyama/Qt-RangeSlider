#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->widgetRangeSlider->SetRange(-100,100);
    ui->widgetRangeSlider->SetLowerValue(-90);
    ui->widgetRangeSlider->SetUpperValue(90);
    ui->widgetRangeSlider->SetOrientation(Qt::Orientation::Horizontal);
    ui->widgetRangeSlider->SetOptions(RangeSlider::Option::DoubleHandles);
    connect(ui->widgetRangeSlider, &RangeSlider::lowerValueChanged, this, &Widget::slotRangeSliderLowerValueChanged);
    connect(ui->widgetRangeSlider, &RangeSlider::upperValueChanged, this, &Widget::slotRangeSliderUpperValueChanged);
    int currentLowerValue, currentUpperValue;
    currentLowerValue = ui->widgetRangeSlider->GetLowerValue();
    currentUpperValue = ui->widgetRangeSlider->GetUpperValue();
    QString label1Text, label2Text;
    label1Text = "Range slider current lower value: " + QString::number(currentLowerValue);
    label2Text = "Range slider current upper value: " + QString::number(currentUpperValue);
    ui->label->setText(label1Text);
    ui->label_2->setText(label2Text);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slotRangeSliderLowerValueChanged(int value)
{
    QString labelText;
    labelText = "Range slider current lower value: " + QString::number(value);
    ui->label->setText(labelText);
}

void Widget::slotRangeSliderUpperValueChanged(int value)
{
    QString labelText;
    labelText = "Range slider current upper value: " + QString::number(value);
    ui->label_2->setText(labelText);
}

