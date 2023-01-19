/*
 * Dns.cpp
 *
 *  Created on: 05-Jan-2023
 *      Author: Admin
 */

#include "Baroda.h"

Baroda::Baroda()
{
	index = 0;
	ipAdd = 0;
	counter = 0;
	barodaIndex = 0;
	recordCount = 0;
	barodaFlag = false;

	util = new utilities();
}

Baroda::~Baroda()
{
	delete(util);
}

void Baroda::startBarodaFun()
{
	barodaFlag= false;
	completePath[0] = 0;

	outFile.open("BarodaAppDnsData.csv", ios::app);

#ifdef _BARODA
	printf("Start Processing Baroda Thread .. Time : %s \n", util->timerfunc());

	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getBarodaPath().c_str(), util->getFileName().c_str());
	uint64_t count = readBarodaResolvedIp(completePath);

	printf("Completed Dumping Baroda DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf("Size of barodaResolvedIpMap Index %02d = %02d....time: %s\n", mapIndex, barodaResolvedIpMap[mapIndex].size(),util->timerfunc());

			/* Data Mapping */
			dnsMapBarodaData(util->YahooMail, 1, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Music, 2, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->CloudProvider, 3, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Stock, 4, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Yahoo, 5, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->MSN, 6, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Apple, 7, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Skype, 8, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Facebook, 9, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Whatsapp, 10, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Google, 11, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Youtube, 12, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Games, 13, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->NetFlix, 14, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Gmail, 15, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Hotmail, 16, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Microsoft, 17, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Office365, 18, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->LinkedIn, 19, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Webex, 20, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Viber, 21, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->SocialNetwork, 22, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->ECommerce, 23, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Travel, 24, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->FoodOrdering, 25, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Twitter, 26, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->FileSharing, 27, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Internet, 28, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->News, 29, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Dropbox, 30, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Browser, 31, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Sports, 32, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Bank, 33, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Akamai, 34, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->GoDaddy, 35, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Video, 36, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Truecaller, 37, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->ISP, 38, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->SpeedTest, 39, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->AmazonPrime, 40, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->ALTBalaji, 41, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->BigFlix, 42, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->ErosNow, 43, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Hotstar, 44, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->SonyLiv, 45, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Voot, 46, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->YouNow, 47, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Zee5, 48, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Jio, 49, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Instagram, 50, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->TIKTOK, 51, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->PUBG, 52, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Uploadhaven, 53, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->DisneyPlus, 54, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Zoom, 55, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Adult, 56, barodaResolvedIpMap[mapIndex]);
			dnsMapBarodaData(util->Amazon, 57, barodaResolvedIpMap[mapIndex]);

			printf("Remaining Size of barodaResolvedIpMap Index %02d = %02d....\n", mapIndex, barodaResolvedIpMap[mapIndex].size());
	}


	barodaFlag= true;
#endif

	outFile.close();
	while(true)
	{
		sleep (50);

		if(barodaFlag)
		{
			printf("Baroda Child Completed the Process ..\n");
		}
	}
}

void Baroda::dnsMapBarodaData(std::map<uint16_t, std::string> &appMap, uint16_t appID, std::map<uint32_t, std::string> &barodaMap)
{

	for (auto it = barodaMap.cbegin(), next_it = it; it != barodaMap.cend(); it = next_it)
	{
		if(checkUrl(appMap, it->second, appID))
		{
		 ++next_it;
		 barodaMap.erase(it);
		}
		else
		{
			 ++next_it;
		}
	}
}

bool Baroda::checkUrl(std::map<uint16_t, std::string> &appMap, string url, uint16_t appID)
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

uint64_t Baroda::readBarodaResolvedIp(char *fileName)
{
	uint16_t	urlLen = 50;
	string    line;
	inFile1.open(fileName, ios::in);

	if(inFile1.is_open())
	{
		while(getline(inFile1,line))
		{
			index = line.find(",");

			ip = line.substr(0, index);
			url = line.substr(index+1);

			util->ipToLong((char *)ip.c_str() , &ipAdd);
			updateBarodaResolvedIp(ipAdd , url);
			recordCount++;
		}
        inFile1.close();
	}
	return recordCount;
}

void Baroda::updateBarodaResolvedIp(uint32_t ipr, string URL)
{ barodaResolvedIpMap[ipr % 10][ipr] = URL; }


