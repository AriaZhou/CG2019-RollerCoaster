/************************************************************************
     File:        Track.cpp

     Author:     
                  Michael Gleicher, gleicher@cs.wisc.edu
     Modifier
                  Yu-Chi Lai, yu-chi@cs.wisc.edu
     
     Comment:     Container for the "World"

						This provides a container for all of the "stuff" 
						in the world.

						It could have been all global variables, or it could 
						have just been
						contained in the window. The advantage of doing it 
						this way is that
						we might have multiple windows looking at the same 
						world. But, I don't	think we'll actually do that.

						See the readme for commentary on code style

     Platform:    Visio Studio.Net 2003/2005

*************************************************************************/

#include "Track.H"

//****************************************************************************
//
// * Constructor
//============================================================================
CTrack::
CTrack() : trainU(0)
//============================================================================
{
	resetPoints();
}

//****************************************************************************
//
// * provide a default set of points
//============================================================================
void CTrack::
resetPoints()
//============================================================================
{

	points.clear();
	points.push_back(ControlPoint(glm::vec3(50,5,0)));
	points.push_back(ControlPoint(glm::vec3(0,5,50)));
	points.push_back(ControlPoint(glm::vec3(-50,5,0)));
	points.push_back(ControlPoint(glm::vec3(0,5,-50)));

	// we had better put the train back at the start of the track...
	trainU = 0.0;
	a = 0;
	
}

//****************************************************************************
//
// * Handy utility to break a string into a list of words
//============================================================================
void breakString(char* str, std::vector<const char*>& words) 
//============================================================================
{
	// start with no words
	words.clear();

	// scan through the string, starting at the beginning
	char* p = str;

	// stop when we hit the end of the string
	while(*p) {
		// skip over leading whitespace - stop at the first character or end of string
		while (*p && *p<=' ') p++;

		// now we're pointing at the first thing after the spaces
		// make sure its not a comment, and that we're not at the end of the string
		// (that's actually the same thing)
		if (! (*p) || *p == '#')
		break;

		// so we're pointing at a word! add it to the word list
		words.push_back(p);

		// now find the end of the word
		while(*p > ' ') p++;	// stop at space or end of string

		// if its ethe end of the string, we're done
		if (! *p) break;

		// otherwise, turn this space into and end of string (to end the word)
		// and keep going
		*p = 0;
		p++;
	}
}

//****************************************************************************
//
// * The file format is simple
//   first line: an integer with the number of control points
//	  other lines: one line per control point
//   either 3 (X,Y,Z) numbers on the line, or 6 numbers (X,Y,Z, orientation)
//============================================================================
void CTrack::
readPoints(const char* filename)
//============================================================================
{
	FILE* fp = fopen(filename,"r");
	if (!fp) {
		printf("Can't Open File!\n");
	} 
	else {
		char buf[512];

		// first line = number of points
		fgets(buf,512,fp);
		size_t npts = (size_t) atoi(buf);

		if( (npts<4) || (npts>65535)) {
			printf("Illegal Number of Points Specified in File");
		} else {
			points.clear();
			// get lines until EOF or we have enough points
			while( (points.size() < npts) && fgets(buf,512,fp) ) {
				glm::vec3 pos,orient;
				vector<const char*> words;
				breakString(buf,words);
				if (words.size() >= 3) {
					pos.x = (float) strtod(words[0],0);
					pos.y = (float) strtod(words[1],0);
					pos.z = (float) strtod(words[2],0);
				} else {
					pos.x=0;
					pos.y=0;
					pos.z=0;
				}
				if (words.size() >= 6) {
					orient.x = (float) strtod(words[3],0);
					orient.y = (float) strtod(words[4],0);
					orient.z = (float) strtod(words[5],0);
				} else {
					orient.x = 0;
					orient.y = 1;
					orient.z = 0;
				}
				glm::normalize(orient);
				//orient.normalize();
				points.push_back(ControlPoint(pos,orient));
			}
		}
		fclose(fp);
	}
}

//****************************************************************************
//
// * write the control points to our simple format
//============================================================================
void CTrack::
writePoints(const char* filename)
//============================================================================
{
	FILE* fp = fopen(filename,"w");
	if (!fp) {
		printf("Can't open file for writing");
	} else {
		fprintf(fp,"%d\n",points.size());
		for(size_t i=0; i<points.size(); ++i)
			fprintf(fp,"%g %g %g %g %g %g\n",
				points[i].pos.x, points[i].pos.y, points[i].pos.z, 
				points[i].orient.x, points[i].orient.y, points[i].orient.z);
		fclose(fp);
	}
}

void CTrack::calTotalLen(int trackType)
{
	totalLen = 0;
	glm::vec3 qt, qt0, qt1, firstP;
	float t;
	switch (trackType) 
	{
	case 0:
	{
		for (size_t i = 0; i < points.size(); ++i) {

			glm::vec3 startP =points[i].pos;
			glm::vec3 endP = points[((i + 1) % points.size())].pos;

			qt = startP;

			for (int j = 1; j <= subdivision; j++)
			{
				t = j / subdivision;

				qt0 = qt;
				qt = (1.f - t) * startP + t * endP;
				qt1 = qt;

				if (i == 0 && j == 1) 
					firstP = qt0;

				totalLen += glm::distance(qt0, qt1);
				
			}
		}
	}break;

	case 1:
	{
		for (size_t i = 0; i < this->points.size(); ++i) {

			glm::vec3 P0 = points[i % points.size()].pos;
			glm::vec3 P1 = points[((i + 1) % points.size())].pos;
			glm::vec3 P2 = points[(i + 2) % points.size()].pos;
			glm::vec3 P3 = points[((i + 3) % points.size())].pos;

			for (int j = 0; j <= subdivision; j++)
			{
				t = j / subdivision;

				float b0 = (-1 * t*t*t + 2 * t*t + (-1) * t) * tension;
				float b1 = ((2 / tension - 1) *t*t*t + (-3 / tension + 1) *t*t + 1 / tension) * tension;
				float b2 = ((-2 / tension + 1) *t*t*t + (3 / tension - 2) *t*t + t) * tension;
				float b3 = (1 * t*t*t + (-1) *t*t) * tension;

				/*float b0 = (-t * t*t + 2 * t*t - t) / 2.0f;
				float b1 = (3 * t*t*t - 5 * t*t + 2) / 2.0f;
				float b2 = (-3 * t*t*t + 4 * t*t + t) / 2.0f;
				float b3 = (t * t*t - t * t) / 2.0f;*/

				qt0 = qt;
				qt = glm::vec3(b0 * P0.x + b1 * P1.x + b2 * P2.x + b3 * P3.x,
					b0 * P0.y + b1 * P1.y + b2 * P2.y + b3 * P3.y,
					b0 * P0.z + b1 * P1.z + b2 * P2.z + b3 * P3.z);
				qt1 = qt;


				if (i == 0 && j == 1)
					firstP = qt0;

				if (i == 0 && j == 0)
					continue;

				totalLen += glm::distance(qt0, qt1);

			}
		}
	}break;

	case 2:
	{
		for (size_t i = 0; i < this->points.size(); ++i) {

			glm::vec3 P0 = points[i % points.size()].pos;
			glm::vec3 P1 = points[((i + 1) % points.size())].pos;
			glm::vec3 P2 = points[(i + 2) % points.size()].pos;
			glm::vec3 P3 = points[((i + 3) % points.size())].pos;

			for (int j = 0; j <= subdivision; j++)
			{

				t = j / subdivision;
				float b0 = (1 - t) * (1 - t) * (1 - t) / 6.0f;
				float b1 = (3 * t*t*t - 6 * t*t + 4) / 6.0f;
				float b2 = (-3 * t*t*t + 3 * t*t + 3 * t + 1) / 6.0f;
				float b3 = t * t*t / 6.0f;

				qt0 = qt;
				qt = glm::vec3(b0 * P0.x + b1 * P1.x + b2 * P2.x + b3 * P3.x,
					b0 * P0.y + b1 * P1.y + b2 * P2.y + b3 * P3.y,
					b0 * P0.z + b1 * P1.z + b2 * P2.z + b3 * P3.z);
				qt1 = qt;

				if (i == 0 && j == 1)
					firstP = qt0;

				if (i == 0 && j == 0)
					continue;

				totalLen += glm::distance(qt0, qt1);
			}
		}
	}break;

	default: break;
	}
}
