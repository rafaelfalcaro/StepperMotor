#include "Arduino.h"
#include "StepperMotor.h"

//************************************************************************************
// Funções Públicas

// Seleção do modo de funcionamento do Motor
void StepperMotor::SetMode(byte _mode) {
    if (_mode == 0) {                           // Full Step
        digitalWrite(pinMode0, LOW);
        digitalWrite(pinMode1, LOW);
        digitalWrite(pinMode2, LOW);
    }
    else if (_mode == 1) {                      // Half Step
        digitalWrite(pinMode0, HIGH);
        digitalWrite(pinMode1, LOW);
        digitalWrite(pinMode2, LOW);
    }
    else if (_mode == 2) {                      // 1/4 Microstepping
        digitalWrite(pinMode0, LOW);
        digitalWrite(pinMode1, HIGH);
        digitalWrite(pinMode2, LOW);
    }
    else if (_mode == 3) {                      // 1/8 Microstepping
        digitalWrite(pinMode0, HIGH);
        digitalWrite(pinMode1, HIGH);
        digitalWrite(pinMode2, LOW);
    }
    else if (_mode == 4) {                      // 1/16 Microstepping
        digitalWrite(pinMode0, LOW);
        digitalWrite(pinMode1, LOW);
        digitalWrite(pinMode2, HIGH);
    }
    else if (_mode == 5) {                      // 1/32 Microstepping
        digitalWrite(pinMode0, HIGH);
        digitalWrite(pinMode1, HIGH);
        digitalWrite(pinMode2, HIGH);
    }
}

// Define automaticamente os pinos do Driver como IN/OUT
void StepperMotor::SetPins(byte _pFault, byte _pDir, byte _pSleep, byte _pReset, byte _pMode2, byte _pMode1, byte _pEnable, byte _pMode0, byte _pStep, byte _pCS, byte _pINC, byte _pUD) {
    pinFault  = _pFault;
    pinDir    = _pDir;
    pinSleep  = _pSleep;
    pinReset  = _pReset;
    pinMode2  = _pMode2;
    pinMode1  = _pMode1;
    pinEnable = _pEnable;
    pinMode0  = _pMode0;
    pinStep   = _pStep;
    
    pinMode(pinFault , INPUT);
    pinMode(pinDir   , OUTPUT);
    pinMode(pinSleep , OUTPUT);
    pinMode(pinReset , OUTPUT);
    pinMode(pinMode2 , OUTPUT);
    pinMode(pinMode1 , OUTPUT);
    pinMode(pinEnable, OUTPUT);
    pinMode(pinMode0 , OUTPUT);
    pinMode(pinStep  , OUTPUT);
    X9C103S(_pINC, _pUD, _pCS);
}


//************************************************************************************
// Funções Privadas

/*void StepperMotor::Jog(byte _dir) {
    digitalWrite(PinEnable, LOW);
    digitalWrite(PinReset, HIGH);
    digitalWrite(PinSleep, HIGH);
    digitalWrite(PinStep, HIGH);
    digitalWrite(PinDir, _dir);
}


*/











/*
#include "PID.h"

PID::PID() {
}

double PID::compute(double PV) {

	error = Setpoint - PV;

	float deltaTime = (millis() - lastCompute) / 1000.0;
	lastCompute = millis();

	if (abs(error) > DeadBand) {
		P = error * Kp;
		I = I + (error * Ki) * deltaTime;
		D = (lastSample - PV) * Kd / deltaTime;
	}

	lastSample = PV;

	return P + I + D + 50;
	//return map((P + I + D), (Setpoint - 100), Setpoint, 0, 100);
}
*/