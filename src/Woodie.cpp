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
a_leftDrive(LEFT_DRIVE_TALON_ID),
a_rightDrive(RIGHT_DRIVE_TALON_ID),
a_Drivetrain(a_leftDrive, a_rightDrive)

{
	SmartDashboard::init();

}

void Woodie::RobotInit()
{

}

void Woodie::RobotPeriodic()
{

}

void Woodie::DisabledInit()
{

}

void Woodie::DisabledPeriodic()
{
	SmartDashboard::PutString("Enabled: ", "False");
}

void Woodie::AutonomousInit()
{}

void Woodie::AutonomousPeriodic()
{}

void Woodie::TeleopInit()
{
	SmartDashboard::PutString("Enabled: ", "True");
}

void Woodie::TeleopPeriodic()
{
	a_Drivetrain.ArcadeDrive(a_Joystick.GetRawAxis(0), a_Joystick.GetRawAxis(1));
}

void Woodie::TestInit()
{

}

void Woodie::TestPeriodic()
{

}

START_ROBOT_CLASS(Woodie);
