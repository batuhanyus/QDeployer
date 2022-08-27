#include "DeploymentJob.h"

#include <QMessageBox>
#include <QProcess>

DeploymentJob::DeploymentJob(QObject *parent)
    : QObject{parent}
{

}

void DeploymentJob::Deploy(DeploymentOptions* Options)
{
    QMessageBox Box;
    Box.setText(Options->SourcePath);
    //Box.exec();

    if(!Options)
    {
       //TODO: Add log here.
        return;
    }
    else if(Options->SourcePath.isEmpty() || Options->SourcePath.isEmpty())
    {
        return;
    }

    QStringList Arguments;

    Arguments.append("--release");
    Arguments.append("--no-translations");
    //Arguments.append("--no-libraries");
    //Arguments.append("--verbose");
    Arguments.append(Options->SourcePath);


    QProcess* Process = new QProcess(this);
    QString ProcessPath="D:/Qt/6.3.1/msvc2019_64/bin/windeployqt.exe";

    Process->startDetached(ProcessPath,Arguments);
    delete Process;
}
