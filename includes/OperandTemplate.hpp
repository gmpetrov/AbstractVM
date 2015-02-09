/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandTemplate.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:09:09 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 12:47:42 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

# include <iostream>
# include <stdint.h>
# include <typeinfo>
# include <stdlib.h>
// # include <boost/algorithm/string.hpp>
# include "IOperand.hpp"
# include "OperandFactory.hpp"
# include "Int8.hpp"
// # include "BaseCommand.hpp"


class Int8;

template <typename T, typename N>
class OperandTemplate : public IOperand {
	public: 
		typedef enum { Int8, Int16, Int32, Float, Double} eOperandType;
		OperandTemplate<T, N>(N nb){ this->_value = nb; };
		OperandTemplate<T, N>(const OperandTemplate<T, N> & src){ *this = src; };
		~OperandTemplate<T, N>(){};
		OperandTemplate<T, N> & 	operator=(OperandTemplate<T, N> const & rhs){ (void)rhs; return *this; };
		virtual OperandTemplate<T, N> const * operator+(IOperand const & rhs) const{
			// const OperandTemplate<T, N> *tmp = dynamic_cast<const OperandTemplate<T, N>* >(&rhs);
			// OperandTemplate<T, N> *ptr = new OperandTemplate<T, N>(this->_value + tmp->getValue());
			const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(Int8, "42"));
			return ptr;
			// return this->createOperand(Int8, "42");
		}
		IOperand const * createInt8( std::string const & value ) const{
			return new OperandTemplate<class Int8, int8_t>(atoi(value.c_str()));
		}

		IOperand const * createOperand( eOperandType type, std::string const & value ) const{
			IOperand const * (OperandTemplate<T, N>::* tab[])(std::string const & value)const = { &OperandTemplate::createInt8, &OperandTemplate::createInt8 };
			return (this->*tab[0])(value);
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