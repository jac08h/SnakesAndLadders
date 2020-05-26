#include <iostream>
#include <snakesandladders.h>

int main()
{
    SnakesAndLadders s{};
    int roll_1, roll_2;
    std::string output;
    for (int i=0; i<10; i++) {
        roll_1 = s.roll_die();
        roll_2 = s.roll_die();
        std::cout << roll_1 << ":" << roll_2 << "(" << roll_1+roll_2 << ")" << std::endl;
        output = s.play(roll_1, roll_2);
        std::cout << output << std::endl;
        std::cout << "-" << std::endl;
    }
}
