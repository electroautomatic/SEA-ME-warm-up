#include "Phonebook.h"

std::string Phonebook::addContact(std::string name, std::string phone, std::string nickname) {
    for (const auto &contact : contacts) {
        if (contact.phone == phone) {
            return "Phone number already exists.";
        }
    }
    contacts.emplace_back(name, phone, nickname);
    return "Contact added successfully.";
}

std::vector<Contact> Phonebook::searchContacts() {
    return contacts;
}

std::string Phonebook::getContactDetails(int index) {
    if (index >= 0 && index < contacts.size()) {
        Contact contact = contacts[index];
        return "Name: " + contact.name + "\nPhone: " + contact.phone + "\nNickname: " + contact.nickname + "\nBookmarked: " + (contact.bookmarked ? "Yes" : "No");
    } else {
        return "Invalid index.";
    }
}

std::string Phonebook::removeContact(int identifier) {
    if (identifier >= 0 && identifier < contacts.size()) {
        contacts.erase(contacts.begin() + identifier);
        return "Contact removed successfully.";
    } else {
        return "Invalid index.";
    }
}

std::string Phonebook::bookmarkContact(int index) {
    if (index >= 0 && index < contacts.size()) {
        contacts[index].bookmarked = true;
        return "Contact bookmarked.";
    } else {
        return "Invalid index.";
    }
}

std::vector<Contact> Phonebook::listBookmarkedContacts() {
    std::vector<Contact> bookmarkedContacts;
    for (const auto &contact : contacts) {
        if (contact.bookmarked) {
            bookmarkedContacts.push_back(contact);
        }
    }
    return bookmarkedContacts;
}
