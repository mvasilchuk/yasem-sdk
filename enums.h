#ifndef ENUM_H
#define ENUM_H

#include <QString>

namespace yasem {
namespace  SDK {

static const QString DB_TAG_PROFILE = "profile";

QT_BEGIN_NAMESPACE

/*class Globals {
    Q_GADGET
    Q_ENUMS(MediaPlayingState)
    Q_ENUMS(TopGuiObject)
    Q_ENUMS(AspectRatio)
    Q_ENUMS(PluginErrorCodes)
    Q_ENUMS(PluginState)
    Q_ENUMS(DB_ERRORS)
    Q_ENUMS(RC_ERRORS)
    Q_ENUMS(RC_KEY_EVENT_TYPE)
    Q_ENUMS(RC_KEY)
    Q_ENUMS(CMD_ARGUMENTS)
    Q_ENUMS(MOUSE_POSITION)
    Q_ENUMS(PluginFlag)
    Q_ENUMS(PluginConflictType)
    Q_ENUMS(MediaStatus)


public:*/
    enum MediaPlayingState
    {
        StoppedState,
        PlayingState,
        PausedState
    };

    enum TopGuiObject {
        BROWSER = 0,
        VIDEO = 1
    };

    enum AspectRatio {
        ASPECT_RATIO_AUTO,      // Qt::KeepAspectRatio
        ASPECT_RATIO_1_1,
        ASPECT_RATIO_5_4,
        ASPECT_RATIO_4_3,
        ASPECT_RATIO_11_8,
        ASPECT_RATIO_14_10,
        ASPECT_RATIO_3_2,
        ASPECT_RATIO_14_9,
        ASPECT_RATIO_16_10,
        ASPECT_RATIO_16_9,
        ASPECT_RATIO_2_35_1,
        ASPECT_RATIO_20_9,
        ASPECT_RATIO_FILL,      // Qt::IgnoreAspectRatio
        ASPECT_RATIO_EXPANDING  // Qt::KeepAspectRatioByExpanding
    };

    enum PluginErrorCodes {
        PLUGIN_ERROR_UNKNOWN_ERROR = -1,
        PLUGIN_ERROR_NO_ERROR = 0,
        PLUGIN_ERROR_NOT_INITIALIZED = 1,
        PLUGIN_ERROR_CYCLIC_DEPENDENCY = 2,
        PLUGIN_ERROR_DEPENDENCY_MISSING = 3,
        PLUGIN_ERROR_NO_PLUGIN_ID = 4,
        PLUGIN_ERROR_DIR_NOT_FOUND = 5,
        PLUGIN_ERROR_CONFLICT = 6,
        PLUGIN_ERROR_PLUGIN_DISABLED = 7,
    };

    enum PluginState {
        PLUGIN_STATE_UNKNOWN = -1,
        PLUGIN_STATE_DISABLED = 0,
        PLUGIN_STATE_NOT_INITIALIZED = 1,
        PLUGIN_STATE_INITIALIZED = 2,
        PLUGIN_STATE_WAITING_FOR_DEPENDENCY = 3,
        PLUGIN_STATE_ERROR_STATE = 4,
        PLUGIN_STATE_CONFLICT = 5,
        PLUGIN_STATE_DISABLED_BY_DEPENDENCY = 6,
        PLUGIN_STATE_THREAD_CREATING = 7,
        PLUGIN_STATE_THREAD_STARTED = 8
    };

    enum DB_ERRORS {
        DB_ERROR_UNKNOWN_ERROR = -1,
        DB_ERROR_NO_ERROR = 0,
        DB_ERROR_NOT_FOUND = 1,
        DB_ERROR_CORRUPTED = 2,
        DB_ERROR_TABLE_NOT_FOUND = 2
    };

    enum RC_ERRORS {
        RC_UNKNOWN_ERROR = -1,
        RC_NO_ERROR = 0,
        RC_KEYCODE_NOT_FOUND = 1
    };

    enum RC_KEY_EVENT_TYPE {
        onKeyPress = 0,
        onKeyDown = 1,
        onKeyUp = 2
    };


    enum CMD_ARGUMENTS {
        COLOR_OUTPUT,
        FULLSCREEN_APP,
        DEVELOPER_TOOLS
    };

    static QString arguments[] = {
        "--color",
        "--fullscreen",
        "--developer-tools"
    };

    enum MOUSE_POSITION {
        MIDDLE  = 0,
        LEFT    = 1,
        TOP     = 2,
        RIGHT   = 4,
        BOTTOM  = 8
    };

    enum PluginFlag
    {
        PLUGIN_FLAG_NONE = 0,
        PLUGIN_FLAG_CLIENT = 1,
        PLUGIN_FLAG_SYSTEM = 2,
        PLUGIN_FLAG_HIDDEN = 4,
        PLUGIN_FLAG_GUI = 8
    };

    enum PluginRole
    {
        ROLE_ANY = -1,
        ROLE_UNKNOWN = 0,
        ROLE_UNSPECIFIED = 1,
        ROLE_GUI = 2,
        ROLE_MEDIA = 3,
        ROLE_STB_API = 4,

        ROLE_BROWSER = 6,
        ROLE_DATASOURCE = 7,
        ROLE_WEB_SERVER = 8,
        ROLE_WEB_GUI = 9,
        ROLE_HTTP_PROXY = 10,
        /**
          Plugins that do some integration into environment (i.e. Windows, Linux,
          OS X or KDE, Gnome, etc)
          */
        ROLE_ENV_INTEGRATION = 11,
        ROLE_TIMESHIFT = 12
    };

    enum PluginConflictType {
        PLUGIN_CONFLICTS_BY_NAME,
        PLUGIN_CONFLICTS_BY_ID,
        PLUGIN_CONFLICTS_BY_NAME_OR_ID
    };


    // Similar to QtAV::MediaStatus, but I made a copy to remove dependency from QtAV
    enum MediaStatus
    {
        UnknownMediaStatus,
        NoMedia,
        LoadingMedia, // when source is set
        LoadedMedia, // if auto load and source is set. player is stopped state
        StalledMedia, // insufficient buffering or other interruptions (timeout, user interrupt)
        BufferingMedia, // NOT IMPLEMENTED
        BufferedMedia, // when playing //NOT IMPLEMENTED
        EndOfMedia,
        InvalidMedia, // what if loop > 0 or stopPosition() is not mediaStopPosition()?,
        VideoInfoReceived,
        MediaInfoReceived = 100 // Both audio and video
    };

/*}; */

QT_END_NAMESPACE

}

}

#endif // ENUM_H
