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

	printf("Completed Dumping Rajkot DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf("Size of rajkotResolvedIpMap Index %02d = %02d....time: %s\n", mapIndex, rajkotResolvedIpMap[mapIndex].size(),util->timerfunc());

			/* Data Mapping */
			dnsMapRajkotData(util->YahooMail, 1,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Music, 2,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->CloudProvider, 3,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Stock, 4,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Yahoo, 5,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->MSN, 6,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Apple, 7,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Skype, 8,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Facebook, 9,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Whatsapp, 10,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Google, 11,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Youtube, 12,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Games, 13,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->NetFlix, 14,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Gmail, 15,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Hotmail, 16,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Microsoft, 17,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Office365, 18,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->LinkedIn, 19,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Webex, 20,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Viber, 21,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->SocialNetwork, 22,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->ECommerce, 23,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Travel, 24,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->FoodOrdering, 25,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Twitter, 26,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->FileSharing, 27,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Internet, 28,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->News, 29,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Dropbox, 30,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Browser, 31,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Sports, 32,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Bank, 33,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Akamai, 34,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->GoDaddy, 35,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Video, 36,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Truecaller, 37,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->ISP, 38,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->SpeedTest, 39,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->AmazonPrime, 40,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->ALTBalaji, 41,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->BigFlix, 42,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->ErosNow, 43,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Hotstar, 44,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->SonyLiv, 45,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Voot, 46,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->YouNow, 47,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Zee5, 48,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Jio, 49,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Instagram, 50,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->TIKTOK, 51,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->PUBG, 52,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Uploadhaven, 53,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->DisneyPlus, 54,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Zoom, 55,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Adult, 56,rajkotResolvedIpMap[mapIndex]);
			dnsMapRajkotData(util->Amazon, 57,rajkotResolvedIpMap[mapIndex]);

			printf("Remaining Size of rajkotResolvedIpMap Index %02d = %02d....\n", mapIndex, rajkotResolvedIpMap[mapIndex].size());
	}

	rajkotFlag= true;
#endif

	outFile.close();

	while(true)
	{
		sleep (5);

		if(rajkotFlag)
		{
			printf("Rajkot Child Completed the Process ..\n");
		}
	}
}

void Rajkot::dnsMapRajkotData(std::map<uint16_t, std::string> &appMap, uint16_t appID, std::map<uint32_t, std::string> &rajkotMap)
{

	for (auto it =rajkotMap.cbegin(), next_it = it; it !=rajkotMap.cend(); it = next_it)
	{
		if(checkUrl(appMap, it->second, appID))
		{
			++next_it;
			rajkotMap.erase(it);
		}
		else
		{
			 ++next_it;
		}
	}
}

bool Rajkot::checkUrl(std::map<uint16_t, std::string> &appMap, string url, uint16_t appID)
{
	for (auto it = appMap.cbegin(), next_it = it; it != appMap.cend(); it = next_it)
	{
		if(strstr(url.c_str(), it->second.c_str()))
		{
			outFile << url <<"," << util->appId[appID] <<endl ;
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


