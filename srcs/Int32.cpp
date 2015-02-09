/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:51:14 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 17:59:09 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Int32.hpp"

Int32::Int32(int32_t nb) : OperandTemplate<Int32, int32_t>(nb, 2){

}

Int32::Int32(Int32 const & src) : OperandTemplate<Int32, int32_t>(src){
	*this = src;
}

Int32::~Int32(){

}

Int32 & 	Int32::operator=(Int32 const & rhs){
	(void)rhs;
	return *this;
}

/*GETTERS & SETTERS*/
