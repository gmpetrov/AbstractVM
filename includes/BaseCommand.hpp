/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseCommand.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/03 17:49:44 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/05 13:32:28 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_COMMAND_HPP
# define BASE_COMMAND_HPP

# include <iostream>

class BaseCommand{
	public:
		BaseCommand(std::string name);
		BaseCommand(const BaseCommand & src);
		virtual ~BaseCommand() = 0;
		BaseCommand & 	operator=(BaseCommand const & rhs);
		std::string 	getName();
	protected:
		BaseCommand();
	private:
		std::string const	_name;
};

#endif