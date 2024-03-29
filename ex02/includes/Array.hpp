/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:51:37 by motoko            #+#    #+#             */
/*   Updated: 2024/03/29 16:50:41 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template< typename T>
class Array {
	private:
		T				*_arr;
		unsigned int	_size;

	public:
		Array(void) : _arr(NULL), _size(0) {
			std::cout << "Constructor by default called : " << _size << std::endl;
		}

		Array(unsigned int n) {
			std::cout << "Constructor with params called : " << n << std::endl;
			_size = n;
			_arr = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_arr[i] = T();
			}
		}
		
		~Array() {
			std::cout << "Destructor called" << std::endl;
			if (_arr)
				delete [] _arr;
		}

		Array(const Array &rhs) : _arr(NULL), _size(0) {
			std::cout << "Constructor by copy called" << std::endl;
			*this = rhs;
		};

		Array& operator=(const Array& rhs) {
			std::cout << "Copy by operator '=' called" << std::endl;
			if (this != &rhs) {
				delete [] _arr;
				_size = rhs._size;
				if (_size > 0) {
					_arr = new T[_size];
					for (unsigned int i = 0; i < _size; i++) {
						_arr[i] = rhs._arr[i];
					}
				} else {
					_arr = NULL;
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
		T* getArr(void) {
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
};

template< typename T>
std::ostream& operator<<(std::ostream &out, const Array<T>& rhs) {
	for (unsigned int i = 0; i < rhs.getSize(); i++)
		out << rhs[i] << " ";
	return (out);
}
