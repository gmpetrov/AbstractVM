/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 12:52:25 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/06 15:23:56 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"

Int8::Int8(int8_t nb) : OperandTemplate<int8_t>(nb){
}

// Int8::Int8(int8_t nb) : _val(nb){
// }


Int8::Int8(Int8 const & src) : OperandTemplate<int8_t>(src){
	*this = src;
}

// Int8::Int8(Int8 const & src){
// 	*this = src;
// }

Int8::~Int8(){

}

Int8 & 	Int8::operator=(Int8 const & rhs){
	(void)rhs;
	return *this;
}
// Int8 const * operator+(Int8 const & rhs) const{
	
// }

/*GETTERS & SETTERS*/

// int8_t 		Int8::mgetValue()const{
// 	return this->_val;
// }