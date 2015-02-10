/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:54:05 by gmp               #+#    #+#             */
/*   Updated: 2015/02/10 21:33:14 by gmp              ###   ########.fr       */
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
	char buf[2];
	char tmp = 0;

	buf[1] = 0;
	while ((ret = read(fd, buf, 1)) != 0){
		if (buf[0] == ';' && tmp == ';')
			break ;
		file << buf;
		tmp = buf[0];
		bzero(buf, 2);
	}
	close(fd);
	std::cout << file.str() << std::endl;
	return file.str();
}