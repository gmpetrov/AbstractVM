/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmp <gmp@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 17:51:27 by gmp               #+#    #+#             */
/*   Updated: 2015/02/12 16:27:05 by gmp              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IOPERAND_HPP
# define IOPERAND_HPP

# include <stdint.h>

class IOperand {
		public:
			typedef enum { INT8 = 0, INT16 = 1, INT32 = 2, FLOAT = 3, DOUBLE = 4} eOperandType;
			virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
			virtual eOperandType getType( void ) const = 0; // Type of the instance
			virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
			virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
			virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
			virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
			virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
			
			virtual std::string const & toString( void ) const = 0; // String representation of the instance
			virtual ~IOperand( void ) {}

	};

#endif