CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDE = -I./inc
B_DIR = build
HEADER = inc/philo.h inc/utils.h
SRC = philo utils/ft_atoi utils/pars ft_usleep utils/get_time utils/printf global_rules check_eat
OBJ = $(addprefix $(B_DIR)/, $(SRC:=.o))

NAME = philo

all: $(NAME)
	
$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $@

$(B_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) -pthread $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(B_DIR) 

fclean: clean
	rm -f $(NAME) $(bonus)

re: fclean all

.PHONY: clean fclean re all