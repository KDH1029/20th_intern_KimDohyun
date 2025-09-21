#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <iostream>
#include <cmath>
#include <QFile>
#include <QTextStream>

void Manipulator::set(int i, int n)
{
    this->degree[i] = n;
}
int Manipulator::get(int i)
{
    return this->degree[i];
}
Manipulator::Manipulator(void)
{
    degree[0] = 0;
    degree[1] = 0;
    degree[2] = 0;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->timer = new QTimer(this);
    manipulator = Manipulator();
    connect(this->timer, &QTimer::timeout, this, &MainWindow::onTimeout);
    this->timer->start(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::black, 3));
    int x1 = 400 + 100 * sin(this->manipulator.get(0) * M_PI / 180.0);
    int y1 = 300 + 100 * cos(this->manipulator.get(0) * M_PI / 180.0);
    int x2 = x1 + 100 * sin((this->manipulator.get(0) + this->manipulator.get(1)) * M_PI / 180.0);
    int y2 = y1 + 100 * cos((this->manipulator.get(0) + this->manipulator.get(1)) * M_PI / 180.0);
    int x3 = x2 + 100 * sin((this->manipulator.get(0) + this->manipulator.get(1) + this->manipulator.get(2)) * M_PI / 180.0);
    int y3 = y2 + 100 * cos((this->manipulator.get(0) + this->manipulator.get(1) + this->manipulator.get(2)) * M_PI / 180.0);
    painter.drawLine(400, 300, x1, y1);
    painter.drawLine(x1, y1, x2, y2);
    painter.drawLine(x2, y2, x3, y3);
}

void MainWindow::onTimeout()
{
    if (this->mode == 1)
    {
        this->manipulator.set(0, (this->manipulator.get(0) + (this->dial[0] - 180) / 10) % 360);
        this->manipulator.set(1, (this->manipulator.get(1) + (this->dial[1] - 180) / 10) % 360);
        this->manipulator.set(2, (this->manipulator.get(2) + (this->dial[2] - 180) / 10) % 360);
        update();
    }
}

void MainWindow::on_dial_sliderMoved(int position)
{
    this->dial[0] = position;
    this->manipulator.set(0, position);
    update();
}
void MainWindow::on_dial_2_sliderMoved(int position)
{
    this->dial[1] = position;
    this->manipulator.set(1, position);
    update();
}
void MainWindow::on_dial_3_sliderMoved(int position)
{
    this->dial[2] = position;
    this->manipulator.set(2, position);
    update();
}

void MainWindow::on_radioButton_clicked()
{
    this->mode = 0;
}

void MainWindow::on_radioButton_2_clicked()
{
    this->mode = 1;
}

void MainWindow::on_pushButton_clicked()
{
    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream save(&file);
    save << this->manipulator.get(0) << "\n"
         << this->manipulator.get(1) << "\n"
         << this->manipulator.get(2);
    file.close();
}

void MainWindow::on_pushButton_2_clicked()
{
    QFile file("log.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream load(&file);
    int a, b, c;
    load >> a >> b >> c;
    file.close();
    this->manipulator.set(0, a);
    this->manipulator.set(1, b);
    this->manipulator.set(2, c);
    update();
}
