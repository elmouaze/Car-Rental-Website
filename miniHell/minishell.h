/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:20:03 by ael-moua          #+#    #+#             */
/*   Updated: 2024/07/13 06:00:52 by ael-moua         ###   ########.fr       */
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
	char **cmd;
	t_token tok;
	t_redit *red;
	struct cmd_infos *next;
};

struct my_cmd {
	struct cmd_infos *infos;
	struct cmd *next;
} command;