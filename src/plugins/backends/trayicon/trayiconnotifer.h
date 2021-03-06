#ifndef TRAYICONNOTIFER_H
#define TRAYICONNOTIFER_H

#include "core/plugins/snorebackend.h"

namespace Snore
{
class SnoreCore;
}

class QSystemTrayIcon;

class TrayIconNotifer: public Snore::SnoreBackend
{
    Q_OBJECT
    Q_INTERFACES(Snore::SnoreBackend)
    Q_PLUGIN_METADATA(IID "org.Snore.NotificationBackend/1.0" FILE "plugin.json")
public:
    TrayIconNotifer();
    virtual ~TrayIconNotifer() override;
    virtual bool deinitialize() override;
public slots:
    void slotNotify(Snore::Notification notification);
    void slotCloseNotification(Snore::Notification notification);
    void slotRegisterApplication(const Snore::Application &application);
    void slotDeregisterApplication(const Snore::Application &application);

private:
    QSystemTrayIcon *trayIcon(const Snore::Application &app);
    QList<Snore::Notification > m_notificationQue;
    uint m_displayed;
    bool m_currentlyDisplaying;


private slots:
    void displayNotification(QSystemTrayIcon *icon);
    void actionInvoked();

};

#endif // TRAYICONNOTIFER_H
