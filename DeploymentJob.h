#ifndef DEPLOYMENTJOB_H
#define DEPLOYMENTJOB_H

#include <QObject>
#include <stdlib.h>

using namespace std;

class DeploymentJob : public QObject
{
    Q_OBJECT
public:
    explicit DeploymentJob(QObject *parent = nullptr);

    void Prepare(QString Source,QString Destination);
    void Deploy();

private:
    QString SourcePath;
    QString DestinationPath;

signals:

};

#endif // DEPLOYMENTJOB_H
