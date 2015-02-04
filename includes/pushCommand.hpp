/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:58:33 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/04 16:49:15 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_COMMAND_HPP
# define PUSH_COMMAND_HPP

# include <iostream>
# include <boost/algorithm/string.hpp>
# include "BaseCommand.hpp"

class pushCommand : public BaseCommand{

	public: 
		pushCommand();
		pushCommand(const pushCommand & src);
		~pushCommand();
		pushCommand & 	operator=(pushCommand const & rhs);


};

#endif