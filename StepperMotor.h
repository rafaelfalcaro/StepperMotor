#ifndef StepperMotor_h
#define StepperMotor_h

#include <Arduino.h>
#include <X9C103S.h>            // Biblioteca de controle do potenciômetro digital X9C103S

// Definições das constantes
#define RS       8400.0         // RV1
#define RL       100047.0       // R4 + R6
#define RT       5600.0         // R2
#define CT       0.00000001     // C4
#define VIN      5.0            // [V]
#define R5       2700.0         // R5

// Classe Principal
class StepperMotor {
    public:
        // Funções
        void Brake();                       // Mantém o motor na posição atual
        void Home();                        // Movimento automático até a posição de Home
        void Jog(bool _dir);                // Movimento em Jog
        void Kill();                        // Libera o eixo do Motor
        void MoveInc(int _pos);             // Movimento incremental
        void MoveTo(int _pos);              // Movimento absoluto
        void SetMode(byte Mode);            // Seleção do modo de funcionamento do motor
        void SetPins(byte _pFault, byte _pDir, byte _pSleep, byte _pReset, byte _pMode2, byte _pMode1, byte _pEnable, byte _pMode0, byte _pStep, byte _pCS, byte _pINC, byte _pUD);   // Define automaticamente os pinos do Driver como IN/OUT

        // Objeto da biblioteca X9C103S
        X9C103S DigiPot;

        // Parametrização do Motor
        byte Dir;                           // Sentido de Giro: 0->CW / 1->CCW
        byte HomeOffset;                    // Offset de posição [cts]
        byte JogSpeed;                      // Setpoint de velocidade de movimento [cts/s]
        byte JogTa;                         // Tempo de aceleração [s]
        byte JogTd;                         // Tempo de desaceleração [s]
        int MaxPos;                         // Posição Máxima permitida [cts]
        int MinPos;                         // Posição Mínima permitida [cts]
        double Mres;                        // Resolução do movimento [°]
        
        // Status do Motor
        int ActPos;                         // Posição atual processada do Servo [cts]
        int ActPos2;                        // Posição atual processada do Servo [°]
        byte Pos;                           // Posição atual não processada do Servo [cts]
        byte Pos2;                          // Posição atual não processada do Servo [°]
        byte Velocity;                      // Velocidade atual de movimento do Servo [cts/s]
        byte Velocity2;                     // Velocidade atual de movimento do Servo [°/s]

    private:
        // Funções
        void moveMotor(int _pos);           // Move (absoluto) levando em consideração velocidade e aceleração
        void setSpeed();                    // Altera a velocidade do motor

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

        // Variáveis de lógica
        double Stepping;                    // Razão de passos completos do motor
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