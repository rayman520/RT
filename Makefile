NAME = rt

CC		=	gcc

SDLFLAGS = -I/usr/local/include/SDL2 -D_THREAD_SAFE -I/usr/include/libxml2
SDL_LIB = -L/usr/local/lib -lSDL2 -lSDL2_ttf -lxml2
CFLAGS	=	-Werror -Wextra -Wall -Weverything -Ofast $(SDLFLAGS)

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
TYPE_DIR =	\
			basic\
			subroutines\

SRC =	\
		basic/ft_atoi.c\
		basic/ft_biggest_fl.c\
		basic/ft_close_win.c\
		basic/ft_event_sdlquit.c\
		basic/ft_exit.c\
		basic/ft_handle_events.c\
		basic/ft_handle_windowevent.c\
		basic/ft_hey.c\
		basic/ft_intlen.c\
		basic/ft_itoa.c\
		basic/ft_putchar.c\
		basic/ft_putpixel.c\
		basic/ft_putstr.c\
		basic/ft_putunlckpixel.c\
		basic/ft_strcat.c\
		basic/ft_strcmp.c\
		basic/ft_strcpy.c\
		basic/ft_strdup.c\
		basic/ft_strjoin.c\
		basic/ft_strlen.c\
		basic/ft_strrev.c\
		basic/ft_strupcase.c\
		basic/ft_xml_rd_res.c\
		subroutines/sub_basic_arg_test.c\
		subroutines/sub_blit_render.c\
		subroutines/sub_check_extension.c\
		subroutines/sub_create_file.c\
		subroutines/sub_create_render_window.c\
		subroutines/sub_create_xml.c\
		subroutines/sub_fullrender_end.c\
		subroutines/sub_xml_malloc_lights_and_objects.c\
		subroutines/sub_xml_read_light.c\
		subroutines/sub_xml_read_object.c\
		subroutines/sub_parser_xml.c\
		subroutines/sub_put_percent.c\
		subroutines/sub_read_pos.c\
		editor_start.c\
		full_render.c\
		main.c\
		parser.c\

OBJ = $(SRC:.c=.o)

SRC_COUNT = $(words $(SRC))

OBJP =	$(addprefix $(OBJ_DIR)/, $(OBJ))
INCP =	$(foreach dir, $(INC_DIR), -I$(dir))

ACTUAL_SRC = 0
PERCENT = 0

VERSION = $(shell cat ./version)
BUILD = $(shell cat ./build)

# Colors
CRESET=		"\\033[0m"
CRED=		"\\033[31m"
CGREEN=		"\\033[32m"
CLGREEN=	"\\033[92m"
CBLUE=		"\\033[34m"
CLBLUE=		"\\033[94m"
CYELLOW=	"\\033[33m"
CLYELLOW=	"\\033[93m"

all:	start

start:
	@echo "\
$(CRED)     -===============================:=========================\
=======-\n\
                              $(CGREEN)linking $(CLGREEN)$(NAME)\n\
$(CRED)     -===============================:=========================\
=======-$(CRESET)\n"
	@$(MAKE) $(NAME)
	@echo "\n\
$(CRED)     -===============================:=========================\
=======-\n\
                   $(CLGREEN)$(NAME) Build.$(BUILD) $(CGREEN)successfully linked\n\
$(CRED)     -===============================:=========================\
=======-$(CRESET)\n"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
		@echo "$(CBLUE)Compiling $(CLBLUE)$(foreach v,$^,$(shell printf '%-40s' $(v)))\c"
		@$(CC) $(CFLAGS) -c -o $@ $^ $(INCP)
		$(eval ACTUAL_SRC=$(shell echo $$(($(ACTUAL_SRC)+1))))
		@echo "$(ECH_SUCCESS)   $(CLYELLOW)$(ACTUAL_SRC)$(CYELLOW) / $(SRC_COUNT)$(CRESET)\c"
		$(eval PERCENT=$(shell echo $$((($(ACTUAL_SRC) * 100) / ($(SRC_COUNT))))))
		@echo "  $(CYELLOW)( $(CLYELLOW)$(PERCENT)$(CYELLOW)% )$(CRESET)\c"
		@echo "\n\c"

$(NAME):	$(OBJ_DIR) $(OBJP)
		$(eval BUILD=$(shell echo $$(($(BUILD)+1))))
		$(shell echo $$(($(BUILD))) > ./build)
		@$(CC) -o $(NAME) $(SDL_LIB) $(CFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ))

$(OBJ_DIR):
		@echo "$(CRED)No obj file found, creating one$(CRESET)     \c"
		@rm -rf $(OBJ_DIR)
		@mkdir $(OBJ_DIR)
		@mkdir $(addprefix $(OBJ_DIR)/, $(TYPE_DIR))
		@echo "$(ECH_SUCCESS)\n"

git:
		$(eval VERSION=$(shell echo $$(($(VERSION)+1))))
		$(shell echo $$(($(VERSION))) > ./version)
		bash ~/code/perso/shell_scripts/fclean.sh
		rm -rf renders/*.bmp
		git add *
		git commit -m "RT - Ver.$(VERSION) Build.$(BUILD)"
		git push

clean:
		@$(RM) -r $(OBJ_DIR)
		@echo "$(CBLUE)Removing obj file$(CRESET)\n"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(CBLUE)Removing $(CLBLUE)$(NAME)$(CRESET)\n"

re:		fclean	all

.PHONY:		all		git	clean	fclean	re	start
