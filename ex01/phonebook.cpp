#include "phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0), oldestIndex(0) {}

void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    std::cout << "Enter first name: ";
    if (!std::getline(std::cin, input)) {
        std::cin.clear();
        return;
    }
    if(input.empty()) {
        std::cout << "First name cannot be empty!" << std::endl;
        std::cin.clear();
        return;
    }   
    newContact.setFirstName(input);

    std::cout << "Enter last name: ";
    if (!std::getline(std::cin, input)) {
        std::cin.clear();
        return;
    }
    if (input.empty()) {
        std::cout << "Last name cannot be empty!" << std::endl;
        std::cin.clear();
        return;
    }
    newContact.setLastName(input);

    std::cout << "Enter nickname: ";
    if (!std::getline(std::cin, input)) {
        std::cin.clear();
        return;
    }
    if (input.empty()) {
        std::cout << "Nickname cannot be empty!" << std::endl;
        std::cin.clear();
        return;
    }
    newContact.setNickname(input);

    std::cout << "Enter phone number: ";
    if (!std::getline(std::cin, input)) {
        std::cin.clear();
        return;
    }
    if (input.empty()) {
        std::cout << "Phone number cannot be empty!" << std::endl;
        std::cin.clear();
        return;
    }
    newContact.setPhoneNumber(input);

    std::cout << "Enter darkest secret: ";
    if (!std::getline(std::cin, input)) {
        std::cin.clear();
        return;
    }
    if (input.empty()) {
        std::cout << "Darkest secret cannot be empty!" << std::endl;
        std::cin.clear();
        return;
    }
    newContact.setDarkestSecret(input);

    if (contactCount < 8)
        contacts[contactCount++] = newContact;
    else {
        contacts[oldestIndex] = newContact;
        oldestIndex = (oldestIndex + 1) % 8;
    }
}

void PhoneBook::searchContacts() const 
{
    if (contactCount == 0) 
    {
        std::cout << "No contacts to display!" << std::endl;
        return;
    }

    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int i = 0; i < contactCount; ++i) 
    {
        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << (contacts[i].getFirstName().length() > 10 
            ? contacts[i].getFirstName().substr(0, 9) + "." 
            : contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << (contacts[i].getLastName().length() > 10 
            ? contacts[i].getLastName().substr(0, 9) + "." 
            : contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << (contacts[i].getNickname().length() > 10 
            ? contacts[i].getNickname().substr(0, 9) + "." 
            : contacts[i].getNickname()) << std::endl;
    }

    int index;
    std::cout << "Enter the index of the contact to display: ";
    if (!(std::cin >> index)) 
    {
        std::cin.clear();
        return;
    }

    if (index < 0 || index >= contactCount) 
    {
        std::cout << "Invalid index!" << std::endl;
        std::cin.clear();
        return;
    }

    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
}