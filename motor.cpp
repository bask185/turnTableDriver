#include "motor.h"
#include "EEPROM.h"
#include "src/basics/io.h"
#include "src/basics/macros.h"

const int TIME_FACTOR = 100 ;

const int ACCELERATION_FACTOR = 3 ;

//#include stepper motor
enum states
{
    idle,
    calculateDist,
    accelerate,
    cruise,
    brake,
    fineTunePosition,
} ;

bool     runOnce        = true ;
bool     enabled        = true ;
uint8_t  state          = calculateDist ; // must be idle
uint8_t  speed          = 0 ;
uint8_t  speedSetpoint  = 0 ;
uint32_t setPoint       = 8000 ;
uint32_t position       = 0 ;
uint32_t prevPos ;
uint32_t brakeRange     = 0 ;
//uint32_t distanceToGo   = 0 ;
uint32_t maxPos         = 20000 ;
uint16_t speedMax       = 35 ;

const int SPEED_MIN = 0 ;
const int SPEED_MAX = 250 ;

int32_t distanceToGo()
{
    return setPoint - position ;
}
void printMillis()
{
    static uint32_t prevTime ;
    uint32_t currTime = millis() ;
    Serial.print("Last Time: " ) ;
    Serial.print( currTime - prevTime ) ;
    prevTime = currTime ;
    Serial.print("  total time: " ) ;
    Serial.println( currTime  ) ;
    
    Serial.print("distanceToGo: ");
    Serial.println( distanceToGo() ) ;
    Serial.print("total position: ");
    Serial.println( position ) ;
}



uint32_t getDistanceToGo ()
{
    uint32_t retVal ;
    
    if( digitalRead( dirPin ) )         // turning CCW
    {
        retVal = position - setPoint ;
        
        if( position > setPoint )       // if true add one circumreference 
        {
            retVal += maxPos ;
        }
    }
    else                                // turning CW
    {
        retVal = setPoint - position ;
        if(  setPoint < position ) 
        {
            retVal += maxPos ;          // if true add one circumreference 
        }
    }
    
    // Serial.print("distance 2 go: ") ;
    // Serial.println( retVal ) ;
    
    return retVal ;
}


void shiftCCW()
{
    //mode = SHIFTING_CCW ;
    //setPoint = getPosition( CCW_ ) ;
}

void shiftCW()
{
    //mode = SHIFTING_CW ;
    //setPoint = getPosition( CW_ ) ;
}

// void cruise( uint8_t dir )
// {
//     speedSetpoint = maxSpeed ;
    
//     if( dir == CCW_ )
//     {
//         //mode = CRUISING_CWW ;
//     }
//     if( dir == CW_ )
//     {
//         //mode = CRUISING_CW ;
//     }
// }

void stopMotor()
{
    speedSetpoint = 0 ;
}


uint32_t getBreakingDistance()
{
    brakeRange = distanceToGo() - ( speedMax * speedMax ) ;
    Serial.println(brakeRange) ;
    return brakeRange ;
}

uint32_t prevMillis ;
void setSteps()
{
    static uint16_t speedVar = speed + 1;
    REPEAT_US( 1000 / speedVar ) ;
   // speedVar = speed ;
    
    if( enabled ) 
    {
        if( !digitalRead( dirPin ) )
        {
            if( ++position == maxPos+1 ) position = 1 ; // verify this code if positions work well
            digitalWrite( stepPin, HIGH ) ;                // may become port manipulated
            digitalWrite( stepPin,  LOW ) ;
        }
        else
        {
            //if( --position == 0 ) position = maxPos ; // currently run 1 direction
        }
    }

    else 
    {
        digitalWrite( stepPin, state ) ;// may become port manipulated
        return ;
    }
    
    //Serial.print("position: ");
    //Serial.println( position ) ;
    
    //manageSpeed() ;
    
    static uint8_t speedPrev = 255 ;
    
    if( speedSetpoint > speed ) speed ++ ;
    if( speedSetpoint < speed ) speed -- ;
    if( speed == 0 ) enabled = false ;          // if speed reaches 0, stop sending pulses
    
    Serial.print("position :") ;
    Serial.print(position);
    Serial.print(",  SPEED :") ;
    Serial.print( speed ) ;
    Serial.print(",  TIME :") ;
    Serial.println( micros() - prevMillis ) ;
    prevMillis = micros() ;
    
    // getBreakingDistance() ;
    
    END_REPEAT
}



// void stepperControl()
// {
//     switch( state ) {
//         case CRUISING_CWW:
        
//         case CRUISING_CW:
        
//         case SHIFTING_CCW:
        
//         case SHIFTING_CW:
        
//         case ACCELERATING: if( speed < maxSpeed ) speed ++ ; break ;
//         case DECELERATING: if( speed >        0 ) speed -- ; break ;
//     }
        
        
//     int32_t difference = setPoint - currentPos ;
//     if( difference < 0 ) distance = maxRev - abs( difference ) ;
//     if( difference < maxRev / 2 ) dir = CCW_ ;
//     if( difference > maxRev / 2 ) dir =  CW_ ;
// }

void nextState( uint8_t next )
{
    state = next ;
    runOnce = true ;
}

#define m_accel 1
#define m_decel 1


int32_t millis(){ return micros()  ) ; }

void stepperControl() 
{
    //setSteps() ;
    
    int32_t t = millis() - m_start_time ;
    int32_t distance_to_move = m_distance_moved ;
    int32_t distance_to_target = m_target_delta - m_distance_moved ; 
    int32_t current_velocity = 0 ;
    int32_t stopping_distance = 0 ;
    
    switch( state )
    { 
    case calculateDist :
        
        nextState( accelerate ) ;
        break ;

    case accelerate :
        if( runOnce == true )
        {   runOnce  = false ;
        
            current_velocity = (m_accel * t) ;
            stopping_distance = (current_velocity * current_velocity) / (2 * m_decel) ;
            
            Serial.println( "\r\naccelerating\r\n" ) ;
            speedSetpoint = speedMax ;
            enabled = true ;
        }
        
        if( current_velocity >= m_vmax )
        {
            // Reset for next phase
            

            nextState( cruise ) ;
        }
        else
        {
            distance_to_move = m_accel * (t * t) / (2 ) ;
        }

        break ;
        
    case cruise :
        if( runOnce == true )
        {   runOnce  = false ;
        
            Serial.println( "\r\ncruising\r\n" ) ;
            
            m_start_time = millis() ;
            m_target_delta = distance_to_target ; 
            m_distance_moved = 0 ;
            distance_to_move = 0 ;
            m_vpeak = m_vmax ;
            current_velocity = m_vmax ;
            stopping_distance = (current_velocity * current_velocity) / (2 * m_decel) ;
        }

        if( position >= brakeRange ) 
        {
            nextState(  brake ) ; // if we are at or beyond braking range, start slowing down already
        }
        break ;
        
    case brake :
        if( runOnce == true )
        {   runOnce  = false ;

            Serial.println( "\r\nbraking\r\n" ) ;
        }
        
        current_velocity = m_vpeak - (m_decel * t)  ;

        if( distance_to_target <= 0 )
        {
            nextState( idle ) ;
        }
        else
        {
            distance_to_move = (m_vpeak * t) - 
                               (m_decel * (t * t) / 2) ;
        }
        break ;
        
        
    default:
        distance_to_move = m_distance_moved ;
        break ;
        
    }
}

void updateSpeed()
{
    int sample = analogRead( speedPin ) ;
    speedMax = map( sample, 0, 1023, SPEED_MIN, SPEED_MAX ) ;
}