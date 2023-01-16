/*
 * utilities.h
 *
 *  Created on: 6 Jan 2023
 *      Author: debas
 */

#ifndef DNSIDENTIFICATION_CORE_SRC_UTILITIES_H_
#define DNSIDENTIFICATION_CORE_SRC_UTILITIES_H_

#include "global.h"

using namespace std;

class utilities
{
	public:
		utilities();
		~utilities();

		ifstream 	fp;
		timeval 	curTime;
		char 		timeStr[50];
		string 		Key, Value;

		string		dnsFileName;
		string		barodaDnsPath;
		string		getFileName();
		string		getBarodaPath();

		string 		rajkotDnsPath;
		string 		getRajkotPath();

		string 		patnaDnsPath;
		string 		getPatnaPath();

		string 		suratDnsPath;
		string		getSuratPath();

		string		hyderabadDnsPath;
		string 		getHyderabadPath();

		void 		openDnsKeyFile(char *fileName);
		void 		pinThread(pthread_t th, uint16_t i);
		char* 		timerfunc();
		void 		readKeyWord();
		void 		closeDnsKeyFile();
		void 		populateAppId();
		uint32_t 	ipToLong(char *ipt, uint32_t *plong);

		std::map<uint16_t, std::string> appId;

		std::map<uint16_t, std::string> YahooMail;
		std::map<uint16_t, std::string> Music;
		std::map<uint16_t, std::string> CloudProvider;
		std::map<uint16_t, std::string> Stock;
		std::map<uint16_t, std::string> Yahoo;
		std::map<uint16_t, std::string> MSN;
		std::map<uint16_t, std::string> Apple;
		std::map<uint16_t, std::string> Skype;
		std::map<uint16_t, std::string> Facebook;
		std::map<uint16_t, std::string> Whatsapp;
		std::map<uint16_t, std::string> Google;
		std::map<uint16_t, std::string> Youtube;
		std::map<uint16_t, std::string> Games;
		std::map<uint16_t, std::string> NetFlix;
		std::map<uint16_t, std::string> Gmail;
		std::map<uint16_t, std::string> Hotmail;
		std::map<uint16_t, std::string> Microsoft;
		std::map<uint16_t, std::string> Office365;
		std::map<uint16_t, std::string> LinkedIn;
		std::map<uint16_t, std::string> Webex;
		std::map<uint16_t, std::string> Viber;
		std::map<uint16_t, std::string> SocialNetwork;
		std::map<uint16_t, std::string> ECommerce;
		std::map<uint16_t, std::string> Travel;
		std::map<uint16_t, std::string> FoodOrdering;
		std::map<uint16_t, std::string> Twitter;
		std::map<uint16_t, std::string> FileSharing;
		std::map<uint16_t, std::string> Internet;
		std::map<uint16_t, std::string> News;
		std::map<uint16_t, std::string> Dropbox;
		std::map<uint16_t, std::string> Browser;
		std::map<uint16_t, std::string> Sports;
		std::map<uint16_t, std::string> Bank;
		std::map<uint16_t, std::string> Akamai;
		std::map<uint16_t, std::string> GoDaddy;
		std::map<uint16_t, std::string> Video;
		std::map<uint16_t, std::string> Truecaller;
		std::map<uint16_t, std::string> ISP;
		std::map<uint16_t, std::string> SpeedTest;
		std::map<uint16_t, std::string> AmazonPrime;
		std::map<uint16_t, std::string> ALTBalaji;
		std::map<uint16_t, std::string> BigFlix;
		std::map<uint16_t, std::string> ErosNow;
		std::map<uint16_t, std::string> Hotstar;
		std::map<uint16_t, std::string> SonyLiv;
		std::map<uint16_t, std::string> Voot;
		std::map<uint16_t, std::string> YouNow;
		std::map<uint16_t, std::string> Zee5;
		std::map<uint16_t, std::string> Jio;
		std::map<uint16_t, std::string> Instagram;
		std::map<uint16_t, std::string> TIKTOK;
		std::map<uint16_t, std::string> PUBG;
		std::map<uint16_t, std::string> Uploadhaven;
		std::map<uint16_t, std::string> DisneyPlus;
		std::map<uint16_t, std::string> Zoom;
		std::map<uint16_t, std::string> Adult;
		std::map<uint16_t, std::string> Amazon;

};

#endif /* DNSIDENTIFICATION_CORE_SRC_UTILITIES_H_ */
