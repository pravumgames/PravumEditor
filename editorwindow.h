#ifndef EDITORWINDOW_H
#define EDITORWINDOW_H

#include <QMainWindow>

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = nullptr);
    ~EditorWindow();

private slots:
    void copy();
    void paste();
    void cut();
    void undo();
    void redo();

private:
    Ui::EditorWindow *ui;
    void createActions();
    void createMenus();
};

#endif // EDITORWINDOW_H
