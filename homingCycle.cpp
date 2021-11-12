// HEADER FILES
#include <Arduino.h>
#include "homingCycle.h"
#include "src/basics/macros.h"
#include "src/basics/io.h"
#include "src/basics/stateMachineClass.h"

StateMachine sm ;

#define beginState homingCycleIDLE

// VARIABLES

// FUNCTIONS
extern void homingCycleInit(void)
{
    sm.nextState( beginState, 0 ) ;
}

// STATE FUNCTIONS
StateFunction( findSensor )
{
    if( sm.entryState() )
    {
        
    }
    if( sm.onState() )
    {
        
        sm.exit() ;
    }
    if( sm.exitState() )
    {
        
    }
    return sm.endState() ;
}

StateFunction( leaveSensor )
{
    if( sm.entryState() )
    {
        
    }
    if( sm.onState() )
    {
        
        sm.exit() ;
    }
    if( sm.exitState() )
    {
        
    }
    return sm.endState() ;
}

StateFunction( measureRound )
{
    if( sm.entryState() )
    {
        
    }
    if( sm.onState() )
    {
        
        sm.exit() ;
    }
    if( sm.exitState() )
    {
        
    }
    return sm.endState() ;
}

StateFunction( turnToHome )
{
    if( sm.entryState() )
    {
        
    }
    if( sm.onState() )
    {
        
        sm.exit() ;
    }
    if( sm.exitState() )
    {
        
    }
    return sm.endState() ;
}

StateFunction( init )
{
    if( sm.entryState() )
    {
        
    }
    if( sm.onState() )
    {
        
        sm.exit() ;
    }
    if( sm.exitState() )
    {
        
    }
    return sm.endState() ;
}


// STATE MACHINE
extern uint8_t homingCycle()
{
    STATE_MACHINE_BEGIN

    State(findSensor) {
        sm.nextState( leaveSensor, 0 ) ; }

    State(leaveSensor) {
        sm.nextState( measureRound, 0 ) ; }

    State(measureRound) {
        sm.nextState( turnToHome, 0 ) ; }

    State(turnToHome) {
        sm.nextState( homingCycleIDLE, 0 ) ; }

    State(init) {
        sm.nextState( findSensor, 0 ) ;
        sm.nextState( turnToHome, 0 ) ; }

    STATE_MACHINE_END
}
