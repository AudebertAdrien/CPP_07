/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:40:21 by motoko            #+#    #+#             */
/*   Updated: 2024/03/15 16:30:59 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

#define ARR_SIZE 3

int	main(void) {
	int 		arr1[ARR_SIZE] = {1, 2, 3};
	std::string arr2[ARR_SIZE] = {"test1", "test2", "test3"};

	iter<int>(arr1, ARR_SIZE, &ft_display);
	iter(arr2, ARR_SIZE, &ft_display);
	return (0);
}
