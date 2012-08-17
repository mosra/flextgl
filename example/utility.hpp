#ifndef UTILITY_HH
#define UTILITY_HH

#include "common.hpp"

bool file_exists(const string &filename);

string read_file(const string &filename);

// Query OpenGL errors and print error messages to STDERR.

void get_errors(void);

#endif
