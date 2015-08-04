#ifndef STBPLUGIN_P_H
#define STBPLUGIN_P_H

#include "enums.h"
#include "stbsubmodel.h"
#include "webobjectinfo.h"

#include <QString>
#include <QList>
#include <QHash>
#include <QUrl>

namespace yasem {
namespace SDK {

class StbPluginObject;
class DatasourcePluginObject;
class MediaPlayer;
class GUI;
class Browser;

class StbPluginObjectPrivate {
    Q_DECLARE_PUBLIC(StbPluginObject)
public:
    explicit StbPluginObjectPrivate(StbPluginObject* q);
    virtual ~StbPluginObjectPrivate();

protected:
     StbPluginObject* q_ptr;
public:

    QHash<QString, QObject*> api;
    DatasourcePluginObject* datasourceInstance;
    MediaPlayer* mediaPlayer;
    QUrl portalUrl;
    GUI* guiPlugin;
    Browser* browserPlugin;
    QList<WebObjectInfo> webObjects;
    QHash<int, GUI::RcKey> keyCodeMap;
    QList<StbSubmodel> subModels;
    QString submodelDatasourceGroup;
    QString submodelDatasourceField;
};

}

}

#endif // STBPLUGIN_P_H

