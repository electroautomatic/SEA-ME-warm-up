#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <vector>
#include <string>

class Contact {
public:
    std::string name;
    std::string phone;
    std::string nickname;
    bool bookmarked;

    Contact(std::string n, std::string p, std::string nn) : name(n), phone(p), nickname(nn), bookmarked(false) {}
};

class Phonebook {
private:
    std::vector<Contact> contacts;

public:
    std::string addContact(std::string name, std::string phone, std::string nickname);
    std::vector<Contact> searchContacts();
    std::string getContactDetails(int index);
    std::string removeContact(int identifier);
    std::string bookmarkContact(int index);
    std::vector<Contact> listBookmarkedContacts();
};

#endif // PHONEBOOK_H
