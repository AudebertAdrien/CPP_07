/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:40:21 by motoko            #+#    #+#             */
/*   Updated: 2024/03/29 16:50:53 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int	main(void) {
	std::cout << std::string(50, '#') << std::endl;

	Array< int >	a1;
	Array< int >	a2(5);

	std::cout << std::string(50, '#') << std::endl;

	Array< int >	a3(a2);
	Array< int >	a4;
	a4 = a3;

	std::cout << std::string(50, '#') << std::endl;

	int 			*arr = a4.getArr();
	unsigned int	size = a4.getSize();

	std::cout << "size : " << size << std::endl;
	for (unsigned int i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}

	std::cout << std::string(50, '#') << std::endl;
	
	for (unsigned int i = 0; i < size; i++) {
		a4[i] = i * 2;
	}

	for (unsigned int i = 0; i < size; i++) {
		std::cout << arr[i] << std::endl;
	}

	std::cout << "Int Array a4: " << a4 << std::endl;

	Array< int >	a5;
	a5 = a4;

	std::cout << "Int Array a5: " << a5 << std::endl;

	std::cout << std::string(50, '#') << std::endl;

	try {
		std::cout << "Accessing a valid index: " << a5[3] << std::endl;
		std::cout << "Accessing an invalid index: " << a5[0] << std::endl;
	} catch (std::exception& e ) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::string(50, '#') << std::endl;

	return (0);
}
