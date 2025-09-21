#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->queue = Queue();
    this->n = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void Queue::enqueue(User user)
{
    this->queue.push_back(user);
}
User Queue::dequeue(void)
{
    User user = this->queue.front();
    queue.erase(this->queue.begin());
    return user;
}

User::User(QString phone, QString name, int n)
{
    this->phone = phone;
    this->name = name;
    this->n = n;
}
void MainWindow::on_pushButton_clicked()
{
    this->queue.enqueue(User(this->ui->lineEdit->text(), this->ui->lineEdit_2->text(), this->n++));
    this->ui->label_4->setText(QString::number(this->n - this->queue.queue.front().n));
    this->ui->lineEdit->setText("");
    this->ui->lineEdit_2->setText("");
}

void MainWindow::on_pushButton_2_clicked()
{
    if (!this->queue.queue.empty())
    {
        User temp = this->queue.dequeue();
        if (!this->queue.queue.empty())
        {
            this->ui->label_4->setText(QString::number(this->n - this->queue.queue.front().n));
        }
        else
        {
            this->ui->label_4->setText("0");
        }
        this->ui->label_8->setText(temp.phone);
        this->ui->label_9->setText(temp.name);
    }
}
