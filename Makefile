GCC=cc
CFLAGS=-Wall -Wextra -Werror
SRCDIR=srcs
OBJDIR=objs
SRCS=$(wildcard $(SRCDIR)/*.c)
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
	@printf "$(GREEN)Compilation successful!$(RESET)\n"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
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
