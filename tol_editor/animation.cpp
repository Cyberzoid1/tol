/**
* @class Animation
*/

#include "animation.h"
#include "rgb.h"

/**
 * Construct a new Animation with the following default values;
 * version: 0.4, filename: (empty string), height: 10. width: 4.
 */
Animation::Animation()
{
	version = "0.4";
    filename = "NoAudioFile";
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
<<<<<<< Updated upstream
 * Set the list of frames in the animation and update numFrames.
 * @param frms list of Frames
=======
 * TODO: determine what we want setFrames to do
 * @param frms A list of Frames representing ...?
>>>>>>> Stashed changes
 */
void Animation::setFrames(std::list<Frame> frms)
{
    frames = frms;
    numFrames = (int)frames.size();
}

/**
 * Returns a copy of the frames that make up the current animation.
 * @return STL List containing frame objects with a length equal to the
 * current number of frames in the animation.
 */
std::list<Frame> Animation::getFrames()
{
	return frames;
}
/**
 * Set the Animation's version number.
 * @param ver String representation of the version being used for
 * the .tan file.
 * @return Void.
 */
void Animation::setVersion(std::string ver)
{
	version = ver;
}

/**
 * Returns the animation's version.
 * @return A string object representing the animations version number.
 */
std::string Animation::getVersion()
{
	return version;
}
/**
 * Check if the parameter has the right extension. If not, add it
 * and then set the Animation's filename.
 * @param fname specified filename.
 * @return Void.
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
 * Returns the file name associated with the animation.
 * @return A string object containing the filename.
 */
std::string Animation::getFilename()
{
	return filename;
}

/**
 * Sets the last color used while creating the animation.
 * @param red An integer representation of the red component.
 * @param green An integer representation of the green component.
 * @param blue An integer representation of the blue component.
 * @return Void.
 */
void Animation::setLastColor(int red, int green, int blue)
{
    lastColor.setColor(red, green, blue);
}
/**
 * Returns the last color used while creating the current animation.
 * @return A copy of an RGB Object containing the color data.
 */
RGB Animation::getLastColor()
{
	return lastColor;
}
/**
 * Set the values of the recent colors used on the Animation in the editor.
 * @param recColors array of rgb structures
 */
void Animation::setRecentColors(RGB *recColors)
{
	for (int i = 0; i < NUMCOLORS; i++) {
		recentColors[i] = recColors[i];
	}
}
/**
 * We need to look at what this does
 */
RGB* Animation::getRecentColors()
{
	return recentColors;
}
/**
 * Returns the current number of frames used in the Animation.
 * @return An int value representing the number of frames used
 * in the current animation.
 */
int Animation::getNumFrames()
{
    return (int)frames.size();
}
/**
 * Set the number of cells that comprise the height of the animation frame.
 * @param h Number of cell objects in a column.
 */
void Animation::setHeight(int h)
{
	height = h;
}
/**
 * Returns the number of cells that make up the column of a frame.
 * @return An integer value representing the number of cell
 * objects per column.
 */
int Animation::getHeight()
{
	return height;
}

/**
 * Set the number of cells that comprise the width of the animation frame.
 * @param h Number of cell objects in a row.
 */
void Animation::setWidth(int w)
{
	width = w;
}

/**
 * Returns the number of cells that make up the row of a frame.
 * @return An integer value representing the number of cell
 * objects per row.
 */
int Animation::getWidth()
{
	return width;
}

/**
 * Add an empty frame object to the specified location in the Animation.
 * @param w Width of the frame in cells.
 * @param h Height of the frame in cells.
 * @param pos Index of the position to add the frame
 * @return Void.
 */
void Animation::addFrame(int w, int h, int pos)
{
	Frame frame(w,h);
	frame.setFrameNumber(pos);
	std::list<Frame>::iterator it = std::next(frames.begin(), frame.getFrameNumber());
	frames.insert(it, frame);
}

/**
 * Creates a copy of the frame passed into the method then inserts
 * it directly after the frame that was duplicated.
 * @param frame The frame object to duplicate.
 * @return Void.
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
 * Removes a frame at the specified position within the frame list.
 * @param pos Index position of the frame to remove.
 * @return Void.
 */
void Animation::removeFrame(int pos)
{
	std::list<Frame>::iterator it = std::next(frames.begin(), pos);
    frames.erase(it);
}

/**
 * Removes all of the frames between the specified indices from the
 * frame list (inclusive).
 * @param start Index of the first frame to remove.
 * @param stop Index of the last frame to remove.
 * @return Void.
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
 * Serializes the Animation into a string suitable for output in a .tan file.
 * @return A string object consisting of the tan file header information followed
 * by the formatted frames and their associated start times in milliseconds.
 */
std::string Animation::toString()
{
	std::string recColors = "";
	for (int i = 0; i < NUMCOLORS; i++)
	{
        recColors += (std::to_string(recentColors[i].getRed()) + " "
            + std::to_string(recentColors[i].getGreen()) + " "
            + std::to_string(recentColors[i].getBlue())
            + " ");
	}

	std::string frms = "";
	for (std::list<Frame>::iterator it = frames.begin(); it != frames.end(); it++)
	{
		frms += it->toString();
	}

	return (version + "\n"
		+ ((filename != "") ? filename : "NoAudioFile") + "\n"
        + std::to_string(lastColor.getRed()) + " " + std::to_string(lastColor.getGreen()) + " " + std::to_string(lastColor.getBlue()) + "\n"
		+ recColors + "\n"
		+ std::to_string(frames.size()) + " " + std::to_string(height) + " " + std::to_string(width) + "\n"
		+ frms);
}
