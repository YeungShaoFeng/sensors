#pragma once
#ifndef _SASE_h
#define _SASE_h

#ifdef ARDUINO
    #if ARDUINO < 100
        #include "WProgram.h"
    #else
        #include "Arduino.h"
    #endif

#endif

class SASE{
    public:
        SASE();

        static int8_t begin();


};




#endif