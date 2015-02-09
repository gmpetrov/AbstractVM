/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int8.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:53:24 by gmp               #+#    #+#             */
/*   Updated: 2015/02/09 14:51:59 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT8_HPP
# define INT8_HPP

# include "OperandTemplate.hpp"

class Int8 : public OperandTemplate<Int8, int8_t> {
	public:
		Int8(int8_t nb);
		Int8(const Int8 & src);
		virtual ~Int8();
		Int8 & 	operator=(Int8 const & rhs);
	private:
		Int8();
};

#endif