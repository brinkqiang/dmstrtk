/*
 *****************************************************************
 *                     String Toolkit Library                    *
 *                                                               *
 * Random Line Selection                                         *
 * Author: Arash Partow (2002-2020)                              *
 * URL: http://www.partow.net/programming/strtk/index.html       *
 *                                                               *
 * Copyright notice:                                             *
 * Free use of the String Toolkit Library is permitted under the *
 * guidelines and in accordance with the most current version of *
 * the MIT License.                                              *
 * http://www.opensource.org/licenses/MIT                        *
 *                                                               *
 *****************************************************************
*/


/*
   Description: This is a solution to the problem of randomly selecting a line
                from a text file in the most efficient way possible taking into
                account time and space complexities, also ensuring that the
                probability of the line selected is exactly 1/N where N is the
                number of lines in the text file - It should be noted that the
                lines can be of varying length.
*/


#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <deque>
#include <ctime>

#include <random>

#include "strtk.hpp"
#include "dmrand.h"

class random_line_selector
{
public:

    random_line_selector(std::string& line)
        : line_count_(1),
          line_(line)
    {}

    inline void operator()(const std::string& s)
    {
        if (CDMRand::Instance()->GetRand() < (10000 / line_count_))
        {
            line_ = s;
        }

        ++line_count_;
    }

public:

    random_line_selector operator=(const random_line_selector&);

    std::size_t line_count_; // should be long long
    std::string& line_;
};

int main(int argc, char* argv[])
{
    std::string file_name = __FILE__;
    std::string line;

    for (int i=0; i < 10; i++)
    {
        strtk::for_each_line(file_name, random_line_selector(line));

        std::cout << line << std::endl;

    }

    return 0;
}
