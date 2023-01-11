G++						=	g++
###############################################
PART0_PATH 				= 	./part0_medic
PART0_SRC_PATH			=	./part0_medic/src
PART0_TST_PATH			=	./part0_medic/tests
PART0_INC_PATH			=	./part0_medic/include
NAME_MEDIC				=	Skat
PART0_SRC				=	$(PART0_SRC_PATH)/Skat.cpp

PART0_SRC_TEST			=	$(PART0_TST_PATH)/$(NAME_MEDIC)_test.cpp
TEST_NAME_MEDIC 		= 	test_$(NAME_MEDIC)

###############################################
CORE_PATH				=	./core

NAME					=	a.out
TEST_NAME 				= 	test_$(NAME)

INCFLAGS				+=	-I $(PART0_INC_PATH) 

CPPFLAGS				+= 	-Wall -Wextra -Werror $(INCFLAGS)#-W -std=c++1z

SRCS 					= 	$(PART0_SRC) \
							$(CORE_PATH)/main.cpp

OBJS					=	$(SRCS:.cpp=.o)
CLEAN					=	clean
FCLEAN					=	fclean

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							$(G++) $(OBJS) $(CPPFLAGS)

RM						=	rm -rf

clean					:
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(PART0_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART1_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART2_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART3_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART4_TST_PATH)
# @$(MAKE) $(CLEAN) -C $(PART5_TST_PATH)


fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART0_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART1_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART2_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART2_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART3_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART3_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART4_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART4_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART5_TST_PATH)
# @$(MAKE) $(FCLEAN) -C $(PART5_PATH)

re						: 	fclean all

part0 					: 	fclean
							@$(MAKE) -C $(PART0_PATH)
							$(PART0_PATH)/$(NAME_MEDIC)

# part1 					: 	fclean
# 							@$(MAKE) -C $(PART1_PATH)
# 							$(PART1_PATH)/$(NAME_BORG)

# part2 					: 	fclean
# 							@$(MAKE) -C $(PART2_PATH)
# 							$(PART2_PATH)/$(NAME_MOVE)

# part3 					: 	fclean
# 							@$(MAKE) -C $(PART3_PATH)
# 							$(PART3_PATH)/$(NAME_WAR)

# part4 					: 	fclean
# 							@$(MAKE) -C $(PART4_PATH)
# 							$(PART4_PATH)/$(NAME_COMMANDER)

tests_run_part0			:	fclean
							@$(MAKE) -C $(PART0_TST_PATH)
							$(PART0_TST_PATH)/$(TEST_NAME_MEDIC)

# tests_run_part1			:	fclean
# 							@$(MAKE) -C $(PART1_TST_PATH)
# 							$(PART1_TST_PATH)/$(TEST_NAME_BORG)

# tests_run_part2			:	fclean
# 							@$(MAKE) -C $(PART2_TST_PATH)
# 							$(PART2_TST_PATH)/$(TEST_NAME_MOVE)

# tests_run_part3			:	fclean
# 							@$(MAKE) -C $(PART3_TST_PATH)
# 							$(PART3_TST_PATH)/$(TEST_NAME_WAR)

# tests_run_part4			:	fclean
# 							@$(MAKE) -C $(PART4_TST_PATH)
# 							$(PART4_TST_PATH)/$(TEST_NAME_COMMANDER)

tests_run				:	fclean
							@$(MAKE) tests_run_part0
# @$(MAKE) tests_run_part1
# @$(MAKE) tests_run_part2
# @$(MAKE) tests_run_part3
# @$(MAKE) tests_run_part4


.PHONY					: 	all clean fclean re part0 tests_run_part0 tests_run
