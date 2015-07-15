#ifndef PROFILE_H
#define PROFILE_H

#include "profile_config_parser.h"
#include "stbsubmodel.h"

#include <QUrl>
#include <QUuid>
#include <QSize>
#include <QJsonDocument>
#include <QJsonArray>

static const QString CONFIG_PROFILE_NAME = "name";
static const QString CONFIG_SUBMODEL = "submodel";
static const QString CONFIG_LIMIT_MAX_REQUESTS = "limit_max_requests";
static const QString CONFIG_PORTAL_SIZE = "portal_size";
static const QString CONFIG_PORTAL_URL = "portal";

namespace yasem {
namespace SDK {

class DatasourcePluginObject;
class StbPluginObject;
class WebPage;

class Profile
{

public:
    enum ProfileFlag {
        NORMAL = 0,
        HIDDEN = 1,
    };

    explicit Profile(StbPluginObject* profilePlugin, const QString &id);

    virtual ~Profile();

    virtual void start() = 0;
    virtual void stop() = 0;

    void setName(const QString &name);
    QString getName() const;
    QString getId() const;
    void setId(const QString &id);
    StbPluginObject* getProfilePlugin() const;

    DatasourcePluginObject* datasource() const;
    void datasource(DatasourcePluginObject* datasource);

    QString getImage() const;
    void setImage(const QString &path);

    virtual void initDefaults() = 0;

    virtual void configureKeyMap() = 0;

    bool hasFlag(ProfileFlag flag) const;

    void addFlag(ProfileFlag flag);

    QString get(const QString &name, const QString &defaultValue = "");
    bool set(const QString &name, const QString &value);

    int get(const QString &name, int defaultValue = 0);
    bool set(const QString &name, int value);

    bool saveJsonConfig(const QString& jsonConfig);

    virtual QString portal() = 0;

    ProfileConfiguration &config();

    StbSubmodel& getSubmodel();
    void setSubmodel(const StbSubmodel& submodel);

    void setPage(WebPage* page);
    WebPage* page() const;


protected:
    StbPluginObject* m_profile_plugin;
    QString m_id;

    StbSubmodel submodel;
    QString name;
    ProfileFlag flags;
    QString image;
    DatasourcePluginObject* m_datasource;
    QHash<QString, QString> userAgents;
    QHash<QString, QSize> portalResolutions;
    QHash<QString, QSize> videoResolutions;
    ProfileConfiguration profileConfiguration;
    WebPage* m_page;

signals:

public slots:

friend class StbPluginObject;
friend class ProfileManager;

};

}

}

#endif // PROFILE_H
