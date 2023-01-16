/*
 * Baroda.h
 *
 *  Created on: 05-Jan-2023
 *      Author: Admin
 */

#ifndef CORE_INC_BARODA_H_
#define CORE_INC_BARODA_H_

#include "global.h"
#include "utilities.h"

using namespace std;

class Baroda
{
	public:
		Baroda();
		~Baroda();

		utilities		*util;

		uint8_t 		index;
		uint32_t    	ipAdd;
		uint32_t 		counter;
		uint8_t			barodaIndex;
		uint64_t		recordCount;
		pthread_t 		barodaThr;
		char 			completePath[50];
		ifstream 		inFile1;
		ofstream        outFile;

		string      	ip, url, ipKey, urlKey;
		bool 			barodaFlag;

		void			startBarodaFun();
		uint64_t		readBarodaResolvedIp(char *fileName);
		void			dnsMapBarodaData(std::map<uint16_t, std::string> &appMap, uint16_t appId, std::map<uint32_t, std::string> &barodaMap);
		void			updateBarodaResolvedIp(uint32_t ipr, string URL);
		bool			checkUrl(std::map<uint16_t, std::string> &appMap, string url, uint16_t appID);

		std::map<uint32_t, std::string> barodaResolvedIpMap[10];

};



#endif /* CORE_INC_BARODA_H_ */
