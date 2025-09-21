#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class Manipulator
{
private:
    int degree[3];

public:
    void set(int i, int n);
    int get(int i);
    Manipulator(void);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int dial[3];

private slots:
    void onTimeout();

    void on_dial_sliderMoved(int position);

    void on_dial_2_sliderMoved(int position);

    void on_dial_3_sliderMoved(int position);

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int mode;
    QTimer *timer;
    Manipulator manipulator;
    void paintEvent(QPaintEvent *e);
};
#endif // MAINWINDOW_H
