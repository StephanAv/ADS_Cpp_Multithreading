#include "ADS_Access.h"

void ADS_Access::_run()
{
	long nErr = 0;

	nErr = AdsGetLocalAddressEx(m_adsPort, &m_amsAddr);

	if (nErr != ADSERR_NOERR) {
		std::cerr << "AdsGetLocalAddressEx() failed" << std::endl;
		throw "AdsGetLocalAddressEx() failed";
	}


	while (m_cnt < 5) {

		unsigned short ads_state = 0;
		unsigned short dev_state = 0;

		nErr = AdsSyncReadStateReqEx(m_adsPort, &m_amsAddr, &ads_state, &dev_state);

		if (nErr != ADSERR_NOERR) {
			std::cerr << "AdsSyncReadStateReqEx() failed" << std::endl;
			throw "AdsSyncReadStateReqEx() failed";
		}


		std::cout << "thread: " << std::this_thread::get_id() << " ads_state: " << ads_state << std::endl << std::flush;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		m_cnt++;
	}
	std::cout << "thread: " << std::this_thread::get_id() << " finished!" << std::endl;
}

ADS_Access::ADS_Access()
	: m_adsPort(0)
	, m_cnt(0)
{
	memset(&m_amsAddr, 0, sizeof(AmsAddr));

	m_adsPort = AdsPortOpenEx();

	if (m_adsPort == 0) {
		std::cerr << "AdsPortOpenEx() failed" << std::endl;
		throw "AdsPortOpenEx() Exception";
	}
	else {
		std::cout << "Ads Port opened: " << m_adsPort  << std::endl;
	}

}

ADS_Access::~ADS_Access()
{
	long nErr = 0;

	nErr = AdsPortCloseEx(m_adsPort);

	if (nErr == 0) {
		std::cout << "thread: " << std::this_thread::get_id() << " - Ads Port " << m_adsPort << " closed successfully" << std::endl;
	}
	else {
		std::cerr << "AdsPortCloseEx() failed" << std::endl;
	}

}

void ADS_Access::run()
{

	std::thread t(&ADS_Access::_run, this);
	t.detach();
}
