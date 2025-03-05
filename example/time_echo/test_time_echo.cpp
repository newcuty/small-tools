#include "time_echo.hpp"
#include <thread>

int main(){

    std::cout << "main begin\n";

    util::time::TimeEcho* time_echo1 = new util::time::TimeEcho();
    std::cin.get();

    delete time_echo1;
    time_echo1 = nullptr;

    util::time::TimeEcho time_echo2;// = new util::time::TimeEcho();
    time_echo2.start();
    std::this_thread::sleep_for(std::chrono::seconds(2));
    time_echo2.end();
}