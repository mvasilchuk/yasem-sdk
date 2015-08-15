#ifndef STBPLUGIN_H
#define STBPLUGIN_H

#include "enums.h"
#include "gui.h"
#include "stbsubmodel.h"
#include "webobjectinfo.h"
#include "abstractpluginobject.h"
#include <QUrl>
#include <QHash>
#include <QDebug>
#include <QSize>
#include <QSharedPointer>

class QWidget;

namespace yasem {
namespace SDK {

class Datasource;
class Browser;
class BaseWidget;
class MediaPlayer;
class StbPluginObject;
class Profile;
class WebPage;
class StbPluginObjectPrivate;

class StbPluginObject: public AbstractPluginObject
{
    Q_DECLARE_PRIVATE(StbPluginObject)
public:

    explicit StbPluginObject(Plugin* plugin);
    virtual ~StbPluginObject();

    virtual QHash<QString, QObject*> getStbApiList();

public:
    QString m_description;
    QString m_web_name;

public slots:
    virtual PluginObjectResult init();

    virtual QList<WebObjectInfo> getWebObjects();
    virtual QHash<int, GUI::RcKey> getKeyCodeMap();

    virtual bool addWebObject(const QString &name, QWidget* widget, const QString &mimeType, const QString &classid, const QString &description);
    virtual bool addWebObject(const QString &name, const QString &mimeType, const QString &classid, const QString &description, std::function < QWidget*() > widgetFactory);

    virtual QUrl handleUrl(QUrl &url) { return url; }
    virtual void applyFixes() {}

    virtual QHash<QString, QObject*>& getApi();
    virtual void cleanApi();

    virtual QList<StbSubmodel>& getSubmodels() const;

    virtual StbSubmodel& findSubmodel(const QString &id);
    virtual QString listSubmodels();

    virtual QString getSubmodelDatasourceGroup();
    virtual QString getSubmodelDatasourceField();

    virtual QString getProfileClassId() = 0;
    virtual SDK::Profile* createProfile(const QString& id = "") = 0;
    virtual void initObject(WebPage* page) = 0;
    virtual QString getIcon(const QSize &size = QSize()) = 0;

protected:
    StbPluginObject(Plugin &plugin, StbPluginObjectPrivate &d):
        AbstractPluginObject(&plugin),
        d_ptr(&d) {}
    // allow subclasses to initialize with their own concrete Private
    StbPluginObjectPrivate *d_ptr;

    void setSubmodelDatasourceField(const QString &group, const QString &field);
};

}

}

#endif // STBPLUGIN_H
