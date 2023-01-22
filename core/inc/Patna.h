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
		char 			completePath[100];
		ifstream 		inFile;
		ofstream        outFile;

		string      	ip, url, ipKey, urlKey;
		bool 			patnaFlag;

		void			startPatnaFun();
		uint64_t		readPatnaResolvedIp(char *fileName);

		void			dnsMapPatnaData(uint16_t appId, std::map<uint32_t, std::string> &barodaMap);
		void			updatePatnaResolvedIp(uint32_t ipr, string URL);
		bool			checkUrl(string url, uint16_t appID);

		std::map<uint32_t, std::string> patnaResolvedIpMap[10];
};

#endif /* DNSIDENTIFICATION_CORE_SRC_PATNA_H_ */
