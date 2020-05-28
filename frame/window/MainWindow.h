//
// Created by septemberhx on 2020/5/23.
//

#ifndef DDE_TOP_PANEL_MAINWINDOW_H
#define DDE_TOP_PANEL_MAINWINDOW_H

#include <DBlurEffectWidget>
#include <DPlatformWindowHandle>
#include "../panel/MainPanelControl.h"
#include "util/TopPanelSettings.h"
#include "xcb/xcb_misc.h"

DWIDGET_USE_NAMESPACE

using namespace Dock;
using DBusDock = com::deepin::dde::daemon::Dock;    // use dbus to get the height/width, position and hide mode of the dock

class MainWindow : public DBlurEffectWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QScreen *screen, QWidget *parent = 0);
    ~MainWindow() override;

    void loadPlugins();

signals:
    void panelGeometryChanged();

private:
    void mousePressEvent(QMouseEvent *e);
    void resizeMainPanelWindow();
    void clearStrutPartial();
    void setStrutPartial();
    void initConnections();

private:
    DockItemManager *m_itemManager;
    DBusDock *m_dockInter;
    MainPanelControl *m_mainPanel;
    TopPanelSettings *m_settings;
    XcbMisc *m_xcbMisc;
    Position m_curDockPos;
    DPlatformWindowHandle m_platformWindowHandle;
};

class TopPanelLauncher : public QObject {
    Q_OBJECT

public:
    explicit TopPanelLauncher();

private slots:
    void monitorsChanged();

private:
    DBusDisplay *m_display;
};


#endif //DDE_TOP_PANEL_MAINWINDOW_H
