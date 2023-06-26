/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfuentes <pfuentes@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 10:48:23 by pfuentes          #+#    #+#             */
/*   Updated: 2023/06/07 11:54:15 by pfuentes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h" 
#include "../libft/libft.h"

t_btree	*btree_new_node(void	*content)
{
	t_btree	*node;

	node = malloc(sizeof(t_btree));
	node->content = content;
	node->up = NULL;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

void	btree_add_left_node(t_btree **root, t_btree *new)
{
	(*root)->left = new;
	new->up = *root;
}

void	btree_add_right_node(t_btree **root, t_btree *new)
{
	(*root)->right = new;
	new->up = *root;
}
