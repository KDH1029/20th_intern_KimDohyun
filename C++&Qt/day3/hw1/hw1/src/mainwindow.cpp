#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (this->str.back() == '.')
    {
        this->str.chop(1);
        this->str += ',';
    }
    else if (this->str.back() == ',')
    {
        this->str.chop(1);
        this->str += '?';
    }
    else if (this->str.back() == '?')
    {
        this->str.chop(1);
        this->str += '!';
    }
    else if (this->str.back() == '!')
    {
        this->str.chop(1);
        this->str += '.';
    }
    else
    {
        this->str += '.';
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_2_clicked()
{
    if (!this->shift)
    {
        if (this->str.back() == 'A')
        {
            this->str.chop(1);
            this->str += 'B';
        }
        else if (this->str.back() == 'B')
        {
            this->str.chop(1);
            this->str += 'C';
        }
        else if (this->str.back() == 'C')
        {
            this->str.chop(1);
            this->str += 'A';
        }
        else
        {
            this->str += 'A';
        }
    }
    else
    {
        if (this->str.back() == 'a')
        {
            this->str.chop(1);
            this->str += 'b';
        }
        else if (this->str.back() == 'b')
        {
            this->str.chop(1);
            this->str += 'c';
        }
        else if (this->str.back() == 'c')
        {
            this->str.chop(1);
            this->str += 'a';
        }
        else
        {
            this->str += 'a';
        }
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_3_clicked()
{
    if (!this->shift)
    {
        if (this->str.back() == 'D')
        {
            this->str.chop(1);
            this->str += 'E';
        }
        else if (this->str.back() == 'E')
        {
            this->str.chop(1);
            this->str += 'F';
        }
        else if (this->str.back() == 'F')
        {
            this->str.chop(1);
            this->str += 'D';
        }
        else
        {
            this->str += 'D';
        }
    }
    else
    {
        if (this->str.back() == 'd')
        {
            this->str.chop(1);
            this->str += 'e';
        }
        else if (this->str.back() == 'e')
        {
            this->str.chop(1);
            this->str += 'f';
        }
        else if (this->str.back() == 'f')
        {
            this->str.chop(1);
            this->str += 'd';
        }
        else
        {
            this->str += 'd';
        }
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_4_clicked()
{
    this->str.chop(1);
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_5_clicked()
{
    if (!this->shift)
    {
        if (this->str.back() == 'G')
        {
            this->str.chop(1);
            this->str += 'H';
        }
        else if (this->str.back() == 'H')
        {
            this->str.chop(1);
            this->str += 'I';
        }
        else if (this->str.back() == 'I')
        {
            this->str.chop(1);
            this->str += 'G';
        }
        else
        {
            this->str += 'G';
        }
    }
    else
    {
        if (this->str.back() == 'g')
        {
            this->str.chop(1);
            this->str += 'h';
        }
        else if (this->str.back() == 'h')
        {
            this->str.chop(1);
            this->str += 'i';
        }
        else if (this->str.back() == 'i')
        {
            this->str.chop(1);
            this->str += 'g';
        }
        else
        {
            this->str += 'g';
        }
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_6_clicked()
{
    if (!this->shift)
    {
        if (this->str.back() == 'J')
        {
            this->str.chop(1);
            this->str += 'K';
        }
        else if (this->str.back() == 'K')
        {
            this->str.chop(1);
            this->str += 'L';
        }
        else if (this->str.back() == 'L')
        {
            this->str.chop(1);
            this->str += 'J';
        }
        else
        {
            this->str += 'J';
        }
    }
    else
    {
        if (this->str.back() == 'j')
        {
            this->str.chop(1);
            this->str += 'k';
        }
        else if (this->str.back() == 'k')
        {
            this->str.chop(1);
            this->str += 'l';
        }
        else if (this->str.back() == 'l')
        {
            this->str.chop(1);
            this->str += 'j';
        }
        else
        {
            this->str += 'j';
        }
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_7_clicked()
{
    if (!this->shift)
    {
        if (this->str.back() == 'M')
        {
            this->str.chop(1);
            this->str += 'N';
        }
        else if (this->str.back() == 'N')
        {
            this->str.chop(1);
            this->str += 'O';
        }
        else if (this->str.back() == 'O')
        {
            this->str.chop(1);
            this->str += 'M';
        }
        else
        {
            this->str += 'M';
        }
    }
    else
    {
        if (this->str.back() == 'm')
        {
            this->str.chop(1);
            this->str += 'n';
        }
        else if (this->str.back() == 'n')
        {
            this->str.chop(1);
            this->str += 'o';
        }
        else if (this->str.back() == 'o')
        {
            this->str.chop(1);
            this->str += 'm';
        }
        else
        {
            this->str += 'm';
        }
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_8_clicked()
{
    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text);
    QTextStream save(&file);
    save << this->str << '\n';
    file.close();

    this->str.clear();
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_9_clicked()
{
    if (!this->shift)
    {
        if (this->str.back() == 'P')
        {
            this->str.chop(1);
            this->str += 'Q';
        }
        else if (this->str.back() == 'Q')
        {
            this->str.chop(1);
            this->str += 'R';
        }
        else if (this->str.back() == 'R')
        {
            this->str.chop(1);
            this->str += 'S';
        }
        else if (this->str.back() == 'S')
        {
            this->str.chop(1);
            this->str += 'P';
        }
        else
        {
            this->str += 'P';
        }
    }
    else
    {
        if (this->str.back() == 'p')
        {
            this->str.chop(1);
            this->str += 'q';
        }
        else if (this->str.back() == 'q')
        {
            this->str.chop(1);
            this->str += 'r';
        }
        else if (this->str.back() == 'r')
        {
            this->str.chop(1);
            this->str += 's';
        }
        else if (this->str.back() == 's')
        {
            this->str.chop(1);
            this->str += 'p';
        }
        else
        {
            this->str += 'p';
        }
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_10_clicked()
{
    if (!this->shift)
    {
        if (this->str.back() == 'T')
        {
            this->str.chop(1);
            this->str += 'U';
        }
        else if (this->str.back() == 'U')
        {
            this->str.chop(1);
            this->str += 'V';
        }
        else if (this->str.back() == 'V')
        {
            this->str.chop(1);
            this->str += 'T';
        }
        else
        {
            this->str += 'T';
        }
    }
    else
    {
        if (this->str.back() == 't')
        {
            this->str.chop(1);
            this->str += 'u';
        }
        else if (this->str.back() == 'u')
        {
            this->str.chop(1);
            this->str += 'v';
        }
        else if (this->str.back() == 'v')
        {
            this->str.chop(1);
            this->str += 't';
        }
        else
        {
            this->str += 't';
        }
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_11_clicked()
{
    if (!this->shift)
    {
        if (this->str.back() == 'W')
        {
            this->str.chop(1);
            this->str += 'X';
        }
        else if (this->str.back() == 'X')
        {
            this->str.chop(1);
            this->str += 'Y';
        }
        else if (this->str.back() == 'Y')
        {
            this->str.chop(1);
            this->str += 'Z';
        }
        else if (this->str.back() == 'Z')
        {
            this->str.chop(1);
            this->str += 'W';
        }
        else
        {
            this->str += 'W';
        }
    }
    else
    {
        if (this->str.back() == 'w')
        {
            this->str.chop(1);
            this->str += 'x';
        }
        else if (this->str.back() == 'x')
        {
            this->str.chop(1);
            this->str += 'y';
        }
        else if (this->str.back() == 'y')
        {
            this->str.chop(1);
            this->str += 'z';
        }
        else if (this->str.back() == 'z')
        {
            this->str.chop(1);
            this->str += 'w';
        }
        else
        {
            this->str += 'w';
        }
    }
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_12_clicked()
{
    if (this->shift)
    {
        this->shift = 0;
        this->ui->pushButton_12->setStyleSheet("color:blue");
        this->ui->pushButton_2->setText("ABC");
        this->ui->pushButton_3->setText("DEF");
        this->ui->pushButton_5->setText("GHI");
        this->ui->pushButton_6->setText("JKL");
        this->ui->pushButton_7->setText("MNO");
        this->ui->pushButton_9->setText("PQRS");
        this->ui->pushButton_10->setText("TUV");
        this->ui->pushButton_11->setText("WXYZ");
    }
    else
    {
        this->shift = 1;
        this->ui->pushButton_12->setStyleSheet("color:black");
        this->ui->pushButton_2->setText("abc");
        this->ui->pushButton_3->setText("def");
        this->ui->pushButton_5->setText("ghi");
        this->ui->pushButton_6->setText("jkl");
        this->ui->pushButton_7->setText("mno");
        this->ui->pushButton_9->setText("pqrs");
        this->ui->pushButton_10->setText("tuv");
        this->ui->pushButton_11->setText("wxyz");
    }
}

void MainWindow::on_pushButton_13_clicked()
{
}

void MainWindow::on_pushButton_14_clicked()
{
}

void MainWindow::on_pushButton_15_clicked()
{
    this->str += ' ';
    this->ui->label->setText(this->str);
}

void MainWindow::on_pushButton_16_clicked()
{
    this->str += ',';
    this->ui->label->setText(this->str);
}
