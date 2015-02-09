/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Double.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 19:03:44 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/09 19:08:15 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_HPP
# define DOUBLE_HPP

# include "OperandTemplate.hpp"

class Double : public OperandTemplate<Double, double>{
	public:
		Double(double nb);
		Double(const Double & src);
		virtual ~Double();
		Double & 	operator=(Double const & rhs);
	private:
		Double();
};

#endif