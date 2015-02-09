/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:03:44 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 19:08:13 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Double.hpp"

Double::Double(double nb) : OperandTemplate<Double, double>(nb, 4){

}

Double::Double(Double const & src) : OperandTemplate<Double, double>(src){
	*this = src;
}

Double::~Double(){

}

Double & 	Double::operator=(Double const & rhs){
	(void)rhs;
	return *this;
}

/*GETTERS & SETTERS*/
