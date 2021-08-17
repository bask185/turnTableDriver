#include "src/basics/io.h"
#include "src/basics/macros.h"
#include "src/modules/debounceClass.h"
#include "EEPROM.h"
//#include "roundRobinTasks.h"

uint32_t    timeLastStep ;
uint32_t    position ;
uint16_t    speedInterval ;
uint8_t     mode ;

Debounce CW(   cwPin ) ;
Debounce CCW( ccwPin ) ;
Debounce modeBtn( modePin ) ;
Debounce record( recordPin ) ;

void debounceButtons()
{
    REPEAT_MS( 20 ) ;
    CW.debounceInputs() ;
    CCW.debounceInputs() ;
    modeBtn.debounceInputs() ;
    record.debounceInputs() ;
    END_REPEAT
}

enum modes
{
    AUTOMATIC,
    MANUAL,
};

bool motorMoving = false ;

const long MAX_REV = 20000 ;
void setStep()
{
    uint32_t currentTime = millis() ;
    
    if( motorMoving == true )                             // if motor is moving..
    {
        if(  currentTime - timeLastStep > speedInterval )   // ..wait for time to pass and move again
        {
            speedInterval = analogRead( speedPin ) ;
            motorMoving = false ;
        }
        return ;
    }
    
    motorMoving = true ;                                  // set flag that motor is moving
    timeLastStep = currentTime ;
    
    digitalWrite( stepPin, HIGH );                          // take a step
    digitalWrite( stepPin,  LOW );
    
    if( digitalRead( dirPin ) )                             // update position
    {
        if( ++position == MAX_REV ) position = 0 ;
    }
    else
    {
        if( --position == 0 )       position = MAX_REV ;
    }
    
    Serial.println( position ) ;
}


void inline cruiseCW()
{
    digitalWrite( dirPin, HIGH ) ;
    setStep( ) ;
}

void inline cruiseCCW()
{
    digitalWrite( dirPin, LOW ) ;
    setStep( ) ;
}

void update()           // updates stepper motor position during automatic mode
{
}

void shiftCW()
{
    digitalWrite( dirPin, HIGH ) ;
}

void shiftCCW()
{
    digitalWrite( dirPin, LOW ) ;
}

void setup() 
{
    initIO();
    Serial.begin(115200);
}

void loop() 
{
    debounceButtons() ;
    
    if( motorMoving == false )
    {
        uint8_t state = modeBtn.readInput() ;
        if( state == HIGH ) mode = AUTOMATIC ; // new mode can only be adopted when motor is not moving
        if( state ==  LOW ) mode = MANUAL ;
    }
    
    uint8_t  cwState =  CW.readInput() ;
    uint8_t ccwState = CCW.readInput() ;
    if( mode == MANUAL )
    {    
        if( cwState == LOW )
        {
            cruiseCW() ;
        }
        
        else if( ccwState == LOW )
        {
            cruiseCCW() ;
        }
    }
    
    if( mode == AUTOMATIC )
    {
        update() ;
        
        if( cwState == FALLING )
        {
            shiftCW() ;
        }
        if( ccwState == FALLING )
        {
            shiftCCW() ;
        }
    }
}