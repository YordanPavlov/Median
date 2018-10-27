#include <string>
#include <iostream>
#include <stdlib.h>

#include "medianstructure.h"

int main(int argc, char* argv[])
{
    MedianStore<int> store;

    std::string input;

    std::cout<<"Enter new element and receive current median, 'q' for exit:"<<std::endl;
    std::cin >> input;

    while(input.length() != 1 || input[0] != 'q')
    {
        store.add(atoi(input.c_str()));
        std::cout<<store.getMedian()<<std::endl;

        std::cin >> input;
    }

}
