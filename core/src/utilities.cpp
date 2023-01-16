/*
 * utilities.cpp
 *
 *  Created on: 6 Jan 2023
 *      Author: debas
 */

#include "utilities.h"

utilities::utilities()
{
	timeStr[0] = 0;

}

utilities::~utilities()
{ }

string utilities::getFileName()
{ return dnsFileName; }

string utilities::getBarodaPath()
{ return barodaDnsPath; }

string utilities::getRajkotPath()
{ return rajkotDnsPath; }

string utilities::getPatnaPath()
{ return patnaDnsPath; }

string  utilities::getSuratPath()
{ return suratDnsPath; }

string  utilities::getHyderabadPath()
{ return hyderabadDnsPath; }

void utilities::openDnsKeyFile(char *fileName)
{
	char probeConfigBaseDir[100];
	char *probeConfigDir;
	char *probeRootEnv;

	char *config = getenv("DNS_CONF");

	sprintf(probeConfigBaseDir, "%s/%s", config, fileName);
	fp.open(probeConfigBaseDir);


	if(fp.fail())
	{
		printf("  Error in Dns Key File : %s\n", probeConfigBaseDir);
		exit(1);
	}
}

void utilities::closeDnsKeyFile()
{
	fp.close();
}

char* utilities::timerfunc()
{
        struct tm *now_tm;
        gettimeofday(&curTime, NULL);
        now_tm = localtime(&curTime.tv_sec);

        sprintf(timeStr, "%02d:%02d:%02d", now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec);
        return timeStr;
}

void utilities::populateAppId()
{
	appId[1] 	= "YahooMail";
	appId[2] 	= "Music";
	appId[3] 	= "CloudProvider";
	appId[4] 	= "Stock";
	appId[5] 	= "Yahoo";
	appId[6] 	= "MSN";
	appId[7] 	= "Apple";
	appId[8] 	= "Skype";
	appId[9] 	= "Facebook";
	appId[10] 	= "Whatsapp";
	appId[11] 	= "Google";
	appId[12] 	= "Youtube";
	appId[13] 	= "Games";
	appId[14] 	= "NetFlix";
	appId[15] 	= "Gmail";
	appId[16] 	= "Hotmail";
	appId[17] 	= "Microsoft";
	appId[18] 	= "Office365";
	appId[19] 	= "LinkedIn";
	appId[20] 	= "Webex";
	appId[21] 	= "Viber";
	appId[22] 	= "SocialNetwork";
	appId[23] 	= "ECommerce";
	appId[24] 	= "Travel";
	appId[25] 	= "FoodOrdering";
	appId[26] 	= "Twitter";
	appId[27] 	= "FileSharing";
	appId[28] 	= "Internet";
	appId[29] 	= "News";
	appId[30] 	= "Dropbox";
	appId[31] 	= "Browser";
	appId[32] 	= "Sports";
	appId[33] 	= "Bank";
	appId[34]	= "Akamai";
	appId[35] 	= "GoDaddy";
	appId[36] 	= "Video";
	appId[37] 	= "Truecaller";
	appId[38] 	= "ISP";
	appId[39] 	= "SpeedTest";
	appId[40] 	= "AmazonPrime";
	appId[41] 	= "ALTBalaji";
	appId[42] 	= "BigFlix";
	appId[43] 	= "ErosNow";
	appId[44] 	= "Hotstar";
	appId[45] 	= "SonyLiv";
	appId[46] 	= "Voot";
	appId[47] 	= "YouNow";
	appId[48] 	= "Zee5";
	appId[49] 	= "Jio";
	appId[50] 	= "Instagram";
	appId[51] 	= "TIKTOK";
	appId[52] 	= "PUBG";
	appId[53] 	= "Uploadhaven";
	appId[54] 	= "DisneyPlus";
	appId[55]	= "Zoom";
	appId[56] 	= "Adult";
	appId[57] 	= "Amazon";
}


void utilities::readKeyWord()
{
	uint32_t x = 0;
	Value.clear();

	while(!fp.eof())
	{
		Key.clear();
		fp >> Key;

		if(Key.compare("DNS_FILE_NAME") == 0)
		{
			fp >> Value;

			dnsFileName = Value;

			printf("Dns File Name = %s\n", dnsFileName.c_str());
		}

		if(Key.compare("BARODA_DNS_PATH") == 0)
		{
			fp >> Value;

			barodaDnsPath = Value;

			printf("Baroda Dns Path = %s\n", barodaDnsPath.c_str());
		}

		if(Key.compare("RAJKOT_DNS_PATH") == 0)
		{
			fp >> Value;

			rajkotDnsPath = Value;

			printf("Rajkot Dns Path = %s\n", rajkotDnsPath.c_str());
		}

		if(Key.compare("SURAT_DNS_PATH") == 0)
		{
			fp >> Value;

			suratDnsPath = Value;

			printf("Surat Dns Path = %s\n", suratDnsPath.c_str());
		}

		if(Key.compare("PATNA_DNS_PATH") == 0)
		{
			fp >> Value;

			patnaDnsPath = Value;

			printf("Patna Dns Path = %s\n", patnaDnsPath.c_str());
		}

		if(Key.compare("HYD_DNS_PATH") == 0)
		{
			fp >> Value;

			hyderabadDnsPath = Value;

			printf("Hyderabad Dns Path = %s\n", hyderabadDnsPath.c_str());
		}


		if(Key.compare("Music") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Music[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Music Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("YahooMail") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				YahooMail[cnt] = std::string(pch);
					pch = strtok (NULL, ",");
					cnt++;
			}
			printf("YahooMail Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("CloudProvider") == 0)
		{
			fp >> Value;

			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				CloudProvider[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("CloudProvider Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Stock") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Stock[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Stock Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Yahoo") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Yahoo[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Yahoo Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("MSN") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				MSN[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("MSN Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Apple") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Apple[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Apple Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Skype") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Skype[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Skype Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Facebook") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Facebook[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Facebook Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Whatsapp") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Whatsapp[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Whatsapp Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Google") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Google[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Google Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Youtube") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Youtube[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Youtube Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Games") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Games[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Games Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("NetFlix") == 0)
		{
		fp >> Value;
		int cnt = 0;

		char *pch = strtok((char *)Value.c_str(),",");

		while (pch != NULL)
		{
			NetFlix[cnt] = std::string(pch);
			pch = strtok (NULL, ",");
			cnt++;
			}
			printf("NetFlix Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Gmail") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Gmail[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Gmail Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Hotmail") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Hotmail[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Hotmail Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Microsoft") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Microsoft[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Microsoft Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Office365") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Office365[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Office365 Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("LinkedIn") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				LinkedIn[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("LinkedIn Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Webex") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Webex[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Webex Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Viber") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Viber[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Viber Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("SocialNetwork") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				SocialNetwork[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("SocialNetwork Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("ECommerce") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				ECommerce[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("ECommerce Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Travel") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Travel[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Travel Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("FoodOrdering") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				FoodOrdering[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("FoodOrdering Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Twitter") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Twitter[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Twitter Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("FileSharing") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				FileSharing[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("FileSharing Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Internet") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Internet[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Internet Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("News") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				News[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("News Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Dropbox") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Dropbox[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Dropbox Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Browser") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Browser[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Browser Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Sports") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Sports[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Sports Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Bank") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Bank[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Bank Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Akamai") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Akamai[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Akamai Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("GoDaddy") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				GoDaddy[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("GoDaddy Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Video") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Video[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Video Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Truecaller") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Truecaller[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Truecaller Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("ISP") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				ISP[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("ISP Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("SpeedTest") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				SpeedTest[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("SpeedTest Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("AmazonPrime") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				AmazonPrime[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("AmazonPrime Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("ALTBalaji") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				ALTBalaji[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("ALTBalaji Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("BigFlix") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				BigFlix[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("BigFlix Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("ErosNow") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				ErosNow[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("ErosNow Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Hotstar") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Hotstar[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Hotstar Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("SonyLiv") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				SonyLiv[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("SonyLiv Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Voot") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Voot[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Voot Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("YouNow") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				YouNow[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("YouNow Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Zee5") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Zee5[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Zee5 Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Jio") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Jio[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Jio Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Instagram") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Instagram[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Instagram Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("TIKTOK") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				TIKTOK[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("TIKTOK Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("PUBG") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				PUBG[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("PUBG Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Uploadhaven") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Uploadhaven[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Uploadhaven Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("DisneyPlus") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				DisneyPlus[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("DisneyPlus Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Zoom") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Zoom[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Zoom Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Adult") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Adult[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Adult Key Word Cnt = %d\n", cnt);
		}

		if(Key.compare("Amazon") == 0)
		{
			fp >> Value;
			int cnt = 0;

			char *pch = strtok((char *)Value.c_str(),",");

			while (pch != NULL)
			{
				Amazon[cnt] = std::string(pch);
				pch = strtok (NULL, ",");
				cnt++;
			}
			printf("Amazon Key Word Cnt = %d\n", cnt);
		}


	}
}

uint32_t utilities::ipToLong(char *ipt, uint32_t *plong)
{
	char        *next = NULL;
	const char  *curr = ipt;
	uint32_t    tmp;
	int         i, err = 0;
	int         NUM_OCTETTS = 4;

	*plong = 0;
	for (i = 0; i < NUM_OCTETTS; i++)
	{
		tmp = strtoul(curr, &next, 10);
		if (tmp >= 256 || (tmp == 0 && next == curr))
		{
			err++;
			break;
		}
		*plong = (*plong << 8) + tmp;
		curr = next + 1;
	}

	if (err)
		return 1;
	else
		return *plong;
}
