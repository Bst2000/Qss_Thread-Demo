#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

private slots:
    void on_pushButton_clicked();

    void on_pushButton_QthreadTest_clicked();

    void onQThreadFinished();
    void onQThreadStarted();

private:
    Ui::MainWindow *ui;
    void QMessageBox();
    void testMap();
};
#endif // MAINWINDOW_H
