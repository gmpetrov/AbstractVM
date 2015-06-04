/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:29 by gpetrov           #+#    #+#             */
/*   Updated: 2015/06/04 13:28:15 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VM.hpp"
#include <dirent.h>

VM::VM(){
	this->initContainers();
	this->parse();
}

VM::VM(char *file){
	if ((this->_fd = open(file, O_RDONLY)) == -1){
		std::cout << "File doesn't exist" << std::endl;
		exit(0);
	}
	if (opendir(file) != NULL){
		std::cout << "Invalid input" << std::endl;
		exit(0);
	}
	this->initContainers();
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

void	VM::initContainers(){
	this->_stack = new std::vector<IOperand const *>();
	this->cmdList = new CommandMap();
	commandListAdd("pop") = &VM::pop;
	commandListAdd("dump") = &VM::dump;
	commandListAdd("add") = &VM::add;
	commandListAdd("sub") = &VM::sub;
	commandListAdd("mul") = &VM::mul;
	commandListAdd("div") = &VM::myDiv;
	commandListAdd("mod") = &VM::mod;
	commandListAdd("print") = &VM::print;
	commandListAdd("exit") = &VM::myExit;

	this->opMap = new operandMap();
	operandMapAdd("int8") = &VM::NewInt8;
	operandMapAdd("int16") = &VM::NewInt16;
	operandMapAdd("int32") = &VM::NewInt32;
	operandMapAdd("float") = &VM::NewFloat;
	operandMapAdd("double") = &VM::NewDouble;
}

void 	VM::printStack(){
	std::vector<IOperand const *>::iterator It;
	for (It = this->getStack()->begin(); It != this->getStack()->end(); It++){
		std::cout << (*It)->toString() << std::endl;
	}
}

// void 	printStack2(IOperand const *op){
// 	std::cout << op->toString() << std::endl;
// }

void 	VM::parse(int fd){
	Parser parser;

	this->_file = parser.readFile(fd);
	try{
		this->exec();
	}
	catch(VM::vmException e){
		std::cout << e.what() << std::endl;
		exit(0);
	}
	catch(std::exception e){
		std::cout << e.what() << std::endl;
		exit(0);
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
	if ((*(cmd->begin()))[0] == ';')
		;
	else if (cmd->size() > 3)
		throw VM::vmException("[ERROR] - On line " + std::to_string(nb) + " : Wrong Syntax");
	else{
		if (line.compare("") == 0)
			;
		else if (this->isCommand(*(cmd->begin())) == false)
			throw VM::vmException("[ERROR] - On line " + std::to_string(nb) + " : Unknown Instruction");
		else if ((*(cmd->begin())).compare("push") == 0 || (*(cmd->begin())).compare("assert") == 0){
			if (cmd->size() < 2)
				throw VM::vmException("[ERROR] - On line " + std::to_string(nb) + " : Missing Argument");
			if ((*(cmd->begin())).compare("push") == 0)
				this->push(*(cmd->begin() + 1), nb);
			else
				this->myAssert(*(cmd->begin() + 1));
		}
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
	throw VM::vmException("[ERROR] - Missing exit command");
}

bool 	VM::isCommand(std::string cmd){
	if (cmd.compare("push") == 0 ||cmd.compare("pop") == 0 ||cmd.compare("dump") == 0 ||cmd.compare("assert") == 0 ||cmd.compare("add") == 0 ||cmd.compare("sub") == 0 ||cmd.compare("mul") == 0 ||cmd.compare("div") == 0 ||cmd.compare("mod") == 0 ||cmd.compare("print") == 0 ||cmd.compare("exit") == 0)
		return true;
	return false;
}

IOperand const * VM::NewInt8(std::string val){
	OperandTemplate<Int8, int8_t> op(42, 0);

	return op.createOperand(INT8, val);
}

IOperand const * VM::NewInt16(std::string val){
	OperandTemplate<Int16, int16_t> op(42, 1);

	return op.createOperand(INT16, val);
}

IOperand const * VM::NewInt32(std::string val){
	OperandTemplate<Int32, int32_t> op(42, 2);

	return op.createOperand(INT32, val);
}

IOperand const * VM::NewFloat(std::string val){
	OperandTemplate<Float, float> op(42, 3);

	return op.createOperand(FLOAT, val);
}

IOperand const * VM::NewDouble(std::string val){
	OperandTemplate<Double, double> op(42, 4);
	// std::cout << "FUCK" << std::endl;
	return op.createOperand(DOUBLE, val);
}

/* COMMMANDS */

void	VM::push(std::string str, int line){
	std::regex rgx("^(int(8|16|32)|float|double)\\((\\d+\\.\\d+|\\d+)\\)$");
	std::smatch match;
	if (std::regex_search(str, match, rgx)){
		// if (match[1].str().compare("int") == 0){
		// 	this->getStack()->push_back( (this->*(opMap->operator[](/*"int" + */match[2].str())))(match[3].str()) );
		// }
		// else{
			this->getStack()->push_back( (this->*(opMap->operator[](match[1].str())))(match[3].str()));
		// }
	}
	else
		throw VM::vmException("[ERROR] - On line " + std::to_string(line) + " : Invalid Argument");
	return ;
}
void	VM::pop(){
	if (this->getStack()->empty())
		throw VM::vmException("[ERROR] - pop on an empty stack");
	// REVERSE_STACK
	this->getStack()->pop_back();
	// REVERSE_STACK
	return ;
}

void	VM::dump(){
	REVERSE_STACK
	this->printStack();
	REVERSE_STACK
	// for_each(this->getStack()->begin(), this->getStack()->end(), printStack2);
	return ;
}

void	VM::myAssert(std::string str){
	if (this->getStack()->size() == 0){
		throw VM::vmException("[ERROR] - Assert");
	}
	std::string val = (*(*(this->getStack()->end() - 1))).toString();
	std::regex rgx("^(int(8|16|32)|float|double)\\((\\d+\\.\\d+|\\d+)\\)$");
	std::smatch match;

	if (std::regex_search(str, match, rgx)){
		if (match[1].str().compare("int8") == 0){
			if (val.compare(match[3].str()) != 0)
				throw VM::vmException("[ERROR] - Assert");
		}
		else if (match[1].str().compare("int16") == 0){
			if (val.compare(match[3].str()) != 0)
				throw VM::vmException("[ERROR] - Assert");
		}
		else if (match[1].str().compare("int32") == 0){
			if (val.compare(match[3].str()) != 0)
				throw VM::vmException("[ERROR] - Assert");
		}
		else if (atof(val.c_str()) != atof(match[3].str().c_str())){
			if (val.compare(match[3].str()) != 0)
				throw VM::vmException("[ERROR] - Assert");
		}
		else if (match[1].str().compare("double") == 0){
			if (atof(val.c_str()) != atof(match[3].str().c_str()))
				throw VM::vmException("[ERROR] - Assert");
			// if (val.compare(match[3].str()) != 0)
			// 	throw VM::vmException("[ERROR] - Assert");
		}
		else
			throw VM::vmException("[ERROR] - Invalid Argument given to assert command");
	}
	else
		throw VM::vmException("[ERROR] - Invalid Argument given to assert command");
	return ;
}

void 	VM::checkAddOverflow(){
	int a = std::atoi((*(*(this->getStack()->end() - 1 ))).toString().c_str());
	int b = std::atoi((*(*(this->getStack()->end() - 2 ))).toString().c_str());
	if ((a > 0 && b > 0 && (a + b) < 0))
		throw VM::vmException("[ERROR] - Alert OVERFLOW in add command");
	else if ((a < 0 && b < 0 && (a + b) > 0))
		throw VM::vmException("[ERROR] - Alert UNDERFLOW in add command");
}

void 	VM::checkSubOverflow(){
	int a = std::atoi((*(*(this->getStack()->end() - 1 ))).toString().c_str());
	int b = std::atoi((*(*(this->getStack()->end() - 2 ))).toString().c_str());
	if (b < 0 && a > 0 && (b - a) > 0)
		throw VM::vmException("[ERROR] - Alert OVERFLOW in sub command");
	else if (b > 0 && a < 0 && (b - a) < 0)
		throw VM::vmException("[ERROR] - Alert UNDERFLOW in sub command");
}

void 	VM::checkMulOverflow(){
	int a = std::atoi((*(*(this->getStack()->end() - 1 ))).toString().c_str());
	int b = std::atoi((*(*(this->getStack()->end() - 2 ))).toString().c_str());
	if ((a > 0 && b > 0 && (a * b) < 0))
		throw VM::vmException("[ERROR] - Alert OVERFLOW in mul command");
	else if ((a < 0 && b < 0 && (a * b) > 0))
		throw VM::vmException("[ERROR] - Alert UNDERFLOW in mul command");
}

void	VM::add(){
	if (this->getStack()->size() < 2)
		throw VM::vmException("[ERROR] - add on a stack size < 2");
	this->checkAddOverflow();
	this->getStack()->push_back( *(*(this->getStack()->begin())) + *(*(this->getStack()->begin() + 1)) );
	this->getStack()->erase(this->getStack()->end() - 3);
	this->getStack()->erase(this->getStack()->end() - 2);
	return ;
}

void	VM::sub(){
	if (this->getStack()->size() < 2)
		throw VM::vmException("[ERROR] - sub on a stack size < 2");
	this->checkSubOverflow();
	this->getStack()->push_back( (*(*(this->getStack()->begin())) - *(*(this->getStack()->begin() + 1))) );
	this->getStack()->erase(this->getStack()->end() - 3);
	this->getStack()->erase(this->getStack()->end() - 2);
	return ;
}

void	VM::mul(){
	if (this->getStack()->size() < 2)
		throw VM::vmException("[ERROR] - mul on a stack size < 2");
	this->checkMulOverflow();
	this->getStack()->push_back( (*(*(this->getStack()->begin())) * *(*(this->getStack()->begin() + 1))) );
	this->getStack()->erase(this->getStack()->end() - 3);
	this->getStack()->erase(this->getStack()->end() - 2);
	return ;
}

void	VM::myDiv(){
	if (this->getStack()->size() < 2)
		throw VM::vmException("[ERROR] - div on a stack size < 2");
	if ((*(*(this->getStack()->begin() + 1))).toString().compare("0") == 0)
		throw VM::vmException("[ERROR] - div by 0");
	this->getStack()->push_back( (*(*(this->getStack()->begin())) / *(*(this->getStack()->begin() + 1))) );
	this->getStack()->erase(this->getStack()->end() - 3);
	this->getStack()->erase(this->getStack()->end() - 2);
	return ;
}

void	VM::mod(){
	if (this->getStack()->size() < 2)
		throw VM::vmException("[ERROR] - mod on a stack size < 2");
	if ((*(*(this->getStack()->begin() + 1))).toString().compare("0") == 0)
		throw VM::vmException("[ERROR] - mod by 0");
	this->getStack()->push_back( (*(*(this->getStack()->begin())) % *(*(this->getStack()->begin() + 1))) );
	this->getStack()->erase(this->getStack()->end() - 3);
	this->getStack()->erase(this->getStack()->end() - 2);
	return ;
}

void	VM::print(){
	if (this->getStack()->size() == 0)
		throw VM::vmException("[ERROR] - Print instruction on an empty stack");
	if ( (*(*(this->getStack()->end() - 1))).getType() != 0)
		throw VM::vmException("[ERROR] - Print - top stack value is not a 8bits integer");
	int to_char = std::atoi((*(*(this->getStack()->end() - 1))).toString().c_str());
	std::cout << static_cast<char>(to_char) << std::endl;
	return ;
}

void	VM::myExit(){
	exit(0);
	return ;
}



/*GETTERS & SETTERS*/

int 	VM::getFd()const{
	return this->_fd;
}

std::vector<IOperand const *> *VM::getStack(){
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
