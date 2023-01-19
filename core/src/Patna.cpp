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
	printf(" Start Processing Patna Thread .. Time : %s \n", util->timerfunc());
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getPatnaPath().c_str(), util->getFileName().c_str());
	uint64_t count = readPatnaResolvedIp(completePath);

	printf("Completed Dumping Patna DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf("Size of PatnaResolvedIpMap Index %02d = %02d....time: %s\n", mapIndex, patnaResolvedIpMap[mapIndex].size(),util->timerfunc());

			/* Data Mapping */
			dnsMapPatnaData(util->YahooMail, 1, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Music, 2, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->CloudProvider, 3, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Stock, 4, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Yahoo, 5, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->MSN, 6, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Apple, 7, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Skype, 8, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Facebook, 9, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Whatsapp, 10, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Google, 11, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Youtube, 12, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Games, 13, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->NetFlix, 14, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Gmail, 15, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Hotmail, 16, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Microsoft, 17, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Office365, 18, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->LinkedIn, 19, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Webex, 20, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Viber, 21, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->SocialNetwork, 22, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->ECommerce, 23, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Travel, 24, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->FoodOrdering, 25, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Twitter, 26, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->FileSharing, 27, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Internet, 28, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->News, 29, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Dropbox, 30, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Browser, 31, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Sports, 32, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Bank, 33, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Akamai, 34, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->GoDaddy, 35, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Video, 36, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Truecaller, 37, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->ISP, 38, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->SpeedTest, 39, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->AmazonPrime, 40, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->ALTBalaji, 41, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->BigFlix, 42, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->ErosNow, 43, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Hotstar, 44, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->SonyLiv, 45, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Voot, 46, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->YouNow, 47, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Zee5, 48, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Jio, 49, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Instagram, 50, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->TIKTOK, 51, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->PUBG, 52, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Uploadhaven, 53, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->DisneyPlus, 54, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Zoom, 55, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Adult, 56, patnaResolvedIpMap[mapIndex]);
			dnsMapPatnaData(util->Amazon, 57, patnaResolvedIpMap[mapIndex]);

			printf("Remaining Size of patnaResolvedIpMap Index %02d = %02d....\n", mapIndex, patnaResolvedIpMap[mapIndex].size());
	}

	patnaFlag= true;
#endif

	outFile.close();

	while(true)
	{
		sleep (5);

		if(patnaFlag)
		{
			printf("Patna Child Completed the Process ..\n");
		}
	}
}

void Patna::dnsMapPatnaData(std::map<uint16_t, std::string> &appMap, uint16_t appID, std::map<uint32_t, std::string> &patnaMap)
{
	for (auto it = patnaMap.cbegin(), next_it = it; it != patnaMap.cend(); it = next_it)
	{
		if(checkUrl(appMap, it->second, appID))
		{
		 ++next_it;
		 patnaMap.erase(it);
		}
		else
		{
			 ++next_it;
		}
	}
}

bool Patna::checkUrl(std::map<uint16_t, std::string> &appMap, string url, uint16_t appID)
{
	for (auto it = appMap.cbegin(), next_it = it; it != appMap.cend(); it = next_it)
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


