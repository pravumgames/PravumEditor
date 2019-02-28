#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QtDebug>

#include <QDesktopServices>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

#include <string>

#include "editorwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette pal = centralWidget()->palette();
    pal.setColor(centralWidget()->backgroundRole(), 0x424242);
    centralWidget()->setPalette(pal);

    setStyleSheet("");
    this->setWindowFlags(this->windowFlags() | Qt::NoDropShadowWindowHint);

    QUrl url("http://well-chosen-correct.000webhostapp.com/changelog.json");
    QNetworkRequest request;
    request.setUrl(url);

    m_currentReply = m_networkAccessManager.get(request);

    connect(m_currentReply, SIGNAL(finished()), this, SLOT (onResult()));
}

void MainWindow::onResult() {
    if (m_currentReply->error() != QNetworkReply::NoError) {
        return;
    }

    QJsonDocument a;
    a = QJsonDocument::fromJson( m_currentReply->readAll() );

    qDebug() << m_currentReply->readAll();

    QJsonObject json_obj=a.object();
    QVariantMap json_map = json_obj.toVariantMap();

    QString changesz = json_map["changes"].toString();

    qDebug() << changesz;

    if (changesz == "") {
        return;
    } else {
        ui->changes->setText(changesz);
    }

    m_currentReply->deleteLater();
    m_currentReply = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    EditorWindow* editwindow = new EditorWindow(this);
    editwindow->show();
    this->hide();
}

void MainWindow::on_openGithub_clicked()
{
    QString link = "https://github.com/xslendix/PravumEditor";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_openFile_clicked()
{

}
