#ifndef DEPLOYMENTJOB_H
#define DEPLOYMENTJOB_H

#include "DeploymentOptions.h"

#include <QObject>
#include <stdlib.h>

using namespace std;

class DeploymentJob : public QObject
{
    Q_OBJECT
public:
    explicit DeploymentJob(QObject *parent = nullptr);

    void Deploy(DeploymentOptions* Options);

private:


signals:

};

#endif // DEPLOYMENTJOB_H
