#include "ContactList.h"
#include <QDebug>

void ContactList::addContact(const Contact& contact)
{
    contacts_.push_back(contact);
}

void ContactList::removeContact(const QString& name)
{
    for (size_t i = 0; i < contacts_.size(); ++i) {
        if (contacts_[i].getName().compare(name, Qt::CaseSensitive) == 0)
        {
            contacts_.removeAt(i);
            return;
        }
    }
}

Contact* ContactList::getByContactName(const QString& name)
{
    for (auto& contact : contacts_) {
        if (contact.getName().compare(name, Qt::CaseSensitive) == 0)
            return &contact;
    }
    return nullptr;
}

const QVector<Contact>& ContactList::getContacts(void) const
{
    return contacts_;
}

QList<Contact> ContactList::searchContacts(const QString &searchTerm, const QString &criteria)
{
    QList<Contact> results;
    for (const Contact &contact : contacts_) {
        if ((criteria == "Name" && contact.getName().contains(searchTerm, Qt::CaseInsensitive)) ||
            (criteria == "Phone" && contact.getPhone().contains(searchTerm, Qt::CaseInsensitive)) ||
            (criteria == "Email" && contact.getEmail().contains(searchTerm, Qt::CaseInsensitive))) {
            results.append(contact);
        }
    }
    return results;
}
