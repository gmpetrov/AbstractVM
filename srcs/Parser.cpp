/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:54:05 by gmp               #+#    #+#             */
/*   Updated: 2015/02/10 18:37:47 by gpetrov          ###   ########.fr       */
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

std::string Parser::readFile(int fd){
	int ret;
	std::stringstream file;
	char buf[3];

	buf[2] = 0;
	while ((ret = read(fd, buf, 2)) != EOF){
		if (buf[0] == ';' && buf[0] == ';')
			break ;
		file << buf;
		bzero(buf, 2);
	}
	std::cout << file << std::endl;
	return file.str();
}