#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"
#include <iostream>
#include <iomanip> 

class PhoneBook {
private:
    Contact contacts[8];
    int contactCount;
    int oldestIndex;

public:
    PhoneBook();
    void addContact();
    void searchContacts() const;
};

#endif