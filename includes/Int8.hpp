/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:53:24 by gmp               #+#    #+#             */
/*   Updated: 2015/02/05 17:59:08 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP
// # include "IOperand.hpp"
# include "OperandTemplate.hpp"

class Int8 : public OperandTemplate<int8_t> {

	public:
		Int8(int8_t nb);
		Int8(const Int8 & src);
		~Int8();
		Int8 & 	operator=(Int8 const & rhs);
		Int8 const * operator+(Int8 const & rhs) const{
			const Int8 *ptr = new Int8(this->getValue() + rhs.getValue());
			return ptr;
		}
		// Int8 const * operator+(Int8 const & rhs) const;
	private:
		Int8();

};

#endif