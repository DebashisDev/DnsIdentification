/*
 * Dns.cpp
 *
 *  Created on: 05-Jan-2023
 *      Author: Admin
 */

#include "Baroda.h"

Baroda::Baroda()
{
	index = 0;
	ipAdd = 0;
	counter = 0;
	barodaIndex = 0;
	recordCount = 0;
	barodaFlag = false;

	util = new utilities();
}

Baroda::~Baroda()
{
	delete(util);
}

void Baroda::startBarodaFun()
{
	barodaFlag= false;
	completePath[0] = 0;

	outFile.open("BarodaAppDnsData.csv", ios::app);

#ifdef _BARODA
	printf(" Start Baroda Thread .. Time : %s \n", util->timerfunc());

	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getBarodaPath().c_str(), util->getFileName().c_str());
	uint64_t count = readBarodaResolvedIp(completePath);

	printf(" Completed Dumping Baroda DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf(" Size of Baroda DNS Resolved Ip Map Index %02d = %02d....time: %s\n", mapIndex, barodaResolvedIpMap[mapIndex].size(),util->timerfunc());

		/* Data Mapping */
		for(uint16_t appId = 1; appId <= MAX_APPLICATIONS; appId++)
			dnsMapBarodaData(appId, barodaResolvedIpMap[mapIndex]);

		printf(" Remaining  Size of Baroda DNS Resolved Ip Map Index %02d = %02d....\n", mapIndex, barodaResolvedIpMap[mapIndex].size());
	}
#endif

	outFile.close();
	barodaFlag= true;
	bool printFlag = false;

	while(true)
	{
		sleep (50);

		if(barodaFlag && !printFlag)
		{
			printf(" Baroda Child Completed the Process ..\n");
			printFlag = true;
		}
	}
}

void Baroda::dnsMapBarodaData(uint16_t appID, std::map<uint32_t, std::string> &barodaMap)
{
	for (auto it = barodaMap.cbegin(), next_it = it; it != barodaMap.cend(); it = next_it)
	{
		if(checkUrl(it->second, appID))
		{
			++next_it;
			barodaMap.erase(it);
		}
		else
		{ ++next_it; }
	}
}

bool Baroda::checkUrl(string url, uint16_t appID)
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

uint64_t Baroda::readBarodaResolvedIp(char *fileName)
{
	uint16_t	urlLen = 50;
	string    line;
	inFile1.open(fileName, ios::in);

	if(inFile1.is_open())
	{
		while(getline(inFile1,line))
		{
			index = line.find(",");

			ip = line.substr(0, index);
			url = line.substr(index+1);

			util->ipToLong((char *)ip.c_str() , &ipAdd);
			updateBarodaResolvedIp(ipAdd , url);
			recordCount++;
		}
        inFile1.close();
	}
	return recordCount;
}

void Baroda::updateBarodaResolvedIp(uint32_t ipr, string URL)
{ barodaResolvedIpMap[ipr % 10][ipr] = URL; }


