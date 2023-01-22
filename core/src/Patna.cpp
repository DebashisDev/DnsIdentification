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
		dnsMapPatnaData(1, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(2, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(3, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(4, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(5, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(6, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(7, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(8, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(9, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(10, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(11, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(12, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(13, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(14, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(15, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(16, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(17, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(18, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(19, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(20, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(21, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(22, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(23, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(24, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(25, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(26, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(27, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(28, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(29, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(30, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(31, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(32, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(33, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(34, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(35, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(36, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(37, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(38, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(39, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(40, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(41, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(42, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(43, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(44, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(45, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(46, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(47, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(48, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(49, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(50, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(51, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(52, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(53, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(54, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(55, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(56, patnaResolvedIpMap[mapIndex]);
		dnsMapPatnaData(57, patnaResolvedIpMap[mapIndex]);

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


