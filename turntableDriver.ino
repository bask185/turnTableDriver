#include "src/basics/io.h"
#include "src/basics/macros.h"
#include "src/modules/debounceClass.h"
#include "EEPROM.h"
//#include "roundRobinTasks.h"

uint32_t    timeLastStep ;
uint32_t    position ;
uint32_t    setPoint ;
uint16_t    currentSpeed ;
uint8_t     mode ;
uint8_t     firstStore ;

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
    uint32_t currentTime = micros() ;
    
    if( motorMoving == true )                             // if motor is moving..
    {
        if(  currentTime - timeLastStep > currentSpeed )   // ..wait for time to pass and move again
        {
            // if( mode == MANUAL ) // calculate next step differently in manual than in auto
            currentSpeed = 500 + (100 * analogRead( speedPin )) ;
            // else 
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
        if( ++position == MAX_REV )     position = 0 ;
    }
    else
    {
        if( --position == 0xffffffff ) position = MAX_REV - 1 ;
    }
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
    if( setPoint != position )
    {
        setStep() ;
    }
}

void shiftCW()
{
    Serial.println(F("shifting CW"));
    digitalWrite( dirPin, HIGH ) ;
    setPoint = getPosition( 1 ) ;
}

void shiftCCW()
{
    Serial.println(F("shifting CCW"));
    digitalWrite( dirPin, LOW ) ;
    setPoint = getPosition( -1 ) ;
}

void setup() 
{
    initIO();
    Serial.begin(115200);
    getSlotAmount() ;
    dumpEEPROM() ;
}

void loop() 
{
    debounceButtons() ;
    
    //if( motorMoving == false )
    //{
        uint8_t state = modeBtn.readInput() ;

        if( state == RISING ) 
        {
            Serial.println("AUTOMATIC MODE") ;
            mode = AUTOMATIC ; // new mode can only be adopted when motor is not moving
            dumpEEPROM() ;
        }
        if( state == FALLING ) 
        {
            mode = MANUAL ;
            firstStore = true ;
            Serial.println("MANUAL MODE") ;
        }
    //}
    //mode = MANUAL ;
    
    uint8_t  cwState =  CW.readInput() ;
    uint8_t ccwState = CCW.readInput() ;
    uint8_t recordState = record.readInput() ;
    //uint8_t ccwState = CCW.readInput() ;
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

        else if( recordState == RISING )
        {
            if( firstStore ) clearSlots() ;
            firstStore = false ;
            storeSlot( position ) ;
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

    REPEAT_MS( 50 );
    static uint32_t prevPos ;

    if( prevPos != position ) 
    {
        Serial.println( position ) ;
        prevPos = position ;
    }
    END_REPEAT
}