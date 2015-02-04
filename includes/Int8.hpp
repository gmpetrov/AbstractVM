/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:53:24 by gmp               #+#    #+#             */
/*   Updated: 2015/02/04 17:55:09 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

# include "IOperand.hpp"

class Int8 : public IOperand{

	public:
		Int8();
		Int8(const Int8 & src);
		~Int8();
		Int8 & 	operator=(Int8 const & rhs);

};

#endif