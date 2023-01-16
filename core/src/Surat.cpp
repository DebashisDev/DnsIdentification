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

			/* Data Mapping */
			dnsMapSuratData(util->YahooMail, 1,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Music, 2,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->CloudProvider, 3,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Stock, 4,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Yahoo, 5,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->MSN, 6,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Apple, 7,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Skype, 8,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Facebook, 9,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Whatsapp, 10,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Google, 11,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Youtube, 12,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Games, 13,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->NetFlix, 14,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Gmail, 15,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Hotmail, 16,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Microsoft, 17,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Office365, 18,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->LinkedIn, 19,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Webex, 20,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Viber, 21,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->SocialNetwork, 22,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->ECommerce, 23,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Travel, 24,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->FoodOrdering, 25,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Twitter, 26,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->FileSharing, 27,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Internet, 28,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->News, 29,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Dropbox, 30,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Browser, 31,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Sports, 32,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Bank, 33,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Akamai, 34,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->GoDaddy, 35,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Video, 36,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Truecaller, 37,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->ISP, 38,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->SpeedTest, 39,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->AmazonPrime, 40,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->ALTBalaji, 41,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->BigFlix, 42,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->ErosNow, 43,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Hotstar, 44,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->SonyLiv, 45,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Voot, 46,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->YouNow, 47,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Zee5, 48,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Jio, 49,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Instagram, 50,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->TIKTOK, 51,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->PUBG, 52,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Uploadhaven, 53,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->DisneyPlus, 54,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Zoom, 55,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Adult, 56,suratResolvedIpMap[mapIndex]);
			dnsMapSuratData(util->Amazon, 57,suratResolvedIpMap[mapIndex]);

			printf("Remaining Size of suratResolvedIpMap Index %02d = %02d....\n", mapIndex, suratResolvedIpMap[mapIndex].size());
	}

	suratFlag= true;
#endif

	outFile.close();

	while(true)
	{
		sleep (5);

		if(suratFlag)
		{
			printf("Surat Child Completed the Process ..\n");
		}
	}
}

void Surat::dnsMapSuratData(std::map<uint16_t, std::string> &appMap, uint16_t appID, std::map<uint32_t, std::string> &suratMap)
{

	for (auto it = suratMap.cbegin(), next_it = it; it != suratMap.cend(); it = next_it)
	{
		if(checkUrl(appMap, it->second, appID))
		{
		 ++next_it;
		 suratMap.erase(it);
		}
		else
		{
			 ++next_it;
		}
	}
}

bool Surat::checkUrl(std::map<uint16_t, std::string> &appMap, string url, uint16_t appID)
{
	for (auto it = appMap.cbegin(), next_it = it; it != appMap.cend(); it = next_it)
	{
		suratIndex = url.find(it->second);

		if(suratIndex > 0)
		{
			outFile << url <<"," << util->appId[appID] <<endl ;
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


