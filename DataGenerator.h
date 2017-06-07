#ifndef DATAGENERATOR_H_INCLUDED
#define DATAGENERATOR_H_INCLUDED
// Suèelje za sve generatore podataka
class DataGenerator {
public:
    // odaberi signal
    virtual void setMode(int) = 0;
    virtual ~DataGenerator() {}

};
#endif
