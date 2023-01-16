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

	outFile.open("HyderabadAppDnsData.csv", ios::app);

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

			/* Data Mapping */
			dnsMapHyderabadData(util->YahooMail, 1,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Music, 2,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->CloudProvider, 3,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Stock, 4,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Yahoo, 5,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->MSN, 6,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Apple, 7,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Skype, 8,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Facebook, 9,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Whatsapp, 10,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Google, 11,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Youtube, 12,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Games, 13,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->NetFlix, 14,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Gmail, 15,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Hotmail, 16,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Microsoft, 17,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Office365, 18,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->LinkedIn, 19,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Webex, 20,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Viber, 21,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->SocialNetwork, 22,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->ECommerce, 23,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Travel, 24,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->FoodOrdering, 25,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Twitter, 26,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->FileSharing, 27,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Internet, 28,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->News, 29,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Dropbox, 30,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Browser, 31,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Sports, 32,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Bank, 33,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Akamai, 34,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->GoDaddy, 35,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Video, 36,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Truecaller, 37,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->ISP, 38,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->SpeedTest, 39,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->AmazonPrime, 40,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->ALTBalaji, 41,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->BigFlix, 42,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->ErosNow, 43,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Hotstar, 44,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->SonyLiv, 45,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Voot, 46,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->YouNow, 47,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Zee5, 48,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Jio, 49,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Instagram, 50,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->TIKTOK, 51,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->PUBG, 52,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Uploadhaven, 53,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->DisneyPlus, 54,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Zoom, 55,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Adult, 56,hyderabadResolvedIpMap[mapIndex]);
			dnsMapHyderabadData(util->Amazon, 57,hyderabadResolvedIpMap[mapIndex]);

			printf("Remaining Size of hyderabadResolvedIpMap Index %02d = %02d....\n", mapIndex, hyderabadResolvedIpMap[mapIndex].size());
	}

	hyderabadFlag= true;

#endif

	outFile.close();

	while(true)
	{
		sleep (5);

		if(hyderabadFlag)
		{
			printf("Hyderabad Child Completed the Process ..\n");
		}
	}
}

void Hyderabad::dnsMapHyderabadData(std::map<uint16_t, std::string> &appMap, uint16_t appID, std::map<uint32_t, std::string> &hyderabadMap)
{

	for (auto it = hyderabadMap.cbegin(), next_it = it; it != hyderabadMap.cend(); it = next_it)
	{
		if(checkUrl(appMap, it->second, appID))
		{
		 ++next_it;
		 hyderabadMap.erase(it);
		}
		else
		{
			 ++next_it;
		}
	}
}

bool Hyderabad::checkUrl(std::map<uint16_t, std::string> &appMap, string url, uint16_t appID)
{
	for (auto it = appMap.cbegin(), next_it = it; it != appMap.cend(); it = next_it)
	{
		hyderabadIndex = url.find(it->second);

		if(hyderabadIndex > 0)
		{
			outFile << url <<"," << util->appId[appID] <<endl ;
			return true;
		}
		 ++next_it;
	}
	return false;
}

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

			if(url.size() > 20)
				url.erase(0, (url.size() - 20));

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


