#include "mediaplayer.h"
#include "browser.h"
#include "webpage.h"
#include "pluginmanager.h"

using namespace yasem::SDK;

MediaPlayer::MediaPlayer(Plugin *plugin):
    AbstractPluginObject(plugin),
    m_is_fullscreen(false),
    m_opacity(1),
    m_virtual_viewport(QRect(0, 0, 1920, 1080)),
    m_vp_scale_x(1),
    m_vp_scale_y(1),
    m_support_opengl(false)
{
    reset();
}

MediaPlayer::~MediaPlayer()
{

}

MediaPlayer* MediaPlayer::instance()
{
    static MediaPlayer* inst = 0;
    if(!inst)
        inst = PluginManager::getByRole<SDK::MediaPlayer>(ROLE_MEDIA);
    if(!inst)
        WARN() << "Media player not found!";
    return inst;
}

qreal MediaPlayer::getOpacity() const
{
    return m_opacity;
}

void MediaPlayer::setOpacity(qreal opacity)
{
    m_opacity = opacity;
}

void MediaPlayer::reset()
{
    m_opacity = 1;
}

void MediaPlayer::setViewport(const QRect &requestedRect)
{
    DEBUG() << "setViewport" << requestedRect << isFullscreen();
    m_player_viewport = requestedRect;
    recalculateViewportScale();
    resize();
}

void MediaPlayer::setViewport(const QRect &containerRect, const qreal containerScale, const QRect &requestedRect)
{
    //#define USE_RELATIVE_RECT

#ifndef USE_REAL_TRANSPARENCY
#define USE_RELATIVE_RECT
#endif //USE_REAL_TRANSPARENCY

    DEBUG() << "setViewport" << containerRect << containerScale << requestedRect << isFullscreen();
    if(requestedRect.width() >= 0 && requestedRect.height() >= 0)
    {
        if(isFullscreen())
        {
        #ifdef USE_RELATIVE_RECT
            rect(containerRect);
        #else
            rect(QRect(0, 0, containerRect.width(), containerRect.height()));
        #endif // USE_RELATIVE_RECT
        }
        else
        {
            m_player_viewport = requestedRect;
            m_container_rect = containerRect;
            recalculateViewportScale();

            QRect currentVideoWidgetRect = rect();

            DEBUG() << "containerRect: " << containerRect;
            DEBUG() << "containerScale: " << containerScale;
            DEBUG() << "currentVideoWidgetRect:" << currentVideoWidgetRect;
            DEBUG() << "requestedRect:" << requestedRect;
            DEBUG() << "vm scale x" << m_vp_scale_x;
            DEBUG() << "vm scale y" << m_vp_scale_y;


        #ifdef USE_RELATIVE_RECT
            QRect zoomedRect = QRect(
                        (int)((float)requestedRect.left() / m_vp_scale_x + containerRect.left()),
                        (int)((float)requestedRect.top() / m_vp_scale_y + containerRect.top()),
                        (int)((float)requestedRect.width() / m_vp_scale_x),
                        (int)((float)requestedRect.height() / m_vp_scale_y)
                        );

        #else

            QRect zoomedRect = QRect(
                        (int)((float)requestedRect.left() * containerScale),
                        (int)((float)requestedRect.top() * containerScale),
                        (int)((float)requestedRect.width() * containerScale),
                        (int)((float)requestedRect.height() * containerScale)
                        );

        #endif // USE_RELATIVE_RECT

            DEBUG() << "rect:" << zoomedRect;

            rect(zoomedRect);

        }
        widget()->repaint();
    }

    else
    {
    #ifdef USE_RELATIVE_RECT
        move((int)((float)requestedRect.left() * containerScale + containerRect.left()),
             (int)((float)requestedRect.top() * containerScale + containerRect.top()));
    #else
        move((int)((float)requestedRect.left() * containerScale),
             (int)((float)requestedRect.top() * containerScale));
    #endif // USE_RELATIVE_RECT
    }
}

QRect MediaPlayer::getViewport() const
{
    return rect();
}

/**
 * @brief MediaPlayerPluginObject::setVirtualViewport
 *
 * Sets a virtaul viewport for a player.
 *
 * @param virtual_viewport
 */
void MediaPlayer::setVirtualViewport(const QRect &virtual_viewport)
{
    m_virtual_viewport = virtual_viewport;
    recalculateViewportScale();
}

QRect MediaPlayer::getVirtualViewport() const
{
    return m_virtual_viewport;
}

void MediaPlayer::recalculateViewportScale()
{
    if(m_container_rect.width() > 0 && m_container_rect.height() > 0)
    {
        m_vp_scale_x = (qreal)m_virtual_viewport.width() / m_container_rect.width();
        m_vp_scale_y = (qreal)m_virtual_viewport.height() / m_container_rect.height();
    }
    else
    {
        m_vp_scale_x = 1;
        m_vp_scale_y = 1;
    }

}

void MediaPlayer::setFullscreen(bool value) {
    this->m_is_fullscreen = value;
}

bool MediaPlayer::isFullscreen() const {
    return this->m_is_fullscreen;
}

void MediaPlayer::resize() {
    Browser* browser = SDK::Browser::instance();
    if(browser)
    {
        WebPage* page = browser->getActiveWebPage();
        if(page)
        {
            QRect rect = page->getPageRect();
            qreal scale = page->scale();
            setViewport(rect, scale, m_player_viewport);
        }
    }
}

void MediaPlayer::addHook(MediaPlayer::HookEvent type, MediaPlayer::Hook *hook)
{
    if(!this->hookList.contains(type))
        this->hookList.insert(type, QSet<Hook*>());
    QSet<Hook*> hooks = this->hookList.value(type);
    hooks.insert(hook);
}

void MediaPlayer::removeHook(MediaPlayer::HookEvent type, MediaPlayer::Hook *hook)
{
    if(hookList.contains(type))
    {
        QSet<Hook*> hooks = hookList.value(type);
        hooks.remove(hook);
        delete hook;
    }
    else
    {
        qDebug() << "Hook type" << type << "not found. Cannot delete!";
    }
}

QSet<MediaPlayer::Hook *> MediaPlayer::hooks(MediaPlayer::HookEvent type)
{
    return hookList.value(type);
}

bool MediaPlayer::processHooks(MediaPlayer::HookEvent type)
{
    QSet<Hook*> list = this->hooks(type);
    foreach(Hook* hook, list)
    {
        if(!hook->m_func()) return false;
    }
    return true;
}

QString MediaPlayer::getQmlComponentName() const
{
    return "";
}

bool MediaPlayer::isSupportOpenGL()
{
    return m_support_opengl;
}
