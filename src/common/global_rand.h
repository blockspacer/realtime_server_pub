#ifndef GLOBAL_RAND_H
#define GLOBAL_RAND_H

#include "fw_env.h"
#include "random/random.h"

BEGIN_NS

class GlobalRand : public SmartPtr<GlobalRand>
{
public:
    typedef boost::intrusive_ptr<GlobalRand> ptr;
    
    static GlobalRand::ptr getInstance();
    
    int getInt(int min, int max);
    void getAllAscii(int length, std::string& ret);
    void getAscii(int length, std::string& ret);
    
    float getFloat(float min, float max);
    float getFloat0_1();
    float getFloatMinus1_1();
    
private:
    GlobalRand();
    
    Random* rand;
};

END_NS

#endif
