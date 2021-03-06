#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H

#include "enums.h"

#include <QObject>
#include <QList>
#include <QStringList>
#include <QJsonArray>
#include <QCoreApplication>
#include <QVariant>
#include <QSet>
#include <QStack>
#include <QSharedPointer>

namespace yasem {
namespace SDK {

class StbPluginObject;
class Profile;

class ProfileManager : public QObject
{
    Q_OBJECT
public:

    static ProfileManager* setInstance(ProfileManager* inst = 0)
    {
        static ProfileManager* instance = inst;// Guaranteed to be destroyed.

        if(instance == NULL)
            instance = static_cast<ProfileManager*>(qApp->property("ProfileManager").value<QObject*>());

        Q_CHECK_PTR(instance);
        return instance;
    }

    static ProfileManager* instance()
    {
       return setInstance();
    }

    virtual void loadProfiles() = 0;
    virtual QSet<Profile*> getProfiles() = 0;
    virtual Profile* getActiveProfile() = 0;
    virtual void addProfile(Profile* profile) = 0;
    virtual void setActiveProfile(Profile* profile) = 0;
    virtual bool removeProfile(Profile* profile) = 0;
    virtual SDK::Profile* createProfile(const QString &classId, const QString &submodel, const QString &baseName = "", bool overwrite = false) = 0;
    virtual void registerProfileClassId(const QString &classId, StbPluginObject* profilePlugin) = 0;
    virtual QMap<QString, SDK::StbPluginObject*> getRegisteredClasses() = 0;

    virtual SDK::StbPluginObject* getProfilePluginByClassId(const QString &classId) = 0;
    virtual SDK::Profile* findById(const QString &id) = 0;
    virtual SDK::Profile* findByName(const QString &id) = 0;
    virtual SDK::Profile* backToPreviousProfile() = 0;
    virtual void backToMainPage() = 0;
    virtual bool canGoBack() = 0;

signals:
    void profileChanged(SDK::Profile* profile);
    void profileAdded(SDK::Profile* profile);
    void profileRemoved(bool removed);

protected:
    ProfileManager(QObject* parent);
    ~ProfileManager();
    QSet<Profile*> m_profiles_list;
    QMap<QString, StbPluginObject*> m_profile_classes;
    Profile* m_active_profile;
    QStack<Profile*> m_profiles_stack;

    virtual QString createUniqueName(const QString &classId, const QString &baseName = "", bool overwrite = false) = 0;

private:

    // Dont forget to declare these two. You want to make sure they
    // are unaccessable otherwise you may accidently get copies of
    // your singleton appearing.
    ProfileManager(ProfileManager const&);              // Don't Implement
    void operator=(ProfileManager const&); // Don't implement

};

}

}

#endif // PROFILEMANAGER_H
