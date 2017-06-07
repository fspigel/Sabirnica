#ifndef STATISTICS_H_INCLUDED
#define STATISTICS_H_INCLUDED
#include "BusController.h"
#include "Instrument.h"
#include "DataRecorder.h"
// Konkretan sakupljaè podataka
class Statistics : public Instrument, public DataRecorder {
public:
    Statistics(BusController & a): mCntrl(a) {mCntrl.insert(this);}
    void send(std::string);
    float receive();
    virtual std::string deviceName() const { return "Statistics"; }


private:
    BusController & mCntrl;
    float arithmeticMean;
};
#endif // STATISTICS_H_INCLUDED
