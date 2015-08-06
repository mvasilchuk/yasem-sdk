#include "datasourcefactory.h"
#include "macros.h"

using namespace yasem;
using namespace SDK;


DatasourceFactory::DatasourceFactory(QObject* parent):
    QObject(parent)
{

}

DatasourceFactory* DatasourceFactory::instance(DatasourceFactory* factory)
{
    static DatasourceFactory* instance = factory;// Guaranteed to be destroyed.

    if(instance == NULL)
        instance = static_cast<DatasourceFactory*>(qApp->property("DatasourceFactory").value<QObject*>());

    Q_CHECK_PTR(instance);
    return instance;
}

