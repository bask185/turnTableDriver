#include "src/basics/io.h"
#include "src/basics/macros.h"
#include "src/modules/debounceClass.h"
#include "EEPROM.h"
//#include "roundRobinTasks.h"

uint32_t    timeLastStep ;
uint32_t    position ;
uint32_t    setPoint ;
uint16_t    currentSpeed ;
uint16_t    setSpeed ;
uint8_t     mode ;
uint8_t     firstStore ;

Debounce CW(   cwPin ) ;
Debounce CCW( ccwPin ) ;
Debounce modeBtn( modePin ) ;
Debounce record( recordPin ) ;


void debounceButtons()
{
    REPEAT_US( 500 ) ;
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

bool accelerating = false ;
bool motorMoving = false ;

const long MAX_REV = 3200 ;
void setStep()
{
    static uint16_t speedTemp = 0 ;
    uint32_t currentTime = micros() ;

    uint16_t accelFactor ;
    if( accelerating == true ) accelFactor = 1000 ; // inc 750
    else                       accelFactor = 333 ;

    REPEAT_US( accelFactor ); // ACCEL FACTOR

    if( speedTemp < setSpeed ) speedTemp ++ ;
    if( speedTemp > setSpeed ) speedTemp -- ;
    END_REPEAT
    
    if( motorMoving == true )                             // if motor is moving..
    {
        if(  currentTime - timeLastStep > currentSpeed )   // ..wait for time to pass and move again
        {
            if( mode == MANUAL  )
            {
                currentSpeed = 15000 - speedTemp ;

            }
            else currentSpeed = getSpeed() ;
            // else 
            motorMoving = false ;
        }
        return ;
    }
    
    motorMoving = true ;                                  // set flag that motor is moving
    timeLastStep = currentTime ;
    
    if( speedTemp == 0 ) return ;
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

/* MANUAL MODE = CRUISING */

void cruise()
{
    if( mode != MANUAL ) return ;

    setStep() ;
}

void stopCruising()
{
    setSpeed = 0 ;
    accelerating = false ;
    Serial.println(F("STOPPING"));     
}

uint32_t getSpeed()
{
    return 2500 + 1024 * 3  + (3 * analogRead( speedPin )) ; ; //max 9750 min 6570
}

void cruiseCW()
{
    Serial.println(F("cruising CW"));        
    digitalWrite( dirPin, HIGH ) ;
    accelerating = true;
    // accelerateCW  = true ;
    // accelerateCCW = false ;
    setSpeed = getSpeed() ;
}

void cruiseCCW()
{
    Serial.println(F("cruising CCW"));       
    digitalWrite( dirPin, LOW ) ;
    accelerating = true;
    // accelerateCW  = true ;
    // accelerateCCW = false ;
    setSpeed = getSpeed() ;
}

/* END CRUISING */



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
    home() ;
    getSlotAmount() ;
    loadCurrentSlot() ;
    dumpEEPROM() ;

    CW.readInput() ;
    CCW.readInput() ;
    modeBtn.readInput() ;
    record.readInput() ;
    delay(20);

    if( digitalRead( modePin )) {
        //mode = AUTOMATIC ;
        mode = MANUAL ;
    } else {
        mode = MANUAL ;
    }

    calibration() ;
    homing() ; 
}

void loop() 
{
    debounceButtons() ;
    cruise() ;

    uint8_t state = modeBtn.readInput() ;
    
    if( state == RISING ) 
    {
        Serial.println("AUTOMATIC MODE") ;
        //mode = AUTOMATIC ; // new mode can only be adopted when motor is not moving
        dumpEEPROM() ;
    }
    if( state == FALLING ) 
    {
        mode = MANUAL ;
        firstStore = true ;
        Serial.println("MANUAL MODE") ;
    }

    uint8_t  cwState =  CW.readInput() ;
    uint8_t ccwState = CCW.readInput() ;
    uint8_t recordState = record.readInput() ;


    if( mode == MANUAL )
    {    
        if( cwState  == FALLING ) cruiseCW() ;
        if( ccwState == FALLING ) cruiseCCW() ;
        if( cwState == RISING || ccwState == RISING ) stopCruising() ;

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
        Serial.print( position ) ; Serial.print("  ");
        Serial.println( currentSpeed ) ;
        prevPos = position ;
    }
    END_REPEAT
}