
#include "Maximum.h"
#include <string>
#include <iostream>
void Maximum::send(std::string name) {
    if(!name.substr(0, 5).compare("READ ")) {
        name = name.substr(5, name.size() - 5);
        int port = std::stoi(name);
        if(mNoReads != 0) {
            maximum = mCntrl.receive(port);
            float temp;
            for (int i = 1; i < mNoReads; ++i) {
                temp = mCntrl.receive(port);
                if(temp>maximum) maximum=temp;
            }
        }
        else {
            maximum = 0;
        }
    }
}

float Maximum::receive() {
    return maximum;
}
