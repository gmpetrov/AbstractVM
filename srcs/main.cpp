/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:31:39 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/11 19:03:49 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "VM.hpp"

# include <regex>

int		main(int ac, char **av){

	// std::string s = "Int8(3)";
	// std::regex rgx(".*Int8((\\w+)).*");
	// std::smatch match;

	// if (std::regex_search(s, match, rgx))
 //        std::cout << "match: " << match[1] << '\n';
	// return 0;
	if (ac == 1)
		VM vm;
	else
		VM vm(av[1]);
	return 0;
}