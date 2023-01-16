/*
 * main.h
 *
 *  Created on: 05-Jan-2023
 *      Author: Admin
 */

#ifndef CORE_INC_MAIN_H_
#define CORE_INC_MAIN_H_

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>
#include <map>
#include <unordered_map>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <iterator>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>

#include "utilities.h"
#include "Baroda.h"
#include "Rajkot.h"
#include "Surat.h"
#include "Patna.h"
#include "Hyderabad.h"

#define handle_error_en(en, msg) \
       do { perror(msg); exit(EXIT_FAILURE); } while (0)

using namespace std;

//utilities		*util;
void pinThread(pthread_t th, uint16_t i);


#endif /* CORE_INC_MAIN_H_ */
