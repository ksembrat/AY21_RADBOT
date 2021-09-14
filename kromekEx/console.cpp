#include "SpectrometerDriver.h"
#include "stdio.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


void stdcall errorCallback(void *pCallbackObject, unsigned int deviceID, int errorCode, const char *pMessage)
{
	if (errorCode != ERROR_ACQUISITION_COMPLETE)
		printf("%s", pMessage);
}

int main()
{

	ofstream outFile("my_file.txt");


	unsigned int detectorID = 0;
	unsigned int totalCounts = 0;
	unsigned int realTime = 0;
	unsigned int liveTime  = 0;
	// Allocate a buffer big enough to hold the channel data for the acquisition
	vector<unsigned int> spectrumData;
	spectrumData.resize(TOTAL_RESULT_CHANNELS);
	cout << "histogram channels: " << TOTAL_RESULT_CHANNELS << "\n";
    // Initialise the library with no error callback (not recommended)
	kr_Initialise(errorCallback, NULL);

	for (int i = 0; i < 3; ++i)
	{
		// Start measurement on all detectors
		while ((detectorID = kr_GetNextDetector(detectorID)))
		{
            kr_BeginDataAcquisition(detectorID, 60000, 0);
		}

        std::this_thread::sleep_for(std::chrono::milliseconds(60000));

		// Start measurement on all detectors
		while ((detectorID = kr_GetNextDetector(detectorID)))
		{
			kr_StopDataAcquisition(detectorID);
			kr_GetAcquiredData(detectorID, spectrumData.data(), &totalCounts, &realTime, &liveTime);
			kr_ClearAcquiredData(detectorID);

			cout << "realTime: " << realTime << "\n";
			cout << "totalCounts: " << totalCounts << "\n";
			cout << "liveTime: " << liveTime << "\n";
			for (const auto &e : spectrumData) outFile << e << "\t";
			outFile << "\n";
		}



	}

    // Cleanup the library
	kr_Destruct();
	return 0;
}
