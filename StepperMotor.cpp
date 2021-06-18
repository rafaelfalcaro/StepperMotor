#include "Arduino.h"
#include "StepperMotor.h"

//************************************************************************************
// Funções Públicas

// Mantém o Motor na posição atual
void StepperMotor::Brake() {
    digitalWrite(pinEnable, LOW);
    digitalWrite(pinReset , HIGH);
    digitalWrite(pinSleep , HIGH);
    digitalWrite(pinStep  , LOW);
    digitalWrite(pinDir   , LOW);
}

// Movimento automático até a posição de Home
void StepperMotor::Home() {
    //moveServo(HomeOffset);
}

// Movimento em Jog
void StepperMotor::Jog(bool _dir) {
    setSpeed();
    digitalWrite(pinEnable, LOW);
    digitalWrite(pinReset , HIGH);
    digitalWrite(pinSleep , HIGH);
    digitalWrite(pinStep  , HIGH);
    digitalWrite(pinDir   , _dir);
}

// Desliga o controle do Motor
void StepperMotor::Kill() {
    digitalWrite(pinEnable, HIGH);
    digitalWrite(pinReset , HIGH);
    digitalWrite(pinSleep , HIGH);
    digitalWrite(pinStep  , LOW);
    digitalWrite(pinDir   , LOW);
}

// Movimento incremental do Servo
void StepperMotor::MoveInc(int _pos) {
    //if ((ActPos + _pos >= MinPos) && (ActPos + _pos <= MaxPos)) {
    //    moveServo(ActPos + _pos + HomeOffset);
    //}
}

// Movimento absoluto do Servo
void StepperMotor::MoveTo(int _pos) {
    //if ((_pos >= MinPos) && (_pos <= MaxPos)) {
    //    moveServo(_pos + HomeOffset);
    //}
}

// Seleção do modo de funcionamento do Motor
void StepperMotor::SetMode(byte _mode) {
    if (_mode == 0) {                           // Full Step
        digitalWrite(pinMode0, LOW);
        digitalWrite(pinMode1, LOW);
        digitalWrite(pinMode2, LOW);
        Stepping = 1;
    }
    else if (_mode == 1) {                      // Half Step
        digitalWrite(pinMode0, HIGH);
        digitalWrite(pinMode1, LOW);
        digitalWrite(pinMode2, LOW);
        Stepping = 1/2;
    }
    else if (_mode == 2) {                      // 1/4 Microstepping
        digitalWrite(pinMode0, LOW);
        digitalWrite(pinMode1, HIGH);
        digitalWrite(pinMode2, LOW);
        Stepping = 1/4;
    }
    else if (_mode == 3) {                      // 1/8 Microstepping
        digitalWrite(pinMode0, HIGH);
        digitalWrite(pinMode1, HIGH);
        digitalWrite(pinMode2, LOW);
        Stepping = 1/8;
    }
    else if (_mode == 4) {                      // 1/16 Microstepping
        digitalWrite(pinMode0, LOW);
        digitalWrite(pinMode1, LOW);
        digitalWrite(pinMode2, HIGH);
        Stepping = 1/16;
    }
    else if (_mode == 5) {                      // 1/32 Microstepping
        digitalWrite(pinMode0, HIGH);
        digitalWrite(pinMode1, HIGH);
        digitalWrite(pinMode2, HIGH);
        Stepping = 1/32;
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

    DigiPot.SetPins(_pCS, _pINC, _pUD);
}


//************************************************************************************
// Funções Privadas

// Move (absoluto) levando em consideração velocidade e aceleração
void StepperMotor::moveMotor(int _pos) {
    
    //setSpeed();
    
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

    /*double waitTime = (-0.1919 * JogSpeed) + 20.192;
    while (_pos != Pos) {
        if (_pos > Pos) Pos++;
        else Pos -= 1;
        ActPos = Pos - HomeOffset;
        servo.write(Pos);
        delay(waitTime);
    }*/
}

// Altera a velocidade do Motor
void StepperMotor::setSpeed() {
    //double Velo = JogSpeed * ScaleFactor;   // Aplicação do fator de escala na velocidade
    //uint8_t Counts = 0.0099009900990099*R5+99.009900990099-0.00852716850632432*R5*RS*Stepping*VIN/(CT*RL*RT*Velo);
    //DigiPot.Set(Counts);                    // Escrita dos Counts no módulo X9C103S


    DigiPot.Set(JogSpeed);

    Serial.print("JogSpeed: ");
    Serial.println(JogSpeed);
}