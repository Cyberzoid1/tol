/**
* CS 383
* Group #4
* Created: 11/05/2016
*
* This file contains the method definitions for the Animation class.
*/

#include "animation.h"
#include "rgb.h"

/**
 * Construct a new Animation with the default values.
 */
Animation::Animation()
{
	version = "0.4";
	filename = "";
    numFrames = (int)frames.size();
	height = 10;
	width = 4;
}
/**
 * TODO: verify that deconstructor is not needed
 */
Animation::~Animation()
{

}
/**
 * TODO: determine what we want setFrames to do
 * @param frms list of Frames
 */
void Animation::setFrames(std::list<Frame> frms)
{

}
/**
 * Return the list of frames from the Animation.
 */
std::list<Frame> Animation::getFrames()
{
	return frames;
}
/**
 * Set the Animation's version number.
 * @param ver
 */
void Animation::setVersion(std::string ver)
{
	version = ver;
}
/**
 * Return the animation's version.
 */
std::string Animation::getVersion()
{
	return version;
}
/**
 * Check if the parameter has the right extension. If not, add it
 * and then set the Animation's filename.
 * @param fname specified filename
 */
void Animation::setFilename(std::string fname)
{
	//may need to check for invalid char's as well
	if (fname.compare("NoAudioFile") == 0 || 
		fname.find(".wav") != std::string::npos)
		filename = fname;
	else
		filename = fname.append(".wav");
}
/**
 * Return the Animation's filename.
 */
std::string Animation::getFilename()
{
	return filename;
}
/**
 * Set the last color used on the Animation in the editor.
 * @param red [0-255]
 * @param green [0-255]
 * @param blue [0-255]
 */
void Animation::setLastColor(int red, int green, int blue)
{
	lastColor.red = ((red >= 0 && red <= 255) ? red : 0);
	lastColor.green = ((green >= 0 && green <= 255) ? green : 0);
	lastColor.blue = ((blue >= 0 && blue <= 255) ? blue : 0);
}
/**
 * Return the last color used on the Animation in the editor.
 */
rgb Animation::getLastColor()
{
	return lastColor;
}
/**
 * Set the values of the recent colors used on the Animation in the editor.
 * @param recColors array of rgb structures
 */
void Animation::setRecentColors(rgb *recColors)
{
	for (int i = 0; i < NUMCOLORS; i++) {
		recentColors[i] = recColors[i];
	}
}
/**
 * Return a pointer to the array of recently used colors.
 */
rgb* Animation::getRecentColors()
{
	return recentColors;
}
/**
 * Return the number of frames in the Animation.
 */
int Animation::getNumFrames()
{
    return (int)frames.size();
}
/**
 * Set the height of the animation.
 * @param h number of columns
 */
void Animation::setHeight(int h)
{
	height = h;
}
/**
 * Return the height of the Animation.
 */
int Animation::getHeight()
{
	return height;
}
/**
 * Set the width of the Animation.
 * @param w number of rows
 */
void Animation::setWidth(int w)
{
	width = w;
}
/**
 * Return the width of the Animation.
 */
int Animation::getWidth()
{
	return width;
}
/**
 * Add an empty frame to the specified location in the Animation.
 * @param w width of the frame
 * @param h height of the frame
 * @param pos position to add the frame at
 */
void Animation::addFrame(int w, int h, int pos)
{
	Frame frame(w,h);
	frame.setFrameNumber(pos);
	std::list<Frame>::iterator it = std::next(frames.begin(), frame.getFrameNumber());
	frames.insert(it, frame);
}
/**
 * Add a copy of the specified frame right after it.
 * @param frame
 */
void Animation::duplicateFrame(Frame frame)
{
	Frame newFrame = frame;
	//since this is a copy of the previous frame, increment the position
	newFrame.setFrameNumber(newFrame.getFrameNumber()+1);
	std::list<Frame>::iterator it = std::next(frames.begin(), newFrame.getFrameNumber());

	frames.insert(it, newFrame);
}
/**
 * Remove a frame at the specified position.
 * @param pos position
 */
void Animation::removeFrame(int pos)
{
	std::list<Frame>::iterator it = std::next(frames.begin(), pos);
    frames.erase(it);
}
/**
 * Remove the frames between the specified indices (inclusive).
 * @param start starting index
 * @param stop ending index
 */
void Animation::removeFrames(int start, int stop)
{
	std::list<Frame>::iterator curr = std::next(frames.begin(), start);
	std::list<Frame>::iterator end = std::next(frames.begin(), stop);
	std::list<Frame>::iterator tmp = curr;
	while (curr != end) {
		tmp = curr;
		curr++;
		frames.erase(tmp);
	}
	//since the loop stops when end is hit, it must be deleted separately
	frames.erase(end);
}
/**
 * Serialize the Animation into a readable string for output to the .tan file.
 */
std::string Animation::toString()
{
	std::string recColors = "";
	for (int i = 0; i < NUMCOLORS; i++)
	{
		recColors += (std::to_string(recentColors[i].red) + " "
			+ std::to_string(recentColors[i].green) + " "
			+ std::to_string(recentColors[i].blue)
			+ " ");
		//add a new line halfway through
		if (i == (NUMCOLORS / 2) - 1)
			recColors += "\n";
	}

	std::string frms = "";
	for (std::list<Frame>::iterator it = frames.begin(); it != frames.end(); it++)
	{
		frms += it->toString();
	}

	return (version + "\n"
		+ ((filename != "") ? filename : "NoAudioFile") + "\n"
		+ std::to_string(lastColor.red) + " " + std::to_string(lastColor.green) + " " + std::to_string(lastColor.blue) + "\n"
		+ recColors + "\n"
		+ std::to_string(frames.size()) + " " + std::to_string(height) + " " + std::to_string(width) + "\n"
		+ frms);
}
