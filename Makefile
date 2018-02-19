# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nthibaud <nthibaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 11:00:56 by nthibaud          #+#    #+#              #
#    Updated: 2018/02/07 16:07:46 by nthibaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rt

CC		=	gcc

CHEADERS = -I ./inc/
CXMLFLAGS = -I /usr/include/libxml2
CSDL2 = -I ./lib/frameworks/SDL2.framework/Headers
CSDL2_IMAGE = -I ./lib/frameworks/SDL2_image.framework/Headers
CSDL2_TTFF = -I ./lib/frameworks/SDL2_ttf.framework/Headers
CSDL2FLAGS = $(CSDL2) $(CSDL2_IMAGE) $(CSDL2_TTFF)
CFLAGS = $(CHEADERS) $(CSDL2FLAGS) $(CXMLFLAGS)
#CFLAGS = -Werror -Wextra -Wall $(CHEADERS) $(CSDL2FLAGS) $(CXMLFLAGS)
LDXMLFLAGS = -L/usr/local/lib -lxml2
LDSDL2 = -framework SDL2
LDSDL2_IMAGE = -framework SDL2_image
LDSDL2_TTF = -framework SDL2_ttf
LDSDL2FLAGS = $(LDSDL2) $(LDSDL2_IMAGE) $(LDSDL2_TTF) -F ./lib/frameworks
LDLOADER_PATH = -rpath @loader_path/lib/frameworks
LDFLAGS = $(LDLOADER_PATH) $(LDSDL2FLAGS) $(LDXMLFLAGS)

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc
TYPE_DIR =	\
			basic\
			basic/vector_handle\
			basic/matrix_handle\
			basic/debug\
			subroutines\
			subroutines/intersections\
			subroutines/lights\
			subroutines/parser\

SRC =	\
		basic/ft_abs.c\
		basic/ft_atoi.c\
		basic/ft_atof.c\
		basic/ft_biggest_fl.c\
		basic/ft_close_win.c\
		basic/ft_descriminent.c\
		basic/ft_dot_product.c\
		basic/ft_double_to_int.c\
		basic/ft_double_eq.c\
		basic/ft_event_sdlquit.c\
		basic/ft_exit.c\
		basic/ft_handle_events.c\
		basic/ft_handle_windowevent.c\
		basic/ft_hey.c\
		basic/ft_intlen.c\
		basic/ft_is_any_string.c\
		basic/ft_isnbr.c\
		basic/ft_isspace.c\
		basic/ft_itoa.c\
		basic/ft_putchar.c\
		basic/ft_putpixel.c\
		basic/ft_putstr.c\
		basic/ft_putunlckpixel.c\
		basic/ft_rgb_to_int.c\
		basic/ft_double_3d_to_int.c\
		basic/ft_int_to_double_3d.c\
		basic/ft_str_replace.c\
		basic/ft_strcat.c\
		basic/ft_strcmp.c\
		basic/ft_strcpy.c\
		basic/ft_strdup.c\
		basic/ft_strjoin.c\
		basic/ft_strlen.c\
		basic/ft_strrev.c\
		basic/ft_strupcase.c\
		basic/ft_unit_vect.c\
		basic/ft_vect_norm.c\
		basic/ft_xml_rd_res.c\
		basic/ft_fmax.c\
		basic/ft_clamp.c\
		basic/ft_doubleswap.c\
		basic/ft_floatswap.c\
		basic/ft_vectorswap.c\
		\
		basic/vector_handle/v_normalize.c\
		basic/vector_handle/v_cross.c\
		basic/vector_handle/v_div_by_nb.c\
		basic/vector_handle/v_div_by_v.c\
		basic/vector_handle/v_dot.c\
		basic/vector_handle/v_len.c\
		basic/vector_handle/v_mult_by_nb.c\
		basic/vector_handle/v_mult_by_v.c\
		basic/vector_handle/v_norm.c\
		basic/vector_handle/v_sub_a_by_b.c\
		basic/vector_handle/v_sum.c\
		\
		basic/matrix_handle/m4_allocate.c\
		basic/matrix_handle/m4_fill.c\
		basic/matrix_handle/m4_mult_m4.c\
		basic/matrix_handle/m4_mult_v.c\
		basic/matrix_handle/m4_set_as_default.c\
		\
		basic/debug/debug.c\
		\
		subroutines/sub_blit_render.c\
		subroutines/sub_calc_cam_vects.c\
		subroutines/sub_create_file.c\
		subroutines/sub_create_xml.c\
		subroutines/sub_create_render_window.c\
		subroutines/sub_draw_image_editor.c\
		subroutines/sub_fullrender_end.c\
		subroutines/sub_handle_keyboard.c\
		subroutines/sub_texture_sphere.c\
		subroutines/sub_texture_cone_cyl.c\
		subroutines/sub_texture_change.c\
		subroutines/sub_texture_change_perlin.c\
		subroutines/sub_move_cam_dir.c\
		subroutines/sub_move_cam_pos.c\
		subroutines/sub_put_fps.c\
		subroutines/sub_put_percent.c\
		subroutines/sub_calc_pix_vect.c\
		subroutines/sub_threads.c\
		\
		subroutines/parser/sub_basic_arg_test.c\
		subroutines/parser/sub_check_extension.c\
		subroutines/parser/sub_xml_malloc_lights_and_objects.c\
		subroutines/parser/sub_xml_read_light.c\
		subroutines/parser/sub_xml_read_object.c\
		subroutines/parser/sub_xml_read_camera.c\
		subroutines/parser/sub_parser_xml.c\
		subroutines/parser/sub_read_hex.c\
		subroutines/parser/sub_read_pos.c\
		subroutines/parser/sub_read_texture.c\
		subroutines/parser/xmlngc.c\
		subroutines/parser/default_object.c\
		\
		subroutines/intersections/sub_inter_plane.c\
		subroutines/intersections/sub_inter_disk.c\
		subroutines/intersections/sub_inter_sphere.c\
		subroutines/intersections/sub_inter_cone.c\
		subroutines/intersections/sub_inter_cylinder.c\
		subroutines/intersections/sub_inter_triangle.c\
		subroutines/intersections/sub_inter_quadrangle.c\
		subroutines/intersections/sub_inter_pyramid.c\
		subroutines/intersections/sub_inter_objects.c\
		subroutines/intersections/sub_inter_paraboloid.c\
		subroutines/intersections/sub_inter_ellipsoid.c\
		subroutines/intersections/sub_inter_hyperboloid.c\
		\
		subroutines/lights/sub_light_primary_ray.c\
		subroutines/lights/sub_light_options.c\
		\
		editor_start.c\
		main.c\
		options_win.c\
		parser.c\
		raytrace_editor.c\
		raytrace_fullrender.c\
		full_render_init.c\
		full_render_from_edit.c\
		full_render_start.c\
		full_render_threads.c

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
		@$(CC) -o $(NAME) $(LDFLAGS) $(addprefix $(OBJ_DIR)/, $(OBJ))

$(OBJ_DIR):
		@echo "$(CRED)No obj file found, creating one$(CRESET)     \c"
		@rm -rf $(OBJ_DIR)
		@mkdir $(OBJ_DIR)
		@mkdir $(addprefix $(OBJ_DIR)/, $(TYPE_DIR))
		@echo "$(ECH_SUCCESS)\n"

CMT_READ_MSG = $(shell echo "\\033[34mCommit message:\\033[1m\\033[36m")

git:
		$(eval VERSION=$(shell echo $$(($(VERSION)+1))))
		$(shell echo $$(($(VERSION))) > ./version)
		@echo "\\033[34mcleaning libft...\\033[0m"
		@echo $(CMT_READ_MSG)
		@echo "\\033[92mSuccessfully cleaned libft\\033[0m\n\n\\033[34mPushing to git repository...\\033[0m"
		@git add *
		@read -p "$(CMT_READ_MSG)" msg; \
		echo "\\033[0m"; \
		git commit -m "LibftV4 - Ver.$(VERSION) b.$(BUILD) - $$msg"
		@git push
		@echo "\\033[92mSuccesfully pushed LibftV4 to git repository\\033[0m"

clean:
		@$(RM) -r $(OBJ_DIR)
		@echo "$(CBLUE)Removing obj file$(CRESET)\n"

fclean:		clean
		@$(RM) $(NAME)
		@echo "$(CBLUE)Removing $(CLBLUE)$(NAME)$(CRESET)\n"

re:		fclean	all

.PHONY:		all		git	clean	fclean	re	start
