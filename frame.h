//
//  frame.h
//  
//
//  Created by Peter Fetros on 11/7/16.
//
//

#ifndef FRAME_H
#define FRAME_H

class Frame {
public:
    Frame();
    Frame(int width, int height);
    ~Frame();
    
    int getCellNumber();
    int getStartTime;
    std::string toString();
    
private:
    Cell cells[][];
    int frameNumber;
    int startTime;
};


#endif /* FRAME_H */
