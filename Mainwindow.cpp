#include "Mainwindow.h"
#include "./ui_Mainwindow.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QProcess>
#include <DeploymentJob.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("QDeployer");

    Options=new DeploymentOptions();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Options;
}

void MainWindow::CheckIfDeployable()
{
    if(!Options->SourcePath.isEmpty() || !Options->DestinationPath.isEmpty())
        ui->OpenDeployDialogBtn->setEnabled(true);
    else
        ui->OpenDeployDialogBtn->setEnabled(false);
}

void MainWindow::on_OpenSourceDialogBtn_pressed()
{
    QDir Directory=QFileDialog::getExistingDirectory(this,"Select a folder.");
    Options->SourcePath=Directory.absolutePath();
    CheckIfDeployable();
}

void MainWindow::on_OpenDestDialogBtn_pressed()
{
    QDir Directory=QFileDialog::getExistingDirectory(this,"Select a folder.");
    Options->DestinationPath=Directory.absolutePath();
    CheckIfDeployable();
}

void MainWindow::on_OpenDeployDialogBtn_pressed()
{
    DeploymentJob* Job=new DeploymentJob();
    Job->Deploy(Options);

    delete Job;
}
