#ifndef DEPLOYMENTOPTIONS_H
#define DEPLOYMENTOPTIONS_H



#include <QString>


struct DeploymentOptions
{
    QString SourcePath;
    QString DestinationPath;
    QString ToolPath;

    qint32 Dummy=-1;

    DeploymentOptions()
    {

    }
};

#endif // DEPLOYMENTOPTIONS_H
