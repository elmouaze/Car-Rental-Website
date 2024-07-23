/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:20:03 by ael-moua          #+#    #+#             */
/*   Updated: 2024/07/23 08:29:32 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H


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
	RI,
	RO,
	APPEND,
	WORD,
	EXPANDABLE,
	ENV,
}	token;

typedef struct tokens 
{
	char *str;
	token type;
	struct tokens *next;
}		t_token;

 struct cmd_infos
{
	char *line;
	char **cmd;
	struct t_token *tok;
};

typedef struct my_cmd {
	struct cmd_infos *infos;
	struct cmd *next;
} command;

t_token *lexer(char *lin);
t_token *new_token(char *str, token type);
void	add_token(t_token **lst, t_token *new);

#endif