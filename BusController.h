#ifndef BUSCONTROLLER_H_INCLUDED
#define BUSCONTROLLER_H_INCLUDED
#include "Instrument.h"
#include <string>
#include <vector>
// Sabirnica.
class BusController {
public:
    // konstruktor
    BusController() {}

    ~BusController(){
    }

        // insertiraj instrunment i postavi mu broj porta. Radi provjere ispisati da je operacija
        // izvršena
    void insert(Instrument * p);

        // Pošalji naredbu cmd ureðaju na danoj adresi. Izbaci izuzetak ako nema ureðaja.
    void send(unsigned int address, std::string cmd);

        // Zatraži vrijednost od ureðaja na danoj adresi.  Izbaci izuzetak ako nema ureðaja.
    float receive(unsigned int address);
private:
        // Prisutni instrumenti. Indeksi su "portovi"
    std::vector<Instrument*> mDevices;
};

#endif
