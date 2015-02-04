/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:36 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/04 16:56:51 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
# define VM_HPP

# include <iostream>
# include <boost/algorithm/string.hpp>
# include "pushCommand.hpp"


class VM{

	public:
		VM();
		VM(const VM & src);
		~VM();
		VM & 	operator=(VM const & rhs);
		void 	parse();

};

#endif