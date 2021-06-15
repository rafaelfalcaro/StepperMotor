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
        void Brake();                       // Mantém o Motor na posição atual
        void Home();                        // Movimento automático até a posição de Home
        void Jog(bool _dir);                // Movimento em Jog
        void Kill();                        // Desliga o controle do Motor
        void MoveInc(int _pos);             // Movimento incremental
        void MoveTo(int _pos);              // Movimento absoluto
        void SetMode(byte Mode);            // Seleção do modo de funcionamento do Motor
        void SetPins(byte _pFault, byte _pDir, byte _pSleep, byte _pReset, byte _pMode2, byte _pMode1, byte _pEnable, byte _pMode0, byte _pStep, byte _pCS, byte _pINC, byte _pUD);   // Define automaticamente os pinos do Driver como IN/OUT

        // Objeto da biblioteca X9C103S
        X9C103S DigiPot;

        // Parametrização do Motor
        byte Dir;                           // Sentido de Giro: 0->CW / 1->CCW
        double HomeOffset;                  // Offset de posição [°]
        double JogSpeed;                    // Setpoint de velocidade de movimento [°/s]
        byte JogTa;                         // Tempo de aceleração [s]
        byte JogTd;                         // Tempo de desaceleração [s]
        double MaxPos;                      // Posição Máxima permitida [°]
        double MinPos;                      // Posição Mínima permitida [°]
        double ScaleFactor;                 // Fator de escala para a movimentação
        
        // Status do Motor
        double ActPos;                      // Posição atual processada do Motor [°]
        double Pos;                         // Posição atual não processada do Motor [°]
        double Velocity;                    // Velocidade atual do Motor [°/s]

    private:
        // Funções
        void moveMotor(int _pos);           // Move (absoluto) levando em consideração velocidade e aceleração
        void setSpeed();                    // Altera a velocidade do Motor

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
        double Stepping;                    // Razão de passos completos do Motor
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