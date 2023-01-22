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
		dnsMapRajkotData(1, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(2, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(3, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(4, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(5, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(6, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(7, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(8, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(9, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(10, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(11, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(12, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(13, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(14, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(15, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(16, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(17, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(18, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(19, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(20, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(21, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(22, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(23, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(24, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(25, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(26, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(27, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(28, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(29, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(30, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(31, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(32, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(33, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(34, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(35, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(36, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(37, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(38, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(39, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(40, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(41, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(42, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(43, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(44, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(45, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(46, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(47, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(48, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(49, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(50, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(51, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(52, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(53, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(54, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(55, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(56, rajkotResolvedIpMap[mapIndex]);
		dnsMapRajkotData(57, rajkotResolvedIpMap[mapIndex]);

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


