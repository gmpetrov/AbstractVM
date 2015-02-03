/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:58:33 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/03 18:36:04 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_COMMAND_HPP
# define PUSH_COMMAND_HPP

# include <iostream>
# include "BaseCommand.hpp"

class pushCommand : public BaseCommand{

	public: 
		pushCommand();
		pushCommand(const pushCommand & src);
		~pushCommand();
		pushCommand & 	operator=(pushCommand const & rhs);


};

#endif