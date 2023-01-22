/*
 * Rajkot1.cpp
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#include "Rajkot.h"

Rajkot::Rajkot()
{
	index = 0;
	ipAdd = 0;
	counter = 0;
	rajkotIndex = 0;
	recordCount = 0;
	rajkotFlag = false;

	util = new utilities();
}

Rajkot::~Rajkot()
{
	delete(util);
}

void Rajkot::startRajkotFun()
{
	rajkotFlag= false;
	completePath[0] = 0;

	outFile.open("RajkotAppDnsData.csv", ios::app);

#ifdef _RAJKOT
	printf(" Start Processing Rajkot Thread .. Time : %s \n", util->timerfunc());
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getRajkotPath().c_str(), util->getFileName().c_str());
	uint64_t count = readRajkotResolvedIp(completePath);

	printf(" Completed Dumping Rajkot DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf(" Size of Rajkot DNS Resolved Ip Map Index %02d = %02d....time: %s\n", mapIndex, rajkotResolvedIpMap[mapIndex].size(),util->timerfunc());

		/* Data Mapping */
		for(uint16_t appId = 1; appId <= 57; appId++)
		{
			dnsMapRajkotData(appId, rajkotResolvedIpMap[mapIndex]);
		}
		printf(" Remaining Size of Rajkot DNS Resolved Ip Map Index %02d = %02d....\n", mapIndex, rajkotResolvedIpMap[mapIndex].size());
	}

#endif

	outFile.close();
	rajkotFlag= true;
	bool printFlag = false;

	while(true)
	{
		sleep (5);

		if(rajkotFlag && !printFlag)
		{
			printf(" Rajkot Child Completed the Process ..\n");
			printFlag = true;
		}
	}
}

void Rajkot::dnsMapRajkotData(uint16_t appID, std::map<uint32_t, std::string> &rajkotMap)
{
	for (auto it =rajkotMap.cbegin(), next_it = it; it !=rajkotMap.cend(); it = next_it)
	{
		if(checkUrl(it->second, appID))
		{
			++next_it;
			rajkotMap.erase(it);
		}
		else
		{ ++next_it; }
	}
}

bool Rajkot::checkUrl(string url, uint16_t appID)
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

uint64_t Rajkot::readRajkotResolvedIp(char *fileName)
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
			updateRajkotResolvedIp(ipAdd , url);
			recordCount++;
		}
        inFile.close();
	}
	return recordCount;
}

void Rajkot::updateRajkotResolvedIp(uint32_t ipr, string URL)
{ rajkotResolvedIpMap[ipr % 10][ipr] = URL; }


