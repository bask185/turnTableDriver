enum homingCycleStates
{
    homingCycleIDLE,
    findSensor,
    leaveSensor,
    measureRound,
    turnToHome,
    init
} ;

extern uint8_t homingCycle(void) ; 
extern void homingCycleInit(void) ; 
