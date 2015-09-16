#ifndef ABSTRACTWEBPAGE
#define ABSTRACTWEBPAGE

#include <QString>
#include <QSize>
#include <QRect>
#include <QUrl>
#include <QColor>

class QWidget;

namespace yasem {
namespace SDK {

class WebPagePrivate;


class WebPage {
    Q_DECLARE_PRIVATE(WebPage)
public slots:

    explicit WebPage();
    virtual ~WebPage();

    virtual bool load(const QUrl &url) = 0;
    virtual bool openWindow(const QString &url, const QString &params, const QString &name) = 0;
    virtual void close() = 0;
    virtual void evalJs(const QString &js) = 0;
    virtual void setPageViewportSize(QSize new_size) = 0;
    virtual QSize getVieportSize() = 0;
    virtual qreal scale() = 0;
    virtual QRect getPageRect() = 0;

    virtual bool isChromaKeyEnabled() const = 0;
    virtual void setChromaKeyEnabled(bool enabled) = 0;
    virtual QColor getChromaKey() const = 0;
    virtual void setChromaKey(QColor color) = 0;
    virtual QColor getChromaMask() const = 0;
    virtual void setChromaMask(QColor color) = 0;
    virtual float getOpacity() const = 0;
    virtual void setOpacity(float opacity) = 0;

    virtual void reset() = 0;
    virtual void execKeyEvent(const QString &action, int code, Qt::KeyboardModifiers mods, const QString &symbol) = 0;
    virtual QWidget* widget() const = 0;

    virtual QString getTitle() const = 0;
    virtual QUrl getURL() const = 0;
    virtual QString getRootDir() const = 0;

    virtual void move(int x, int y) = 0;
    virtual void resize(int width, int height) = 0;
    virtual void show() = 0;
    virtual void hide() = 0;
    virtual void raise() = 0;
    virtual void setStyleSheet(const QString& stylesheet) = 0;

    virtual void setId(const QString& id);
    virtual QString getId() const;

protected:
protected:
    WebPage(WebPagePrivate &d): d_ptr(&d) {}
    // allow subclasses to initialize with their own concrete Private
    WebPagePrivate *d_ptr;

};
}

}

#endif // ABSTRACTWEBPAGE

