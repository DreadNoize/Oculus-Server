#ifndef VRSYS_HMD_MESSAGE
#define VRSYS_HMD_MESSAGE

#include <array>
#include <vector>

struct Controller{ // adapted for vive controller
	Controller() :
		status{false},
		id{ -1 },
		app_menu{false},
		grip{false},
		pad_touch{false},
		pad_press{false},
		trigger_p{false},
		pad_x{0.0},
		pad_y{0.0},
		trigger{0.0} 
	{
		matrix.fill(0);
		// initialize identity matrix
		matrix[0] = 1;
		matrix[5] = 1;
		matrix[10] = 1;
		matrix[15] = 1;
	};

	std::array<float, 16> matrix;
	bool status;
	short id;
	bool app_menu;	// Application Menu button on Vive controller
	bool grip;		// Grip button on Vive controller
	bool pad_touch; // touch/untouch on Touchpad
	bool pad_press;	// Touchpad button
	bool trigger_p;	// Trigger is fully pressed
	float pad_x;	// X values on touchpad
	float pad_y;	// Y values on touchpad
	float trigger;	// Trigger value
};

struct Tracker { // e.g. Lighthouse or Oculus tracking device
	Tracker() :
		status{false},
		id{ -1 }
	{
		matrix.fill(0);
		// initialize identity matrix
		matrix[0] = 1;
		matrix[5] = 1;
		matrix[10] = 1;
		matrix[15] = 1;
	};

	std::array<float, 16> matrix;
	bool status;
	short id;
};

struct Message {
	Message() :
		hmd_status{false},
		hmd_id{-1}		
	{
		hmd.fill(0);
		// initialize identity matrix
		hmd[0] = 1;
		hmd[5] = 1;
		hmd[10] = 1;
		hmd[15] = 1;

		for (int i = 0; i < 4; ++i) {
			controller[i] = Controller();
		}
		for (int j  = 0; j < 2; ++j)
		{
			tracker[j] = Tracker();
		}
	};
	
	bool hmd_status;
	short hmd_id;
	std::array<float, 16> hmd;
	std::array<Controller, 4> controller;
	std::array<Tracker, 2> tracker;
};




#endif // VRSYS_HMD_MESSAGE
