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
			dnsMapBarodaData(1, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(2, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(3, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(4, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(5, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(6, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(7, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(8, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(9, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(10, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(11, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(12, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(13, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(14, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(15, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(16, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(17, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(18, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(19, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(20, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(21, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(22, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(23, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(24, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(25, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(26, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(27, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(28, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(29, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(30, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(31, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(32, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(33, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(34, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(35, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(36, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(37, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(38, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(39, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(40, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(41, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(42, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(43, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(44, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(45, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(46, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(47, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(48, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(49, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(50, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(51, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(52, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(53, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(54, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(55, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(56, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(57, barodaResolvedIpMap[mapIndex]);

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


