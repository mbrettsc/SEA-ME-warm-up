#ifndef CONTACT_H
#define CONTACT_H

#include <QString>

class Contact
{
public:
    Contact(const QString& name, const QString& phone, const QString& email);

    void setName(const QString& name);
    void setPhone(const QString& phone);
    void setEmail(const QString& email);

    QString getName(void) const;
    QString getPhone(void) const;
    QString getEmail(void) const;
private:
    QString name_;
    QString phone_;
    QString email_;
};

#endif // CONTACT_H
