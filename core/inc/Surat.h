/*
 * Surat.h
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#ifndef DNSIDENTIFICATION_CORE_SRC_SURAT_H_
#define DNSIDENTIFICATION_CORE_SRC_SURAT_H_

#include "global.h"
#include "utilities.h"

using namespace std;

class Surat
{
	public:
		Surat();
		~Surat();

		utilities		*util;

		uint8_t 		index;
		uint32_t    	ipAdd;
		uint32_t 		counter;
		uint8_t			suratIndex;
		uint64_t		recordCount;

		pthread_t 		suratThr;
		char 			completePath[50];
		ifstream 		inFile;
		ofstream        outFile;

		string      	ip, url, ipKey, urlKey;
		bool 			suratFlag;

		void			startSuratFun();
		uint64_t		readSuratResolvedIp(char *fileName);
		void			dnsMapSuratData(std::map<uint16_t, std::string> &appMap, uint16_t appId, std::map<uint32_t, std::string> &barodaMap);
		void			updateSuratResolvedIp(uint32_t ipr, string URL);
		bool			checkUrl(std::map<uint16_t, std::string> &appMap, string url, uint16_t appID);


		std::map<uint32_t, std::string> suratResolvedIpMap[10];
		std::map<std::string, uint16_t> dnsLookUpSuratData[57];
};

#endif /* DNSIDENTIFICATION_CORE_SRC_SURAT_H_ */
