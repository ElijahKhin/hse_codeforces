# --- PROJECT S21_CAT ---
NAME = t8

SRC = main.cc

OBJ_FOLDER = obj
OBJ = $(SRC:%.c=$(OBJ_FOLDER)/%.o)

CC = g++
FLAGS = -std=c++20 -Werror -Wextra -Wall -I.

# --- TESTING S21_CAT ---
TCC = g++
TESTS = s21_cat_tests.cc
TESTS_BIN = tests_bin_s21_cat
GCOV_REPORT_NAME = tests_coverage_s21_cat

# --- COLORS FOR A GOOD-LOOKING ASSEMBLING ---
GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m
NO_COLOR = \x1b[0m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@
	@printf "\n$(CURSIVE)$(GREEN)$(NAME)$(RESET)$(CURSIVE) is ready to launch 💃🕺$(RESET)\n"

$(OBJ_FOLDER):
	@mkdir $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: %.c $(PREREQ)
	@$(CC) -c $(FLAGS) $< -o $@

fclean:
	@echo "$(RED)Cleaning $(NAME) & executable..."
	@rm -rf $(NAME) $(OBJ_FOLDER)
	@echo "$(GRAY)$(CURSIVE)---$(NAME) staff is completely cleaned!\n$(RESET)"
.PHONY: fclean

re: fclean all
.PHONY: re

#leaks: tests
#	@make leaks -C ../s21_common/
#	@leaks -quiet --atExit -- ./$(TESTS_BIN)
#.PHONY: leaks
#
