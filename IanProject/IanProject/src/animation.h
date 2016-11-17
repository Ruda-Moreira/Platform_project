#ifndef animation_h
#define animation_h

#include "ofMain.h"
#include <vector>
#include <string>


class Animation {
private:
	vector <ofImage*> images;
	ofImage* img;
	int frame;
	bool repeat;
	float frameTime;
	float time;

public:
	Animation();
	void update(float secs);
	void draw(const ofVec2f& position);
	void addFrame(string image);
	void setFrameTime(float f_time);
	void setFrame(int _frame);
	const ofVec2f& getFrameSize() const;
};

#endif
