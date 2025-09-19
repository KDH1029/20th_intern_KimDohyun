#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QHostAddress>
#include <QByteArray>
#include <QDebug>

#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);
    udpSocket->bind(QHostAddress::Any, 8888);
    connect(udpSocket, &QUdpSocket::readyRead, this, &MainWindow::get_udp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::get_udp()
{
    while (udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(int(udpSocket->pendingDatagramSize()));
        QHostAddress sender;
        quint16 senderPort;

        udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        std::vector<uchar> data(datagram.begin(), datagram.end());
        cv::Mat img = cv::imdecode(data, cv::IMREAD_COLOR);
        QImage qimg(img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
        ui->label->setPixmap(QPixmap::fromImage(qimg).scaled(ui->label->size(), Qt::KeepAspectRatio));
    }
}

void MainWindow::on_pushButton_clicked()
{
    cv::Mat img = cv::imread("balloon.png");
    std::vector<uchar> buf;
    cv::imencode(".png", img, buf);
    QByteArray datagram(reinterpret_cast<const char *>(buf.data()), static_cast<int>(buf.size()));
    udpSocket->writeDatagram(datagram, QHostAddress(ui->lineEdit->text()), 8888);
}
