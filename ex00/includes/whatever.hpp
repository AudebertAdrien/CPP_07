/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:47:10 by motoko            #+#    #+#             */
/*   Updated: 2024/03/14 16:44:50 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template< typename T>
void	swap(T &x, T &y) {
	T	tmp;

	tmp = x;
	x = y;
	y = tmp;
}

template< typename T>
T const & max(T const &x, T const &y) {
	return ((x >= y) ? x : y);
}

template< typename T>
T const & min(T const &x, T const &y) {
	return ((x <= y) ? x : y);
}
