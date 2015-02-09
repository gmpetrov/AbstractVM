/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Int32.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 17:51:09 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 17:51:44 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT32_HPP
# define INT32_HPP

# include "OperandTemplate.hpp"

class Int32 : public OperandTemplate<Int32, int32_t>{
	public:
		Int32(int32_t nb);
		Int32(const Int32 & src);
		virtual ~Int32();
		Int32 & 	operator=(Int32 const & rhs);
	private:
		Int32();
};

#endif