#ifndef DATASOURCECLASS
#define DATASOURCECLASS

#include "abstractpluginobject.h"

namespace yasem {

namespace SDK {

class Datasource;
class Profile;

class DatasourceClass: public AbstractPluginObject
{
    Q_OBJECT
public:
    DatasourceClass(Plugin* plugin);
    ~DatasourceClass();

    virtual Datasource* createDatasource(const Profile* profile) = 0;
};

}

}

#endif // DATASOURCECLASS

