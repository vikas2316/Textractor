#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Windows.h>
#include "../texthook/textthread.h"
#include "hostsignaller.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString ProcessOutput(TextThread *thread, QString output);
private slots:
    void on_attachButton_clicked();
    void on_detachButton_clicked();
    void on_ttCombo_activated(int index);
    void AddProcess(unsigned int processId);
    void RemoveProcess(unsigned int processId);
    void AddThread(TextThread* thread);
    void RemoveThread(TextThread* thread);
    void ThreadOutput(TextThread* thread, QString output);

private:
    Ui::MainWindow *ui;
    HostSignaller* hostSignaller;
};

#endif // MAINWINDOW_H