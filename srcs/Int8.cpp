/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 12:52:25 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 14:56:31 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int8.hpp"

Int8::Int8(int8_t nb) : OperandTemplate<Int8, int8_t>(nb, 0){

}

Int8::Int8(Int8 const & src) : OperandTemplate<Int8, int8_t>(src){
	*this = src;
}

Int8::~Int8(){

}

Int8 & 	Int8::operator=(Int8 const & rhs){
	(void)rhs;
	return *this;
}

/*GETTERS & SETTERS*/
