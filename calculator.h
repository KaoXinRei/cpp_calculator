#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();
private slots:
    void click_1();
    void click_2();
    void click_3();
    void click_4();
    void click_5();
    void click_6();
    void click_7();
    void click_8();
    void click_9();
    void click_0();
    void click_bracket1();
    void click_bracket2();
    void click_plus();
    void click_minus();
    void click_mult();
    void click_div();
    void click_point();
    void click_equals();
    void click_c();
private:
    Ui::Calculator *ui;
    bool point_is_entered = false;
    bool operation_is_entered = true;
    bool answered = false;
    int n_of_bracket1 = 0;
};
#endif // MAINWINDOW_H
