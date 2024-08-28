#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

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
    if (ui->nameLineEdit->text() == "") {
        QMessageBox::information(this, "Error", "At least name field must be filled for saving a contact!");
        return;
    }

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
    QString searchTerm = ui->searchLineEdit->text();
    QString criteria = ui->searchCriteriaComboBox->currentText();


    QList<Contact> results = contactList.searchContacts(searchTerm, criteria);


    ui->contactListWidget->clear();
    for (const Contact &contact : results) {
    ui->contactListWidget->addItem(contact.getName() + " - " + contact.getPhone() + " - " + contact.getEmail());
    }
}

void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Contact List", "", "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);

        const QVector<Contact>& contacts = contactList.getContacts();
        for (const Contact& contact : contacts) {
            out << contact.getName() << "," << contact.getPhone() << "," << contact.getEmail() << "\n";
        }

        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Failed to save contact list");
    }
}

void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Load Contact List", "", "Text Files (*.txt);;All Files (*)");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);


        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(",");

            if (fields.size() == 3) {
                QString name = fields[0];
                QString phone = fields[1];
                QString email = fields[2];

                Contact contact(name, phone, email);
                contactList.addContact(contact);
            }
        }

        file.close();
        updateContactListView();
    } else {
        QMessageBox::warning(this, "Error", "Failed to load contact list");
    }
}

void MainWindow::on_contactListWidget_itemClicked(QListWidgetItem *item)
{
    QString selectedText = item->text();

    QStringList details = selectedText.split(" - ");
    if (details.size() == 3) {
        QString name = details[0];
        QString phone = details[1];
        QString email = details[2];

        ui->nameLineEdit->setText(name);
        ui->phoneLineEdit->setText(phone);
        ui->emailLineEdit->setText(email);
    }
}

void MainWindow::on_loadJsonButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Import Contacts from JSON", "", "JSON Files (*.json);;All Files (*)");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", "Could not open file for reading.");
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    file.close();

    if (doc.isNull() || !doc.isObject()) {
        QMessageBox::critical(this, "Error", "Invalid JSON file format.");
        return;
    }

    QJsonObject rootObject = doc.object();
    QJsonArray contactsArray = rootObject["contacts"].toArray();

    for (const QJsonValue &value : contactsArray) {
        if (value.isObject()) {
            QJsonObject contactObj = value.toObject();
            QString name = contactObj["name"].toString();
            QString phone = contactObj["phone"].toString();
            QString email = contactObj["email"].toString();

            Contact contact(name, phone, email);
            contactList.addContact(contact);
        }
    }

    updateContactListView();
}
