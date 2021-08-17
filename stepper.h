#include <Arduino.h>

class cTrapezoidStepper
{
    public:

        cTrapezoidStepper( Stepper& stepper, int32_t accel, int32_t vmax, int32_t decel, int32_t range ) :
            m_stepper( stepper ),
            m_accel( accel ),
            m_vmax( vmax ),
            m_vpeak( 0 ),
            m_decel( decel ),
            m_range( range ),
            m_start_time( 0 ),
            m_current_pos( 0 ),
            m_target_delta( 0 ),
            m_direction( 0 ),
            m_distance_moved( 0 ),
            m_trap_phase( STOP )
        {

        }

        bool isMoving() ;
        int32_t setTargetPos( int32_t target );
        int32_t update() ;

    private :
        static const int32_t ONE_SECOND = 100 ;

        Stepper& m_stepper ;
        int32_t m_accel ;
        int32_t m_vmax ;
        int32_t m_vpeak ;
        int32_t m_decel ; 
        int32_t m_range ;
        unsigned long m_start_time ;
        int32_t m_current_pos ;
        int32_t m_target_delta ;
        int32_t m_direction ;
        int32_t m_distance_moved ;
        enum
        {
            STOP,
            ACCEL,
            CONSTANT,
            DECEL
        } m_trap_phase ;

        int32_t tick(){ return millis() / (1000 / ONE_SECOND) ; }

};