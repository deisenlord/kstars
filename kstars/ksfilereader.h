/***************************************************************************
                          ksfilereader.h  -  description
                             -------------------
    begin                : Tue Jan 28 2003
    copyright            : (C) 2003 by Heiko Evermann
    email                : heiko@evermann.de
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#ifndef KSFILEREADER_H
#define KSFILEREADER_H

#include <tqobject.h>
#include <tqstringlist.h>

/**@class KSFileReader
	*This class will read an entire file into a TQStringList, where each item
	*in the list is a line in the file.  It can then access each line in the 
	*list very quickly.
	*@author Heiko Evermann
	*@version 1.0
	*/

class TQFile;
class TQString;

class KSFileReader : public TQObject  {
	Q_OBJECT
public:
	/**Constructor.  Read an entire file into a TQStringList object.
		*@p file the file to be read
		*/
	KSFileReader( TQFile& file);
	
	/**Destructor*/
	~KSFileReader();

	/**@return TRUE if we are not yet at the end of the file.
		*/
	bool hasMoreLines();
	
	/**Read a line from the file, and increment the "current line" counter.
		*@return the line that we read, as a TQString.
		*/
	TQString& readLine();

	/**Go to a specific line in the file.
		*@p i the line number to skip to.
		*/
	bool setLine(int i);

private:
	/** After loading the whole file, we split it into lines and keep them here. */
	TQStringList lines;
	/** How many lines do we have in the file? */
	int numLines;
	/** Which line are we at? */
	int curLine;
};

#endif
