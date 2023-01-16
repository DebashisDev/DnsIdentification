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


#ifdef _RAJKOT
	printf(" Start Processing Rajkot Thread .. Time : %s \n", util->timerfunc());
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getRajkotPath().c_str(), util->getFileName().c_str());
	uint64_t count = readRajkotResolvedIp(completePath);

	printf("Completed Dumping Rajkot DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf("Size of rajkotResolvedIpMap Index %02d = %02d....time: %s\n", mapIndex, rajkotResolvedIpMap[mapIndex].size(),util->timerfunc());
		for(counter = 0; counter <= rajkotResolvedIpMap[mapIndex].size(); counter ++)
		{
			/* Data Mapping */
			dnsMapRajkotData(util->YahooMail, 1, mapIndex);
			dnsMapRajkotData(util->Music, 2, mapIndex);
			dnsMapRajkotData(util->CloudProvider, 3, mapIndex);
			dnsMapRajkotData(util->Stock, 4, mapIndex);
			dnsMapRajkotData(util->Yahoo, 5, mapIndex);
			dnsMapRajkotData(util->MSN, 6, mapIndex);
			dnsMapRajkotData(util->Apple, 7, mapIndex);
			dnsMapRajkotData(util->Skype, 8, mapIndex);
			dnsMapRajkotData(util->Facebook, 9, mapIndex);
			dnsMapRajkotData(util->Whatsapp, 10, mapIndex);
			dnsMapRajkotData(util->Google, 11, mapIndex);
			dnsMapRajkotData(util->Youtube, 12, mapIndex);
			dnsMapRajkotData(util->Games, 13, mapIndex);
			dnsMapRajkotData(util->NetFlix, 14, mapIndex);
			dnsMapRajkotData(util->Gmail, 15, mapIndex);
			dnsMapRajkotData(util->Hotmail, 16, mapIndex);
			dnsMapRajkotData(util->Microsoft, 17, mapIndex);
			dnsMapRajkotData(util->Office365, 18, mapIndex);
			dnsMapRajkotData(util->LinkedIn, 19, mapIndex);
			dnsMapRajkotData(util->Webex, 20, mapIndex);
			dnsMapRajkotData(util->Viber, 21, mapIndex);
			dnsMapRajkotData(util->SocialNetwork, 22, mapIndex);
			dnsMapRajkotData(util->ECommerce, 23, mapIndex);
			dnsMapRajkotData(util->Travel, 24, mapIndex);
			dnsMapRajkotData(util->FoodOrdering, 25, mapIndex);
			dnsMapRajkotData(util->Twitter, 26, mapIndex);
			dnsMapRajkotData(util->FileSharing, 27, mapIndex);
			dnsMapRajkotData(util->Internet, 28, mapIndex);
			dnsMapRajkotData(util->News, 29, mapIndex);
			dnsMapRajkotData(util->Dropbox, 30, mapIndex);
			dnsMapRajkotData(util->Browser, 31, mapIndex);
			dnsMapRajkotData(util->Sports, 32, mapIndex);
			dnsMapRajkotData(util->Bank, 33, mapIndex);
			dnsMapRajkotData(util->Akamai, 34, mapIndex);
			dnsMapRajkotData(util->GoDaddy, 35, mapIndex);
			dnsMapRajkotData(util->Video, 36, mapIndex);
			dnsMapRajkotData(util->Truecaller, 37, mapIndex);
			dnsMapRajkotData(util->ISP, 38, mapIndex);
			dnsMapRajkotData(util->SpeedTest, 39, mapIndex);
			dnsMapRajkotData(util->AmazonPrime, 40, mapIndex);
			dnsMapRajkotData(util->ALTBalaji, 41, mapIndex);
			dnsMapRajkotData(util->BigFlix, 42, mapIndex);
			dnsMapRajkotData(util->ErosNow, 43, mapIndex);
			dnsMapRajkotData(util->Hotstar, 44, mapIndex);
			dnsMapRajkotData(util->SonyLiv, 45, mapIndex);
			dnsMapRajkotData(util->Voot, 46, mapIndex);
			dnsMapRajkotData(util->YouNow, 47, mapIndex);
			dnsMapRajkotData(util->Zee5, 48, mapIndex);
			dnsMapRajkotData(util->Jio, 49, mapIndex);
			dnsMapRajkotData(util->Instagram, 50, mapIndex);
			dnsMapRajkotData(util->TIKTOK, 51, mapIndex);
			dnsMapRajkotData(util->PUBG, 52, mapIndex);
			dnsMapRajkotData(util->Uploadhaven, 53, mapIndex);
			dnsMapRajkotData(util->DisneyPlus, 54, mapIndex);
			dnsMapRajkotData(util->Zoom, 55, mapIndex);
			dnsMapRajkotData(util->Adult, 56, mapIndex);
			dnsMapRajkotData(util->Amazon, 57, mapIndex);
		}
	}

	for(uint16_t appCounter = 0; appCounter < 57; appCounter++)
	{
		printf(" App Id: %d| Count: %llu\n", appCounter, dnsLookUpRajkotData[appCounter].size());
	}
	rajkotFlag= true;
#endif

	while(true)
	{
		sleep (5);

		if(rajkotFlag)
		{
			printf("Rajkot Child Completed the Process ..\n");
		}
	}
}

bool Rajkot::dnsMapRajkotData(std::map<uint16_t, std::string> &appMap, uint16_t appID, uint16_t mapIndex)
{
	for (auto elem = rajkotResolvedIpMap[mapIndex].cbegin(), next_it = elem; elem != rajkotResolvedIpMap[mapIndex].cend(); elem = next_it)
	{
		for(auto elem1 : appMap)
		{
			rajkotIndex = elem->second.find(elem1.second);
			if(rajkotIndex > 0)
			{
				 updateRajkotMapData(elem->second, util->appId[appID], appID);
				 rajkotResolvedIpMap[mapIndex].erase(elem);
				 counter = 0;
				 rajkotIndex= 0;
				 return true;
			}
		}
		++next_it;
	}
	counter++;
	return false;
}

void Rajkot::updateRajkotMapData(string url , string keyword, uint16_t appID)
{ dnsLookUpRajkotData[appID][url] = appID; }

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


