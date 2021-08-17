#include "EEPROM.h"
#include <EEPROM.h>

int8_t currentSlot ;
uint8_t MAX_SLOTS = 0 ;
uint16_t eeAddress = 0 ;


void clearSlots()
{
    for( int i = 0 ; i < MAX_SLOTS ; i ++ ) // whipe all addresses
    {
        uint16_t eeAddress = i * 2;
        EEPROM.write( i     , 0 ) ;
        EEPROM.write( i + 1 , 0 ) ;
    }
    
    MAX_SLOTS = currentSlot = 0 ;
    // whipe eeprom() ;
    Serial.println(F("All slots whiped"));
}

void storeSlot()
{
    currentSlot ++ ;
    
    uint16_t eeAddress = currentSlot * 2 ;
    uint16_t position = 0;//getPosition() ;
    EEPROM.put( eeAddress, position ) ;
    
    MAX_SLOTS = currentSlot ;
    
    Serial.print(F("Slot added: ")) ;
    Serial.println( currentSlot ) ;
    
    Serial.print(F("Position stored: ")) ;
    Serial.println( position ) ;
}

uint16_t getPosition( int8_t dir )
{  
    currentSlot += dir ; // adds either 1 or -1
    
    if(      currentSlot == MAX_SLOTS ) currentSlot = 1 ;
    else if( currentSlot == 0         ) currentSlot = MAX_SLOTS ;

    Serial.print(F("moving to slot: ")) ;
    Serial.println( currentSlot ) ;
    
    uint16_t eeAddress = currentSlot * 2 ;
    uint16_t newPos ;
    EEPROM.get( eeAddress, newPos ) ;
    
    Serial.print(F( "returning position: " )) ;
    Serial.println( newPos ) ;
    
    return newPos ;
}
