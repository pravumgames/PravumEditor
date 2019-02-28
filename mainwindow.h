#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkAccessManager>
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
    void on_pushButton_clicked();
    void onResult(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;
    QNetworkReply *m_currentReply;
    QNetworkAccessManager m_networkAccessManager;

};

#endif // MAINWINDOW_H
