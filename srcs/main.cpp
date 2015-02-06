/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:31:39 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/06 15:24:52 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "VM.hpp"

int		main(int ac, char **av){
	(void)av;
	if (ac == 1){
		VM vm;
		Int8 a(21);
		// Int8 b(21);

		// const Int8 *c = a + b;
		// std::cout <<  "value = " << static_cast<int>(c->getValue()) << std::endl;
	}
	else
		VM vm(av[1]);
	return 0;
}