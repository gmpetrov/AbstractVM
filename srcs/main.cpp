/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 16:31:39 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 18:48:42 by gpetrov          ###   ########.fr       */
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

		Int16 d(4);
		Int16 e(42);

		const Int16 *f = static_cast<const Int16 *>(e % d);
		std::cout <<  "value = " << static_cast<int>(f->getValue()) << std::endl;

		Int32 j(4);
		Int32 k(42);

		const Int32 *l = static_cast<const Int32 *>(k % j);
		std::cout <<  "value = " << static_cast<int>(l->getValue()) << std::endl;

		Float m(4);
		Float n(42.42f);

		const Float *o = static_cast<const Float *>(n + m);
		std::cout <<  "value = " << std::fixed << static_cast<float>(o->getValue()) << std::endl;

	}
	else
		VM vm(av[1]);
	return 0;
}