
#include "EEPROM.h"
#include <EEPROM.h>

int8_t currentSlot ;
uint8_t MAX_SLOTS = 0 ;
uint16_t eeAddress = 0 ;

const int CIRCUM_REF_ADDRESS = 1010 ;
const int MAX_SLOT_ADDRESS = 1000 ;
const int CURRENT_SLOT_ADDRESS = 1001 ;


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

    storeCurrentSlot( ) ;
}

uint16_t getPosition( int8_t dir )
{  
    currentSlot += dir ; // adds either 1 or -1
    
    if(      currentSlot == MAX_SLOTS + 1 ) currentSlot = 1 ;
    else if( currentSlot == 0             ) currentSlot = MAX_SLOTS ;

    Serial.print(F("moving to slot: ")) ;
    Serial.println( currentSlot ) ;

    storeCurrentSlot() ;
    
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
    EEPROM.write( MAX_SLOT_ADDRESS, MAX_SLOTS ) ; // store current slot
    Serial.print(F("Slot amount: "));
    Serial.println(MAX_SLOTS) ;
}

void getSlotAmount()
{
    Serial.println(F("loading eeprom")) ;
    MAX_SLOTS = EEPROM.read( MAX_SLOT_ADDRESS ) ;
    Serial.print(F("slot amount =")) ;
    Serial.println(MAX_SLOTS);
}

void storeCurrentSlot( )
{
    EEPROM.write( CURRENT_SLOT_ADDRESS, currentSlot ) ;
}

void loadCurrentSlot( )
{
    currentSlot = EEPROM.read( CURRENT_SLOT_ADDRESS ) ;
    Serial.print(F("current slot = ")) ;
    Serial.println( currentSlot ) ;
}

uint16_t getCircumReference()
{
    uint16_t retVal ;

    EEPROM.get( CIRCUM_REF_ADDRESS, retVal ) ;

    return retVal ;
}

void setCircumreference( uint16_t circumReference  )
{
    EEPROM.put( CIRCUM_REF_ADDRESS, circumReference ) ;
    Serial.print(F("circumReference stored: ")) ; Serial.print( circumReference );
}
