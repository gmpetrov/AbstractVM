/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:53:24 by gmp               #+#    #+#             */
/*   Updated: 2015/02/09 12:48:12 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP
// # include "IOperand.hpp"
# include "OperandTemplate.hpp"

class Int8 : public OperandTemplate<Int8, int8_t> {
// class Int8 : public IOperand {

	public:
		Int8(int8_t nb);
		Int8(const Int8 & src);
		virtual ~Int8();
		Int8 & 	operator=(Int8 const & rhs);
		// virtual Int8 const * operator+(Int8 const & rhs) const{
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