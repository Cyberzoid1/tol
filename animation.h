/**
* CS 383
* Group #4
* Created: 11/05/2016
*
* This is the header file for the Animation class. This class is utilized to store
* the sequence of frames in the Tower of Light's animation as well as the header info
* for the resulting .tan2 file.
*/

#ifndef ANIMATION_H
#define ANIMATION_H

#include <list>
#include <string>
#include "frame.h"
#include "rgb.h"

///number of recently used colors that are stored by the ToL editor
const int NUMCOLORS = 16;

/**
* Class for storing a list of frames and other information related to
* the overall animation.
*/
class Animation {
private:
	std::list<Frame> frames;
	std::string version;
	std::string filename;
	rgb lastColor;
	rgb recentColors[NUMCOLORS];
	int numFrames;
	int height;
	int width;

public:
	Animation();
	~Animation();
	void setFrames(std::list<Frame> frms);
	std::list<Frame> getFrames();
	void setVersion(std::string ver);
	std::string getVersion();
	void setFilename(std::string fname);
	std::string getFilename();
	void setLastColor(int red, int green, int blue);
	rgb getLastColor();
	void setRecentColors(rgb *recColors);
	rgb* getRecentColors();
	int getNumFrames();
	void setHeight(int h);
	int getHeight();
	void setWidth(int w);
	int getWidth();

	void addFrame(int w, int h, int pos);
	void duplicateFrame(Frame frame);
	void removeFrame(int pos);
	void removeFrames(int first, int last);
	std::string toString();
};
#endif