/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:54:05 by gmp               #+#    #+#             */
/*   Updated: 2015/02/04 16:55:53 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser(){
}

Parser::Parser(Parser const & src){
	*this = src;
}

Parser::~Parser(){

}

Parser & 	Parser::operator=(Parser const & rhs){
	(void)rhs;
	return *this;
}