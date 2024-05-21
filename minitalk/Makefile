LIBFTOBJ = libft/libft.a

CCFLAGS = cc #-Wall -Werror #-Wextra

SERVER = server
CLIENT = client
SRCS_SERVER = mandatory/server.c
SRCS_CLIENT = mandatory/client.c
SRCS_CLIENT_BONUS = client_bonus
SRCS_SERVER_BONUS = server_bonus

OBJS_SERVER = $(SRCS_SERVER:.c=.o) 
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT)
		$(CCFLAGS) $(LIBFTOBJ)  $(SRCS_SERVER) -o $(SERVER) 

$(CLIENT): $(LIBFT)
		$(CCFLAGS) $(LIBFTOBJ)  $(SRCS_CLIENT) -o $(CLIENT) 

$(LIBFT):
		${MAKE} -C ./libft

clean:	
		rm -rf ${OBJS_SERVER} ${OBJS_CLIENT} 

fclean:	clean
		rm -rf $(SERVER) $(CLIENT)

re:	fclean all