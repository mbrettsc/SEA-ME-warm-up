#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include <QVector>

class ContactList
{
public:
    void addContact(const Contact& contact);
    void removeContact(const QString& name);
    Contact* getByContactName(const QString& name);
    const QVector<Contact>& getContacts(void) const;
private:
    QVector<Contact> contacts_;
};

#endif // CONTACTLIST_H
