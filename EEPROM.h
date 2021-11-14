#include <Arduino.h>

extern void storeSlot( uint16_t position ) ;
extern uint16_t getPosition( int8_t dir ) ;
extern void clearSlots() ;
extern void dumpEEPROM() ;
extern void getSlotAmount() ;
extern void storeCurrentSlot() ;
extern void loadCurrentSlot() ;