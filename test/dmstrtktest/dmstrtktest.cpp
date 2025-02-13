
#include "dmstrtk.hpp"

int main( int argc, char* argv[] )
{
    std::deque<std::string> str_lst;

    str_lst.push_back("12,32,12");
    str_lst.push_back("13,232,12");
    str_lst.push_back("14,234,2332");

    strtk::write_to_text_file("out.txt", str_lst, "\n");

    std::deque<std::string> new_lst;

    strtk::load_from_text_file("out.txt",new_lst);

    std::cout << strtk::join("\n", new_lst) << std::endl;

    return 0;
}
