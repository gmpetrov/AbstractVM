/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:36 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/12 15:44:12 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_HPP
# define VM_HPP

# include <iostream>
# include <stdlib.h>
// # include <boost/algorithm/string.hpp>
# include <fcntl.h>
# include <vector>
# include <algorithm>
# include <stdio.h>
# include <stdlib.h>
# include <map>
# include "Parser.hpp"
# include "Int8.hpp"
# include "Int16.hpp"
# include "Int32.hpp"
# include "Float.hpp"
# include "Double.hpp"
# include <regex>
// # include <iomanip>

# define commandListAdd cmdList->operator[]
# define callCommand(x) (this->*(cmdList->operator[](x)))();

# define operandMapAdd opMap->operator[]
# define callOP(x, y) (this->*(opMap->operator[](x)))(y);

# define REVERSE_STACK std::reverse(this->getStack()->begin(), this->getStack()->end());

class VM{
	public:
		typedef void (VM::*Command)(void);
		typedef std::map<std::string, Command> CommandMap;

		typedef IOperand const *(VM::*OP)(std::string);
		typedef std::map<std::string, OP> operandMap;

		typedef enum { SYNTAX = 0, UNKNOWN = 1 } eERROR;
		VM();
		VM(char *);
		VM(const VM & src);
		~VM();
		VM & 	operator=(VM const & rhs);
		void 	parse();
		void 	parse(int fd);
		void 	printStack();
		void 	exec();
		void 	parseLine(std::string, int);
		bool 	isCommand(std::string);
		IOperand const *NewInt8(std::string);
		IOperand const *NewInt16(std::string val);
		IOperand const *NewInt32(std::string val);
		IOperand const *NewFloat(std::string val);
		IOperand const *NewDouble(std::string val);

		/* COMMANDS */

		void	push(std::string, int);
		void 	pop();
		void 	dump();
		void 	myAssert(std::string);
		void 	add();
		void 	sub();
		void 	mul();
		void 	myDiv();
		void 	mod();
		void 	print();
		void 	myExit();

		/* GETTERS && SETTERS */
		int		getFd()const;
		std::vector<IOperand const *>  *getStack();
		std::vector<std::string> *getFile();
		/* EXCEPTION */
		class vmException : public std::exception {
			public:
				vmException(std::string const &) throw();
				vmException(vmException const & src) throw();
				~vmException() throw();
				vmException & operator=(vmException const & rhs) throw();
				virtual const char *what() const throw();
				std::string const			error;
			private:
				vmException() throw();
		};
		CommandMap 	*cmdList;
		operandMap 	*opMap;
	private:
		int									_fd;
		std::vector<IOperand const *> 			*_stack;
		std::vector<std::string> 			*_file;
};

#endif