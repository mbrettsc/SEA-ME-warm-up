#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVector>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateContactListView()
{
    ui->contactListWidget->clear();

    const QVector<Contact>& contacts = contactList.getContacts();

    for (const Contact& contact : contacts) {
        QString contactDetails = contact.getName() + " - " + contact.getPhone() + " - " + contact.getEmail();
        ui->contactListWidget->addItem(contactDetails);
    }
}

void MainWindow::on_addButton_clicked()
{
    Contact contact(ui->nameLineEdit->text(),
                    ui->phoneLineEdit->text(),
                    ui->emailLineEdit->text());

    contactList.addContact(contact);

    updateContactListView();
}

void MainWindow::on_removeButton_clicked()
{
    QString name = ui->nameLineEdit->text();

    contactList.removeContact(name);

    updateContactListView();
}

void MainWindow::on_searchButton_clicked()
{
    QString name = ui->nameLineEdit->text();

    Contact contact = *contactList.getByContactName(name);

    if (!contact.getName().isEmpty())
    {
        ui->nameLineEdit->setText(contact.getName());
        ui->phoneLineEdit->setText(contact.getPhone());
        ui->emailLineEdit->setText(contact.getEmail());
    }
    else
    {
        ui->phoneLineEdit->clear();
        ui->emailLineEdit->clear();
    }
}
