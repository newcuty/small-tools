// time echo: for calculating time cost in funcution call
// Authour: chen biao
// e-mail : chenbiaojob@163.com

#include <chrono>
#include <iostream>

namespace util::time{


/// @brief  A simple time count implementation
/// This class can automatic calcualting the time const in function calls
/// Also can manual calculate the time cost, whose result prints with ms by default.
class TimeEcho final
{
private:
    std::chrono::_V2::system_clock::time_point start_;
    std::chrono::_V2::system_clock::time_point end_;

    bool is_manual_{false};

public:
    TimeEcho(/* args */){

        start_ = std::chrono::high_resolution_clock::now();
    }

    ~TimeEcho(){

        if(is_manual_ == false){
            end_ = std::chrono::high_resolution_clock::now();
        
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_ - start_);
            std::cout << "Time spend is " << duration.count()/1000 << " ms" << std::endl;

        }

    }

    //manual start the count
    void start(){

        is_manual_ = true;
        start_ = std::chrono::high_resolution_clock::now();
    } 

    void end(){
        
        end_ = std::chrono::high_resolution_clock::now();
    
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_ - start_);
        std::cout << "Time spend is " << duration.count()/1000 << " ms" << std::endl;

    }

    void end(std::chrono::microseconds& __duration){
        end_ = std::chrono::high_resolution_clock::now();
    
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_ - start_);
        std::cout << "Time spend is " << duration.count()/1000 << " ms" << std::endl;

        __duration = duration;
    }
    
    void printMS() {
    
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_ - start_);
        std::cout << "Time spend is " << duration.count()/1000 << " ms" << std::endl;
    }

    void printUS() {
    
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end_ - start_);
        std::cout << "Time spend is " << duration.count() << " us" << std::endl;
    }
};


} // namespace util::time