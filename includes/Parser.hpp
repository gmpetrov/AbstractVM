/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 16:54:11 by gmp               #+#    #+#             */
/*   Updated: 2015/02/05 13:29:56 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
// # include <boost/algorithm/string.hpp>
# include "pushCommand.hpp"


class Parser{

	public:
		Parser();
		Parser(const Parser & src);
		~Parser();
		Parser & 	operator=(Parser const & rhs);

};

#endif