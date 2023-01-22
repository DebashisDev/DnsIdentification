/*
 * Hyderabad.cpp
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#include "Hyderabad.h"

Hyderabad::Hyderabad()
{
	index = 0;
	ipAdd = 0;
	counter = 0;
	hyderabadIndex = 0;
	recordCount = 0;
	hyderabadFlag = false;

	util = new utilities();
}

Hyderabad::~Hyderabad()
{
	delete(util);
}

void Hyderabad::startHyderabadFun()
{
	hyderabadFlag= false;
	completePath[0] = 0;

	outFile.open("HyderabadAppDnsData.csv", ios::app);

#ifdef _HYD
	printf(" Start Hyderabad Thread .. Time : %s \n", util->timerfunc());
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getHyderabadPath().c_str(), util->getFileName().c_str());
	uint64_t count = readHyderabadResolvedIp(completePath);

	printf(" Completed Dumping Hyderabad DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf(" Size of Hyderabad DNS Resolved Ip Map Index %02d = %02d....time: %s\n", mapIndex, hyderabadResolvedIpMap[mapIndex].size(),util->timerfunc());

		/* Data Mapping */
		for(uint16_t appId = 1; appId <= 57; appId++)
		{
			dnsMapHyderabadData(appId, hyderabadResolvedIpMap[mapIndex]);
		}
		printf(" Remaining Size of Hyderabad DNS Resolved Ip Map Index %02d = %02d....\n", mapIndex, hyderabadResolvedIpMap[mapIndex].size());
	}
#endif

	hyderabadFlag= true;

	outFile.close();
	bool printFlag = false;

	while(true)
	{
		sleep (5);

		if(hyderabadFlag && !printFlag)
		{
			printf(" Hyderabad Child Completed the Process ..\n");
			printFlag = true;
		}
	}
}

void Hyderabad::dnsMapHyderabadData(uint16_t appID, std::map<uint32_t, std::string> &hyderabadMap)
{
	for (auto it = hyderabadMap.cbegin(), next_it = it; it != hyderabadMap.cend(); it = next_it)
	{
		if(checkUrl(it->second, appID))
		{
			++next_it;
			hyderabadMap.erase(it);
		}
		else
		{ ++next_it; }
	}
}

bool Hyderabad::checkUrl(string url, uint16_t appID)
{
	for (auto it = util->keyWordMap[appID].cbegin(), next_it = it; it != util->keyWordMap[appID].cend(); it = next_it)
	{
		if(strstr(url.c_str(), it->second.c_str()))
		{
			outFile << url <<"| " << util->appId[appID] <<endl ;
			return true;
		}
		 ++next_it;
	}
	return false;
}

uint64_t Hyderabad::readHyderabadResolvedIp(char *fileName)
{
	string    line;
	inFile.open(fileName, ios::in);

	if(inFile.is_open())
	{
		while(getline(inFile,line))
		{
			index = line.find(",");

			ip = line.substr(0, index);
			url = line.substr(index+1);

			if(url.size() > 20)
				url.erase(0, (url.size() - 20));

			util->ipToLong((char *)ip.c_str() , &ipAdd);
			updateHyderabadResolvedIp(ipAdd , url);
			recordCount++;
		}
        inFile.close();
	}
	return recordCount;
}

void Hyderabad::updateHyderabadResolvedIp(uint32_t ipr, string URL)
{ hyderabadResolvedIpMap[ipr % 10][ipr] = URL; }


