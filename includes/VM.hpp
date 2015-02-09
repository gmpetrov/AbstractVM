/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:36 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 19:05:17 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
# define VM_HPP

# include <iostream>
# include <stdlib.h>
// # include <boost/algorithm/string.hpp>
# include <fcntl.h>
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

		/* GETTERS && SETTERS */
		int		getFd()const;
	private:
		int		_fd;

};

#endif