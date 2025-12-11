/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:56:53 by dylan             #+#    #+#             */
/*   Updated: 2025/12/11 17:17:11 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

/// @brief Find the winner between two elements according to cmp function
/// @param a Element a
/// @param b Element b
/// @param cmp Comparison function that returns true if a should come before b
/// @return The winner element according to cmp
static void	*find_winner(void *restrict a, void *restrict b,
		bool (*cmp)(void *restrict a, void *restrict b))
{
	if (!a)
		return (b);
	if (!b)
		return (a);
	if (cmp(a, b))
		return (a);
	return (b);
}

/// @brief Merge two sorted linked lists into one sorted linked list
/// @param list_a List a
/// @param list_b List b
/// @param ops Operations struct containing function pointers
/// @return Head of the merged sorted linked list
void	*ft_lstmerge_sorted_lls(void *restrict list_a, void *restrict list_b,
		const struct s_list_ops *restrict ops)
{
	void	*head;
	void	*tail;
	void	*winner;

	head = NULL;
	tail = NULL;
	winner = NULL;
	while (list_a || list_b)
	{
		winner = find_winner(list_a, list_b, ops->cmp);
		if (winner == list_a)
			list_a = ops->get_next(list_a);
		else
			list_b = ops->get_next(list_b);
		tail = ops->add_back(tail, winner);
		if (!head)
			head = tail;
	}
	return (head);
}

/// @brief Merge two elements according to the comparison function
/// @param a Element a
/// @param b Element b
/// @param ops Operations struct containing function pointers
/// @return The merged element
void	*ft_lstmerge(void *a, void *b, const struct s_list_ops *ops)
{
	if (ops->cmp(a, b))
	{
		ops->add_back(a, b);
		ops->add_back(b, NULL);
		return (a);
	}
	ops->add_back(b, a);
	ops->add_back(a, NULL);
	return (b);
}
