#ifndef VIDEOVIEW_H
#define VIDEOVIEW_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>

class QVideoWidget;
class VideoControl;
class CBarrageWidget;

class VideoView : public QWidget
{
    Q_OBJECT
public:
    explicit VideoView(QWidget *parent = 0);
    ~VideoView();

signals:

public slots:
    void play();

private slots:
    void positionChanged(qint64 position);
    void durationChanged(qint64 duration);
    void setPosition(int position);
    void volumnChanged(int volumn);
    void mediaChanged(const QString &data);
    void stateChanged(QMediaPlayer::State state);

    void addBarrageChanged(const QString &str);
    void pushBarrageChanged(bool on);
    void barrageSizeButtonChanged(int size);
    void barrageColorButtonChanged(const QColor &color);

protected:
    virtual void enterEvent(QEvent *event) override;
    virtual void leaveEvent(QEvent *event) override;
    virtual void contextMenuEvent(QContextMenuEvent *event) override;

    QMediaPlayer *m_player;
    QVideoWidget *m_videoWidget;
    VideoControl *m_control;
    CBarrageWidget *m_barrageCore;

};

#endif // VIDEOVIEW_H
