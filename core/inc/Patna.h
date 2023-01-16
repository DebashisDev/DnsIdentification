/*
 * Patna.h
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#ifndef DNSIDENTIFICATION_CORE_SRC_PATNA_H_
#define DNSIDENTIFICATION_CORE_SRC_PATNA_H_

#include "global.h"
#include "utilities.h"

using namespace std;

class Patna
{
	public:
		Patna();
		~Patna();

		utilities		*util;

		uint8_t 		index;
		uint32_t    	ipAdd;
		uint32_t 		counter;
		uint8_t			patnaIndex;
		uint64_t		recordCount;

		pthread_t 		patnaThr;
		char 			completePath[50];
		ifstream 		inFile;
		ofstream        outFile;

		string      	ip, url, ipKey, urlKey;
		bool 			patnaFlag;

		void			startPatnaFun();
		uint64_t		readPatnaResolvedIp(char *fileName);
		bool			dnsMapPatnaData(std::map<uint16_t, std::string> &appMap, uint16_t id, uint16_t mapIndex);
		void			updatePatnaResolvedIp(uint32_t ipr, string URL);
		void			updatePatnaMapData(string url , string keyword, uint16_t appId);

		std::map<uint32_t, std::string> patnaResolvedIpMap[10];
		std::map<std::string, uint16_t> dnsLookUpPatnaData[57];
};

#endif /* DNSIDENTIFICATION_CORE_SRC_PATNA_H_ */
