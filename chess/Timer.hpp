//
//  Timer.hpp
//  chess
//
//  Created by Sam Clark
//

#ifndef Timer_hpp
#define Timer_hpp

#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

class Timer {
public:
    Timer(int seconds, function<void()> callback);
    
    bool hasCompleted();
    
    function<void()> callback;
    
private:
    int endSeconds;
};

#endif /* Timer_hpp */
