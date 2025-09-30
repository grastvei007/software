#ifndef SYSTEMTRAYICON_H
#define SYSTEMTRAYICON_H

#include <QObject>
#include <QSystemTrayIcon>

#include <memory>

#include "batteryindicator.h"

class TagSocket;

class SystemTrayIcon : public QObject
{
    Q_OBJECT
public:
    SystemTrayIcon(QObject *parent = nullptr);
    ~SystemTrayIcon();


signals:

private slots:
    void onStateOfChargeChange(double aValue);
    void onActivated(QSystemTrayIcon::ActivationReason reason);

private:
    void onIconClicked();
    std::unique_ptr<QSystemTrayIcon> mSystemTrayIcon;
    BatteryIndicator mBatteryIndicator;

    std::unique_ptr<TagSocket> mSocTagSocket;
    BatteryIndicator::State mBatteryState;
};

#endif // SYSTEMTRAYICON_H
