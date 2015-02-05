/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandTemplate.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:09:09 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/05 17:56:07 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

# include <iostream>
# include <stdint.h>
# include <typeinfo>
// # include <boost/algorithm/string.hpp>
// # include "Int8.hpp"
# include "IOperand.hpp"
// # include "BaseCommand.hpp"

template <typename T>
class OperandTemplate : public IOperand {
	public: 
		OperandTemplate<T>(T nb){ this->_value = nb; };
		OperandTemplate<T>(const OperandTemplate<T> & src){ *this = src; };
		~OperandTemplate<T>(){};
		OperandTemplate<T> & 	operator=(OperandTemplate<T> const & rhs){ (void)rhs; return *this; };
		OperandTemplate<T> const * operator+(OperandTemplate<T> const & rhs) const{
			OperandTemplate<T> *ptr = new OperandTemplate<T>(this->_value + rhs.getValue());
			return ptr;
		}

		/* Getters & Setters) */

		T 	getValue()const{
			return this->_value;
		}
	private:
		OperandTemplate<T>();
		T 					_value;
};

#endif