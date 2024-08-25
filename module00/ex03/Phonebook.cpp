/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 13:51:15 by mbrettsc          #+#    #+#             */
/*   Updated: 2024/08/25 16:43:16 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() {
	std::cout << "Welcome to Phonebook!" << std::endl;
	std::cout << "You can use: ADD, SEARCH, REMOVE, BOOKMARK and EXIT commands!" << std::endl;
}

Phonebook::~Phonebook () {
	std::cout << "Goodbye!" << std::endl;
}

void	get_input(std::string &str, std::string message) {
	do {
		std::getline(std::cin, str);
		if (str.empty()) {
			std::cout << "Input Should not be empty" << std::endl;
			std::cout << message;
		}
	} while (str.empty());
}

void Phonebook::printContacts()
{
    std::vector<Contact>::iterator it = _contacts.begin();

    for (int i = 0; it != _contacts.end(); ++it, ++i) {
        std::cout << i + 1 << ". ";
        std::cout << "Name: " << it->getName() << std::endl;
        std::cout << "Nickname: " << it->getNickName() << std::endl;
        std::cout << "Phone number: " << it->getNumber() << std::endl;
    }
}

void Phonebook::printDetail(int i)
{   
    std::cout << "Name: " << _contacts[i].getName() << std::endl;
    std::cout << "Nickname: " << _contacts[i].getNickName() << std::endl;
    std::cout << "Phone number: " << _contacts[i].getNumber() << std::endl;
}

void Phonebook::remove() {
    int row;

    if (_contacts.size() == 0) {
        std::cout << "No contacts found!" << std::endl;
        return;
    }

    printContacts();
    while (1)
    {
        std::cout << "Select row: ";
        std::cin >> row;
        
        if (std::cin.fail() || _contacts[row - 1].getName().empty()) {
            std::cout << "Invalid row!" << std::endl;
        }

        else {
            _contacts.erase(_contacts.begin() + row - 1);
            std::cout << "Contact removed!" << std::endl;
            std::cin.clear();
            fflush(stdin);
            break;
        }
        std::cin.clear();
        fflush(stdin);
    }
}

void Phonebook::bookmark()
{
    std::vector<Contact>::iterator it = _contacts.begin();

    for (int i = 0; it != _contacts.end(); ++it, ++i) {
        if (it->getBookmark() == true) {
            std::cout << i + 1 << ". ";
            std::cout << "Name: " << it->getName() << std::endl;
            std::cout << "Nickname: " << it->getNickName() << std::endl;
            std::cout << "Phone number: " << it->getNumber() << std::endl;
        }
    }
}

void    Phonebook::add()
{
	std::string str;
    Contact tmp;
    
	std::cout << "Please enter a  name: ";
    get_input(str, "Please enter a name: ");
    tmp.setName(str);
	std::cout << "Please enter a phone number: ";
	get_input(str, "Please enter a phone number: ");
	tmp.setNumber(str);
    std::cout << "Please enter a nickname: ";
    get_input(str, "Please enter a phone nickname: ");
    tmp.setNickName(str);
	std::cout << "Contact added!" << std::endl;
    _contacts.push_back(tmp);
}

void    Phonebook::search() {
	int j;
    int row;

    if (_contacts.size() == 0) {
        std::cout << "No contacts found!" << std::endl;
        return;
    }
	printContacts();
	while (1)
    {
		std::cout << "Select row: ";
		std::cin >> row;
        
		if (std::cin.fail() || _contacts[row - 1].getName().empty()) {
            std::cout << "Invalid row!" << std::endl;
        }

        else {
            printDetail(row);
            std::cout << "Do you want to bookmark this contact? (1/0): ";
            std::cin >> j;
            if (j == 1)
            {
                _contacts[row - 1].setBookmark(true);
                std::cout << "Contact bookmarked!" << std::endl;
            } else {
                std::cout << "Contact not bookmarked!" << std::endl;
            }
            std::cin.clear();
		    fflush(stdin);
            break;
        }
		std::cin.clear();
		fflush(stdin);
	}
}
