/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Float.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:58:16 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 18:01:14 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_HPP
# define FLOAT_HPP

# include "OperandTemplate.hpp"

class Float : public OperandTemplate<Float, float>{
	public:
		Float(float nb);
		Float(const Float & src);
		virtual ~Float();
		Float & 	operator=(Float const & rhs);
	private:
		Float();
};

#endif