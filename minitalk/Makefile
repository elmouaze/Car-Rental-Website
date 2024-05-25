CCFLAGS = cc -Wall -Werror -Wextra
SERVER = server
CLIENT = client
HEADER = ./inc/minitalk.h
SRCS_SERVER = mandatory/server.c
SRCS_CLIENT = mandatory/client.c
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


clean:	
		make -C ./libft clean

fclean:
		make -C ./libft fclean
		rm -f $(SERVER) $(CLIENT)

re:	fclean all