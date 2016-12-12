//
//  Coordinate.hpp
//  chess
//
//  Created by Sam Clark
//

#ifndef Coordinate_hpp
#define Coordinate_hpp

class Coordinate {
public:
    Coordinate(int x, int y);
    int getX();
    int getY();
    
    bool operator==(const Coordinate &other);
    
private:
    int x;
    int y;
};

#endif /* Coordinate_hpp */
