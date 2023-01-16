/*
 * Hyderabad.cpp
 *
 *  Created on: 09-Jan-2023
 *      Author: Admin
 */

#include "Hyderabad.h"

Hyderabad::Hyderabad()
{
	index = 0;
	ipAdd = 0;
	counter = 0;
	hyderabadIndex = 0;
	recordCount = 0;
	hyderabadFlag = false;

	util = new utilities();
}

Hyderabad::~Hyderabad()
{
	delete(util);
}

void Hyderabad::startHyderabadFun()
{
	hyderabadFlag= false;
	completePath[0] = 0;


#ifdef _HYD
	printf(" Start Processing Hyderabad Thread .. Time : %s \n", util->timerfunc());
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getHyderabadPath().c_str(), util->getFileName().c_str());
	uint64_t count = readHyderabadResolvedIp(completePath);

	printf("Completed Dumping Hyderabad DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf("Size of HyderabadResolvedIpMap Index %02d = %02d....time: %s\n", mapIndex, hyderabadResolvedIpMap[mapIndex].size(),util->timerfunc());
		for(counter = 0; counter <= hyderabadResolvedIpMap[mapIndex].size(); counter ++)
		{
			/* Data Mapping */
			dnsMapHyderabadData(util->YahooMail, 1, mapIndex);
			dnsMapHyderabadData(util->Music, 2, mapIndex);
			dnsMapHyderabadData(util->CloudProvider, 3, mapIndex);
			dnsMapHyderabadData(util->Stock, 4, mapIndex);
			dnsMapHyderabadData(util->Yahoo, 5, mapIndex);
			dnsMapHyderabadData(util->MSN, 6, mapIndex);
			dnsMapHyderabadData(util->Apple, 7, mapIndex);
			dnsMapHyderabadData(util->Skype, 8, mapIndex);
			dnsMapHyderabadData(util->Facebook, 9, mapIndex);
			dnsMapHyderabadData(util->Whatsapp, 10, mapIndex);
			dnsMapHyderabadData(util->Google, 11, mapIndex);
			dnsMapHyderabadData(util->Youtube, 12, mapIndex);
			dnsMapHyderabadData(util->Games, 13, mapIndex);
			dnsMapHyderabadData(util->NetFlix, 14, mapIndex);
			dnsMapHyderabadData(util->Gmail, 15, mapIndex);
			dnsMapHyderabadData(util->Hotmail, 16, mapIndex);
			dnsMapHyderabadData(util->Microsoft, 17, mapIndex);
			dnsMapHyderabadData(util->Office365, 18, mapIndex);
			dnsMapHyderabadData(util->LinkedIn, 19, mapIndex);
			dnsMapHyderabadData(util->Webex, 20, mapIndex);
			dnsMapHyderabadData(util->Viber, 21, mapIndex);
			dnsMapHyderabadData(util->SocialNetwork, 22, mapIndex);
			dnsMapHyderabadData(util->ECommerce, 23, mapIndex);
			dnsMapHyderabadData(util->Travel, 24, mapIndex);
			dnsMapHyderabadData(util->FoodOrdering, 25, mapIndex);
			dnsMapHyderabadData(util->Twitter, 26, mapIndex);
			dnsMapHyderabadData(util->FileSharing, 27, mapIndex);
			dnsMapHyderabadData(util->Internet, 28, mapIndex);
			dnsMapHyderabadData(util->News, 29, mapIndex);
			dnsMapHyderabadData(util->Dropbox, 30, mapIndex);
			dnsMapHyderabadData(util->Browser, 31, mapIndex);
			dnsMapHyderabadData(util->Sports, 32, mapIndex);
			dnsMapHyderabadData(util->Bank, 33, mapIndex);
			dnsMapHyderabadData(util->Akamai, 34, mapIndex);
			dnsMapHyderabadData(util->GoDaddy, 35, mapIndex);
			dnsMapHyderabadData(util->Video, 36, mapIndex);
			dnsMapHyderabadData(util->Truecaller, 37, mapIndex);
			dnsMapHyderabadData(util->ISP, 38, mapIndex);
			dnsMapHyderabadData(util->SpeedTest, 39, mapIndex);
			dnsMapHyderabadData(util->AmazonPrime, 40, mapIndex);
			dnsMapHyderabadData(util->ALTBalaji, 41, mapIndex);
			dnsMapHyderabadData(util->BigFlix, 42, mapIndex);
			dnsMapHyderabadData(util->ErosNow, 43, mapIndex);
			dnsMapHyderabadData(util->Hotstar, 44, mapIndex);
			dnsMapHyderabadData(util->SonyLiv, 45, mapIndex);
			dnsMapHyderabadData(util->Voot, 46, mapIndex);
			dnsMapHyderabadData(util->YouNow, 47, mapIndex);
			dnsMapHyderabadData(util->Zee5, 48, mapIndex);
			dnsMapHyderabadData(util->Jio, 49, mapIndex);
			dnsMapHyderabadData(util->Instagram, 50, mapIndex);
			dnsMapHyderabadData(util->TIKTOK, 51, mapIndex);
			dnsMapHyderabadData(util->PUBG, 52, mapIndex);
			dnsMapHyderabadData(util->Uploadhaven, 53, mapIndex);
			dnsMapHyderabadData(util->DisneyPlus, 54, mapIndex);
			dnsMapHyderabadData(util->Zoom, 55, mapIndex);
			dnsMapHyderabadData(util->Adult, 56, mapIndex);
			dnsMapHyderabadData(util->Amazon, 57, mapIndex);
		}
	}

	for(uint16_t appCounter = 0; appCounter < 57; appCounter++)
	{
		printf(" App Id: %d| Count: %llu\n", appCounter, dnsLookUpHyderabadData[appCounter].size());
	}
	hyderabadFlag= true;

#endif

	while(true)
	{
		sleep (5);

		if(hyderabadFlag)
		{
			printf("Hyderabad Child Completed the Process ..\n");
		}
	}
}

bool Hyderabad::dnsMapHyderabadData(std::map<uint16_t, std::string> &appMap, uint16_t appID, uint16_t mapIndex)
{
	for (auto elem = hyderabadResolvedIpMap[mapIndex].cbegin(), next_it = elem; elem != hyderabadResolvedIpMap[mapIndex].cend(); elem = next_it)
	{
		for(auto elem1 : appMap)
		{
			hyderabadIndex = elem->second.find(elem1.second);
			if(hyderabadIndex > 0)
			{
				 updateHyderabadMapData(elem->second, util->appId[appID], appID);
				 hyderabadResolvedIpMap[mapIndex].erase(elem);
				 counter = 0;
				 hyderabadIndex= 0;
				 return true;
			}
		}
		++next_it;
	}
	counter++;
	return false;
}
void Hyderabad::updateHyderabadMapData(string url , string keyword, uint16_t appID)
{ dnsLookUpHyderabadData[appID][url] = appID; }

uint64_t Hyderabad::readHyderabadResolvedIp(char *fileName)
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
			updateHyderabadResolvedIp(ipAdd , url);
			recordCount++;
		}
        inFile.close();
	}
	return recordCount;
}

void Hyderabad::updateHyderabadResolvedIp(uint32_t ipr, string URL)
{ hyderabadResolvedIpMap[ipr % 10][ipr] = URL; }


