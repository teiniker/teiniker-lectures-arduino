#include "Arduino.h"

#include "RGBLed.h"

int RGBLed::RED[3] = {255, 0, 0};
int RGBLed::GREEN[3] = {0, 255, 0};
int RGBLed::BLUE[3] = {0, 0, 255};
int RGBLed::MAGENTA[3] = {255, 0, 255};
int RGBLed::CYAN[3] = {0, 255, 255};
int RGBLed::YELLOW[3] = {255, 255, 0};
int RGBLed::WHITE[3] = {255, 255, 255};

bool RGBLed::COMMON_ANODE = true;
bool RGBLed::COMMON_CATHODE = false;

RGBLed::RGBLed(int red, int green, int blue, bool common) : _red(red), _green(green), _blue(blue), _common(common), _brightness(100)
{
#if defined(ESP32)
	ledcSetup(0, 5000, 8);
	ledcSetup(1, 5000, 8);
	ledcSetup(2, 5000, 8);

	ledcAttachPin(_red, 0);
	ledcAttachPin(_green, 1);
	ledcAttachPin(_blue, 2);

#else
	pinMode(_red, OUTPUT);
	pinMode(_green, OUTPUT);
	pinMode(_blue, OUTPUT);
#endif
}

void RGBLed::off()
{
	color(0, 0, 0);
}

void RGBLed::brightness(int rgb[3], int brightness)
{
	_brightness = brightness;
	intensity(rgb[0], rgb[1], rgb[2], brightness);
}

void RGBLed::brightness(int red, int green, int blue, int brightness)
{
	_brightness = brightness;
	intensity(red, green, blue, brightness);
}

void RGBLed::brightness(int brightness)
{
	_brightness = brightness;
}

void RGBLed::intensity(int red, int green, int blue, int brightness)
{
	if (brightness > 100)
		brightness = 100;
	if (brightness < 0)
		brightness = 0;

	red = (red * brightness) / 100;
	green = (green * brightness) / 100;
	blue = (blue * brightness) / 100;
	color(red, green, blue);
}

void RGBLed::flash(int rgb[3], int duration)
{
	blink(rgb[0], rgb[1], rgb[2], duration, duration);
}

void RGBLed::flash(int rgb[3], int onDuration, int duration)
{
	blink(rgb[0], rgb[1], rgb[2], onDuration, duration);
}

void RGBLed::flash(int red, int green, int blue, int duration)
{
	blink(red, green, blue, duration, duration);
}

void RGBLed::flash(int red, int green, int blue, int onDuration, int duration)
{
	blink(red, green, blue, onDuration, duration);
}

void RGBLed::blink(int red, int green, int blue, int onDuration, int duration)
{
	if (onDuration < 0)
		onDuration = 0;
	if (duration < 0)
		duration = 0;

	intensity(red, green, blue, _brightness);
	delay(onDuration);
	off();
	delay(duration);
}

void RGBLed::setColor(int rgb[3])
{
	intensity(rgb[0], rgb[1], rgb[2], _brightness);
}

void RGBLed::setColor(int red, int green, int blue)
{
	intensity(red, green, blue, _brightness);
}

void RGBLed::color(int red, int green, int blue)
{
	if (red < 0)
	{
		red = 0;
	}
	if (red > 255)
	{
		red = 255;
	}

	if (green < 0)
	{
		green = 0;
	}
	if (green > 255)
	{
		green = 255;
	}

	if (blue < 0)
	{
		blue = 0;
	}
	if (blue > 255)
	{
		blue = 255;
	}

	if (_common == COMMON_ANODE)
	{
#if defined(ESP32)
		ledcWrite(0, 255 - red);
		ledcWrite(1, 255 - green);
		ledcWrite(2, 255 - blue);
#else
		analogWrite(_red, 255 - red);
		analogWrite(_green, 255 - green);
		analogWrite(_blue, 255 - blue);
#endif
	}
	else
	{
#if defined(ESP32)
		ledcWrite(0, red);
		ledcWrite(1, green);
		ledcWrite(2, blue);
#else
		analogWrite(_red, red);
		analogWrite(_green, green);
		analogWrite(_blue, blue);
#endif
	}
}

void RGBLed::fadeOut(int rgb[3], int steps, int duration)
{
	fade(rgb[0], rgb[1], rgb[2], steps, duration, true);
}

void RGBLed::fadeOut(int red, int green, int blue, int steps, int duration)
{
	fade(red, green, blue, steps, duration, true);
}

void RGBLed::fadeIn(int rgb[3], int steps, int duration)
{
	fade(rgb[0], rgb[1], rgb[2], steps, duration, false);
}

void RGBLed::fadeIn(int red, int green, int blue, int steps, int duration)
{
	fade(red, green, blue, steps, duration, false);
}

void RGBLed::fade(int red, int green, int blue, int steps, int duration, bool out)
{
	if (duration < 0)
		duration = 0;
	if (steps < 1)
		steps = 1;

	if (out)
	{
		for (int i = steps; i >= 0; i--)
		{
			fade(red, green, blue, steps, duration, i * 255 / steps, i > 0);
		}
	}
	else
	{
		for (int i = 0; i <= steps; i++)
		{
			fade(red, green, blue, steps, duration, i * 255 / steps, i < steps);
		}
	}
}

void RGBLed::fade(int red, int green, int blue, int steps, int duration, int value, bool wait)
{
	float brightness = float(value) / 255.f;

	intensity(red * brightness, green * brightness, blue * brightness, _brightness);

	if (wait)
	{
		delay((unsigned long)(duration / steps));
	}
}

void RGBLed::crossFade(int rgbFrom[3], int rgbTo[3], int steps, int duration)
{
	crossFade(rgbFrom[0], rgbFrom[1], rgbFrom[2], rgbTo[0], rgbTo[1], rgbTo[2], steps, duration);
}

void RGBLed::crossFade(int fromRed, int fromGreen, int fromBlue, int toRed, int toGreen, int toBlue, int steps, int duration)
{
	// Determine per color change
	//   toValue - fromValue = deltaValue
	int deltaRed = toRed - fromRed;
	int deltaGreen = toGreen - fromGreen;
	int deltaBlue = toBlue - fromBlue;

	// Determine change per step per color
	//   deltaValue / steps
	//   Note: Forcing casting to floats to ensure smooth fades
	//         with large number of steps
	float changeRed = (float) deltaRed / (float) steps;
	float changeGreen = (float) deltaGreen / (float) steps;
	float changeBlue = (float) deltaBlue / (float) steps;

	// run through steps
	for (int i = 0; i <= steps; i++)
	{
		// Determine the new value for each color based on the step
		//  stepValue = fromValue + (changeValue * stepNumber)
		int stepRed = fromRed + (changeRed * i);
		int stepGreen = fromGreen + (changeGreen * i);
		int stepBlue = fromBlue + (changeBlue * i);

		// Make step change in color
		intensity(stepRed, stepGreen, stepBlue, _brightness);

		// delay based on total duration requested and number of steps
		if (i < steps)
		{
			delay((unsigned long)(duration / steps));
		}
	}
}

void RGBLed::gradient(int rgbFrom[3], int rgbTo[3], int step)
{
	gradient(rgbFrom[0], rgbFrom[1], rgbFrom[2], rgbTo[0], rgbTo[1], rgbTo[2], step);
}

void RGBLed::gradient(int fromRed, int fromGreen, int fromBlue, int toRed, int toGreen, int toBlue, int step)
{
	// Determine per color change
	//   toValue - fromValue = deltaValue
	int deltaRed = toRed - fromRed;
	int deltaGreen = toGreen - fromGreen;
	int deltaBlue = toBlue - fromBlue;

	// Determine change per step per color
	//   deltaValue / steps
	//   Note: Forcing casting to floats to ensure smooth fades
	//         with large number of steps
	float changeRed = (float) deltaRed / (float)255;
	float changeGreen = (float) deltaGreen / (float) 255;
	float changeBlue = (float) deltaBlue / (float) 255;

	
	// Determine the new value for each color based on the step
	//  stepValue = fromValue + (changeValue * stepNumber)
	int stepRed = fromRed + (changeRed * step);
	int stepGreen = fromGreen + (changeGreen * step);
	int stepBlue = fromBlue + (changeBlue * step);

	// Make step change in color
	intensity(stepRed, stepGreen, stepBlue, _brightness);
}
