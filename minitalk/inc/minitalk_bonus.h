/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:01:27 by ael-moua          #+#    #+#             */
/*   Updated: 2024/05/28 08:15:45 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include "../libft/libft.h"

typedef struct s_char_node
{
	unsigned char		print[5];
	unsigned char		tmp;
	int					i;
	int					pid;
	int					bytes;
	int					byte_index;
	struct s_stack_node	*next;
}				t_char_node;	

#endif  
