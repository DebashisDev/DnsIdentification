/*
 * Patna.cpp
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#include "Patna.h"

Patna::Patna()
{
	index = 0;
	ipAdd = 0;
	counter = 0;
	patnaIndex = 0;
	recordCount = 0;
	patnaFlag = false;

	util = new utilities();
}

Patna::~Patna()
{
	delete(util);
}

void Patna::startPatnaFun()
{
	patnaFlag= false;
	completePath[0] = 0;

	outFile.open("PatnaAppDnsData.csv", ios::app);

#ifdef _PATNA
	printf(" Start Patna Thread .. Time : %s \n", util->timerfunc());
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getPatnaPath().c_str(), util->getFileName().c_str());
	uint64_t count = readPatnaResolvedIp(completePath);

	printf(" Completed Dumping Patna DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf(" Size of Patna DNS Resolved Ip Map Index %02d = %02d....time: %s\n", mapIndex, patnaResolvedIpMap[mapIndex].size(),util->timerfunc());

		/* Data Mapping */
		for(uint16_t appId = 1; appId <= 57; appId++)
		{
			dnsMapPatnaData(appId, patnaResolvedIpMap[mapIndex]);
		}
		printf(" Remaining Size of Patna DNS Resolved Ip Map Index %02d = %02d....\n", mapIndex, patnaResolvedIpMap[mapIndex].size());
	}

#endif

	patnaFlag= true;
	outFile.close();

	bool printFlag = false;

	while(true)
	{
		sleep (5);

		if(patnaFlag && !printFlag)
		{
			printf(" Patna Child Completed the Process ..\n");
			printFlag = true;
		}
	}
}

void Patna::dnsMapPatnaData(uint16_t appID, std::map<uint32_t, std::string> &patnaMap)
{
	for (auto it = patnaMap.cbegin(), next_it = it; it != patnaMap.cend(); it = next_it)
	{
		if(checkUrl(it->second, appID))
		{
			++next_it;
			patnaMap.erase(it);
		}
		else
		{ ++next_it; }
	}
}

bool Patna::checkUrl(string url, uint16_t appID)
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

uint64_t Patna::readPatnaResolvedIp(char *fileName)
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
			updatePatnaResolvedIp(ipAdd , url);
			recordCount++;
		}
        inFile.close();
	}
	return recordCount;
}

void Patna::updatePatnaResolvedIp(uint32_t ipr, string URL)
{ patnaResolvedIpMap[ipr % 10][ipr] = URL; }


