#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/opencv.hpp>
#include <QImage>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    images[0] = ui->imageWhite;
    images[1] = ui->imageBlue;
    images[2] = ui->imageNeon;
    images[3] = ui->imageOrange;

    for (int i = 0; i < 4; ++i)
    {
        H[0][i] = 179;
        H[1][i] = 0;
        S[0][i] = 255;
        S[1][i] = 0;
        V[0][i] = 255;
        V[1][i] = 0;
    }

    capture.open(0);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::process);
    timer->start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_sliderHH_valueChanged(int value)
{
    H[0][i] = value;
    ui->valHH->setText(QString::number(value));
    updateImage(i);
}
void MainWindow::on_sliderHL_valueChanged(int value)
{
    H[1][i] = value;
    ui->valHL->setText(QString::number(value));
    updateImage(i);
}
void MainWindow::on_sliderSH_valueChanged(int value)
{
    S[0][i] = value;
    ui->valSH->setText(QString::number(value));
    updateImage(i);
}
void MainWindow::on_sliderSL_valueChanged(int value)
{
    S[1][i] = value;
    ui->valSL->setText(QString::number(value));
    updateImage(i);
}
void MainWindow::on_sliderVH_valueChanged(int value)
{
    V[0][i] = value;
    ui->valVH->setText(QString::number(value));
    updateImage(i);
}
void MainWindow::on_sliderVL_valueChanged(int value)
{
    V[1][i] = value;
    ui->valVL->setText(QString::number(value));
    updateImage(i);
}

void MainWindow::setObj(int i)
{
    this->i = i;
    ui->sliderHH->setValue(H[0][i]);
    ui->sliderHL->setValue(H[1][i]);
    ui->sliderSH->setValue(S[0][i]);
    ui->sliderSL->setValue(S[1][i]);
    ui->sliderVH->setValue(V[0][i]);
    ui->sliderVL->setValue(V[1][i]);
}

void MainWindow::on_radioWhite_clicked() { setObj(0); }
void MainWindow::on_radioBlue_clicked() { setObj(1); }
void MainWindow::on_radioNeon_clicked() { setObj(2); }
void MainWindow::on_radioOrange_clicked() { setObj(3); }

void MainWindow::updateImage()
{
    capture >> original;
    if (original.empty())
        return;

    ui->imageOriginal->setPixmap(QPixmap::fromImage(QImage(original.data, original.cols, original.rows, original.step, QImage::Format_BGR888)).scaled(ui->imageOriginal->size(), Qt::KeepAspectRatio));

    cv::GaussianBlur(original, hsv, cv::Size(5, 5), 0);
    cv::cvtColor(hsv, hsv, cv::COLOR_BGR2HSV);

    for (int i = 0; i < 4; i++)
        updateImage(i);

    original.setTo(cv::Scalar(0, 255, 255), obj[0]);
    original.setTo(cv::Scalar(255, 0, 255), obj[1]);

    std::vector<std::vector<cv::Point>> contours[4];

    cv::findContours(obj[2], contours[2], cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    for (size_t i = 0; i < contours[2].size(); ++i)
    {
        if (cv::contourArea(contours[2][i]) < 200)
            continue;
        cv::rectangle(original, cv::boundingRect(contours[2][i]), cv::Scalar(255, 0, 0), 10);
    }

    cv::findContours(obj[3], contours[3], cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    for (size_t i = 0; i < contours[3].size(); ++i)
    {
        if (cv::contourArea(contours[3][i]) < 200)
            continue;
        cv::rectangle(original, cv::boundingRect(contours[3][i]), cv::Scalar(0, 0, 255), 10);
    }
    ui->imageObj->setPixmap(QPixmap::fromImage(QImage(original.data, original.cols, original.rows, original.step, QImage::Format_BGR888)).scaled(ui->imageObj->size(), Qt::KeepAspectRatio));

    int line[2][2];

    cv::findContours(obj[0], contours[0], cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    if (!contours[0].empty())
    {
        cv::Rect rect = cv::boundingRect(contours[0][0]);
        line[0][0] = rect.x;
        line[0][1] = rect.x + rect.width;
    }

    cv::findContours(obj[1], contours[1], cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    if (!contours[1].empty())
    {
        cv::Rect rect = cv::boundingRect(contours[1][0]);
        line[1][0] = rect.y;
        line[1][1] = rect.y + rect.height;
    }

    if (!contours[2].empty())
    {
        cv::Rect rect = cv::boundingRect(contours[2][0]);
        ui->neonX->setText(rect.x > line[0][0] ? "right" : (rect.x + rect.width < line[0][1] ? "left" : "middle"));
        ui->neonY->setText(rect.y > line[1][0] ? "down" : (rect.y + rect.height < line[1][1] ? "up" : "middle"));
    }

    if (!contours[3].empty())
    {
        cv::Rect rect = cv::boundingRect(contours[3][0]);
        ui->orangeX->setText(rect.x > line[0][0] ? "right" : (rect.x + rect.width < line[0][1] ? "left" : "middle"));
        ui->orangeY->setText(rect.y > line[1][0] ? "down" : (rect.y + rect.height < line[1][1] ? "up" : "middle"));
    }
}

void MainWindow::updateImage(int i)
{
    cv::inRange(hsv, cv::Scalar(H[1][i], S[1][i], V[1][i]), cv::Scalar(H[0][i], S[0][i], V[0][i]), obj[i]);
    cv::erode(obj[i], obj[i], cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3)), cv::Point(-1, -1), 2);
    cv::GaussianBlur(obj[i], obj[i], cv::Size(5, 5), 0);

    QImage qimg(obj[i].data, obj[i].cols, obj[i].rows, obj[i].step, QImage::Format_Grayscale8);
    images[i]->setPixmap(QPixmap::fromImage(qimg).scaled(images[i]->size(), Qt::KeepAspectRatio));
}

void MainWindow::process()
{
    updateImage();
}