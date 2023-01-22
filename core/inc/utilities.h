/*
 * utilities.h
 *
 *  Created on: 6 Jan 2023
 *      Author: debas
 */

#ifndef DNSIDENTIFICATION_CORE_SRC_UTILITIES_H_
#define DNSIDENTIFICATION_CORE_SRC_UTILITIES_H_

#include "global.h"

using namespace std;

class utilities
{
	public:
		utilities();
		~utilities();

		ifstream 	fp;
		timeval 	curTime;
		char 		timeStr[50];
		string 		Key, Value;

		string		dnsFileName;
		string		barodaDnsPath;
		string		getFileName();
		string		getBarodaPath();
		uint16_t 	Baroda_Cpu_Core = 0;

		string 		rajkotDnsPath;
		string 		getRajkotPath();
		uint16_t 	Rajkot_Cpu_Core = 0;

		string 		patnaDnsPath;
		string 		getPatnaPath();
		uint16_t 	Surat_Cpu_Core = 0;

		string 		suratDnsPath;
		string		getSuratPath();
		uint16_t 	Patna_Cpu_Core = 0;

		string		hyderabadDnsPath;
		string 		getHyderabadPath();
		uint16_t	Hyd_Cpu_Core = 0;

		void 		openDnsKeyFile(char *fileName);
		void 		pinThread(pthread_t th, uint16_t i);
		char* 		timerfunc();
		void 		readKeyWord();
		void 		closeDnsKeyFile();
		void 		populateAppId();
		uint32_t 	ipToLong(char *ipt, uint32_t *plong);

		std::map<uint16_t, std::string> appId;

		std::map<uint16_t, map<uint16_t, std::string> > keyWordMap;
};

#endif /* DNSIDENTIFICATION_CORE_SRC_UTILITIES_H_ */
