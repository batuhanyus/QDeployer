#include "DeploymentJob.h"

DeploymentJob::DeploymentJob(QObject *parent)
    : QObject{parent}
{

}

void DeploymentJob::Prepare(QString Source, QString Destination)
{
    //Set paths.
    SourcePath=Source;
    DestinationPath=Destination;

    //TODO:Digest deployment options.

}

void DeploymentJob::Deploy()
{

}
