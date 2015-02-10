/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:36 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/10 22:01:00 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
# define VM_HPP

# include <iostream>
# include <stdlib.h>
// # include <boost/algorithm/string.hpp>
# include <fcntl.h>
# include <vector>
# include <algorithm>
# include "Parser.hpp"
# include "pushCommand.hpp"
# include "Int8.hpp"
# include "Int16.hpp"
# include "Int32.hpp"
# include "Float.hpp"
# include "Double.hpp"
// # include <iomanip>

class VM{

	public:
		VM();
		VM(char *);
		VM(const VM & src);
		~VM();
		VM & 	operator=(VM const & rhs);
		void 	parse();
		void 	parse(int fd);
		void 	printStack();

		/* GETTERS && SETTERS */
		int		getFd()const;
		std::vector<IOperand *>  *getStack();
	private:
		int							_fd;
		std::vector<IOperand *> 	*_stack;


};

#endif