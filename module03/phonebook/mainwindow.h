#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "ContactList.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_searchButton_clicked();
    void on_saveButton_clicked();
    void on_loadButton_clicked();
    void on_contactListWidget_itemClicked(QListWidgetItem *item);
    void on_loadJsonButton_clicked();

private:
    Ui::MainWindow *ui;
    ContactList contactList;

    void updateContactListView();

};
#endif // MAINWINDOW_H
