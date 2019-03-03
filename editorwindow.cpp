#include "editorwindow.h"
#include "actionhistorymdi.h"
#include "ui_editorwindow.h"
#include "ui_actionhistorymdi.h"

#include <QMdiSubWindow>

#include <QFileSystemModel>

EditorWindow::EditorWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);

    //this->setFixedSize(1100,663);

    loadSubWindow(new ActionHistoryMDI(this), "Action History");

    //ui->mdiArea->addSubWindow();

    ui->statusbar->showMessage("Boi");
    ActionHistoryMDI *sadf = new ActionHistoryMDI(this);
    QString *heplmepls = new QString("healp");
    sadf->addItem(heplmepls);     // Wai it no work ;-;
    //ui->actionHistoryList->addItem("boi");

    QFileSystemModel *model = new QFileSystemModel;
    model->setRootPath(QDir::currentPath()); //any path
    ui->treeProject->setModel(model);
    ui->treeProject->setRootIndex(model->index(QDir::currentPath())); // to show only this path
}

void EditorWindow::loadSubWindow (QWidget *widget, QString title) {
    auto window = ui -> mdiArea -> addSubWindow(widget);
    window -> setWindowTitle(title);
    window -> setWindowIcon(window->windowIcon());
    window -> show();
}

void EditorWindow::copy()  {}
void EditorWindow::paste() {}
void EditorWindow::cut()   {}
void EditorWindow::undo()  {}
void EditorWindow::redo()  {}

EditorWindow::~EditorWindow()
{
    delete ui;
}
