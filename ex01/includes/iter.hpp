/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:47:10 by motoko            #+#    #+#             */
/*   Updated: 2024/03/15 16:23:45 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template< typename T>
void	iter(T *arr, size_t arr_len, void (*fn)(T &)) {
	for (size_t i = 0; i < arr_len; i++) {
		fn(arr[i]);
	}
}

template< typename T>
void	ft_display(T &val) {
	std::cout << val << std::endl;
}
