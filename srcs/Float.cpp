/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:58:16 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 18:25:25 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Float.hpp"

Float::Float(float nb) : OperandTemplate<Float, float>(nb, 3){

}

Float::Float(Float const & src) : OperandTemplate<Float, float>(src){
	*this = src;
}

Float::~Float(){

}

Float & 	Float::operator=(Float const & rhs){
	(void)rhs;
	return *this;
}

/*GETTERS & SETTERS*/
