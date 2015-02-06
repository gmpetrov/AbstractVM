/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandTemplate.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:09:09 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/06 18:50:04 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

# include <iostream>
# include <stdint.h>
# include <typeinfo>
// # include <boost/algorithm/string.hpp>
# include "IOperand.hpp"
# include "OperandFactory.hpp"
// # include "Int8.hpp"
// # include "BaseCommand.hpp"


class Int8;

template <typename T, typename N>
class OperandTemplate : public IOperand {
	public: 
		typedef enum { 
			Int8 = 0,
			Int16 = 1,
			Int32 = 2,
			Float = 3,
			Double = 4 
		} eOperandType;
		OperandTemplate<T, N>(N nb){ this->_value = nb; };
		OperandTemplate<T, N>(const OperandTemplate<T, N> & src){ *this = src; };
		~OperandTemplate<T, N>(){};
		OperandTemplate<T, N> & 	operator=(OperandTemplate<T, N> const & rhs){ (void)rhs; return *this; };
		virtual OperandTemplate<T, N> const * operator+(IOperand const & rhs) const{
			const OperandTemplate<T, N> *tmp = dynamic_cast<const OperandTemplate<T, N>* >(&rhs);
			// OperandTemplate<T, N> *ptr = new OperandTemplate<T, N>(this->_value + tmp->getValue());
			const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(Int8, "42"));
			return ptr;
		}
		IOperand const * createInt8( std::string const & value ) const{
			return new OperandTemplate<class Int8, int8_t>(std::atoi(value.c_str()));
		}
		IOperand const * createOperand( eOperandType type, std::string const & value ) const{
			IOperand const * (OperandTemplate<T, N>::* tab)(std::string const & value) = { &OperandTemplate<T, N>::createInt8 };
			return (this->*tab[type])(value);
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