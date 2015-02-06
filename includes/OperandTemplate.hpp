/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandTemplate.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:09:09 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/06 16:53:47 by gmp              ###   ########.fr       */
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

template <typename T, typename N>
class OperandTemplate : public IOperand {
	public: 
		OperandTemplate<T, N>(N nb){ this->_value = nb; };
		OperandTemplate<T, N>(const OperandTemplate<T, N> & src){ *this = src; };
		// virtual ~OperandTemplate<T, N>(){};
		OperandTemplate<T, N> & 	operator=(OperandTemplate<T, N> const & rhs){ (void)rhs; return *this; };
		virtual OperandTemplate<T, N> const * operator+(IOperand const & rhs) const{
			const OperandTemplate<T, N> *tmp = dynamic_cast<const OperandTemplate<T, N>* >(&rhs);
			OperandTemplate<T, N> *ptr = new OperandTemplate<T, N>(this->_value + tmp->getValue());
			return ptr;
		}
		/* Getters & Setters) */

		N 	getValue()const{
			return this->_value;
		}
	private:
		OperandTemplate<T, N>(){}
		N 					_value;
};

#endif