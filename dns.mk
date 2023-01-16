#########################################################################
#																		#
# SCRIPT NAME	: probe.mk												#
# DESCRIPTION	: Include script for SpectaProbe						#
# DATE 			: 19-02-2016										    #
# AUTHOR		: Debashis.											    #
#																		#
# Copyright (c) 2016, Pinnacle Digital (P) Ltd. New-Delhi				# 
#########################################################################

GCC = g++ -g -O0 -g3 -Wall -std=c++11 -fPIC -Wno-deprecated -w

CFLAGS = -D_BARODA -D_RAJKOT -D_SURAT -D_PATNA -D_HYD -D_MT_SAFE -D_REENTRANT -D_POSIX_THREAD_SAFE_FUNCTIONS -D_GNU_SOURCE -D_PTHREADS -D_POSIX_PTHREAD_SEMANTICS -D_POSIX_C_SOURCE=199506L -D__EXTENSIONS__	

MAKE 		= make
RM			= rm

DNS_BIN			= ${DNS_ROOT}/bin

# SpectaProbe Directory

DNS_CORE		= ${DNS_ROOT}/core
DNS_SRC			= ${DNS_CORE}/src
DNS_INC			= ${DNS_CORE}/inc


DNS_INCLUDE 	= \
				-I${DNS_INC}
