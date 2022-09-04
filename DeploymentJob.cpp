#include "DeploymentJob.h"

#include <QDir>
#include <QMessageBox>
#include <QProcess>
#include <QString>

DeploymentJob::DeploymentJob(QObject *parent)
    : QObject{parent}
{

}

void DeploymentJob::Deploy(DeploymentOptions* Options)
{
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
    Arguments.append(Options->SourcePath);

    QProcess* Process = new QProcess(this);
    QString ProcessPath="D:/Qt/6.3.1/msvc2019_64/bin/windeployqt.exe";

    Process->execute(ProcessPath,Arguments);
    Move(Options);
    CleanUp(Options);

    delete Process;
}

void DeploymentJob::Move(DeploymentOptions *Options)
{
    QDir SourceDir=QDir(Options->SourcePath);

    QList <QFileInfo> FileList= SourceDir.entryInfoList();

    QMessageBox Box;
    Box.setText(QString("Found %1 filelist entries.").arg(FileList.length()));
    Box.exec();

    for(int i=0;i<FileList.length();i++)
    {

        Box.setText(FileList[i].absoluteFilePath());
        Box.exec();

    }

    SourceDir.rename(Options->SourcePath,Options->DestinationPath);

    //QDir::rename(Options->SourcePath,Options->DestinationPath);
}

void DeploymentJob::CleanUp(DeploymentOptions *Options)
{

}
