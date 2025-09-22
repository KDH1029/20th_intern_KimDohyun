#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include <QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setObj(int i);
    void updateImage();
    void updateImage(int i);

private slots:
    void on_sliderHH_valueChanged(int value);
    void on_sliderHL_valueChanged(int value);
    void on_sliderSH_valueChanged(int value);
    void on_sliderSL_valueChanged(int value);
    void on_sliderVH_valueChanged(int value);
    void on_sliderVL_valueChanged(int value);

    void on_radioWhite_clicked();
    void on_radioBlue_clicked();
    void on_radioNeon_clicked();
    void on_radioOrange_clicked();

    void process();

private:
    Ui::MainWindow *ui;
    cv::VideoCapture capture;
    QTimer *timer;
    cv::Mat original, hsv;
    cv::Mat obj[4];
    int i;
    int H[2][4], S[2][4], V[2][4];
    QLabel *images[4];
};
#endif // MAINWINDOW_H
