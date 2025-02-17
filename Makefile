##
## EPITECH PROJECT, 2024
## B-YEP-400-PAR-4-1-zappy-thibaud.cathala
## File description:
## Makefile
##

SERVER_PATH		=	./my_zappy_server/
GUI_PATH		=	./my_zappy_gui/
AI_PATH			=	./my_zappy_ai/

all:
	cd $(SERVER_PATH) && $(MAKE)
	cd $(GUI_PATH) && $(MAKE)
	cd $(AI_PATH) && $(MAKE)

clean:
	cd $(SERVER_PATH) && $(MAKE) clean
	cd $(GUI_PATH) && $(MAKE) clean
	cd $(AI_PATH) && $(MAKE) clean

fclean:
	cd $(SERVER_PATH) && $(MAKE) fclean
	cd $(GUI_PATH) && $(MAKE) fclean
	cd $(AI_PATH) && $(MAKE) fclean
	rm -f $(shell find . -name "*.gcno")
	rm -f $(shell find . -name "*.gcda")

re:
	cd $(SERVER_PATH) && $(MAKE) re
	cd $(GUI_PATH) && $(MAKE) re
	cd $(AI_PATH) && $(MAKE) re

unit_tests:
	cd $(SERVER_PATH) && $(MAKE) unit_tests

tests_run:
	cd $(SERVER_PATH) && $(MAKE) tests_run

code_analyse:
	cd $(SERVER_PATH) && $(MAKE) code_analyse
	cd $(GUI_PATH) && $(MAKE) code_analyse
	cd $(AI_PATH) && $(MAKE) code_analyse

zappy_server:
	cd $(SERVER_PATH) && $(MAKE) re

zappy_gui:
	cd $(GUI_PATH) && $(MAKE) re

zappy_ai:
	cd $(AI_PATH) && $(MAKE) re

.PHONY: all clean fclean re unit_tests tests_run code_analyse \
	zappy_server zappy_gui zappy_ai
