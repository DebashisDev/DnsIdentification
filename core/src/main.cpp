/*
 * main.cpp
 *
 *  Created on: 05-Jan-2023
 *      Author: Admin
 */

#include "main.h"

void *startBaroda(void* arg)
{
	Baroda *ft = (Baroda*)arg;

	ft->startBarodaFun();

	return NULL;
}

void *startRajkot(void* arg)
{
	Rajkot *rj = (Rajkot*)arg;

	rj->startRajkotFun();

	return NULL;
}

void *startSurat(void* arg)
{
	Surat *su = (Surat*)arg;

	su->startSuratFun();

	return NULL;
}

void *startPatna(void* arg)
{
	Patna *pt = (Patna*)arg;

	pt->startPatnaFun();

	return NULL;
}

void *startHyderabad(void* arg)
{
	Hyderabad *hyd = (Hyderabad*)arg;

	hyd->startHyderabadFun();

	return NULL;
}

int main()
{
	bool	ret = false;
	utilities *util = new utilities();
	util->openDnsKeyFile((char *)"dnsKeyword.conf");
	util->readKeyWord();
	util->closeDnsKeyFile();
	util->populateAppId();

	/* Baroda thread*/
	Baroda *baroda = new Baroda();

	pthread_create(&baroda->barodaThr, NULL, startBaroda, (void *)baroda);
	pinThread(baroda->barodaThr,util->Baroda_Cpu_Core);

	/*Rajkot Thread*/
	Rajkot *rajkot = new Rajkot();

	pthread_create(&rajkot->rajkotThr, NULL, startRajkot, (void *)rajkot);
	pinThread(rajkot->rajkotThr, util->Rajkot_Cpu_Core);

	/*Surat Thread*/
	Surat *surat = new Surat();

	pthread_create(&surat->suratThr, NULL, startSurat, (void *)surat);
	pinThread(surat->suratThr,util->Surat_Cpu_Core);

	/*Patna Thread*/
	Patna *patna = new Patna();

	pthread_create(&patna->patnaThr, NULL, startPatna, (void *)patna);
	pinThread(patna->patnaThr, util->Patna_Cpu_Core);

	/*Hyderabad Thread*/
	Hyderabad *hyd = new Hyderabad();

	pthread_create(&hyd->hyderabadThr, NULL, startHyderabad, (void *)hyd);
	pinThread(hyd->hyderabadThr, util->Hyd_Cpu_Core);

	while(true)
	{
		printf("Parent Thread ..\n");
		sleep(50);

		printf("BarodaFlag =  %d : RajkotFlag = %d : SuratFlag = %d : PatnaFlag = %d : HyderabadFlag = %d \n ",
				baroda->barodaFlag,rajkot->rajkotFlag,surat->suratFlag,patna->patnaFlag,hyd->hyderabadFlag);

		if(baroda->barodaFlag && rajkot->rajkotFlag && surat->suratFlag && patna->patnaFlag /*&& hyd->hyderabadFlag*/)
		{
			/*Baroda Data Dump*/

			baroda->outFile.open("BarodaAppDnsData.csv", ios::app);
			printf("Start Dumping of Baroda Data.....\n");

			for(uint16_t mapIndex = 0; mapIndex < 10; mapIndex++)
			{
				for(auto elem1 : baroda->barodaResolvedIpMap[mapIndex])
					baroda->outFile << elem1.second << "| " << "IP2IP" << endl ;
			}

			printf("Dumping Of Baroda Data is Done.....\n");
			baroda->outFile.close();

			/*Rajkot Data Dump*/

			rajkot->outFile.open("RajkotAppDnsData.csv", ios::app);
			printf("Start Dumping of Rajkot Data.....\n");

			for(uint16_t mapIndex = 0; mapIndex < 10; mapIndex++)
			{
				for(auto elem1 : rajkot->rajkotResolvedIpMap[mapIndex])
					rajkot->outFile << elem1.second << "| " << "IP2IP" << endl ;
			}

			printf("Dumping Of Rajkot Data is Done.....\n");
			rajkot->outFile.close();


			/*Surat Data Dump*/

			surat->outFile.open("SuratAppDnsData.csv", ios::app);
			printf("Start Dumping of Surat Data.....\n");

			for(uint16_t mapIndex = 0; mapIndex < 10; mapIndex++)
			{
				for(auto elem1 : surat->suratResolvedIpMap[mapIndex])
					surat->outFile << elem1.second << "| " << "IP2IP" << endl ;
			}

			printf("Dumping Of Surat Data is Done.....\n");
			surat->outFile.close();

			/*Patna Data Dump*/

			patna->outFile.open("PatnaAppDnsData.csv", ios::app);
			printf("Start Dumping of patna Data.....\n");

			for(uint16_t mapIndex = 0; mapIndex < 10; mapIndex++)
			{
				for(auto elem1 : patna->patnaResolvedIpMap[mapIndex])
					patna->outFile << elem1.second << "| " << "IP2IP" << endl ;
			}

			printf("Dumping Of patna Data is Done.....\n");
			patna->outFile.close();

			/*Hyderabad Data Dump*/

			hyd->outFile.open("HyderabadAppDnsData.csv", ios::app);
			printf("Start Dumping of Hyderabad Data.....\n");

			for(uint16_t mapIndex = 0; mapIndex < 10; mapIndex++)
			{
				for(auto elem1 : hyd->hyderabadResolvedIpMap[mapIndex])
					hyd->outFile << elem1.second << "| " << "IP2IP" << endl ;
			}

			printf("Dumping Of hyderabad Data is Done.....\n");
			hyd->outFile.close();

			exit(1);
		}
	}
}

void pinThread(pthread_t th, uint16_t i)
{
   /* Set affinity mask to include CPUs 0 to 7 */
	cpu_set_t cpuset;
	CPU_ZERO(&cpuset);
	CPU_SET(i,&cpuset);

	int s = pthread_setaffinity_np(th, sizeof(cpu_set_t), &cpuset);
	if (s != 0)
		handle_error_en(s, "ERROR!!! pthread_setaffinity_np");

	/* Check the actual affinity mask assigned to the thread */
	s = pthread_getaffinity_np(th, sizeof(cpu_set_t), &cpuset);
	if (s != 0)
		handle_error_en(s, "ERROR!!! pthread_getaffinity_np");

	if (!CPU_ISSET(i, &cpuset))
		printf("CPU pinning failed at core :: %d\n", i);
}

