#include "Contact.h"

Contact::Contact(const QString& name, const QString& phone, const QString& email)
    : name_(name), phone_(phone), email_(email) {}

void Contact::setName(const QString& name)
{
    name_ = name;
}

void Contact::setPhone(const QString& phone)
{
    phone_ = phone;
}

void Contact::setEmail(const QString& email)
{
    email_ = email;
}

QString Contact::getName(void) const
{
    return name_;
}

QString Contact::getPhone(void) const
{
    return phone_;
}

QString Contact::getEmail(void) const
{
    return email_;
}
