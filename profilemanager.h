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

namespace yasem {

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
    virtual Profile* createProfile(const QString &classId, const QString &submodel, const QString &baseName = "", bool overwrite = false) = 0;
    virtual void registerProfileClassId(const QString &classId, StbPluginObject* profilePlugin) = 0;
    virtual QMap<QString, StbPluginObject*> getRegisteredClasses() = 0;

    virtual StbPluginObject* getProfilePluginByClassId(const QString &classId) = 0;
    virtual Profile* findById(const QString &id) = 0;
    virtual Profile* findByName(const QString &id) = 0;
    virtual Profile* backToPreviousProfile() = 0;
    virtual void backToMainPage() = 0;
    virtual bool canGoBack() = 0;

signals:
    void profileChanged(Profile* profile);
    void profileAdded(Profile* profile);
    void profileRemoved(bool removed);

protected:
    ProfileManager(QObject* parent): QObject(parent) {}
    QSet<Profile*> profilesList;
    QMap<QString, StbPluginObject*> profileClasses;
    Profile* activeProfile;
    QStack<Profile*> profileStack;

    virtual QString createUniqueName(const QString &classId, const QString &baseName = "", bool overwrite = false) = 0;

private:

    // Dont forget to declare these two. You want to make sure they
    // are unaccessable otherwise you may accidently get copies of
    // your singleton appearing.
    ProfileManager(ProfileManager const&);              // Don't Implement
    void operator=(ProfileManager const&); // Don't implement

};


}

#endif // PROFILEMANAGER_H
