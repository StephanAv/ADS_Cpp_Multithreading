#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <vector>

#include "ADS_Access.h"


int main()
{
    int numThreads = 25;

    std::vector<ADS_Access*> ads_objects;

    for (int i = 0; i < numThreads; i++) {
        ADS_Access* obj = new ADS_Access();
        ads_objects.push_back(obj);
        obj->run();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(8000));

    std::cout << "Press Enter to destroy objects" << std::endl;
    while (getchar() != '\n') {}

    std::vector<ADS_Access*>::iterator iter;
    for (iter = ads_objects.begin(); iter != ads_objects.end(); ) {
        delete* iter;
        iter = ads_objects.erase(iter);
    }

    std::cout << "Press Enter to Exit" << std::endl;
    while (getchar() != '\n') {}
}
