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

}

float DataFast::receive() {
    auto start = std::chrono::time_point_cast<std::chrono::microseconds>(mStartTime);
    auto current = std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::system_clock::now());
    std::chrono::duration<double, std::ratio<1, 1000000>> elapsed = current - start;
    std::cout << "elapsed : " << elapsed.count()  << std::endl;
    if(mMode == 0) {
        return sin(0.175*(elapsed.count()));
    } else if(mMode == 1) {
        return sin(2*0.175*(elapsed.count()));
    }
}

