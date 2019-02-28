#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore>
#include <QtGui>
#include <QtDebug>

#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>

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

    QNetworkAccessManager networkManager;

    QUrl url("https://xslendix.github.io/PravumEngineAPI/changelog.json");
    QNetworkRequest request;
    request.setUrl(url);

    QNetworkReply* currentReply = networkManager.get(request);

    connect(&networkManager, SIGNAL(finished(QNetworkReply*)), this, SLOT (onResult(QNetworkReply*)));
}

void MainWindow::onResult(QNetworkReply* reply) {
    /*if (m_currentReply->error() != QNetworkReply::NoError) {
        return;
    }*/

    QJsonDocument a;
    a = QJsonDocument::fromJson( reply->readAll() );

    qDebug() << reply->readAll();

    QJsonObject json_obj=a.object();
    QVariantMap json_map = json_obj.toVariantMap();

    QString changes = json_map["changes"].toString();

    qDebug() << changes;

    if (changes != "") {
        return;
    } else {
        ui->changes->setText(changes);
    }

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
