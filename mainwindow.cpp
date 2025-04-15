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


int num_list[50] {0};
int status_list[50] {0};
unsigned int step=0;
bool nowNum;
int result;
int i=0;
int sumNum;

void pressNum(int inNum)
{
    if(inNum){
        if(i){
            i=i*10+inNum;
        }
        else{
            i+=inNum;
        }
    }
    else{
        if(i){
            i=i*10;
        }
    }
    nowNum=true;
}
void operating(int inOp)
{
    if(nowNum)
    {
        num_list[step]=i;
        status_list[step]=inOp;
        step++;
        i=0;
        nowNum=false;
    }
    else
    {
        status_list[--step]=inOp;
        step++;
    }
}
void cal_result()
{

    for(int j=0;j<step;j++)
    {
        switch(status_list[j])
        {
        case 1:
            sumNum=num_list[j]+num_list[j+1];
            num_list[j+1]=sumNum;
            break;
        case 2:
            sumNum=num_list[j]-num_list[j+1];
            num_list[j+1]=sumNum;
            break;
        case 3:
            sumNum=num_list[j]*num_list[j+1];
            num_list[j+1]=sumNum;
            break;
        case 4:
            sumNum=num_list[j]/num_list[j+1];
            num_list[j+1]=sumNum;
            break;
        case 5:
            i=num_list[j];
            break;
        }
    }
}

void MainWindow::on_pushButton_pressed()
{
    pressNum(1);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_2_pressed()
{
    pressNum(2);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_3_pressed()
{
    pressNum(3);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_4_pressed()
{
    pressNum(4);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_5_pressed()
{
    pressNum(5);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_6_pressed()
{
    pressNum(6);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_7_pressed()
{
    pressNum(7);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_8_pressed()
{
    pressNum(8);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_9_pressed()
{
    pressNum(9);
    ui->lcdNumber->display(i);
}

void MainWindow::on_pushButton_10_pressed()
{
    pressNum(0);
    ui->lcdNumber->display(i);
}

void MainWindow::on_clearButton_pressed()
{
    if(i){
        i=0;
    }
    ui->lcdNumber->display(i);
    for(size_t j=0; j<=step; j++)
    {
        num_list[j]=0;
        status_list[j]=0;
    }
}

void MainWindow::on_lcdNumber_overflow()
{
    ui->lcdNumber->display("error");
}


void MainWindow::on_pushButton_add_pressed()
{
    operating(1);

}


void MainWindow::on_pushButton_sub_pressed()
{
    operating(2);
}


void MainWindow::on_pushButton_mul_pressed()
{
    operating(3);
}


void MainWindow::on_pushButton_div_pressed()
{
    operating(4);
}


void MainWindow::on_pushButton_equl_pressed()
{
    operating(5);
    cal_result();
    ui->lcdNumber->display(i);
}
