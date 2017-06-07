#include <iostream>
#include <vector>
#include "Instrument.h"
#include "DataFast.h"
#include "DataRecorder.h"
#include "Statistics.h"
#include "Maximum.h"
#include "BusController.h"
#include <string>

using namespace std;

// Klijent suèelja Instrument
void experimentSetUp(Instrument & dataGen, std::vector<Instrument *> & recorders)
{
  for(auto p : recorders) p->send("READ " + std::to_string(dataGen.getPort()));
}

// Klijent suèelja DataRecorder
void init(std::vector<DataRecorder *> & recorders)
{
  int i = 10;
  for(auto p : recorders){
        p->setNoReads(i);
            i+=5;
          }
}

// Klijent suèelja Instrument
void printData( std::vector<Instrument *> & recorders){
  for(auto p : recorders)
    std::cout << p->deviceName() << ", value = " << p->receive() << "\n";
}


int main()
{
    BusController bus;

    DataFast generator(bus);
        generator.setMode(1);
    Statistics * stat1 = new Statistics(bus);
    Statistics * stat2 = new Statistics(bus);
    Statistics * stat3 = new Statistics(bus);
    Maximum * max1 = new Maximum(bus);

    std::vector<Instrument *> iRecorders;
    iRecorders.push_back(stat1);
    iRecorders.push_back(stat2);
    iRecorders.push_back(stat3);
    iRecorders.push_back(max1);

    std::vector<DataRecorder *> dRecorders;
    dRecorders.push_back(stat1);
    dRecorders.push_back(stat2);
    dRecorders.push_back(stat3);
    dRecorders.push_back(max1);

    init(dRecorders);
    experimentSetUp(generator, iRecorders);
    printData(iRecorders);

    delete stat1;
    delete stat2;
    delete stat3;

    return 0;
}
