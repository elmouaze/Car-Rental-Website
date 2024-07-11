/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-moua <ael-moua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 23:19:47 by ael-moua          #+#    #+#             */
/*   Updated: 2024/07/12 00:09:26 by ael-moua         ###   ########.fr       */
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
		line++;
	}
	if (*line == '\0' && c == ' ')
		return (cpt);
	return (-1);
}


int syn_error(char *str)
{
	printf("Morzesh : %s  error \n",str);
	return 2;
}

struct command *parsing(char *line)
{
	struct command *cmd;
	char symbols[] = "<|>";
	while (*line)
	{
		while (*line == " ")
			line++;
		if (strchr(symbols,*line))
		{
			
		}
		if (*line)
			line++;	
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
		printf("%s\n",new_line);
	}
	return 1;
}
