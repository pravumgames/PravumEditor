#include "editorwindow.h"
#include "ui_editorwindow.h"

#include <QFileSystemModel>

EditorWindow::EditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    this->setFixedSize(1100,663);

    ui->statusbar->showMessage("Boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");
    ui->actionHistoryList->addItem("boi");

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath()); //any path
    ui->treeProject->setModel(model);
    ui->treeProject->setRootIndex(model->index(QDir::currentPath())); // to show only this path
}

void EditorWindow::copy() {}
void EditorWindow::paste() {}
void EditorWindow::cut() {}
void EditorWindow::undo() {}
void EditorWindow::redo() {}

EditorWindow::~EditorWindow()
{
    delete ui;
}
