
#* NAMING FORMAT
#* I = INCLUDE, C = CODE
#* G = GLOBAL, A = ASSEMBLER, C = COMPILER, M = MACHINE
#* DIR = DIRECTORY

IGDIR = ./libs/headers
CGDIR = ./libs/src

IADIR = ./SASM/headers
CADIR = ./SASM/src

ICDIR =	./O/headers
CCDIR =	./O/src

IMDIR = ./VM/headers
CMDIR = ./VM/src


_A_HEAD = 		sasm_assembler.h	sasm_instructions.c
_A_CODE = 		sasm_assembler.c	sasm_instructions.c		sasm_binding.c	sasm_ast.c	sasm_expressions.c	sasm_lexer.c	sasm_parser.c	sasm_tokenizer.c

_G_HEAD = 		univ_defs.h		 	univ_errors.h			univ_fileops.h 		univ_strings.h		univ_hashmap.h		univ_malloc.h
_G_CODE = 		univ_defs.c			univ_errors.c			univ_fileops.c 		univ_strings.c		univ_hashmap.c		univ_malloc.c

_C_HEAD =		O_lexer.h			O_parser.h				O_parse_tree.h		O_symbol_table.h	O_inter_codegen.h 	O_debug_help.h		O_inter_code_optimizer.h		O_token_types.h
_C_CODE = 		O_lexer.c			O_parser.c				O_parse_tree.c		O_symbol_table.c	O_inter_codegen.c	O_debug_help.c		O_inter_code_optimizer.c


_M_HEAD = 		virex_assembler.h	virex.h					virex_vmcalls.h		virex_tui.h
_M_CODE =		virex_assembler.c	virex.c					virex_vmcalls.c		virex_tui.c

G_HEAD = 		$(patsubst %, 		$(IGDIR)/%,				$(_G_HEAD))
G_CODE = 		$(patsubst %, 		$(CGDIR)/%,				$(_G_CODE))

A_HEAD = 		$(patsubst %, 		$(IADIR)/%,				$(_A_HEAD))
A_CODE = 		$(patsubst %, 		$(CADIR)/%,				$(_A_CODE))

C_HEAD =		$(patsubst %, 		$(ICDIR)/%,				$(_C_HEAD))
C_CODE = 		$(patsubst %, 		$(CCDIR)/%,				$(_C_CODE))

M_HEAD = 		$(patsubst %, 		$(IMDIR)/%,				$(_M_HEAD))
M_CODE =		$(patsubst %, 		$(CMDIR)/%,				$(_M_CODE))

.PHONY: clean
MAKEFLAGS += --no-print-directory


CC = gcc
CFLAGS = -O3 -Wall -Wextra -Werror -Wfatal-errors -Wswitch-enum -std=c2x -pedantic -lncursesw -I$(IGDIR) -I$(IADIR) -I$(ICDIR) -I$(IMDIR) 
LIBS =

sasm: 	SASM/sasm.c $(G_CODE) $(A_CODE)
		@$(CC) -o $@ $^   $(CFLAGS) $(LIBS)
		@echo  ""
		@echo  "SASM MADE SUCCESSFULLY"
		@echo  ""

occ:	O/occ.c  $(G_CODE) $(C_CODE) 
		@$(CC) -g -o $@ $^   $(CFLAGS) $(LIBS)
		@echo  ""
		@echo  "COMPILER MADE SUCCESSFULLY"
		@echo  ""

virex: 	VM/main.c $(G_CODE) $(M_CODE) $(A_CODE) $(C_CODE)
		@make occ
		@make sasm
	  	@$(CC) -o $@ $^   $(CFLAGS) $(LIBS)
		@echo  ""
		@echo  "VM MADE SUCCESSFULLY"
		@echo  ""

clean:
		@rm -f $(CGDIR)/*.o $(CADIR)/*.o $(CCDIR)/*.o main.o virex sasm occ
		@echo  ""
		@echo  "CLEANED ALL OBJECT FILES AND EXECUTABLES"
		@echo  ""
