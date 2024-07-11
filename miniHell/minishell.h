/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:20:03 by ael-moua          #+#    #+#             */
/*   Updated: 2024/07/12 00:16:16 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <libc.h>
#include "./libft/libft.h"

typedef enum e_token
{
	PIPE,
	HEREDOC,
	LPR,
	RPR,
	APPEND,
	END
}	t_token;

struct cmd_infos
{
	char *word;
	t_token tok;
	
	struct cmd_infos *next;
};

struct my_cmd {
	struct cmd_infos *infos;
	struct cmd *next;
} command;