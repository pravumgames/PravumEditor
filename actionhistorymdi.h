#ifndef ACTIONHISTORYMDI_H
#define ACTIONHISTORYMDI_H

#include <QMainWindow>

//void addItem(QString *text);

namespace Ui {
class ActionHistoryMDI;
}

class ActionHistoryMDI : public QMainWindow
{
    Q_OBJECT



public:
    explicit ActionHistoryMDI(QWidget *parent = nullptr);

    void addItem(QString *text);
    ~ActionHistoryMDI();

private:
    Ui::ActionHistoryMDI *ui;


};

#endif // ACTIONHISTORYMDI_H
