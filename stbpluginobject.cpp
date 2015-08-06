
#include "stbpluginobject.h"
#include "stbpluginobject_p.h"
#include "profilemanager.h"
#include "macros.h"
#include "browser.h"
#include "mediaplayer.h"

using namespace yasem::SDK;

StbPluginObject::StbPluginObject(Plugin* plugin):
    AbstractPluginObject(plugin),
    d_ptr(new StbPluginObjectPrivate(this))
{

}

StbPluginObject::~StbPluginObject()
{
    STUB() << this;
    if(d_ptr)
        delete d_ptr;
}

QHash<QString, QObject*> StbPluginObject::getStbApiList()
{
    Q_D(StbPluginObject);
    return d->api;
}

PluginObjectResult StbPluginObject::init()
{
    ProfileManager::instance()->registerProfileClassId(getProfileClassId(), this);
    return PLUGIN_OBJECT_RESULT_OK;
}

MediaPlayer* StbPluginObject::player()
{
    return SDK::MediaPlayer::instance();
}

Browser* StbPluginObject::browser()
{
    return SDK::Browser::instance();
}

QList<WebObjectInfo> StbPluginObject::getWebObjects()
{
    Q_D(StbPluginObject);
    return d->webObjects;
}

QHash<int, GUI::RcKey> StbPluginObject::getKeyCodeMap()
{
    Q_D(StbPluginObject);
    return d->keyCodeMap;
}

bool StbPluginObject::addWebObject(const QString &name, QWidget* widget, const QString &mimeType, const QString &classid, const QString &description)
{
    Q_D(StbPluginObject);
    WebObjectInfo webObject;
    webObject.name = name;
    webObject.webObject = widget;
    webObject.mimeType = mimeType;
    webObject.description = description;
    webObject.classid = classid;
    webObject.widgetFactory = NULL;

    d->webObjects.append(webObject);
    return true;
}

bool StbPluginObject::addWebObject(const QString &name, const QString &mimeType, const QString &classid, const QString &description, std::function<QWidget*()> widgetFactory)
{
    Q_D(StbPluginObject);
    WebObjectInfo webObject;
    webObject.name = name;
    webObject.widgetFactory = widgetFactory;
    webObject.webObject = NULL;
    webObject.mimeType = mimeType;
    webObject.description = description;
    webObject.classid = classid;

    d->webObjects.append(webObject);
    return true;
}

QHash<QString, QObject*> &StbPluginObject::getApi()
{
    Q_D(StbPluginObject);
    return d->api;
}

void StbPluginObject::cleanApi()
{
    Q_D(StbPluginObject);
    QMutableHashIterator<QString, QObject*> iter(d->api);
    while(iter.hasNext())
    {
        iter.next();
        DEBUG() << "Removing " << iter.key() << iter.value();
        iter.value()->deleteLater();
        iter.remove();
    }
}

QList<StbSubmodel>& StbPluginObject::getSubmodels() const
{
    return d_ptr->subModels;
}

StbSubmodel &StbPluginObject::findSubmodel(const QString &id)
{
    Q_D(StbPluginObject);
    for(StbSubmodel &submodel: d->subModels)
        if(submodel.getId() == id)
            return submodel;
    throw new std::runtime_error(QString("Requested undefined submodel ID: %1").arg(id).toUtf8().constData());
}

QString StbPluginObject::listSubmodels()
{
    Q_D(StbPluginObject);
    QStringList result;
    for(StbSubmodel model: d->subModels)
    {
        result << model.getName();
    }
    return result.join(", ");
}

QString StbPluginObject::getSubmodelDatasourceGroup()
{
    Q_D(StbPluginObject);
    return d->submodelDatasourceGroup;
}

QString StbPluginObject::getSubmodelDatasourceField()
{
    Q_D(StbPluginObject);
    return d->submodelDatasourceField;
}

void StbPluginObject::setSubmodelDatasourceField(const QString &group, const QString &field)
{
    Q_D(StbPluginObject);
    d->submodelDatasourceGroup = group;
    d->submodelDatasourceField = field;
}


StbPluginObjectPrivate::StbPluginObjectPrivate(StbPluginObject *q):
    q_ptr(q)
{
}

StbPluginObjectPrivate::~StbPluginObjectPrivate()
{
    STUB() << this;
    //api.clear();
    /*QMutableHashIterator<QString, QObject*> iter(api);
    while(iter.hasNext())
    {
        iter.next();
        DEBUG() << "Removing " << iter.key() << iter.value();
        iter.value()->deleteLater();
    }*/
}
