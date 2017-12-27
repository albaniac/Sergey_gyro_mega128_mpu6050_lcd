//#include "pressurer.h"
#ifndef MY_PRESSURER_H
#define MY_PRESSURER_H

#define PRESSURER_WEEL_FIRST_LEFT_PIN_UP 0
#define PRESSURER_WEEL_FIRST_RIGHT_PIN_UP 1
#define PRESSURER_WEEL_LAST_LEFT_PIN_UP 2
#define PRESSURER_WEEL_LAST_RIGHT_PIN_UP 3

#define PRESSURER_WEEL_FIRST_LEFT_PIN_DOWN 4
#define PRESSURER_WEEL_FIRST_RIGHT_PIN_DOWN 5
#define PRESSURER_WEEL_LAST_LEFT_PIN_DOWN 6
#define PRESSURER_WEEL_LAST_RIGHT_PIN_DOWN 7

class Pressurer{
public:
	Pressurer();
	void Up();
	void Down();
  void Stop();

	int pin_up_number_;
	int pin_down_number_;

private:
};
#endif
