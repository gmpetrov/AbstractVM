/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:49:44 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/03 18:41:10 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseCommand.hpp"

BaseCommand::BaseCommand(){

}

BaseCommand::BaseCommand(std::string name) : _name(name){

}

BaseCommand::BaseCommand(BaseCommand const & src){
	*this = src;
}

BaseCommand::~BaseCommand(){

}

BaseCommand & 	BaseCommand::operator=(BaseCommand const & rhs){
	(void)rhs;
	return *this;
}

std::string 	BaseCommand::getName(){
	return this->_name;
}
