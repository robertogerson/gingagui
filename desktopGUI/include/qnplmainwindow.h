#ifndef QNPLMAINWINDOW_H
#define QNPLMAINWINDOW_H

#include <QMainWindow>
#include <QProgressDialog>
#include <QTimer>

#include "gingaproxy.h"
#include "qnplview.h"
#include "qnplsettings.h"
#include "qnplpreferencesdialog.h"
#include "qnplaboutdialog.h"
#include "qnplutil.h"
#include "qnplchannelsdialog.h"
#include "qnpliptvtunerdialog.h"
#include "qnplaplicationdialog.h"
#include "developerview.h"

class QnplMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QnplMainWindow(QWidget* parent = 0);
    ~QnplMainWindow();

    void load(QString location);

signals:
    void scanFinished ();

public slots:
    void performOpen();
    void performOpen(QAction* action);
    void performClear();
    void performClose();
    void performQuit();

    void playNextChannel();
    void playPreviousChannel();

    void performDevice();

    void performPreferences();
    void performChannels();
    void performIptv();
    void performAplication();

    void performBug();
    void performAbout();

    void performPlay();
    void performStop();

    void performRun();
    void performRunAsPassive();
    void performRunAsActive();

    void performCloseWindow(int, QProcess::ExitStatus);

    void notifyKey(QString key);

    void writeScanOutput ();

    void scan ();
    void playChannel (Channel channel);
    void showErrorDialog(QProcess::ProcessError);
    void writeTunerOutput ();
    void sendKillMessage ();
    void stopTuning();
    void removeCarouselData();

    void keyPressEvent(QKeyEvent *);

    void appendDebugMessage(QString);

    void startSession ();
protected:
    void resizeEvent(QResizeEvent* event);

private:
    void createMenus();
    void createRecent();
    void createActions();
    void createWidgets();
    void createDialogs();
    void createToolbars();
    void createConnections();
    void removePath (QString);
    void setUpProcessConnections (QProcess *);

    inline QString viewWID () {
        QString WID = "";

        foreach (QObject* ob, view->children()) {
            QWidget* w = qobject_cast<QWidget*>(ob);

            if (w)
            {
                WID =  hwndToString(w->winId());
            }
        }
        return WID;
    }

    QString hwndToString(WId winid);

    QMenu* fileMenu;    
    QMenu* recentMenu;
    QMenu* deviceMenu;
    QMenu* windowMenu;
    QMenu* helpMenu;

    QAction* openAction;
    QAction* tuneAppChannellAction;
    QAction* tuneIPTVChannellAction;
    QAction* tuneBroadChannellAction;
    QAction* quitAction;
    QAction* clearAction;
    QAction* baseAction;
    QAction* passiveAction;
    QAction* activeAction;
    QAction* preferencesAction;
    QAction* bugAction;
    QAction* aboutAction;

    QActionGroup* deviceGroup;

    QToolBar* playToolbar;
    QToolBar* openToolbar;

    QLineEdit* openLine;

    QPushButton* playButton;
    QPushButton* stopButton;
    QPushButton* openButton;
    QPushButton* nextButton;
    QPushButton* previousButton;
    QPushButton* refreshButton;
    QPushButton* channelsButton;

    QString location;

    QProcess* process;

    bool passiveIsRunning;

    QnplView* view;
    QnplSettings* settings;

    QnplPreferencesDialog* preferencesDialog;
    QnplAboutDialog* aboutDialog;
    QnplChannelsDialog * channelDialog;
    QnplIPTVTunerDialog * iptvDialog;
    QnplAplicationDialog * aplication;

    QProgressDialog *scanProgress;

    Channel lastChannel;
    QGraphicsProxyWidget *animTuning;
    QMovie *movie;
    QLabel *gifLabel;
    bool isPlayingChannel;
    QTimer *timer;

    GingaProxy *_gingaProxy;

    DeveloperView *_developerView;
};

#endif // QNPLMAINWINDOW_H
