
#ifndef MAXIMUM_H_INCLUDED
#define MAXIMUM_H_INCLUDED
#include "BusController.h"
#include "Instrument.h"
#include "DataRecorder.h"
// Konkretan sakupljaè podataka
class Maximum : public Instrument, public DataRecorder {
public:
    Maximum(BusController & a): mCntrl(a) {mCntrl.insert(this);}
    void send(std::string);
    float receive();
    virtual std::string deviceName() const { return "Maximum"; }


private:
    BusController & mCntrl;
    float maximum;
};
#endif // STATISTICS_H_INCLUDED
