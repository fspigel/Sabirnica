#include "BusController.h"
#include <iostream>
#include <stdexcept>
void BusController::insert(Instrument * p) {
    p->setPort(mDevices.size());
    mDevices.push_back(p);
    std::cout << "Ubacen " << p->deviceName() << " instrument." << std::endl;
}

void BusController::send(unsigned int address, std::string cmd) {
    std::cout << "BusController::Send " << std::endl;
    if(mDevices.size() >= address) {
        throw std::invalid_argument("Wrong address!");
    } else {
        mDevices.at(address)->send(cmd);
    }
}

float BusController::receive(unsigned int address) {
    std::cout << "BusController::Receive " << std::endl;
    if(mDevices.size() <= address) {
        throw std::invalid_argument("Wrong address!");
    } else {
        return mDevices.at(address)->receive();
    }

}
