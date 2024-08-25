/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:34:47 by mbrettsc          #+#    #+#             */
/*   Updated: 2024/08/25 16:35:07 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <iostream>

class Phonebook {
	private:
		class Contact {
			private:
				std::string name;
				std::string nickName;
				std::string number;
				bool isBookmarked;
			public:
				void setName(std::string name) { this->name = name; }
				void setNickName(std::string nickName) { this->nickName = nickName; }
				void setNumber(std::string number) { this->number = number; }
				void setBookmark(bool isBookmarked) { this->isBookmarked = isBookmarked; }

				std::string getName() { return name; }
				std::string getNickName() { return nickName; }
				std::string getNumber() { return number; }
				bool getBookmark() { return isBookmarked; }
		};
		std::vector<Contact> _contacts;
	public:
		Phonebook();
		~Phonebook();
		void	add();
		void	search();
        void    remove();
        void    bookmark();

		void printContacts();
		void printDetail(int i);
};

void	printHood();
