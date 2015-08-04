#ifndef PROFILE_CONFIG_PARSER_H
#define PROFILE_CONFIG_PARSER_H

#include <QString>
#include <QList>
#include <QVariant>
#include <QHash>

namespace yasem {
namespace SDK {

class ConfigOption {
public:
    QString m_tag;
    QString m_name;
    QString m_default_value;
    QString m_type;
    QString m_title;
    QString m_comment;
    QHash<QString, QString> m_options;

    ConfigOption(){}

    ConfigOption(const QString &tag,
                 const QString &name,
                 const QString &title,
                 const QString &defaultValue,
                 const QString &type = "string",
                 const QString &comment = "",
                 const QHash<QString, QString> &options = QHash<QString, QString>())
    {
        this->m_tag = tag;
        this->m_name = name;
        this->m_type = type;
        this->m_title = title;
        this->m_default_value = defaultValue;
        this->m_type = type;
        this->m_comment = comment;
        this->m_options = options;
    }

};

class ProfileConfigGroup {
public:
    QString m_title;
    QList<ConfigOption> m_options;

    ProfileConfigGroup() {}

    ProfileConfigGroup(const QString &title, const QList<ConfigOption> &options = QList<ConfigOption>())
    {
        this->m_title = title;
        this->m_options = options;
    }
};

class ProfileConfiguration {
public:
    QList<ProfileConfigGroup> groups;
};

class ProfileConfigParser {
public:
    virtual ProfileConfiguration parseOptions(ProfileConfiguration &config, const QByteArray &data) = 0;
};

}

}

#endif // PROFILE_CONFIG_PARSER_H
