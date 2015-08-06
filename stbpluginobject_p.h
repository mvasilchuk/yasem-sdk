#ifndef STBPLUGIN_P_H
#define STBPLUGIN_P_H

#include "enums.h"
#include "stbsubmodel.h"
#include "webobjectinfo.h"
#include "gui.h"

#include <QString>
#include <QList>
#include <QHash>
#include <QUrl>

namespace yasem {
namespace SDK {

class StbPluginObject;
class DatasourcePluginObject;
class MediaPlayer;
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
    MediaPlayer* mediaPlayer;
    QUrl portalUrl;
    QSharedPointer<GUI> guiPlugin;
    QSharedPointer<Browser> browserPlugin;
    QList<WebObjectInfo> webObjects;
    QHash<int, GUI::RcKey> keyCodeMap;
    QList<StbSubmodel> subModels;
    QString submodelDatasourceGroup;
    QString submodelDatasourceField;
};

}

}

#endif // STBPLUGIN_P_H

