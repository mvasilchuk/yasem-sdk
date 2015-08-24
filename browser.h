#ifndef BROWSERPLUGIN_H
#define BROWSERPLUGIN_H

#include "enums.h"
#include "abstractpluginobject.h"
#include "gui.h"

#include <QSize>
#include <QObject>
#include <QMetaMethod>
#include <QSslError>

class QRect;
class QUrl;
class QResizeEvent;
class QWidget;
class QEvent;

namespace yasem {
namespace SDK {
class StbPluginObject;
class CustomKeyEvent;
class WebPage;

class Browser: public AbstractPluginObject
{
    Q_OBJECT
public:
    Browser(Plugin* plugin);
    virtual ~Browser();

    enum TopWidget {
        TOP_WIDGET_BROWSER,
        TOP_WIDGET_PLAYER
    };

    enum SslStatus {
        SSL_UNDEFINED,
        PLAINTEXT,
        ENCRYPTED,
        SSL_ERROR
    };

    static Browser* instance();

    virtual void setParentWidget(QWidget *parent) = 0;
    virtual QWidget* getParentWidget() = 0;
    virtual QWidget* widget() = 0 ;
    virtual void resize(QResizeEvent* = 0) = 0;
    virtual void rect(const QRect &rect) = 0;
    virtual QRect rect() = 0;
    virtual void scale(qreal scale) = 0;
    virtual qreal scale() = 0;
    virtual void stb(SDK::StbPluginObject* stbPlugin) = 0;
    virtual SDK::StbPluginObject* stb() = 0;
    virtual void show() = 0;
    virtual void hide() = 0;
    virtual void fullscreen(bool setFullscreen) = 0;
    virtual bool fullscreen() = 0;

    virtual QUrl url() const = 0;

    Q_DECL_DEPRECATED
    virtual QString browserRootDir() const = 0;
    virtual void setUserAgent(const QString &userAgent) = 0;
    virtual void addFont(const QString &fileName) = 0;
    virtual void registerKeyEvent(GUI::RcKey rc_key, int keyCode) = 0;
    virtual void registerKeyEvent(GUI::RcKey rc_key, int keyCode, int which, bool alt = false, bool ctrl = false, bool shift = false) = 0;
    virtual void registerKeyEvent(GUI::RcKey rc_key, int keyCode, int which, int keyCode2, int which2, bool alt = false, bool ctrl = false, bool shift = false) = 0;
    virtual void clearKeyEvents() = 0;
    virtual void passEvent(QEvent *event) = 0;

    virtual void setupMousePositionHandler(const QObject *receiver, const char* method) = 0;

    virtual SDK::WebPage* getFirstPage() = 0;

    virtual QString getQmlComponentName();

    virtual SDK::WebPage* createNewPage(bool child = false) = 0;
    virtual WebPage* getActiveWebPage() = 0;

    virtual void setUseQml(bool use);
    virtual bool isUsingQml() const;

    virtual void setTopWidget(TopWidget top);
    virtual TopWidget getTopWidget();

public slots:
    virtual void showDeveloperTools();

protected:
    QWidget* activeWebView;
    bool m_use_qml;
    TopWidget m_top_widget;

signals:
    void topWidgetChanged();

    void page_loading_started(const QString& url);
    void connection_encrypted(const QString& url);
    void encryption_error(const QString& url, const QList<QSslError> &errors);
};
}
}

#endif // BROWSERPLUGIN_H
