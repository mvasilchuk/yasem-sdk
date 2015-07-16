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

class QWidget;

namespace yasem {
namespace SDK {

class DatasourcePlugin;
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
    QString description;
    QString webName;

public slots:
    virtual PluginObjectResult init();

    virtual void player(MediaPlayer* player);
    virtual MediaPlayer* player();

    virtual void browser(Browser* browser);
    virtual Browser* browser();

    virtual QList<WebObjectInfo> getWebObjects();
    virtual QHash<int, GUI::RcKey> getKeyCodeMap();

    virtual bool addWebObject(const QString &name, QWidget* widget, const QString &mimeType, const QString &classid, const QString &description);
    virtual bool addWebObject(const QString &name, const QString &mimeType, const QString &classid, const QString &description, std::function < QWidget*() > widgetFactory);

    virtual QUrl handleUrl(QUrl &url) { return url; }
    virtual void applyFixes() {}

    virtual QHash<QString, QObject*>& getApi();

    virtual QList<StbSubmodel> &getSubmodels();

    virtual StbSubmodel& findSubmodel(const QString &id);
    virtual QString listSubmodels();

    virtual QString getSubmodelDatasourceGroup();
    virtual QString getSubmodelDatasourceField();

    virtual QString getProfileClassId() = 0;
    virtual Profile* createProfile(const QString& id = "") = 0;
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
