#include <iostream>
#include "Terminal.h"
#include "mainFunctions.h"

int main() {
    Terminal *terminal = new Terminal();

    getUserQueries(terminal);

    return 0;
}