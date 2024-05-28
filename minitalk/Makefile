CCFLAGS = cc -Wall -Werror -Wextra
SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus
HEADER = ./inc/minitalk.h
SRCS_SERVER = mandatory/server.c
SRCS_CLIENT = mandatory/client.c
SRCS_SERVER_BONUS = bonus/server_bonus.c
SRCS_CLIENT_BONUS = bonus/client_bonus.c
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c $(LIBFT_DIR)/*.h)

all: $(LIBFT) $(SERVER) $(CLIENT) 

$(LIBFT): $(LIBFT_SRCS)
		make -C ./libft

$(SERVER): $(LIBFT) $(SRCS_SERVER) $(HEADER)
		$(CCFLAGS) $(LIBFT)  $(SRCS_SERVER) -o $(SERVER) 

$(CLIENT): $(LIBFT) $(SRCS_CLIENT) $(HEADER)
		$(CCFLAGS) $(LIBFT)  $(SRCS_CLIENT) -o $(CLIENT) 

$(SERVER_BONUS): $(LIBFT) $(SRCS_SERVER_BONUS) ./inc/minitalk_bonus.h
		$(CCFLAGS) $(LIBFT)  $(SRCS_SERVER_BONUS) -o server_bonus 

$(CLIENT_BONUS): $(LIBFT) $(SRCS_CLIENT_BONUS) ./inc/minitalk_bonus.h
		$(CCFLAGS) $(LIBFT)  $(SRCS_CLIENT_BONUS) -o client_bonus


bonus: $(LIBFT) $(SERVER_BONUS) $(CLIENT_BONUS) 

clean:	
		make -C ./libft clean

fclean:
		make -C ./libft fclean
		rm -f $(SERVER) $(CLIENT)
		rm -f server_bonus client_bonus

re:	fclean all clean