#include "stbprofile.h"
#include "macros.h"
#include "stbpluginobject.h"
#include "datasourcefactory.h"
#include "datasource.h"

using namespace yasem::SDK;

Profile::Profile(SDK::StbPluginObject* profilePlugin, const QString &id):
    m_profile_plugin(profilePlugin),
    m_id(id)
{
    if(m_id == "")
        this->m_id = QUuid::createUuid().toString().mid(1, 34); //Remove braces, full length is 36
    this->flags = NORMAL;

    m_name = getId();

    ProfileConfigGroup group(QObject::tr("Main settings"));
    group.m_options.append(ConfigOption(DB_TAG_PROFILE, CONFIG_PROFILE_NAME, QObject::tr("Profile name"), QObject::tr("New profile")));

    QHash<QString, QString> models;
    QList<StbSubmodel>& submodels = profilePlugin->getSubmodels();
    for(StbSubmodel model: submodels)
    {
        models.insert(model.getId(), model.getName());
    }

    group.m_options.append(ConfigOption(DB_TAG_PROFILE, CONFIG_SUBMODEL, QObject::tr("Model name"), "","options", "", models));
    group.m_options.append(ConfigOption(DB_TAG_PROFILE, CONFIG_LIMIT_MAX_REQUESTS, QObject::tr("Limit max. requests per second"), "0", "string"));

    profileConfiguration.groups.append(group);
}

Profile::~Profile()
{
}

void Profile::cleanApi()
{
    DEBUG() << "Cleaning a list of API of the profile";
    getProfilePlugin()->cleanApi();
}

void Profile::setName(const QString &name)
{
    this->m_name = name;
}

QString Profile::getName() const
{
    return m_name;
}

QString Profile::getId() const
{
    return m_id;
}

void Profile::setId(const QString &id)
{
    this->m_id = id;
}

StbPluginObject* Profile::getProfilePlugin() const
{
    return this->m_profile_plugin;
}

Datasource* Profile::datasource() const
{
    return SDK::DatasourceFactory::instance()->forProfile(this);
}

QString Profile::getImage() const
{
    return this->image;
}

void Profile::setImage(const QString &path)
{
    this->image = path;
}

bool Profile::hasFlag(Profile::ProfileFlag flag) const
{
    return (flags & flag) == flag;
}

void Profile::addFlag(Profile::ProfileFlag flag)
{
    this->flags = (ProfileFlag)(this->flags | flag);
}

QString Profile::get(const QString &name, const QString &defaultValue)
{
    return datasource()->get(DB_TAG_PROFILE, name, defaultValue);
}

bool Profile::set(const QString &name, const QString &value)
{
    return datasource()->set(DB_TAG_PROFILE, name, value);
}

int Profile::get(const QString &name, int defaultValue)
{
    return datasource()->get(DB_TAG_PROFILE, name, defaultValue);
}

bool Profile::set(const QString &name, int value) {
    return datasource()->set(DB_TAG_PROFILE, name, value);
}

bool Profile::saveJsonConfig(const QString &jsonConfig)
{
    Q_ASSERT(datasource());
    DEBUG() << jsonConfig;
    QJsonArray arr = QJsonDocument::fromJson(jsonConfig.toUtf8()).array();
    foreach(QJsonValue item, arr)
    {
        QJsonObject obj = item.toObject();
        QStringList names = obj.value("name").toString().split("/");
        Q_ASSERT(names.length() == 2);

        QJsonValue value = obj.value("value");
        qDebug() << "saving" << names.at(1) << " -> " << value;
        datasource()->set(names.at(0), names.at(1), value.toVariant().toString());

    }

    setName(get("name", m_name));

    return true;
}

ProfileConfiguration &Profile::config()
{
    return profileConfiguration;
}

StbSubmodel &Profile::getSubmodel()
{
    return m_submodel;
}

void Profile::setSubmodel(const StbSubmodel &submodel)
{
    this->m_submodel = submodel;
}

void Profile::setPage(WebPage* page)
{
    this->m_page = page;
}

WebPage* Profile::page() const
{
    return m_page;
}
