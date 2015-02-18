/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OperandTemplate.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/05 13:09:09 by gpetrov           #+#    #+#             */
/*   Updated: 2015/02/18 16:36:18 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_TEMPLATE_HPP
# define OPERAND_TEMPLATE_HPP

# include <iostream>
# include <stdint.h>
# include <typeinfo>
# include <stdlib.h>
# include <string>
# include <math.h>
// # include <sstream>
// # include <boost/algorithm/string.hpp>
# include "IOperand.hpp"
// # include <iomanip>

class Int8;
class Int16;
class Int32;
class Float;
class Double;

template <typename T, typename N>
class OperandTemplate : public IOperand {
	public: 
		// typedef enum { INT8 = 0, INT16 = 1, INT32 = 2, FLOAT = 3, DOUBLE = 4} eOperandType;
		OperandTemplate<T, N>(N nb, int type){ this->_value = nb; this->_type = static_cast<eOperandType>(type); };
		OperandTemplate<T, N>(const OperandTemplate<T, N> & src){ *this = src; };
		~OperandTemplate<T, N>(){};
		OperandTemplate<T, N> & 	operator=(OperandTemplate<T, N> const & rhs){ (void)rhs; return *this; };
		virtual eOperandType getType(void) const{
			return this->_type;
		}
		virtual int getPrecision( void ) const{
			return static_cast<int>(this->getType());
		}

		/* OPERATORS OVERLOAD */

		virtual OperandTemplate<T, N> const * operator+(IOperand const & rhs) const{
			eOperandType type = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());

			// std::cout << "ULTIMATE TEST : " << rhs.getType() << std::endl;
			// const OperandTemplate<Float, float> *tmp = static_cast<const OperandTemplate<class Float, float>* >(&rhs);
			// std::cout << "ZBRA TEST : " << static_cast< const OperandTemplate<Int32, int32_t> *>(&rhs)->getValue() << std::endl;
			// std::cout << "FLUTE TEST : " << tmp->getValue() << std::endl;
			// std::cout << "YOLO TEST : " << this->getValue() << std::endl;
			// const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value + tmp->getValue())));

			/* FUCKING UGLY WAY */

			if (rhs.getType() == 0){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value + static_cast< const OperandTemplate<Int8, int8_t> *>(&rhs)->getValue())));
				return ptr;
			}
			else if (rhs.getType() == 1){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value + static_cast< const OperandTemplate<Int16, int16_t> *>(&rhs)->getValue())));
				return ptr;
			}
			else if (rhs.getType() == 2){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value + static_cast< const OperandTemplate<Int32, int32_t> *>(&rhs)->getValue())));					
				return ptr;
			}
			else if (rhs.getType() == 3){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value + static_cast< const OperandTemplate<Float, float> *>(&rhs)->getValue())));					
				return ptr;

			}
			else{
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value + static_cast< const OperandTemplate<Double, double> *>(&rhs)->getValue())));
				return ptr;
			}
		}

		virtual IOperand const * operator-( IOperand const & rhs ) const{
			eOperandType type = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());

			// const OperandTemplate<T, N> *tmp = dynamic_cast<const OperandTemplate<T, N>* >(&rhs);
			// const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(this->getType(), std::to_string(this->_value - tmp->getValue())));
			// return ptr;

			if (rhs.getType() == 0){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value - static_cast< const OperandTemplate<Int8, int8_t> *>(&rhs)->getValue())));
				return ptr;
			}
			else if (rhs.getType() == 1){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value - static_cast< const OperandTemplate<Int16, int16_t> *>(&rhs)->getValue())));
				return ptr;
			}
			else if (rhs.getType() == 2){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value - static_cast< const OperandTemplate<Int32, int32_t> *>(&rhs)->getValue())));					
				return ptr;
			}
			else if (rhs.getType() == 3){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value - static_cast< const OperandTemplate<Float, float> *>(&rhs)->getValue())));					
				return ptr;
			}
			else{
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value - static_cast< const OperandTemplate<Double, double> *>(&rhs)->getValue())));
				return ptr;
			}
		}

		virtual IOperand const * operator*( IOperand const & rhs ) const{
			eOperandType type = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());

			// const OperandTemplate<T, N> *tmp = dynamic_cast<const OperandTemplate<T, N>* >(&rhs);
			// const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(this->getType(), std::to_string(this->_value * tmp->getValue())));
			// return ptr;

			if (rhs.getType() == 0){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value * static_cast< const OperandTemplate<Int8, int8_t> *>(&rhs)->getValue())));
				return ptr;
			}
			else if (rhs.getType() == 1){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value * static_cast< const OperandTemplate<Int16, int16_t> *>(&rhs)->getValue())));
				return ptr;
			}
			else if (rhs.getType() == 2){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value * static_cast< const OperandTemplate<Int32, int32_t> *>(&rhs)->getValue())));					
				return ptr;
			}
			else if (rhs.getType() == 3){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value * static_cast< const OperandTemplate<Float, float> *>(&rhs)->getValue())));					
				return ptr;
			}
			else{
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value * static_cast< const OperandTemplate<Double, double> *>(&rhs)->getValue())));
				return ptr;
			}
		}

		virtual IOperand const * operator/( IOperand const & rhs ) const{
			eOperandType type = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());

			// const OperandTemplate<T, N> *tmp = dynamic_cast<const OperandTemplate<T, N>* >(&rhs);
			// const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(this->getType(), std::to_string(this->_value / tmp->getValue())));
			// return ptr;

			if (rhs.getType() == 0){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value / static_cast< const OperandTemplate<Int8, int8_t> *>(&rhs)->getValue())));
				return ptr;
			}
			else if (rhs.getType() == 1){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value / static_cast< const OperandTemplate<Int16, int16_t> *>(&rhs)->getValue())));
				return ptr;

			}
			else if (rhs.getType() == 2){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value / static_cast< const OperandTemplate<Int32, int32_t> *>(&rhs)->getValue())));					
				return ptr;

			}
			else if (rhs.getType() == 3){
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value / static_cast< const OperandTemplate<Float, float> *>(&rhs)->getValue())));					
				return ptr;

			}
			else{
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(this->_value / static_cast< const OperandTemplate<Double, double> *>(&rhs)->getValue())));
				return ptr;
			}			
		}

		virtual IOperand const * operator%( IOperand const & rhs ) const{
			eOperandType type = (this->getPrecision() >= rhs.getPrecision() ? this->getType() : rhs.getType());

			// const OperandTemplate<T, N> *tmp = dynamic_cast<const OperandTemplate<T, N>* >(&rhs);
			// const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(this->getType(), std::to_string(fmod(this->_value, tmp->getValue()))));
			// return ptr;
			if (rhs.getType() == 0){
				const N val = static_cast<const N>(static_cast< const OperandTemplate<Int8, int8_t> *>(&rhs)->getValue());
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string( fmod(this->_value, val) )));
				return ptr;
			}
			else if (rhs.getType() == 1){
				const N val = static_cast<const N>(static_cast< const OperandTemplate<Int16, int16_t> *>(&rhs)->getValue());
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(fmod(this->_value, val) )));
				return ptr;
			}
			else if (rhs.getType() == 2){
				const N val = static_cast<const N>(static_cast< const OperandTemplate<Int32, int32_t> *>(&rhs)->getValue());
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(fmod(this->_value, val) )));					
				return ptr;
			}
			else if (rhs.getType() == 3){
				const N val = static_cast<const N>(static_cast< const OperandTemplate<Float, float> *>(&rhs)->getValue());
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(fmod(this->_value, val) )));					
				return ptr;
			}
			else{
				const N val = static_cast<const N>(static_cast< const OperandTemplate<Float, float> *>(&rhs)->getValue());
				const OperandTemplate<T, N> *ptr = static_cast<const OperandTemplate<T, N> *>(this->createOperand(type, std::to_string(fmod(this->_value, val) )));
				return ptr;
			}
		}

		/* Factory */

		IOperand const * createInt8( std::string const & value ) const{
			return new OperandTemplate<class Int8, int8_t>(atoi(value.c_str()), this->getType());
		}

		IOperand const * createInt16( std::string const & value ) const{
			return new OperandTemplate<class Int16, int16_t>(atoi(value.c_str()), this->getType());	
		}

		IOperand const * createInt32( std::string const & value ) const{
			return new OperandTemplate<class Int32, int32_t>(atoi(value.c_str()), this->getType());	
		}

		IOperand const * createFloat( std::string const & value ) const{
			return new OperandTemplate<class Float, float>(atof(value.c_str()), this->getType());	
		}

		IOperand const * createDouble( std::string const & value ) const{
			return new OperandTemplate<class Double, double>(atof(value.c_str()), this->getType());	
		}

		IOperand const * createOperand( eOperandType type, std::string const & value ) const{
			IOperand const * (OperandTemplate<T, N>::* tab[])(std::string const & value)const = { &OperandTemplate::createInt8, &OperandTemplate::createInt16, &OperandTemplate::createInt32, &OperandTemplate::createFloat, &OperandTemplate::createDouble };
			return (this->*tab[type])(value);
		}

		virtual std::string const & toString( void ) const{
			static std::string str;
			str = std::to_string(_value);
			return str;
		}

		/* Getters & Setters) */

		N 	getValue()const{
			return this->_value;
		}
	private:
		OperandTemplate<T, N>(){}
		N 					_value;
		eOperandType 		_type;
};

#endif