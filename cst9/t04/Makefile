# --- PROJECT S21_CAT ---
NAME = t04

SRC = main.cc

OBJ_FOLDER = obj
OBJ = $(SRC:%.c=$(OBJ_FOLDER)/%.o)

CC = g++
FLAGS = -std=c++20 -Werror -Wextra -Wall -I.

# --- TESTING S21_CAT ---
TCC = g++
TESTS = tests.cc
TESTS_BIN = bin_tests

# --- COLORS FOR A GOOD-LOOKING ASSEMBLING ---
GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m
NO_COLOR = \x1b[0m
RESET = \033[0m

# --- JUST TRASH --- 
TRASH = obj *.a a.out .*.swp .DS_Store $(NAME) units $(TESTS_BIN) file_with_tests_trash py_res.csv unx_full_coverage_combo.csv

all: $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $@
	@printf "\n$(CURSIVE)$(GREEN)$(NAME)$(RESET)$(CURSIVE) is ready to launch 💃🕺$(RESET)\n"

$(OBJ_FOLDER):
	@mkdir $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: %.c $(PREREQ)
	@$(CC) -c $(FLAGS) $< -o $@

clean: fclean

fclean:
	@echo "$(RED)Cleaning $(NAME) & executable..."
	@rm -rf $(TRASH) 
	@echo "$(GRAY)$(CURSIVE)---$(NAME) staff is completely cleaned!\n$(RESET)"
.PHONY: fclean

re: fclean all
.PHONY: re

tests:
	@$(TCC) -std=c++17 -I. -D __TESTS__ $(TESTS) $(SRC)  -lgtest -lgtest_main -pthread -o $(TESTS_BIN)
.PHONY: test

show_tests_result: tests
	@./$(TESTS_BIN)
.PHONY: launch_test_bin

leaks: tests
	@make leaks -C ../s21_common/
	@leaks -quiet --atExit -- ./$(TESTS_BIN)
.PHONY: leaks
