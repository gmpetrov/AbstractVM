/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:29 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/10 22:50:03 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VM.hpp"

VM::VM(){
	this->_stack = new std::vector<IOperand *>();
	this->parse();
}

VM::VM(char *file){
	if ((this->_fd = open(file, O_RDONLY)) == -1){
		std::cout << "File doesn't exist" << std::endl;
		exit(0);
	}
	this->_stack = new std::vector<IOperand *>();
	this->parse(this->_fd);
}

VM::VM(VM const & src){
	*this = src;
}

VM::~VM(){

}

VM & 	VM::operator=(VM const & rhs){
	this->_fd = rhs.getFd();
	return *this;
}

void 	VM::printStack(){
	std::vector<IOperand *>::iterator It;
	for (It = this->getStack()->begin(); It != this->getStack()->end(); It++){
		std::cout << (*It)->toString() << std::endl;
	}
}

void 	VM::parse(int fd){
	Parser parser;

	parser.readFile(fd);
}

void 	VM::parse(){
	Parser parser;

	parser.readFile();
}

/*GETTERS & SETTERS*/

int 	VM::getFd()const{
	return this->_fd;
}

std::vector<IOperand *> *VM::getStack(){
	return this->_stack;
}

std::vector<std::string> *VM::getFile(){
	return this->_file;
}
