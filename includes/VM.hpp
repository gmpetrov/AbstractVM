/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:36 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/04 17:57:01 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
# define VM_HPP

# include <iostream>
# include <boost/algorithm/string.hpp>
# include <fcntl.h>
# include "pushCommand.hpp"
# include "Int8.hpp"


class VM{

	public:
		VM();
		VM(char *);
		VM(const VM & src);
		~VM();
		VM & 	operator=(VM const & rhs);
		void 	parse();

		/* GETTERS && SETTERS */
		int		getFd()const;
	private:
		int		_fd;

};

#endif