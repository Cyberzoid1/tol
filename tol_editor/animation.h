/**
* @author Trevor Morse
* @date 11/05/2016
* @class Animation
* @brief This is the header file for the Animation class.
* @details This class is utilized to store the sequence of
* frames in the Tower of Light's animation as well as the header
* info for the resulting .tan2 file.
*
*/

#ifndef ANIMATION_H
#define ANIMATION_H

#include <list>
#include <string>
#include "frame.h"
#include "RGB.h"

///number of recently used colors that are stored by the ToL editor
const int NUMCOLORS = 16;

class Animation {
public:
	Animation();
	~Animation();
	void setFrames(std::list<Frame> frms);
	std::list<Frame> getFrames();
	void setVersion(std::string ver);
    Frame* getCurrentFrame();
    void setCurrentFrame(Frame* newFrame);
	std::string getVersion();
	void setFilename(std::string fname);
	std::string getFilename();
	void setLastColor(int red, int green, int blue);
    RGB getLastColor();
    void setTimeInterval(int interval);
    int getTimeInterval();

    void setRecentColors(RGB *recColors);
    RGB* getRecentColors();
	int getNumFrames();
	void setHeight(int h);
	int getHeight();
	void setWidth(int w);
	int getWidth();

	void addFrame(int w, int h, int pos);
	void duplicateFrame(Frame frame);
    void incrementFrameInfo(std::list<Frame>::iterator it);
	void removeFrame(int pos);
    void decrementFrameInfo(std::list<Frame>::iterator it);
    void removeFrames(int first, int last);

    void shiftFrame(Frame frame, int dir);

	std::string toString();

private:
    std::list<Frame> frames; //!< List containing the ordered sequence of frames.
    std::string version; //!< Version of the .tan2 file used for import/export.
    std::string filename; //!< Name of the .tan2 file to be exported.
    RGB lastColor; //!< The last color used while creating the animation.
    RGB recentColors[NUMCOLORS]; //!< The 16 Most recent colors used.
    int numFrames; //!< The total number of frames in the animation.
    int height; //!< The height in cell objects of each animation frame.
    int width; //!< The width in cell objects of each animation frame.
    Frame* currentFrame; //!< The currently displayed frame in the editor window.
    int timeInterval; //!< The time interval (in ms) set in the toolbox.
};
#endif
