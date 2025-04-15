#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <cstdio>
#include <cstdlib>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
double num_show=0;
double num1, num2=0;
unsigned int status1, status2=0;
bool num_now=false;

void num_set(int inNum)
{
    if(status1)
    {
        num2=num2*10+inNum;
        num_show=num2;
    }
    else
    {
        num1=num1*10+inNum;
        num_show=num1;
    }
    num_now=true;
}

void num_cal(int inStatus)
{
    if(status1!=0&&status1!=5)
    {
        if(num_now)
        {
            status2=inStatus;
            switch (status1) {
            case 1:
                num_show=num1+num2;
                break;
            case 2:
                num_show=num1-num2;
                break;
            case 3:
                num_show=num1*num2;
                break;
            case 4:
                num_show=num1/num2;
                break;
            default:
                break;
            }
            status1=status2;
            num1=num_show;
            num2=0;
        }
        else
        {
            status2=inStatus;
        }
    }
    else
    {
        status1=inStatus;
    }
        num_now = false;
}

void num_erase()
{
    if(status1)
    {
        num2=int(num2/10);
        num_show=num2;
    }
    else
    {
        num1=int(num1/10);
        num_show=num1;
    }
}

void MainWindow::on_pushButton_pressed()
{
    num_set(1);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_2_pressed()
{
    num_set(2);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_3_pressed()
{
    num_set(3);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_4_pressed()
{
    num_set(4);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_5_pressed()
{
    num_set(5);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_6_pressed()
{
    num_set(6);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_7_pressed()
{
    num_set(7);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_8_pressed()
{
    num_set(8);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_9_pressed()
{
    num_set(9);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_10_pressed()
{
    num_set(0);
    ui->lcdNumber->display(num_show);
}


void MainWindow::on_pushButton_add_pressed()
{
    num_cal(1);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_sub_pressed()
{
    num_cal(2);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_mul_pressed()
{
    num_cal(3);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_div_pressed()
{
    num_cal(4);
    ui->lcdNumber->display(num_show);
}

void MainWindow::on_pushButton_equl_pressed()
{
    num_cal(5);
    ui->lcdNumber->display(num_show);
}


void MainWindow::on_backspace_pressed()
{
    if(num_now) num_erase();
    ui->lcdNumber->display(num_show);
}


void MainWindow::on_clearButton_pressed()
{
    num1=0;
    num2=0;
    num_show=0;
    status1=0;
    status2=0;
    num_now=false;
    ui->lcdNumber->display(num_show);
}


void MainWindow::on_lcdNumber_overflow()
{
    ui->lcdNumber->display("error");
}

