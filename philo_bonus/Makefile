#-*-Makefile-*-

CC = cc
CFLAGS =  -g -Wall -Wextra -Werror #-fsanitize=thread #-fsanitize=address

SRCM = philo_bonus.c parse_bonus.c init_bonus.c phils_funcs_bonus.c phils_funcs_bonus2.c \
		phils_funcs_bonus3.c semaphores.c \
		utils_bonus.c utils_bonus2.c \

OBJM = $(SRCM:%.c=%.o)

SRCB = 

OBJB = $(SRCB:%.c=%.o)

#binaries :
NAME = philo_bonus
BONUS = 
HEADER_MAN = philo_bonus.h
HEADER_BON = 

all: $(NAME) $(BONUS)
man: $(NAME)
bonus: $(BONUS)

#Build mandatory part :
$(NAME): $(OBJM)
	cc $(CFLAGS) $^ -g -lpthread -o $@
# Compile object files for mandatory part :
$(OBJM):%.o:%.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

#Build bonus part :
$(BONUS): $(OBJB)
	cc $(CFLAGS) $^ -o $@
# Compile object files for bonus part :
$(OBJB):%.o:%.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJM) $(OBJB)
fclean: clean
	rm -f $(NAME) $(BONUS)
re: fclean all 
