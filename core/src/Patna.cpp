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
		for(counter = 0; counter <= patnaResolvedIpMap[mapIndex].size(); counter ++)
		{
			/* Data Mapping */
			dnsMapPatnaData(util->YahooMail, 1, mapIndex);
			dnsMapPatnaData(util->Music, 2, mapIndex);
			dnsMapPatnaData(util->CloudProvider, 3, mapIndex);
			dnsMapPatnaData(util->Stock, 4, mapIndex);
			dnsMapPatnaData(util->Yahoo, 5, mapIndex);
			dnsMapPatnaData(util->MSN, 6, mapIndex);
			dnsMapPatnaData(util->Apple, 7, mapIndex);
			dnsMapPatnaData(util->Skype, 8, mapIndex);
			dnsMapPatnaData(util->Facebook, 9, mapIndex);
			dnsMapPatnaData(util->Whatsapp, 10, mapIndex);
			dnsMapPatnaData(util->Google, 11, mapIndex);
			dnsMapPatnaData(util->Youtube, 12, mapIndex);
			dnsMapPatnaData(util->Games, 13, mapIndex);
			dnsMapPatnaData(util->NetFlix, 14, mapIndex);
			dnsMapPatnaData(util->Gmail, 15, mapIndex);
			dnsMapPatnaData(util->Hotmail, 16, mapIndex);
			dnsMapPatnaData(util->Microsoft, 17, mapIndex);
			dnsMapPatnaData(util->Office365, 18, mapIndex);
			dnsMapPatnaData(util->LinkedIn, 19, mapIndex);
			dnsMapPatnaData(util->Webex, 20, mapIndex);
			dnsMapPatnaData(util->Viber, 21, mapIndex);
			dnsMapPatnaData(util->SocialNetwork, 22, mapIndex);
			dnsMapPatnaData(util->ECommerce, 23, mapIndex);
			dnsMapPatnaData(util->Travel, 24, mapIndex);
			dnsMapPatnaData(util->FoodOrdering, 25, mapIndex);
			dnsMapPatnaData(util->Twitter, 26, mapIndex);
			dnsMapPatnaData(util->FileSharing, 27, mapIndex);
			dnsMapPatnaData(util->Internet, 28, mapIndex);
			dnsMapPatnaData(util->News, 29, mapIndex);
			dnsMapPatnaData(util->Dropbox, 30, mapIndex);
			dnsMapPatnaData(util->Browser, 31, mapIndex);
			dnsMapPatnaData(util->Sports, 32, mapIndex);
			dnsMapPatnaData(util->Bank, 33, mapIndex);
			dnsMapPatnaData(util->Akamai, 34, mapIndex);
			dnsMapPatnaData(util->GoDaddy, 35, mapIndex);
			dnsMapPatnaData(util->Video, 36, mapIndex);
			dnsMapPatnaData(util->Truecaller, 37, mapIndex);
			dnsMapPatnaData(util->ISP, 38, mapIndex);
			dnsMapPatnaData(util->SpeedTest, 39, mapIndex);
			dnsMapPatnaData(util->AmazonPrime, 40, mapIndex);
			dnsMapPatnaData(util->ALTBalaji, 41, mapIndex);
			dnsMapPatnaData(util->BigFlix, 42, mapIndex);
			dnsMapPatnaData(util->ErosNow, 43, mapIndex);
			dnsMapPatnaData(util->Hotstar, 44, mapIndex);
			dnsMapPatnaData(util->SonyLiv, 45, mapIndex);
			dnsMapPatnaData(util->Voot, 46, mapIndex);
			dnsMapPatnaData(util->YouNow, 47, mapIndex);
			dnsMapPatnaData(util->Zee5, 48, mapIndex);
			dnsMapPatnaData(util->Jio, 49, mapIndex);
			dnsMapPatnaData(util->Instagram, 50, mapIndex);
			dnsMapPatnaData(util->TIKTOK, 51, mapIndex);
			dnsMapPatnaData(util->PUBG, 52, mapIndex);
			dnsMapPatnaData(util->Uploadhaven, 53, mapIndex);
			dnsMapPatnaData(util->DisneyPlus, 54, mapIndex);
			dnsMapPatnaData(util->Zoom, 55, mapIndex);
			dnsMapPatnaData(util->Adult, 56, mapIndex);
			dnsMapPatnaData(util->Amazon, 57, mapIndex);
		}
	}

	for(uint16_t appCounter = 0; appCounter < 57; appCounter++)
	{
		printf(" App Id: %d| Count: %llu\n", appCounter, dnsLookUpPatnaData[appCounter].size());
	}

	patnaFlag= true;
#endif
	while(true)
	{
		sleep (5);

		if(patnaFlag)
		{
			printf("Patna Child Completed the Process ..\n");
		}
	}
}

bool Patna::dnsMapPatnaData(std::map<uint16_t, std::string> &appMap, uint16_t appID, uint16_t mapIndex)
{
	for (auto elem = patnaResolvedIpMap[mapIndex].cbegin(), next_it = elem; elem != patnaResolvedIpMap[mapIndex].cend(); elem = next_it)
	{
		for(auto elem1 : appMap)
		{
			patnaIndex = elem->second.find(elem1.second);
			if(patnaIndex > 0)
			{
				 updatePatnaMapData(elem->second, util->appId[appID], appID);
				 patnaResolvedIpMap[mapIndex].erase(elem);
				 counter = 0;
				 patnaIndex= 0;
				 return true;
			}
		}
		++next_it;
	}
	counter++;
	return false;
}

void Patna::updatePatnaMapData(string url , string keyword, uint16_t appID)
{ dnsLookUpPatnaData[appID][url] = appID; }

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


