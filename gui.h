#ifndef GUIPLUGIN_H
#define GUIPLUGIN_H

#include "abstractpluginobject.h"

#include <QtPlugin>
#include <QRect>

class QMenu;
class QMainWindow;

namespace yasem {
namespace SDK {

class GUI: public AbstractPluginObject
{
    Q_OBJECT
    Q_ENUMS(RcKey)
public:
    Q_PROPERTY(bool fullscreen READ getFullscreen WRITE setFullscreen)
    Q_PROPERTY(QRect rect READ getWindowRect WRITE setWindowRect)

    enum RcKey {
        RC_KEY_NO_KEY = 0,
        RC_KEY_OK = 1,

        RC_KEY_RIGHT = 2,
        RC_KEY_LEFT = 3,
        RC_KEY_UP = 4,

        RC_KEY_DOWN = 5,
        RC_KEY_PAGE_UP = 6,
        RC_KEY_PAGE_DOWN = 7,

        RC_KEY_MENU = 8,
        RC_KEY_BACK = 9,
        RC_KEY_REFRESH = 10,

        RC_KEY_RED = 11,
        RC_KEY_GREEN = 12,
        RC_KEY_YELLOW = 13,
        RC_KEY_BLUE = 14,

        RC_KEY_CHANNEL_PLUS = 15,
        RC_KEY_CHANNEL_MINUS = 16,

        RC_KEY_SERVICE = 17,
        RC_KEY_TV = 18,
        RC_KEY_PHONE = 19,
        RC_KEY_WEB = 20,
        RC_KEY_FRAME = 21,

        RC_KEY_VOLUME_UP = 22,
        RC_KEY_VOLUME_DOWN = 23,

        RC_KEY_REWIND = 24,
        RC_KEY_FAST_FORWARD = 25,
        RC_KEY_STOP = 26,
        RC_KEY_PLAY_PAUSE = 27,
        RC_KEY_REC = 28,

        RC_KEY_MIC = 29,
        RC_KEY_MUTE = 30,
        RC_KEY_POWER = 31,
        RC_KEY_INFO = 32,

        RC_KEY_NUMBER_0 = 33,
        RC_KEY_NUMBER_1 = 34,
        RC_KEY_NUMBER_2 = 35,
        RC_KEY_NUMBER_3 = 36,
        RC_KEY_NUMBER_4 = 37,
        RC_KEY_NUMBER_5 = 38,
        RC_KEY_NUMBER_6 = 39,
        RC_KEY_NUMBER_7 = 40,
        RC_KEY_NUMBER_8 = 41,
        RC_KEY_NUMBER_9 = 42,
        RC_KEY_EXIT = 99,

        RC_KEY_PLAY,
        RC_KEY_PAUSE
    };

#if QT_VERSION >= QT_VERSION_CHECK(5,5,0)
    Q_ENUM(RcKey)
#endif

    explicit GUI(Plugin* plugin):
        AbstractPluginObject(plugin) {}
    virtual ~GUI(){}

    static GUI* instance();

    virtual QRect getWindowRect() = 0;
    virtual void setWindowRect(const QRect &rect) = 0;

    virtual void setFullscreen(bool fullscreen) = 0;
    virtual bool getFullscreen() = 0;

    virtual void repaintGui() = 0;
    virtual QList<QMenu*> getMenuItems() = 0;
    virtual QRect widgetRect() = 0;

    QString getRcKeyName(RcKey key) const;
    RcKey getRcKeyByName(const QString &name) const;

    virtual QMainWindow* window() = 0;

signals:
    void windowRectChanged(const QRect& rect);
    void fullScreenModeChanged(bool fullscreen);
};

}

}

#endif // GUIPLUGIN_H
