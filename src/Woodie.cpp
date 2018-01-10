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

a_Joystick(JOYSTICK_PORT) // this should be the gamepad - list on port 1

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

}

void Woodie::TestInit()
{

}

void Woodie::TestPeriodic()
{

}

START_ROBOT_CLASS(Woodie);
