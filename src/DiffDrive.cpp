#include <WPILib.h>
#include "DiffDrive.h"
#include "ctre/Phoenix.h"
#include <Math.h>
#include <pathfinder.h>

DiffDrive::DiffDrive(int leftDriveOne, int rightDriveOne)
: a_leftDriveOne(leftDriveOne),
  a_rightDriveOne(rightDriveOne),
  a_Drivetrain(a_leftDriveOne, a_rightDriveOne)
{
	driveType = 0;
	targetPositionRotations = 10.0 * 4096; /* 10 Rotations in either direction??? */
	kSlotIdx = 0;
	kPIDLoopIdx = 0;
	kTimeoutMs = 10;
}

void DiffDrive::Init()
{
	InvertLeftDrive();
	InvertRightDrive();
	UpdateVal(0.0,0.0);
}

void DiffDrive::Init(float p, float i, float d, float f){
	Init();
	SetLeftPIDF(p,i,d,f);
	SetRightPIDF(p,i,d,f);
}

void DiffDrive::SetLeftPIDF(float p, float i, float d, float f){
	a_leftDriveOne.Config_kP(kPIDLoopIdx, p, kTimeoutMs);
	a_leftDriveOne.Config_kI(kPIDLoopIdx, i, kTimeoutMs);
	a_leftDriveOne.Config_kD(kPIDLoopIdx, d, kTimeoutMs);
	a_leftDriveOne.Config_kF(kPIDLoopIdx, f, kTimeoutMs);
}

void DiffDrive::SetRightPIDF(float p, float i, float d, float f){
	a_rightDriveOne.Config_kP(kPIDLoopIdx, p, kTimeoutMs);
	a_rightDriveOne.Config_kI(kPIDLoopIdx, i, kTimeoutMs);
	a_rightDriveOne.Config_kD(kPIDLoopIdx, d, kTimeoutMs);
	a_rightDriveOne.Config_kF(kPIDLoopIdx, f, kTimeoutMs);
}

void DiffDrive::SetDriveType(int type)
{
	driveType = type;
}

void DiffDrive::DisableMotorSafetyTraitor(){
	a_leftDriveOne.SetSafetyEnabled(false);
	a_rightDriveOne.SetSafetyEnabled(false);
}

void DiffDrive::InvertLeftDrive(){
	a_leftDriveOne.SetInverted(true);
}

void DiffDrive::InvertRightDrive(){
	a_rightDriveOne.SetInverted(true);
}

void DiffDrive::Update(Joystick &stick1, Joystick &stick2, Joystick &stick3, Joystick &stick4)
{
	switch (driveType) {
	  case 0: // ArcadeDrive from the flightstick with a Z
		  a_Drivetrain.ArcadeDrive((stick2.GetRawAxis(1)), stick2.GetRawAxis(0), false);
	    break;
	  case 1: // CurvatureDrive works better at high speeds.
		  	  // Using flightstick with a z
		  a_Drivetrain.CurvatureDrive(stick2.GetRawAxis(1), stick2.GetRawAxis(0), false);
	    break;
	  case 2: // Traditional Two Stick Tank.
		  	  // Uses the two flightsticks without z axes.
		  a_Drivetrain.TankDrive((stick2.GetRawAxis(1)), (stick3.GetRawAxis(1)), false);
		break;
	  default:
		  a_Drivetrain.TankDrive(0, 0, false); // theo disable
	}
}

void DiffDrive::UpdateVal(float left, float right){
	a_Drivetrain.TankDrive(left, right, false);
}

bool DiffDrive::UpdateAngle(float curAngle, float tarAngle){ // rets true when its right.
	if(curAngle > (tarAngle - 3)) {
		if(fabs(tarAngle - curAngle) > 10) {
			UpdateVal(-0.3, 0.3);
		} else {
			UpdateVal(-0.2, 0.2);
		}
	} else if(curAngle < tarAngle + 3) {
		if(fabs(tarAngle - curAngle) > 10) {
			UpdateVal(0.3, -0.3);
		} else {
			UpdateVal(0.2, -0.2);
		}
	} else {
		UpdateVal(0.0, 0.0);
		return true;
	}
	return false;
}

void DiffDrive::DriveStraightGyro(float curAngle, float tarVelo){
	if(curAngle > 0.5) {
		UpdateVal(tarVelo * 0.95, tarVelo * 1.05);
	} else if(curAngle < -0.5) {
		UpdateVal(tarVelo * 1.05, tarVelo * 0.95);
	} else {
		UpdateVal(tarVelo, tarVelo);
	}
}
