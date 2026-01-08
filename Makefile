###############################################
# Makefile for global wireless comm. exercice #
# Author: TekMath                         	  #
# Date: 2025-01-09                            #
###############################################

MODULATION_SIMULATION_SRC = modulation_simulation/

all: modulation_simulation

modulation_simulation:
	$(MAKE) -C $(MODULATION_SIMULATION_SRC)

clean:
	$(MAKE) -C $(MODULATION_SIMULATION_SRC) clean

fclean:
	$(MAKE) -C $(MODULATION_SIMULATION_SRC) fclean

.PHONY: all modulation_simulation clean fclean
