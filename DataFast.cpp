#include "DataFast.h"
#include <chrono>
#include <string>
#include <math.h>
#include <iostream>
#include <time.h>

void DataFast::setMode(int i) {
    mMode = i;
};

void DataFast::send(std::string name) {

    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - mStartTime);
    std::cout << "elapsed : " << elapsed.count()  << std::endl;
    if(mMode == 0) {
        value = sin(0.175*(elapsed.count()));
    } else if(mMode == 1) {
        value = sin(2*0.175*(elapsed.count()));
    }
}

float DataFast::receive() {
    send("");
    return value;
}

