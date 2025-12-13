/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:55:46 by dylan             #+#    #+#             */
/*   Updated: 2025/12/12 11:37:12 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list/ft_lstmerge.h"
#include "list/ft_lstsort.h"

/// @brief Get the middle element of a linked list
/// @param head Head of the linked list
/// @param mid Index of the middle element
/// @param get_next Function to get the next element
/// @return Pointer to the middle element
static void	*get_mid(void *head, size_t mid, void *(*get_next)(void *element))
{
	size_t	i;

	i = 0;
	while (++i < mid)
		head = get_next(head);
	return (head);
}

/// @brief Get information about the linked list: head, mid, tail, length
/// @param head Head of the linked list
/// @param get_next Function to get the next element
/// @return Struct containing head, mid, tail, and length of the list
static struct s_info	get_info(void *head, void *(*get_next)(void *element))
{
	void			*next;
	struct s_info	res;

	res.len = 0;
	res.head = head;
	next = head;
	while (next)
	{
		res.len++;
		if (!get_next(next))
			break ;
		next = get_next(next);
	}
	res.tail = next;
	if (!res.len)
		return (res);
	if (res.len % 2)
		res.mid = get_mid(head, res.len / 2 + 1, get_next);
	else
		res.mid = get_mid(head, res.len / 2, get_next);
	return (res);
}

/// @brief Recursively split and sort the linked list
/// @param head Head of the linked list
/// @param len Length of the linked list
/// @param ops Operations struct containing function pointers
/// @return Head of the sorted linked list
static void	*split_and_sort(void *head, size_t len,
		const struct s_list_ops *ops)
{
	void	*head_left;
	void	*head_right;
	void	*mid;

	if (len <= 1)
		return (head);
	if (len == 2)
		return (ft_lstmerge(head, ops->get_next(head), ops));
	if (len % 2)
	{
		mid = get_mid(head, len / 2 + 1, ops->get_next);
		head_right = split_and_sort(ops->get_next(mid), len / 2, ops);
		ops->add_back(mid, NULL);
		head_left = split_and_sort(head, len / 2 + 1, ops);
	}
	else
	{
		mid = get_mid(head, len / 2, ops->get_next);
		head_right = split_and_sort(ops->get_next(mid), len / 2, ops);
		ops->add_back(mid, NULL);
		head_left = split_and_sort(head, len / 2, ops);
	}
	return (ft_lstmerge_sorted_lls(head_left, head_right, ops));
}

/// @brief Sort a linked list using merge sort algorithm
/// @param head Head of the linked list
/// @param ops Operations struct containing function pointers
/// @return Head of the sorted linked list
void	*ft_lstsort(void *restrict head, const struct s_list_ops *restrict ops)
{
	const struct s_info	info = get_info(head, ops->get_next);
	size_t				len_a;
	size_t				len_b;
	void				*list_a;
	void				*list_b;

	if (!info.len)
		return (NULL);
	if (info.len % 2)
	{
		len_a = info.len / 2 + 1;
		len_b = len_a - 1;
	}
	else
	{
		len_a = info.len / 2;
		len_b = len_a;
	}
	list_b = split_and_sort(ops->get_next(info.mid), len_b, ops);
	ops->add_back(info.mid, NULL);
	list_a = split_and_sort(info.head, len_a, ops);
	return (ft_lstmerge_sorted_lls(list_a, list_b, ops));
}
