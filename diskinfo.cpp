#include "diskinfo.h"

using namespace yasem::SDK;

QString StorageInfo::toString()
{
    return QString("disk: [%1, %2, %3, %4, %5, %6, %7, %8]")
            .arg(blockDevice)
            .arg(mountPoint)
            .arg(size)
            .arg(used)
            .arg(available)
            .arg(percentComplete)
            .arg(vendor)
            .arg(model);
}


BlockDeviceInfo::BlockDeviceInfo(QObject *parent):
    QObject(parent),
    m_index(-1),
    m_conn_interface( ConnectionInterface::NONE),
    m_hardware_type(DEVICE_TYPE_UNKNOWN)
{
}

BlockDeviceInfo::~BlockDeviceInfo()
{
}

QString BlockDeviceInfo::toString()
{
    return QString("block device: [%1, %2, %3, %4, %5, %6, %7, %8, %9]")
            .arg(QString::number(m_index))
            .arg(unique_id)
            .arg(parent_id)
            .arg(sys_fs_id)
            .arg(model)
            .arg(vendor)
            .arg(device)
            .arg(revision)
            .arg(device_file);
}
