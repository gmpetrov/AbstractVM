/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VM.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:30:36 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/12 10:12:22 by gmp              ###   ########.fr       */
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
// # include <iomanip>

# define commandListAdd cmdList->operator[]
# define callCommand(x) (this->*(cmdList->operator[](x)))();

class VM{
	public:
		typedef void (VM::*Command)(void);
		typedef std::map<std::string, Command> CommandMap;
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

		/* COMMANDS */

		void	push(std::string);
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
		std::vector<IOperand *>  *getStack();
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
	private:
		int									_fd;
		std::vector<IOperand *> 			*_stack;
		std::vector<std::string> 			*_file;



};

#endif