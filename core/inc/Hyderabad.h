/*
 * Hyderabad.h
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#ifndef DNSIDENTIFICATION_CORE_SRC_HYDERABAD_H_
#define DNSIDENTIFICATION_CORE_SRC_HYDERABAD_H_

#include "global.h"
#include "utilities.h"

using namespace std;

class Hyderabad
{
	public:
		Hyderabad();
		~Hyderabad();

		utilities		*util;

		uint8_t 		index;
		uint32_t    	ipAdd;
		uint32_t 		counter;
		uint8_t			hyderabadIndex;
		uint64_t		recordCount;

		pthread_t 		hyderabadThr;
		char 			completePath[100];
		ifstream 		inFile;
		ofstream        outFile;

		string      	ip, url, ipKey, urlKey;
		bool 			hyderabadFlag;

		void			startHyderabadFun();
		uint64_t		readHyderabadResolvedIp(char *fileName);
		void			dnsMapHyderabadData(uint16_t appId, std::map<uint32_t, std::string> &barodaMap);
		void			updateHyderabadResolvedIp(uint32_t ipr, string URL);
		bool			checkUrl(string url, uint16_t appID);

		std::map<uint32_t, std::string> hyderabadResolvedIpMap[10];
};

#endif /* DNSIDENTIFICATION_CORE_SRC_HYDERABAD_H_ */
