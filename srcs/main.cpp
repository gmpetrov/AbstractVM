/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:31:39 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 13:48:44 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "VM.hpp"

int		main(int ac, char **av){
	(void)av;
	if (ac == 1){
		VM vm;
		Int8 a(4);
		Int8 b(42);

		const Int8 *c = static_cast<const Int8 *>(b % a);
		std::cout <<  "value = " << static_cast<int>(c->getValue()) << std::endl;

	}
	else
		VM vm(av[1]);
	return 0;
}