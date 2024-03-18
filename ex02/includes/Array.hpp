/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 16:51:37 by motoko            #+#    #+#             */
/*   Updated: 2024/03/18 15:12:03 by motoko           ###   ########.fr       */
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
		}

		Array(const Array &rhs) {
			std::cout << "Constructor by copy called" << std::endl;
			*this = rhs;
		};

		Array& operator=(const Array& rhs) {
			std::cout << "Copy by operator '=' called" << std::endl;
			if (this != &rhs) {
				delete [] _arr;
				_arr = new T[rhs.size()];
				_size = rhs.size();
				for (unsigned int i = 0; i < _size; i++) {
					_arr[i] = rhs._arr[i];
				}
			}
		}

	private:
		T				*_arr;
		unsigned int	_size;
};
