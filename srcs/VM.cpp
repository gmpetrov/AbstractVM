/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:29 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/11 17:34:13 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VM.hpp"

VM::VM(){
	this->_stack = new std::vector<IOperand *>();
	this->cmdList = new CommandMap();
	commandListAdd("push") = &VM::push;
	commandListAdd("pop") = &VM::pop;
	commandListAdd("dump") = &VM::dump;
	commandListAdd("assert") = &VM::myAssert;
	commandListAdd("add") = &VM::add;
	commandListAdd("sub") = &VM::sub;
	commandListAdd("mul") = &VM::mul;
	commandListAdd("div") = &VM::myDiv;
	commandListAdd("mod") = &VM::mod;
	commandListAdd("print") = &VM::print;
	commandListAdd("exit") = &VM::myExit;
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
	delete this->_stack;
	delete this->_file;
	delete this->cmdList;
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

	this->_file = parser.readFile(fd);
	try{
		this->exec();
	}
	catch(VM::vmException e){
		std::cout << e.what() << std::endl;
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;	
	}
}

void 	VM::parse(){
	Parser parser;

	this->_file = parser.readFile();
	try{
		this->exec();
	}
	catch(VM::vmException e){
		std::cout << e.what() << std::endl;
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;	
	}
}

void 	VM::parseLine(std::string line, int nb){
	Parser parser;
	std::vector<std::string> *cmd;

	cmd = parser.splitString(line, ' ');
	if (cmd->size() > 3)
		throw VM::vmException("[ERROR] - On line " + std::to_string(nb) + " : Wrong Syntax");
	else{
		if (this->isCommand(*(cmd->begin())) == false)
			throw VM::vmException("[ERROR] - On line " + std::to_string(nb) + " : Unknown Instruction");
		else
			callCommand(*(cmd->begin()));
	}
	delete cmd;
}

void 	VM::exec(){
	std::vector<std::string>::iterator 	It;
	int									line = 1;
	for (It = this->_file->begin(); It != this->_file->end(); It++){
		parseLine(*It, line);
		line++;
	}
}

bool 	VM::isCommand(std::string cmd){
	if (cmd.compare("push") == 0 ||cmd.compare("pop") == 0 ||cmd.compare("dump") == 0 ||cmd.compare("assert") == 0 ||cmd.compare("add") == 0 ||cmd.compare("sub") == 0 ||cmd.compare("mul") == 0 ||cmd.compare("div") == 0 ||cmd.compare("mod") == 0 ||cmd.compare("print") == 0 ||cmd.compare("exit") == 0)
		return true;
	return false;
}

/* COMMMANDS */

void	VM::push(){
	std::cout << "push" << std::endl;
	return ;
}
void	VM::pop(){
	std::cout << "pop" << std::endl;
	return ;
}

void	VM::dump(){
	std::cout << "dump" << std::endl;
	return ;
}

void	VM::myAssert(){
	std::cout << "assert" << std::endl;
	return ;
}

void	VM::add(){
	std::cout << "add" << std::endl;
	return ;
}

void	VM::sub(){
	std::cout << "sub" << std::endl;
	return ;
}

void	VM::mul(){
	std::cout << "mul" << std::endl;
	return ;
}

void	VM::myDiv(){
	std::cout << "div" << std::endl;
	return ;
}

void	VM::mod(){
	std::cout << "mod" << std::endl;
	return ;
}

void	VM::print(){
	std::cout << "print" << std::endl;
	return ;
}

void	VM::myExit(){
	std::cout << "myExit" << std::endl;
	return ;
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

/* Exceptions */


/* --------------  vmExceptions -------------- */

VM::vmException::vmException(std::string const & str) throw() : error(str){
	return ;
}

VM::vmException::vmException(vmException const & src) throw() : error(src.error){
	*this = src;
	return ;
}

VM::vmException::~vmException() throw(){
	return ;
}

VM::vmException & VM::vmException::operator=(vmException const & rhs) throw(){
	(void)rhs;
	return *this;
}

const char 		*VM::vmException::what() const throw(){
	return this->error.c_str();
}
