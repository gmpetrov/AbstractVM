/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:54:05 by gmp               #+#    #+#             */
/*   Updated: 2015/02/11 14:29:01 by gpetrov          ###   ########.fr       */
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

void printString(std::string str){
	std::cout << str << std::endl;
}

void trimString(std::string & str){
	str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
}

void rtrim(std::string & s)
{
   s.erase( s.find_last_not_of(" \f\n\r\t\v") + 1 );
}

void ltrim(std::string & s)
{
   s.erase( 0, s.find_first_not_of(" \f\n\r\t\v") );
}

std::vector<std::string> *Parser::readFile(int fd){
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
	this->split = this->splitString(file.str(), '\n');
	for_each(this->split->begin(), this->split->end(), ltrim);
	for_each(this->split->begin(), this->split->end(), rtrim);
	// for_each(this->split->begin(), this->split->end(), printString);
	return this->split;
}

std::vector<std::string> *Parser::splitString(std::string file, char c){
	std::vector<std::string> *sp = new std::vector<std::string>();
	std::string::size_type tmp = file.find(c);
	while (tmp != std::string::npos){
		sp->push_back(file.substr(0, tmp));
		file = file.substr(tmp + 1);
		tmp = file.find(c);
	}
	sp->push_back(file);
	return sp;
}