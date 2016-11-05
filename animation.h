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
#include <tuple>
#include "frame.h"

//number of recently used colors that are stored by the ToL editor
const int NUMCOLORS = 16;

/*
 * Structure for storing sets of rgb color values.
 */
struct RGB
{
	int red;
	int green;
	int blue;
};
typedef struct RGB rgb;
/*
 * Class for storing a list of frames and other information related to
 * the overall animation.
 */
class Animation{
   private:
      std::list<Frame> frames;
	  double version;
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
	   void setVersion(double ver);
	   double getVersion();
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

	   void addFrame(Frame frame);
	   void duplicateFrame(Frame frame);
	   void removeFrame(Frame frame);
	   std::string toString();
};
#endif