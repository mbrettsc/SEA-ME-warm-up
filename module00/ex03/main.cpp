/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrettsc <mbrettsc@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 12:23:49 by mbrettsc          #+#    #+#             */
/*   Updated: 2023/07/23 23:33:09 by mbrettsc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int main()
{
	Phonebook	pb;
	std::string	str;

	while (1)
	{
		std::cout << "> ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb.add();
		else if (str == "SEARCH")
			pb.search();
        else if (str == "REMOVE")
            pb.remove();
        else if (str == "BOOKMARK")
            pb.bookmark();
		else if (str == "EXIT")
			break ;
		else
			std::cout << "Enter a valid command!" << std::endl;
	}
	return (0);
}
