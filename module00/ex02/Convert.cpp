#include <iostream>
#include <string>

int main(int ac, char **av)
{
    if (ac < 3)
    {
        std::cerr << "Usage: " << av[0] << " <COMMAND> <STRING>" << std::endl;
        return 1;
    }
    std::string command = av[1];
    std::string str = av[2];
    if (command == "up")
    {
        for (auto &c : str)
        {
            c = std::toupper(c);
        }
        std::cout << str << std::endl;
    }
    else if (command == "down")
    {
        for (auto &c : str)
        {
            c = std::tolower(c);
        }
        std::cout << str << std::endl;
    }
    else
    {
        std::cerr << "Unknown command: " << av[1] << std::endl;
        return 1;
    }

}
