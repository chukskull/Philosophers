CC = cc

CFLAGS = -Wall -Wextra -Werror -g

INCLUDE = -I./inc

B_DIR = build

HEADER = inc/philo.h inc/utils.h

HEADER_bonus = inc/bonus.h

SRC = philo utils/ft_atoi utils/pars ft_usleep utils/get_time utils/printf global_rules check_eat

SRC_bonus = bonus/main_bonus bonus/utils_bonus/ft_atoi_bonus bonus/utils_bonus/pars_bonus bonus/utils_bonus/get_time_bonus bonus/utils_bonus/printf bonus/utils_bonus/ft_usleep

OBJ = $(addprefix $(B_DIR)/, $(SRC:=.o))

OBJ_bonus = $(addprefix $(B_DIR)/, $(SRC_bonus:=.o))

NAME = philo

NAME_bonus = philo_bonus

all: $(NAME)
	
$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $@


bonus: $(NAME_bonus)

$(NAME_bonus): $(OBJ_bonus) $(HEADER_bonus)
	$(CC) -pthread $(OBJ_bonus) -o $@

$(B_DIR)/%.o: src/%.c
	mkdir -p $(@D)
	$(CC) -pthread $(INCLUDE) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(B_DIR) 

fclean: clean
	rm -f $(NAME) $(NAME_bonus)

re: fclean all

.PHONY: clean fclean re all