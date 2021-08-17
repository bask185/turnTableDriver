
// #include "roundRobinTasks.h"
// #include "src/basics/io.h"
// #include "src/basics/macros.h"
// #include "config.h"
// #include <Arduino.h>
// #include "motor.h"

// void debounceButtons()
// {
//     // CW.debounceInputs() ;
//     // CCW.debounceInputs() ;
//     // mode.debounceInputs() ;
//     // record.debounceInputs() ;
// }

// enum modes
// {
//     AUTOMATIC,
//     MANUAL,
// };

// // uint8_t motorControll()
// // {
// //     uint8_t ccwState = CCW.readInput() ;
// //     uint8_t  cwState =  CW.readInput() ;
// //     static uint32_t previousPos = 0xFFFFFFFF ;
// //     //uint8_t     modeState = mode.readInput ;
    
// //     switch( mode )
// //     {
// //     case AUTOMATIC:
// //         if( ccwState == FALLING ) { shiftCCW() ; }    
// //         if(  cwState == FALLING ) {  shiftCW() ; }
// //         break ;
    
// //     case MANUAL:
// //         if( ccwState == FALLING ) { cruise( CCW_ ) ; Serial.println(F("CRUISING CCW")) ; } // print state of motor to screen for debugging
// //         if( ccwState ==  RISING ) { stopMotor() ;    Serial.println(F("BREAKING")) ;     }
// //         if(  cwState == FALLING ) { cruise( CW_  ) ; Serial.println(F("CRUISING CW")) ;  }
// //         if(  cwState ==  RISING ) { stopMotor() ;    Serial.println(F("BREAKING")) ;     }

// //         break ;
// //     }
    
// //     currentPos = moveMotor() ;
// // }

// /* print update of stepper motor position every 100ms */
// // void printUpdate()
// // {
// //     const int timeToPrint = 100 ;
// //     static uint32_t prevTime = 0 ;
// //     uint32_t currentTime = millis() ;
    
// //     if(( previousPos != currentPos )
// //     && ( currentTime  - prevTime > timeToPrint ))
// //     {
// //         previousPos = currentPos;
// //         prevTime    = currentTime ;
        
// //         Serial.print(F("Position: ")) ;
// //         Serial.println( currentPos) ;
// //     }
// //     return 0 ;
// // }

// /* only when motor is stationairy the mode may be changed
// void updateMode()
// {
//     uint8_t state = mode.readInput() ;
//     if( state == FALLING )
//     {
//         mode = AUTOMATIC ;
//         Serial.println("mode = AUTOMATIC") ;
//     }
//     else if( state == RISING )
//     {
//         mode = MANUAL ;
//         Serial.println("mode = MANUAL") ;
//     }
// }

// /* if an home sensor is present, it will be used to synchronize zero position every time it is triggered */
// void synchronizeHome()
// {
    
// }

// extern void processRoundRobinTasks(void) 
// {
//     static unsigned char taskCounter = 0;
    
// // HIGH PRIORITY ROUND ROBIN TASKS
//     // setSteps() ;
//     // manageSpeed() ;
//     stepperControl() ;
    
    
//     //if( motorControll() == 0 ) { updateMode() ; }

// // LOW PRIORITY ROUND ROBIN TASKS

//     switch( ++taskCounter ) 
//     { default: taskCounter = 0 ;

//     case 0:
//         REPEAT_MS( 100 ) ; // take ADC sample 10x per second and update the max speed
//         //updateSpeed() ;
//         END_REPEAT
//         break;

//     case 1:
//         // REPEAT_MS( 20 ) ;
//         // debounceButtons() ;
//         // END_REPEAT
//         break;
        
//     case 2:
//         synchronizeHome() ;
//         break ;
        
//     case 3:
//         //printUpdate() ;
//         break ;
//     }
// }