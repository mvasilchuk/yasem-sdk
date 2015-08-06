#ifndef DATASOURCEFACTORY_H
#define DATASOURCEFACTORY_H

#include "enums.h"

#include <QObject>
#include <functional>

namespace yasem {
namespace SDK {

class Plugin;
class Profile;
class Datasource;
class DatasourceClass;

class DatasourceFactory: public QObject
{
    Q_OBJECT
public:
    DatasourceFactory(QObject* parent);

    static DatasourceFactory* instance(DatasourceFactory* factory = 0);

    virtual Datasource* forProfile(const Profile* profile) = 0;
    virtual void registerDatasourceClass(SDK::DatasourceClass* ds_class) = 0;

};

}

}
#endif // DATASOURCEFACTORY_H
