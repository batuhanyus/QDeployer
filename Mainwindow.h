#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DeploymentOptions.h>
#include <QDir>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//#define LOGGER


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:


private slots:
    void on_OpenDeployDialogBtn_pressed();

    void on_OpenSourceDialogBtn_pressed();

    void on_OpenDestDialogBtn_pressed();

private:
    Ui::MainWindow *ui;
    DeploymentOptions* Options;
};
#endif // MAINWINDOW_H
