#ifndef RECORDING_ERRORS_H
#define RECORDING_ERRORS_H

extern char* error_text[];

typedef enum Errors {   
    NEGATIVE_DISCRIMINANT = 1,
    NO_COEFFICIENTS
} Errors;


#endif