/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:53:24 by gmp               #+#    #+#             */
/*   Updated: 2015/02/06 15:23:31 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP
// # include "IOperand.hpp"
# include "OperandTemplate.hpp"

class Int8 : public OperandTemplate<int8_t> {
// class Int8 : public IOperand {

	public:
		Int8(int8_t nb);
		Int8(const Int8 & src);
		~Int8();
		Int8 & 	operator=(Int8 const & rhs);
		// Int8 const * operator+(Int8 const & rhs) const{
		// 	return new const Int8(this->getValue() + rhs.getValue());
		// 	// return ptr;
		// }
		// int8_t 		getValue()const;
		// Int8 const * operator+(Int8 const & rhs) const;
	private:
		Int8();
		// int8_t		_val;

};

#endif