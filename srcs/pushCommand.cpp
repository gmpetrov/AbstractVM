/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushCommand.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:58:33 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/03 18:37:02 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushCommand.hpp"

pushCommand::pushCommand() : BaseCommand("push"){

}

pushCommand::pushCommand(pushCommand const & src){
	*this = src;
}

pushCommand::~pushCommand(){

}

pushCommand & 	pushCommand::operator=(pushCommand const & rhs){
	(void)rhs;
	return *this;
}