/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:54:11 by gmp               #+#    #+#             */
/*   Updated: 2015/02/10 19:02:58 by gpetrov          ###   ########.fr       */
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


class Parser{

	public:
		Parser();
		Parser(const Parser & src);
		~Parser();
		Parser & 	operator=(Parser const & rhs);
		std::string 	readFile(int fd = 0);


};

#endif