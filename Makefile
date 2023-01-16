#########################################################################
#																		#
# SCRIPT NAME	: Makefile												#
# DESCRIPTION	: To build the SpectaProbe along with user librarys		#
# DATE 			: 19-02-2016										    #
# AUTHOR		: Debashis.											    #
#																		#
# To make GN probe : make gnclean; make gnprobe 						#
# To make FL probe : make flclean; make flprobe 						#
# Copyright (c) 2016, Pinnacle Digital (P) Ltd. New-Delhi.				# 
#########################################################################

# Include all the header directories.
include ${DNS_ROOT}/dns.mk

DNS_DIRS = 	\
		${DNS_SRC}

#########################################################################
# SCP Platform and Platform Library File Name							#
#########################################################################
DNS_TARGET = ${DNS_BIN}/dns

#System Library
PCAPLIB 	= pcap
THRLIB 		= pthread

LIBS 		= -lm -ldl -l$(PCAPLIB) -l$(THRLIB)

#########################################################################
# For SpectaProbe
#########################################################################
dns:
	echo ${DNS_DIRS}
	for i in ${DNS_DIRS}; \
	do \
		(cd $$i; \
		echo "*******" $$i; \
		${MAKE} all \
		); \
	done

	${GCC} -o ${DNS_TARGET} \
				${DNS_SRC}/*.o 	\
				${LIBS}

#########################################################################

clean:
	for i in ${DNS_DIRS}; \
	do \
		(cd $$i; \
		echo $$i; \
		${MAKE} clean \
		); \
	done

	${RM} ${DNS_TARGET}
	
