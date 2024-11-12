NAME=libftprintf.a

MY_SOURCES= src/ft_printf_functions.c \
			src/ft_printf_hexa.c \
			src/ft_printf_pointer.c \
			src/ft_printf_unsigned.c \
			src/ft_printf.c \
			src/ft_printf_utils.c

ALL_SOURCES=$(MY_SOURCES) $(BONUS)

MY_OBJECTS=$(ALL_SOURCES:.c=.o)

# ====================
#      COMMANDES
# ====================

RM=rm -f
CC=cc
ARRC=ar -rcs
FLAGS=-Wall -Werror -Wextra

# ====================
#        HEADER
# ====================

define HEADER
      $(CYAN)_____    _
     $(CYAN)|  __ \  (_)
     $(CYAN)| |  | |  _   _ __    ___   _ __ ___
     $(CYAN)| |  | | | | | '__|  / _ \ | '_ ` _ \\
     $(CYAN)| |__| | | | | |    |  __/ | | | | | |
     $(CYAN)|_____/  |_| |_|     \___| |_| |_| |_|

endef
export HEADER

# ====================
#    COULEURS AINSI
# ====================

RESET=\033[0m
GREEN=\033[0;32m
CYAN=\033[0;36m
BLUE=\033[0;34m
YELLOW=\033[0;33m
RED=\033[0;31m

# ====================
#     COMPILATION
# ====================

all: $(NAME)

$(NAME): $(MY_OBJECTS)
	@$(ARRC) $(NAME) $(MY_OBJECTS)
	@echo "$(GREEN)Tous les fichiers ont été compilés avec succès!$(RESET)"
	@echo "$(CYAN)Fichiers compilés :$(RESET)"
	@echo " "$(COMPILED_FILES)

bonus: $(BONUS:.c=.o)
	@$(ARRC) $(NAME) $^

%.o: %.c
	@clear
	@echo "$(CYAN)Compiling $<...$(RESET)"
	@$(CC) $(FLAGS) -c $< -o $@
	@$(eval COMPILED_FILES += "$< $(GREEN)🗹\n$(RESET)")
	@clear
	@echo "$$HEADER"
	@echo "$(CYAN) ============================================$(RESET)"

clean:
	@$(RM) $(MY_OBJECTS)

fclean: clean
	@$(RM) $(NAME)
	@clear
	@echo "\n$(CYAN)   ╔════════════════════════════════════════════╗$(RESET)"
	@echo "$(CYAN)        All cleaned up! Ready to build fresh! $(RESET)"
	@echo "$(CYAN)   ╚════════════════════════════════════════════╝$(RESET)"
	@echo

re: fclean all

.PHONY: all bonus clean fclean re header
