#ifndef SRC_WOODIE_H_
#define SRC_WOODIE_H_

#include <WPILib.h>
#include <SerialPort.h>
#include <IterativeRobot.h>
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"
#include "ctre/Phoenix.h"
#include <DiffDrive.h>
#include <JrimmyGyro.h>

class Woodie : public IterativeRobot {
public:
	Woodie(void);
	void RobotInit(void);
	void RobotPeriodic(void);
	void DisabledInit(void);
	void DisabledPeriodic(void);
	void TeleopInit(void);
	void TeleopPeriodic(void);
	void TestInit(void);
	void TestPeriodic(void);
	void AutonomousInit(void);
	void AutonomousPeriodicFull(void);
	void AutonomousPeriodic(void);
	void AutonomousPeriodicSimple(void);
	void ShuffleboardPeriodicUpdate(void);

private:
	Joystick a_Joystick;
	JrimmyGyro a_Gyro;
	DiffDrive a_DiffDrive;
};

#endif
