#ifndef INSTRUMENT_H_INCLUDED
#define INSTRUMENT_H_INCLUDED
#include <string>

/** Suèelje za svaki instrument povezan na sabirnicu. */
class Instrument {
public:
    // pošalji instrumentu naredbu
    virtual void send(std::string) = 0;
    // preuzmi od instrumenta vrijednost
    virtual float receive() = 0;
    // ime instrumenta
    virtual std::string deviceName() const = 0;
    // implemenatcijski dio klase
    void setPort(int port) {mPort = port; }
    int  getPort() const { return mPort; }

    virtual ~Instrument() {}
protected:
    int mPort = -1;
};
#endif // INSTRUMENT_H_INCLUDED
