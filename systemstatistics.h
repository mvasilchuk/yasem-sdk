#ifndef SYSTEMSTATISTICS
#define SYSTEMSTATISTICS

#include "core.h"
#include <QObject>

namespace yasem {
namespace SDK {

class OsInfo: public QObject {
    Q_OBJECT
public:
    OsInfo(QObject* parent = 0): QObject(parent){};
    virtual ~OsInfo(){}

    virtual QString name() const = 0;
    virtual QString version() const = 0;
    virtual QString description() const = 0;
};

class HostInfo: public QObject {
    Q_OBJECT
public:
    HostInfo(QObject* parent = 0): QObject(parent){};
    virtual ~HostInfo(){}

    virtual QString name() const = 0;
    virtual QString ip() const = 0;
};

class PlatformInfo: public QObject {
    Q_OBJECT
public:
    enum Arch {
        UNKNOWN,
        x86,
        x86_64,
        ARMv7a, // Didn't check if it works on ARMv7a
        ARMv7h, // Paspberry Pi
    };

    PlatformInfo(QObject* parent = 0): QObject(parent){};
    virtual ~PlatformInfo(){}

    virtual Arch arch() const = 0;
    virtual QString archName() const = 0;
    virtual Core::VirtualMachine vm() const = 0;
};

class SystemStatistics: public QObject
{
    Q_OBJECT
public:
    enum OsGroup {
        UNKNOWN,
        Windows,
        Linux,
        OSX,
        Android
    };

    SystemStatistics(QObject* parent = 0): QObject(parent){};
    virtual ~SystemStatistics(){}

    virtual OsInfo* OS() const = 0;
    virtual HostInfo* host() const = 0;
    virtual PlatformInfo* platform() const = 0;

    virtual void print() const = 0;
};

}

}

#endif // SYSTEMSTATISTICS

