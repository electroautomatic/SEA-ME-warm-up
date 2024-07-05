#include <QCoreApplication>
#include <QTextStream>
#include <QStringList>
#include "Phonebook.h"

void printContacts(const std::vector<Contact> &contacts) {
    QTextStream out(stdout);
    out << "Index\tName\tPhone\tNickname" << Qt::endl;
    for (int i = 0; i < contacts.size(); ++i) {
        out << i << "\t" << QString::fromStdString(contacts[i].name) << "\t" << QString::fromStdString(contacts[i].phone) << "\t" << QString::fromStdString(contacts[i].nickname) << Qt::endl;
    }
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    QTextStream in(stdin);
    QTextStream out(stdout);

    Phonebook phonebook;

    while (true) {
        out << "Enter Command: ";
        out.flush();
        QString input = in.readLine();
        QStringList parts = input.split(" ");
        QString cmd = parts[0].toUpper();

        if (cmd == "ADD" && parts.size() == 4) {
            QString name = parts[1];
            QString phone = parts[2];
            QString nickname = parts[3];
            out << QString::fromStdString(phonebook.addContact(name.toStdString(), phone.toStdString(), nickname.toStdString())) << Qt::endl;
        } else if (cmd == "SEARCH") {
            std::vector<Contact> results = phonebook.searchContacts();
            if (!results.empty()) {
                printContacts(results);
            } else {
                out << "No contacts found." << Qt::endl;
            }
        } else if (cmd == "DETAILS" && parts.size() == 2) {
            int index = parts[1].toInt();
            out << QString::fromStdString(phonebook.getContactDetails(index)) << Qt::endl;
        } else if (cmd == "REMOVE" && parts.size() == 2) {
            int index = parts[1].toInt();
            out << QString::fromStdString(phonebook.removeContact(index)) << Qt::endl;
        } else if (cmd == "BOOKMARK" && parts.size() == 2) {
            int index = parts[1].toInt();
            out << QString::fromStdString(phonebook.bookmarkContact(index)) << Qt::endl;
        } else if (cmd == "BOOKMARKS") {
            std::vector<Contact> results = phonebook.listBookmarkedContacts();
            if (!results.empty()) {
                printContacts(results);
            } else {
                out << "No bookmarked contacts found." << Qt::endl;
            }
        } else if (cmd == "EXIT") {
            break;
        } else {
            out << "Invalid command." << Qt::endl;
        }
    }

    return 0;
}
