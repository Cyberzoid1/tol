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

struct RGB
{
	int red;
	int green;
	int blue;
};
typedef struct RGB rgb;

class Animation{
   private:
      std::list<Frame> frames;
	  double version;
	  std::string filename;
	  rgb lastColor;
	  rgb recentColors[16];
	  int numFrames;
	  int height;
	  int width;

   public:
	   Animation();
	   ~Animation();
	   void setFrames(std::list<Frame> frames);
	   std::list<Frame> getFrames();
	   void setVersion(double ver);
	   double getVersion();
	   void setFilename(std::string fname);
	   std::string getFilename();
	   void setLastColor(rgb color);
	   std::tuple<int, int, int> getLastColor();
	   void setRecentColors(rgb *recColors);
	   rgb* getRecentColors();
	   int getNumFrames();
	   void setHeight(int h);
	   int getHeight();
	   void setWidth(int w);
	   int getWidth();

	   void addFrame(Frame frame);
	   void duplicateFrame(Frame frame);
	   void removeFrame(int position);
	   std::string toString();
};
#endif