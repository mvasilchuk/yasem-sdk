#ifndef ENUM_H
#define ENUM_H

#include <QString>

namespace yasem {

static const QString DB_TAG_PROFILE = "profile";

enum MediaPlayingState
{
    StoppedState,
    PlayingState,
    PausedState
};

enum TOP_GUI_OBJECT {
    BROWSER = 0,
    VIDEO = 1
};

enum AspectRatio {
    ASPECT_RATIO_AUTO,
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
    ASPECT_RATIO_20_9
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

enum RC_KEY {
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

enum PluginFlag {
    PLUGIN_FLAG_NONE = 0,
    PLUGIN_FLAG_CLIENT = 1,
    PLUGIN_FLAG_SYSTEM = 2,
    PLUGIN_FLAG_HIDDEN = 4,
    PLUGIN_FLAG_GUI = 8
};


enum PluginRole {
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
    ROLE_HTTP_PROXY = 10
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
    InvalidMedia // what if loop > 0 or stopPosition() is not mediaStopPosition()?
};
}

#endif // ENUM_H
