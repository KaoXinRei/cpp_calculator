#include "calculator.h"
#include "ui_mainwindow.h"
#include <stack>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <queue>

calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    connect(ui->button_number_1, &QPushButton::clicked, this, &calculator::click_1);
    connect(ui->button_number_2, &QPushButton::clicked, this, &calculator::click_2);
    connect(ui->button_number_3, &QPushButton::clicked, this, &calculator::click_3);
    connect(ui->button_number_4, &QPushButton::clicked, this, &calculator::click_4);
    connect(ui->button_number_5, &QPushButton::clicked, this, &calculator::click_5);
    connect(ui->button_number_6, &QPushButton::clicked, this, &calculator::click_6);
    connect(ui->button_number_7, &QPushButton::clicked, this, &calculator::click_7);
    connect(ui->button_number_8, &QPushButton::clicked, this, &calculator::click_8);
    connect(ui->button_number_9, &QPushButton::clicked, this, &calculator::click_9);
    connect(ui->button_number_0, &QPushButton::clicked, this, &calculator::click_0);
    connect(ui->button_bracket1, &QPushButton::clicked, this, &calculator::click_bracket1);
    connect(ui->button_bracket2, &QPushButton::clicked, this, &calculator::click_bracket2);
    connect(ui->button_plus, &QPushButton::clicked, this, &calculator::click_plus);
    connect(ui->button_minus, &QPushButton::clicked, this, &calculator::click_minus);
    connect(ui->button_mult, &QPushButton::clicked, this, &calculator::click_mult);
    connect(ui->button_divide, &QPushButton::clicked, this, &calculator::click_div);
    connect(ui->button_point, &QPushButton::clicked, this, &calculator::click_point);
    connect(ui->button_equals, &QPushButton::clicked, this, &calculator::click_equals);
    connect(ui->button_c, &QPushButton::clicked, this, &calculator::click_c);
}

calculator::~calculator()
{
    delete ui;
}

std::deque<QString> reverse_polish_notation(QString s){
    std::deque<QString> result;
    std::stack<QString> tmp;
    tmp.push("b");
    std::unordered_map<std::string, int> d =
    {{"bb", 4}, {"b+", 1}, {"b*", 1}, {"b/", 1}, {"b(", 1}, {"b)", 5}, {"++", 2}, {"+*", 1}, {"+/", 1},
     {"+b", 2}, {"+(", 1}, {"+)", 2}, {"*b", 2}, {"*+", 2}, {"**", 2}, {"*/", 2}, {"*(", 1}, {"*)", 2},
     {"/b", 2}, {"/+", 2}, {"/*", 2}, {"//", 2}, {"/(", 1}, {"/)", 2}, {"(b", 5}, {"(+", 1}, {"(*", 1},
     {"(/", 1}, {"((", 1}, {"()", 3}, {"-b", 2}, {"-+", 2}, {"--", 2}, {"-*", 1}, {"-/", 1}, {"-(", 1},
     {"-)", 2}, {"b-", 1}, {"+-", 2}, {"*-", 2}, {"/-", 2}, {"(-", 1}};
    s.replace("(","( ");
    s.replace(")"," )");
    s.append(" b");
    auto sl = s.split(" ");
    bool stop = false;
    while (!stop){
        auto i = sl.front();
        sl.pop_front();
        bool is_number;
        i.toDouble(&is_number);
        if (is_number){
            result.push_back(i);
        }
        else{
            auto com = tmp.top();
            tmp.pop();
            auto t = d.find((com + i).toStdString());
            switch (t->second) {
            case 1:
                tmp.push(com);
                tmp.push(i);
                break;
            case 2:
                result.push_back(com);
                sl.push_front(i);
                break;
            case 4:
                stop = true;
                break;
            case 5:
                throw std::invalid_argument("Given formula is incorrect");
            }
        }
    }
    return result;
}

void calculator::click_1(){
    if(!answered){
        ui->display->setText(ui->display->text()+"1");
        operation_is_entered = false;
    }
}

void calculator::click_2(){
    if(!answered){
        ui->display->setText(ui->display->text()+"2");
        operation_is_entered = false;
    }
}

void calculator::click_3(){
    if(!answered){
        ui->display->setText(ui->display->text()+"3");
        operation_is_entered = false;
    }
}

void calculator::click_4(){
    if(!answered){
        ui->display->setText(ui->display->text()+"4");
        operation_is_entered = false;
    }
}

void calculator::click_5(){
    if(!answered){
        ui->display->setText(ui->display->text()+"5");
        operation_is_entered = false;
    }
}

void calculator::click_6(){
    if(!answered){
        ui->display->setText(ui->display->text()+"6");
        operation_is_entered = false;
    }
}

void calculator::click_7(){
    if(!answered){
        ui->display->setText(ui->display->text()+"7");
        operation_is_entered = false;
    }
}

void calculator::click_8(){
    if(!answered){
        ui->display->setText(ui->display->text()+"8");
        operation_is_entered = false;
    }
}

void calculator::click_9(){
    if(!answered){
        ui->display->setText(ui->display->text()+"9");
        operation_is_entered = false;
    }
}

void calculator::click_0(){
    if(!answered){
        ui->display->setText(ui->display->text()+"0");
        operation_is_entered = false;
    }
}

void calculator::click_bracket1(){
    if (operation_is_entered && !answered){
        ui->display->setText(ui->display->text()+"(");
        n_of_bracket1++;
    }
}

void calculator::click_bracket2(){
    if (!operation_is_entered && n_of_bracket1>0 && !answered){
        ui->display->setText(ui->display->text()+")");
        n_of_bracket1--;
    }
}

void calculator::click_plus(){
    if (!operation_is_entered && !answered){
        ui->display->setText(ui->display->text()+" + ");
        point_is_entered = false;
        operation_is_entered = true;
    }
}

void calculator::click_minus(){
    if (!operation_is_entered && !answered){
        ui->display->setText(ui->display->text()+" - ");
        point_is_entered = false;
        operation_is_entered = true;
    }
}

void calculator::click_mult(){
    if (!operation_is_entered && !answered){
        ui->display->setText(ui->display->text()+" * ");
        point_is_entered = false;
        operation_is_entered = true;
    }
}


void calculator::click_div(){
    if (!operation_is_entered && !answered){
        ui->display->setText(ui->display->text()+" / ");
        point_is_entered = false;
        operation_is_entered = true;
    }
}

void calculator::click_point(){
    if (!point_is_entered && !answered){
        ui->display->setText(ui->display->text()+".");
        point_is_entered = true;
    }
}

void calculator::click_equals(){
    if (!operation_is_entered && !answered){
        auto rpn = reverse_polish_notation(ui->display->text());
        std::stack<QString> tmp;
        int n = rpn.size();
        for (int i = 0; i < n; i++){
            auto t = rpn.front();
            rpn.pop_front();
            bool is_number;
            t.toDouble(&is_number);
            if (is_number){
                tmp.push(t);
            }
            else{
                QString n1, n2;
                switch(t.toStdString().back()){
                case '+':
                    n1 = tmp.top(); tmp.pop();
                    n2 = tmp.top(); tmp.pop();
                    tmp.push(QString::number(n2.toDouble()+n1.toDouble()));
                    break;
                case '-':
                    n1 = tmp.top(); tmp.pop();
                    n2 = tmp.top(); tmp.pop();
                    tmp.push(QString::number(n2.toDouble()-n1.toDouble()));
                    break;
                case '*':
                    n1 = tmp.top(); tmp.pop();
                    n2 = tmp.top(); tmp.pop();
                    tmp.push(QString::number(n2.toDouble()*n1.toDouble()));
                    break;
                case '/':
                    n1 = tmp.top(); tmp.pop();
                    n2 = tmp.top(); tmp.pop();
                    tmp.push(QString::number(n2.toDouble()/n1.toDouble()));
                }
            }
        }
        ui->display->setText(ui->display->text() + " = " + tmp.top());
        answered = true;
    }
}

void calculator::click_c(){
    ui->display->setText("");
    point_is_entered = false;
    operation_is_entered = true;
    answered = false;
}
