#ifndef LIBDIVIDE_WRAPPER_H
#define LIBDIVIDE_WRAPPER_H

namespace LibDivide {
    int divide(unsigned int dividend, unsigned int divisor);
    int remainder(unsigned int dividend, unsigned int divisor);

    struct IntegerDivisionResult {
        int quotient;
        int remainder;
    };

}

#endif // LIBDIVIDE_WRAPPER_H
