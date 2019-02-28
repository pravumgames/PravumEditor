#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>

#include <string>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onResult();

    void on_pushButton_clicked();
    void on_openGithub_clicked();

    void on_openFile_clicked();

private:
    Ui::MainWindow *ui;
    QNetworkReply *m_currentReply;
    QNetworkAccessManager m_networkAccessManager;

};

#endif // MAINWINDOW_H
