/*
 * Surat.cpp
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#include "Surat.h"

Surat::Surat()
{
	index = 0;
	ipAdd = 0;
	counter = 0;
	suratIndex = 0;
	recordCount = 0;
	suratFlag = false;

	util = new utilities();
}

Surat::~Surat()
{
	delete(util);
}

void Surat::startSuratFun()
{
	suratFlag= false;
	completePath[0] = 0;

	outFile.open("SuratAppDnsData.csv", ios::app);

#ifdef _SURAT
	printf(" Start Surat Thread .. Time : %s \n", util->timerfunc());
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getSuratPath().c_str(), util->getFileName().c_str());
	uint64_t count = readSuratResolvedIp(completePath);

	printf(" Completed Dumping Surat DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf(" Size of Surat DNS Resolved Ip Map Index %02d = %02d....time: %s\n", mapIndex, suratResolvedIpMap[mapIndex].size(),util->timerfunc());

		/* Data Mapping */
		dnsMapSuratData(1, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(2, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(3, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(4, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(5, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(6, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(7, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(8, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(9, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(10, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(11, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(12, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(13, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(14, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(15, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(16, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(17, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(18, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(19, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(20, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(21, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(22, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(23, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(24, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(25, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(26, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(27, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(28, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(29, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(30, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(31, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(32, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(33, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(34, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(35, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(36, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(37, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(38, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(39, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(40, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(41, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(42, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(43, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(44, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(45, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(46, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(47, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(48, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(49, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(50, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(51, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(52, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(53, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(54, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(55, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(56, suratResolvedIpMap[mapIndex]);
		dnsMapSuratData(57, suratResolvedIpMap[mapIndex]);

			printf(" Remaining Size of Surat DNS Resolved Ip Map Index %02d = %02d....\n", mapIndex, suratResolvedIpMap[mapIndex].size());
	}

#endif

	outFile.close();
	suratFlag= true;
	bool printFlag = false;

	while(true)
	{
		sleep (5);

		if(suratFlag && !printFlag)
		{
			printf(" Surat Child Completed the Process ..\n");
			printFlag = true;
		}
	}
}

void Surat::dnsMapSuratData(uint16_t appID, std::map<uint32_t, std::string> &suratMap)
{
	for (auto it = suratMap.cbegin(), next_it = it; it != suratMap.cend(); it = next_it)
	{
		if(checkUrl(it->second, appID))
		{
			++next_it;
			suratMap.erase(it);
		}
		else
		{ ++next_it; }
	}
}

bool Surat::checkUrl(string url, uint16_t appID)
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


uint64_t Surat::readSuratResolvedIp(char *fileName)
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
			updateSuratResolvedIp(ipAdd , url);
			recordCount++;
		}
        inFile.close();
	}
	return recordCount;
}

void Surat::updateSuratResolvedIp(uint32_t ipr, string URL)
{ suratResolvedIpMap[ipr % 10][ipr] = URL; }


