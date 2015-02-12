/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:31:39 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/12 12:02:20 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "VM.hpp"

int		main(int ac, char **av){

	// std::string s = "Int8(3.42)";
	// std::regex rgx("^(Int(8|16|32)|Float|Double)\\((\\d+\\.\\d+|\\d+)\\)$");
	// std::smatch match;

	// if (std::regex_search(s, match, rgx)){
	// 	std::cout << "match: " << match[3].str().size() << std::endl;
	// }
	// else
	// 	std::cout << "NULL" << std::endl;
	// return 0;
	if (ac == 1)
		VM vm;
	else
		VM vm(av[1]);
	return 0;
}