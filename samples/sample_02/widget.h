#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "RangeSlider.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
private slots:
    void slotRangeSliderLowerValueChanged(int value);
    void slotRangeSliderUpperValueChanged(int value);
};
#endif // WIDGET_H
