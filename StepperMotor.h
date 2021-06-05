#ifndef StepperMotor_h
#define StepperMotor_h

#include <Arduino.h>
#include <X9C103S.h>        // Biblioteca de controle do potenciômetro digital X9C103S

// Classe Principal
class StepperMotor {
    public:
        // Funções
        void SetMode(byte Mode);            // Seleção do modo de funcionamento do motor
        void SetPins(byte _pFault, byte _pDir, byte _pSleep, byte _pReset, byte _pMode2, byte _pMode1, byte _pEnable, byte _pMode0, byte _pStep, byte _pCS, byte _pINC, byte _pUD);   // Define automaticamente os pinos do Driver como IN/OUT
        
        // Parametrização do Motor
        float Vel;                          // Velocidade de movimento [°/s]
        byte Dir;                           // Sentido de Giro: 0->CW / 1->CCW

    private:
        // Pinos do Driver DRV8825
        byte pinFault;                      // Diagnóstico de Falha
        byte pinDir;                        // Sentido de Giro
        byte pinSleep;                      // Sleep Driver
        byte pinReset;                      // Reset do Driver
        byte pinMode2;                      // Seleção de modo de operação 2
        byte pinMode1;                      // Seleção de modo de operação 1
        byte pinEnable;                     // Enable Driver
        byte pinMode0;                      // Seleção de modo de operação 0
        byte pinStep;                       // Steps para o Motor
};

#endif


















/*
#ifndef PID_h
#define PID_h

#include <Arduino.h>

class PID {

    public:
        PID();
        double compute(double PV);

		double Kp;
		double Ki;
		double Kd;
		double Setpoint;
		double DeadBand;
		double MaxMV;
		double MinMV;
    
    private:
        double error;
	    double lastSample;
	    double P, I, D;
		double MV;
	    long lastCompute;
};

#endif



PID	    KEYWORD1

compute	KEYWORD2

Kp   LITERAL1
Ki   LITERAL1
Kd   LITERAL1
Setpoint   LITERAL1
DeadBand   LITERAL1
MaxMV   LITERAL1
MinMV   LITERAL1

*/