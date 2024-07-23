/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:19:47 by ael-moua          #+#    #+#             */
/*   Updated: 2024/07/23 09:13:11 by ael-moua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *rl_gets (char *str,char *line_read)
{
  if (line_read)
    {
      free (line_read);
      line_read = (char *)NULL;
    }

  line_read = readline (str);
  if (line_read && *line_read)
  	add_history (line_read);

  return (line_read);
}

int syn_error(char *str)
{
	printf("Morzesh : syntax error near unexpected token %s \n",str);
	exit(1);
	return (-1);
}
int skip_quotes(char *line,char c)
{
	int cpt ;
	cpt = 1;
	while (line[cpt])
	{
		if (line[cpt] == c)
			return (cpt);
		cpt++;
	}
	syn_error("Quotes");
	return (-1);
}



int append_operator(char *line, t_token **tokens)
{
	if (*line == '<')
	{
		if (*(line + 1) == '<')
			return (add_token(tokens,new_token(ft_strdup("<<"),HEREDOC)),2);
		else 
			return (add_token(tokens,new_token(ft_strdup("<"),RI)),1);
	}else if (*line == '>')
	{
		if (*(line + 1) == '>')
			return (add_token(tokens,new_token(ft_strdup(">>"),APPEND)),2);
		else 
			return (add_token(tokens,new_token(ft_strdup(">"),RO)),1);
	}else if (*line == '|')
		return( add_token(tokens,new_token(ft_strdup("|"),PIPE)),1);
	return 0;
}
int append_cmd(char *line, t_token **tokens)
{
	char *str;
	int steps ;
	steps = 0;
	while (line[steps] && line[steps] != ' ' && 
		!(line[steps] == '<' || line[steps] == '>' || line[steps] == '|'))
	{
		if (line[steps] == '"' || line[steps] == '\'')
			steps += skip_quotes(line + steps, line[steps]);
		else
			steps++;
	}
	add_token(tokens,new_token(ft_substr(line,0,steps),WORD));
	return (steps);
}

t_token  *lexer(char *line)
{
	int i = 0, q,end;
	t_token *tokens = NULL;
	q = 0;
	while (*line)
	{
		while (*line ==  ' ')
			line++;
		if (*line == '<' || *line == '>' || *line == '|' )
			line += append_operator(line, &tokens);
		else 
			line += append_cmd(line, &tokens);
	}
	return tokens;
}

int main()
{
	static char *line_read = NULL;
	char *new_line;
	t_token *tokens;
	
	tokens = NULL;
	while (1)
	{
		line_read = rl_gets("MiniHell: ",line_read);
		if (!line_read)
			return (syn_error("line read"));
		new_line = ft_strtrim(line_read, " \t\r\n\v");
		tokens = lexer(new_line);
		while (tokens)
		{
			printf("str = %s  type = %d\n",tokens->str,tokens->type);
			tokens = tokens->next;
		}
	}
	return (1);
}
