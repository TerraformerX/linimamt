#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

    void on_actionOpen_triggered();

private:
    Ui::MainWindow *ui;
    QProcess *process;
    bool needsSave;
    QString currentFile;
    QString currentDir;
    QString label;
    QString serial;

    //structure
    struct fileEntry {
        QString name; //name contains folder.
        bool dir;
        unsigned long size;
        QString date;
        QString attrib;
    };
    QList<fileEntry>dirs;

    //functions
    int execute(QString command, QString parameters, QString & result);
    int loadFile(QString fileName);
    int prepareDirDump(QString home);
    int errorMessage(QString text, QString console);


};

#endif // MAINWINDOW_H