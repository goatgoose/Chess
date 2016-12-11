//
//  Timer.cpp
//  chess
//
//  Created by Sam Clark on 12/11/16.
//  Copyright © 2016 Sam Clark. All rights reserved.
//

#include "Timer.hpp"

Timer::Timer(int seconds, function<void()> callback) {
    // http://stackoverflow.com/questions/19555121/how-to-get-current-timestamp-in-milliseconds-since-1970-just-the-way-java-gets
    this->endSeconds = (duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() / 1000) + seconds;
    this->callback = callback;
}

bool Timer::hasCompleted() {
    int now = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() / 1000;
    return now >= endSeconds;
}
