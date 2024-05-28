GCC=cc
CFLAGS=-Wall -Wextra -Werror -g3 -mtune=native -march=native -O3 -fomit-frame-pointer -Iinclude -mavx -mavx2
SRCDIR=srcs
OBJDIR=objs
SRCS=$(wildcard $(SRCDIR)/**/*.c $(SRCDIR)/*.c)
OBJS=$(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET=string-in-c

GREEN = \033[38;2;4;231;98m
BLUE = \033[38;2;119;166;182m
RED = \033[0;31m
RESET = \033[0m

all: $(TARGET)

$(TARGET): $(OBJS)
	@printf "$(GREEN)Linking...$(RESET)\n"
	@$(GCC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@printf "$(GREEN)╭────────────────────────────────────────────╮\n"
	@printf "│           Compiled Successfully            │\n"
	@printf "╰────────────────────────────────────────────╯\n$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@printf "$(BLUE)Compiling $<...$(RESET)\n"
	@$(GCC) $(CFLAGS) -c $< -o $@
	@printf "$(GREEN)Compiled $< successfully!$(RESET)\n"

clean:
	@printf "$(RED)Cleaning up object files...$(RESET)\n"
	@rm -frd $(OBJDIR)
	@printf "$(RED)Cleaned.$(RESET)\n"

fclean: clean
	@printf "$(RED)Removing executable $(TARGET)...$(RESET)\n"
	@rm -f $(TARGET)
	@printf "$(RED)Removed.$(RESET)\n"

re: fclean all

.PHONY: all clean fclean re

# Rule to generate compile_commands.json using Bear
bear: clean
	@printf "$(BLUE)Generating compile_commands.json with Bear...$(RESET)\n"
	@bear -- make $(TARGET)
	@printf "$(GREEN)Generated compile_commands.json successfully!$(RESET)\n"
