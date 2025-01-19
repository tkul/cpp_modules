#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
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

void set();
void print(const Contact contacts[], int index);

#endif