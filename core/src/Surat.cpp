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


#ifdef _SURAT
	printf(" Start Processing Surat Thread .. Time : %s \n", util->timerfunc());
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	sprintf(completePath,"%s/%s", util->getSuratPath().c_str(), util->getFileName().c_str());
	uint64_t count = readSuratResolvedIp(completePath);

	printf("Completed Dumping Surat DNS Resolved Ips with count : %llu ..time: %s\n", count, util->timerfunc());
	recordCount = 0;

	for(uint16_t mapIndex = 0; mapIndex <= 9; mapIndex++)
	{
		printf("Size of SuratResolvedIpMap Index %02d = %02d....time: %s\n", mapIndex, suratResolvedIpMap[mapIndex].size(),util->timerfunc());
		for(counter = 0; counter <= suratResolvedIpMap[mapIndex].size(); counter ++)
		{
			/* Data Mapping */
			dnsMapSuratData(util->YahooMail, 1, mapIndex);
			dnsMapSuratData(util->Music, 2, mapIndex);
			dnsMapSuratData(util->CloudProvider, 3, mapIndex);
			dnsMapSuratData(util->Stock, 4, mapIndex);
			dnsMapSuratData(util->Yahoo, 5, mapIndex);
			dnsMapSuratData(util->MSN, 6, mapIndex);
			dnsMapSuratData(util->Apple, 7, mapIndex);
			dnsMapSuratData(util->Skype, 8, mapIndex);
			dnsMapSuratData(util->Facebook, 9, mapIndex);
			dnsMapSuratData(util->Whatsapp, 10, mapIndex);
			dnsMapSuratData(util->Google, 11, mapIndex);
			dnsMapSuratData(util->Youtube, 12, mapIndex);
			dnsMapSuratData(util->Games, 13, mapIndex);
			dnsMapSuratData(util->NetFlix, 14, mapIndex);
			dnsMapSuratData(util->Gmail, 15, mapIndex);
			dnsMapSuratData(util->Hotmail, 16, mapIndex);
			dnsMapSuratData(util->Microsoft, 17, mapIndex);
			dnsMapSuratData(util->Office365, 18, mapIndex);
			dnsMapSuratData(util->LinkedIn, 19, mapIndex);
			dnsMapSuratData(util->Webex, 20, mapIndex);
			dnsMapSuratData(util->Viber, 21, mapIndex);
			dnsMapSuratData(util->SocialNetwork, 22, mapIndex);
			dnsMapSuratData(util->ECommerce, 23, mapIndex);
			dnsMapSuratData(util->Travel, 24, mapIndex);
			dnsMapSuratData(util->FoodOrdering, 25, mapIndex);
			dnsMapSuratData(util->Twitter, 26, mapIndex);
			dnsMapSuratData(util->FileSharing, 27, mapIndex);
			dnsMapSuratData(util->Internet, 28, mapIndex);
			dnsMapSuratData(util->News, 29, mapIndex);
			dnsMapSuratData(util->Dropbox, 30, mapIndex);
			dnsMapSuratData(util->Browser, 31, mapIndex);
			dnsMapSuratData(util->Sports, 32, mapIndex);
			dnsMapSuratData(util->Bank, 33, mapIndex);
			dnsMapSuratData(util->Akamai, 34, mapIndex);
			dnsMapSuratData(util->GoDaddy, 35, mapIndex);
			dnsMapSuratData(util->Video, 36, mapIndex);
			dnsMapSuratData(util->Truecaller, 37, mapIndex);
			dnsMapSuratData(util->ISP, 38, mapIndex);
			dnsMapSuratData(util->SpeedTest, 39, mapIndex);
			dnsMapSuratData(util->AmazonPrime, 40, mapIndex);
			dnsMapSuratData(util->ALTBalaji, 41, mapIndex);
			dnsMapSuratData(util->BigFlix, 42, mapIndex);
			dnsMapSuratData(util->ErosNow, 43, mapIndex);
			dnsMapSuratData(util->Hotstar, 44, mapIndex);
			dnsMapSuratData(util->SonyLiv, 45, mapIndex);
			dnsMapSuratData(util->Voot, 46, mapIndex);
			dnsMapSuratData(util->YouNow, 47, mapIndex);
			dnsMapSuratData(util->Zee5, 48, mapIndex);
			dnsMapSuratData(util->Jio, 49, mapIndex);
			dnsMapSuratData(util->Instagram, 50, mapIndex);
			dnsMapSuratData(util->TIKTOK, 51, mapIndex);
			dnsMapSuratData(util->PUBG, 52, mapIndex);
			dnsMapSuratData(util->Uploadhaven, 53, mapIndex);
			dnsMapSuratData(util->DisneyPlus, 54, mapIndex);
			dnsMapSuratData(util->Zoom, 55, mapIndex);
			dnsMapSuratData(util->Adult, 56, mapIndex);
			dnsMapSuratData(util->Amazon, 57, mapIndex);
		}
	}

	for(uint16_t appCounter = 0; appCounter < 57; appCounter++)
	{
		printf(" App Id: %d| Count: %llu\n", appCounter, dnsLookUpSuratData[appCounter].size());
	}
	suratFlag= true;
#endif

	while(true)
	{
		sleep (5);

		if(suratFlag)
		{
			printf("Surat Child Completed the Process ..\n");
		}
	}
}

bool Surat::dnsMapSuratData(std::map<uint16_t, std::string> &appMap, uint16_t appID, uint16_t mapIndex)
{
	for (auto elem = suratResolvedIpMap[mapIndex].cbegin(), next_it = elem; elem != suratResolvedIpMap[mapIndex].cend(); elem = next_it)
	{
		for(auto elem1 : appMap)
		{
			suratIndex = elem->second.find(elem1.second);
			if(suratIndex > 0)
			{
				 updateSuratMapData(elem->second, util->appId[appID], appID);
				 suratResolvedIpMap[mapIndex].erase(elem);
				 counter = 0;
				 suratIndex= 0;
				 return true;
			}
		}
		++next_it;
	}
	counter++;
	return false;
}

void Surat::updateSuratMapData(string url , string keyword, uint16_t appID)
{ dnsLookUpSuratData[appID][url] = appID; }

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


