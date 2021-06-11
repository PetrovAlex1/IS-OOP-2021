#include <iostream>

#include "Timestamp.h"
#include "TimestampWithDescription.h"

int main()
{
    Timestamp t1;
    std::cin >> t1;
    std::cout << t1;

    TimestampWithDescription t2;
    std::cin >> t2;
    std::cout << t2;

    return 0;
}