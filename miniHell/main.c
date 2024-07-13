/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:19:47 by ael-moua          #+#    #+#             */
/*   Updated: 2024/07/13 05:38:14 by ael-moua         ###   ########.fr       */
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

int skip(char *line,char c)
{
	int cpt;
	//:(){:|:&};:
	cpt = 0;

	line++;
	cpt++;
	while (*line)
	{
		if (*line == c)
			return (cpt);
		cpt++;
		line++;
	}
	return (-1);
}

void replace_c(char *line, char from, char to,int stop)
{
	while (stop >= 0)
	{
		if (line[stop] == from)
			line[stop] = to;
		stop--;		
	}
}
int syn_error(char *str)
{
	printf("Morzesh : %s  error \n",str);
	return 2;
}

struct command *parsing(char *line)
{
	struct command *cmd;
	char *tmp;
	char **tokens;
	int i, q;
	i = 0;
	q = 0;
	tmp = line;
	while (*line)
	{
		if ((*line == '"' || *line ==  '\'' ) && skip(line, *line) > 0)
		{ 
			q = skip(line,*line);
			replace_c(line,' ', 127,q);
			line += q;
		}
		line++;
	}
	tokens = ft_split(tmp, ' ');
	while (tokens[i])
	{
		replace_c(tokens[i], 127, ' ',ft_strlen(tokens[i]));
		i++;
	}
	for (int x = 0; tokens[x];x++)
	{
		printf("%s\n",tokens[x]);
	}
	return cmd;
}

int main()
{
	static char *line_read = (char *)NULL;
	char *new_line;
	struct command *cmd;
	
	while (1)
	{
		line_read = rl_gets("MiniHell: ",line_read);
		if (!line_read)
			return (syn_error("line read"));
		new_line = ft_strtrim(line_read, " \t\r\n\v");
		cmd = parsing(new_line);
		// 	return (free(line_read),syn_error("unclosed quotes"));
		//cmd = ft_split(line_read, '|');
		// while (*cmd && cmd && **cmd )
	}
	return 1;
}
