#include "EEPROM.h"
#include <EEPROM.h>

int8_t currentSlot ;
uint8_t MAX_SLOTS = 0 ;
uint16_t eeAddress = 0 ;


void clearSlots()
{
    for( int i = 0 ; i < 512 ; i ++ ) // whipe all addresses
    {
        EEPROM.write( i     , 0 ) ;
    }
    
    MAX_SLOTS = currentSlot = 0 ;
    // whipe eeprom() ;
    Serial.println(F("All slots whiped"));
}

void storeSlot( uint16_t position )
{    
    uint16_t eeAddress = currentSlot * 2 ;
    EEPROM.put( eeAddress, position ) ;
    
    currentSlot ++ ;
    MAX_SLOTS = currentSlot ;
    
    Serial.print(F("Slot added: ")) ;
    Serial.println( currentSlot ) ;
    
    Serial.print(F("Position stored: ")) ;
    Serial.println( position ) ;
}

uint16_t getPosition( int8_t dir )
{  
    currentSlot += dir ; // adds either 1 or -1
    
    if(      currentSlot == MAX_SLOTS + 1 ) currentSlot = 1 ;
    else if( currentSlot == 0             ) currentSlot = MAX_SLOTS ;

    Serial.print(F("moving to slot: ")) ;
    Serial.println( currentSlot ) ;
    
    eeAddress = currentSlot * 2 - 2 ;
    uint16_t newPos ;
    EEPROM.get( eeAddress, newPos ) ;
    
    Serial.print(F( "returning position: " )) ;
    Serial.println( newPos ) ;
    
    return newPos ;
}

void dumpEEPROM()
{
    for( int i = 0 ; i < MAX_SLOTS ; i ++ )
    {
        uint16_t newPos ;
        eeAddress = i * 2 ;
        EEPROM.get( eeAddress, newPos ) ;
        Serial.print(F("Stored: "));
        Serial.println( newPos ) ;
    }
    EEPROM.write( 1000, MAX_SLOTS ) ; // store current slot
    Serial.print(F("Slot amount: "));
    Serial.println(MAX_SLOTS) ;
}

void getSlotAmount()
{
    Serial.println(F("loading eeprom")) ;
    MAX_SLOTS = EEPROM.read( 1000 ) ;
    Serial.print(F("slot amount =")) ;
    Serial.println(MAX_SLOTS);
}