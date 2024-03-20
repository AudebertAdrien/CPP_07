/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:51:37 by motoko            #+#    #+#             */
/*   Updated: 2024/03/18 17:18:00 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template< typename T>
class Array {
	public:
		Array(void) : _arr(new T[0]), _size(0) {
			std::cout << "Constructor by default called : " << _size << std::endl;
		}

		Array(unsigned int n) {
			std::cout << "Constructor with params called : " << n << std::endl;
			_arr = new T[n];
			_size = n;
		}
		
		~Array< T >() {
			std::cout << "Destructor called" << std::endl;
			delete [] _arr;
		}

		Array(const Array &rhs) {
			std::cout << "Constructor by copy called" << std::endl;
			*this = rhs;
		};

		Array& operator=(const Array& rhs) {
			std::cout << "Copy by operator '=' called" << std::endl;
			if (this != &rhs) {
				delete [] _arr;
				_arr = new T[rhs._size];
				_size = rhs._size;
				for (unsigned int i = 0; i < _size; i++) {
					_arr[i] = rhs._arr[i];
				}
			}
			return (*this);
		}

		T& operator[](unsigned int i) const {
			if (i >= _size)
				throw OutOfBoundsException();
			return (_arr[i]);
		}

		/* == getter == */
		T * getArr(void) {
			return (_arr);
		}

		unsigned int	getSize(void) const {
			return (_size);
		}

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return ("Index is out of bounds");
				}
		};

	private:
		T				*_arr;
		unsigned int	_size;
};

template< typename T>
std::ostream& operator<<(std::ostream &out, const Array<T>& rhs) {
	for (unsigned int i = 0; i < rhs.getSize(); i++)
		out << rhs[i] << " ";
	return (out);
}
