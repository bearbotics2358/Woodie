#include <Woodie.h>
#include <Prefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include <string>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

Woodie::Woodie(void):

a_Joystick(JOYSTICK_PORT), // this should be the gamepad - list on port 1
a_Gyro(I2C::kMXP),
a_DiffDrive(LEFT_DRIVE_TALON_ID, RIGHT_DRIVE_TALON_ID)

{
	SmartDashboard::init();  // dont forget, shuffleboard over sd
	a_Gyro.Init();
}

void Woodie::RobotInit()
{

}

void Woodie::RobotPeriodic()
{
	a_Gyro.Update();
	ShuffleboardPeriodicUpdate();
}

void Woodie::DisabledInit()
{

}

void Woodie::DisabledPeriodic()
{
	SmartDashboard::PutString("Enabled: ", "False");
}

void Woodie::AutonomousInit()
{
	a_Gyro.Zero();
}

void Woodie::AutonomousPeriodic()
{
	a_DiffDrive.DriveStraightGyro(a_Gyro.GetAngle(0),a_Joystick.GetRawAxis(0));
}

void Woodie::TeleopInit()
{
	SmartDashboard::PutString("Enabled: ", "True");
	a_DiffDrive.SetDriveType(0);
	a_Gyro.Zero();
}

void Woodie::TeleopPeriodic()
{
	a_DiffDrive.UpdateVal(a_Joystick.GetRawAxis(1), a_Joystick.GetRawAxis(0));
}

void Woodie::TestInit()
{

}

void Woodie::TestPeriodic()
{

}

void Woodie::ShuffleboardPeriodicUpdate(){
	float gyroValue1 = a_Gyro.GetAngle(0);
	float gyroValue2 = a_Gyro.GetAngle(1);
	float gyroValue3 = a_Gyro.GetAngle(2);
	SmartDashboard::PutNumber("Gyro Angle 1: ", gyroValue1);
	SmartDashboard::PutNumber("Gyro Angle 2: ", gyroValue2);
	SmartDashboard::PutNumber("Gyro Angle 3: ", gyroValue3);
	SmartDashboard::PutNumber("Gyro X", a_Gyro.GetX());
	SmartDashboard::PutNumber("Gyro Y", a_Gyro.GetY());
	SmartDashboard::PutNumber("Gyro Z", a_Gyro.GetZ());
}

START_ROBOT_CLASS(Woodie);
