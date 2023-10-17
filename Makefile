NAME	=	ft_libc.a

HEADERS	=	$(shell find inc -type f)

HEAD_PATHS	=	-I./inc

SRC_DIR		=	src

SRCS	:=	$(shell find ${SRC_DIR} -type f | sed -e 's/${SRC_DIR}\///')

SRC_SUBDIRS := $(shell find ${SRC_DIR} -type d  | sed -e 's/${SRC_DIR}\///' | grep -v ${SRC_DIR})

OBJS_DIR	=	objs

OBJS_SDIR	=	$(addprefix $(OBJS_DIR)/, $(SRC_SUBDIRS))

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

RM		=	rm -f

ifdef DEBUG
	CFLAGS := -g
else
	CFLAGS := -Wall -Werror -Wextra
endif

BOLD	= \033[1m
BLACK	= \033[30;1m
RED		= \033[31;1m
BLUE	= \033[34;1m
GREEN	= \033[32;1m
CYAN	= \033[36;1m
RESET	= \033[0m

all: ${NAME}

${NAME}: $(OBJS_DIR) ${OBJS}
	@ar rc ${NAME} ${OBJS}
	@echo "$(BOLD)$(GREEN)ft_libc created!$(RESET)"

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEAD_PATHS)
	@echo "$(BOLD)$(CYAN)$(notdir $<)\t\t$(GREEN)[OK]$(RESET)"

$(OBJS_DIR):
	@mkdir -p $@ $(OBJS_SDIR)

clean:
	@$(RM) -r $(OBJS_DIR)
	@echo "❌ $(RED)OBJS FILES$(RESET)"

fclean:	clean
	@${RM} ${NAME}
	@echo "❌ $(RED)LIB$(RESET)"

re: fclean ${NAME}

.PHONY: all clean fclean re
