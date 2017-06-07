#ifndef DATAFAST_H_INCLUDED
#define DATAFAST_H_INCLUDED
#include "DataGenerator.h"
#include "Instrument.h"
#include "BusController.h"
#include <chrono>
// Konkretan generator podataka
class DataFast : public Instrument, public DataGenerator {
public:
    DataFast(BusController & a) : mCntrl(a), mStartTime(std::chrono::system_clock::now()) { mCntrl.insert(this);}
    void setMode(int);
    void send(std::string);
    float receive();
    virtual std::string deviceName() const { return "DataFast"; }

private:
    BusController & mCntrl;
    int mMode;
    std::chrono::time_point<std::chrono::system_clock> mStartTime;
};
#endif // DATAFAST_H_INCLUDED
