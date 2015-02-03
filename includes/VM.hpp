/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:36 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/03 18:40:16 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
# define VM_HPP

# include <iostream>
# include "pushCommand.hpp"


class VM{

	public:
		VM();
		VM(const VM & src);
		~VM();
		VM & 	operator=(VM const & rhs);

};

#endif