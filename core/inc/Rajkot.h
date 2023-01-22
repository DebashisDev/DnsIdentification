/*
 * Rajkot1.h
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#ifndef DNSIDENTIFICATION_CORE_SRC_RAJKOT_H_
#define DNSIDENTIFICATION_CORE_SRC_RAJKOT_H_

#include "global.h"
#include "utilities.h"

using namespace std;

class Rajkot
{
	public:
		Rajkot();
		~Rajkot();

		utilities		*util;

		uint8_t 		index;
		uint32_t    	ipAdd;
		uint32_t 		counter;
		uint8_t			rajkotIndex;
		uint64_t		recordCount;

		pthread_t 		rajkotThr;
		char 			completePath[100];
		ifstream 		inFile;
		ofstream        outFile;

		string      	ip, url, ipKey, urlKey;
		bool 			rajkotFlag;

		void			startRajkotFun();
		uint64_t		readRajkotResolvedIp(char *fileName);
		void			dnsMapRajkotData(uint16_t appId, std::map<uint32_t, std::string> &barodaMap);
		void			updateRajkotResolvedIp(uint32_t ipr, string URL);
		bool			checkUrl(string url, uint16_t appID);

		std::map<uint32_t, std::string> rajkotResolvedIpMap[10];
};

#endif /* DNSIDENTIFICATION_CORE_SRC_RAJKOT1_H_ */
