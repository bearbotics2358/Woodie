#ifndef SRC_WOODIE_H_
#define SRC_WOODIE_H_

#include <WPILib.h>
#include <SerialPort.h>
#include <Prefs.h>
#include <IterativeRobot.h>
#include "SmartDashboard/SmartDashboard.h"
#include "SmartDashboard/SendableChooser.h"
#include "ctre/Phoenix.h"

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

private:
	Joystick a_Joystick;
	WPI_TalonSRX a_leftDrive;
	WPI_TalonSRX a_rightDrive;
	DifferentialDrive a_Drivetrain;
};

#endif
