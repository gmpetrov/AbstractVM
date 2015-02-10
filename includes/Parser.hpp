/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:54:11 by gmp               #+#    #+#             */
/*   Updated: 2015/02/10 22:26:42 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <sstream>
// # include <boost/algorithm/string.hpp>
# include "pushCommand.hpp"
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <strings.h>
# include <vector>
# include <algorithm>


class Parser{

	public:
		Parser();
		Parser(const Parser & src);
		~Parser();
		Parser & 	operator=(Parser const & rhs);
		std::string 	readFile(int fd = 0);
		std::vector<std::string> *splitString(std::string file);
		std::vector<std::string> *split;
};

#endif