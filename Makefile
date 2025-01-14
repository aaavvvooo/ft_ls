CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb -fsanitize=address
NAME = ft_ls
RM = rm -rf

SRC_DIR = src
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR = obj
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Libs
LIBS = ./libs
LIBFT_PATH =  $(LIBS)/libft/
PRINTF_PATH = $(LIBS)/ft_printf/
HEADER = ft_ls.h

# Colors
Red='\033[0;31m'          # Red
Green='\033[0;32m'        # Green
Yellow='\033[0;33m'       # Yellow
Blue='\033[0;34m'         # Blue
Purple='\033[0;35m'       # Purple
Cyan='\033[0;36m'         # Cyan
White='\033[0;37m'        # White


all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
		 @make -C $(LIBFT_PATH) all
		 @echo  -e ${Green}LIBFT COMPILED ${White}
		 @make -C $(PRINTF_PATH) all
		 @echo -e  $(Green)PRINTF COMPILED$(White)
		 $(CC) $(CFLAGS) $(OBJS) $(LIBFT_PATH)libft.a $(PRINTF_PATH)libprintf.a -o $(NAME)
		 @echo -e  $(Green)DONE$(White)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_PATH) clean
	@echo  -e ${Green}LIBFT CLEANED ${White}
	@make -C $(PRINTF_PATH) clean
	@echo -e  $(Green)PRINTF CLEANED$(White)

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@echo  -e ${Green}LIBFT DELETED ${White}
	@make -C $(PRINTF_PATH) fclean
	@echo -e  $(Green)PRINTF DELETED$(White)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
