#########################################################################
#																		#
# SCRIPT NAME	: Makefile												#
# DESCRIPTION	: To build all .cpp files								#
# DATE 			: 19-02-2016										    #
# AUTHOR		: Debashis.											    #
#																		#
# Copyright (c) 2016, Pinnacle Digital (P) Ltd. New-Delhi				# 
#########################################################################

include ${DNS_ROOT}/dns.mk
OBJS= \
	Baroda.o 	\
	main.o 		\
	utilities.o	\
	Rajkot.o	\
	Surat.o	\
	Patna.o	\
	Hyderabad.o
			
	

all:${OBJS}

.cpp.o:

	${GCC} ${CFLAGS} -I/usr/include ${DNS_INCLUDE} -c $< 

clean:
	${RM} ${OBJS}
