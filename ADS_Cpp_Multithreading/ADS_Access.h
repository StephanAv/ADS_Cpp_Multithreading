#pragma once
#include <Windows.h>
#include <iostream>
#include <exception>
#include <thread>
#include <chrono>
#include <ostream>

#include "TcAdsDef.h"
#include "TcAdsAPI.h"


class ADS_Access
{
	unsigned long m_cnt;
	LONG m_adsPort;
	AmsAddr m_amsAddr;

	void _run();

public:
	ADS_Access();

	~ADS_Access();

	void run();
};

