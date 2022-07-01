#include <exception>

#ifndef __MODUS_MASTER_EXCEPTION_h__
#define __MODUS_MASTER_EXCEPTION_h__

class InvalidData : public std::exception {
    virtual const char* what() const throw() {
        return "**** ERROR: Invalid Require Data \n\n";
    }
};

#endif __MODUS_MASTER_EXCEPTION_h__