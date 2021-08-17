#include "stepper.h"

cTrapezoidStepper::bool isMoving()
        {
            return m_trap_phase != 0 ;
        }

cTrapezoidStepper::int32_t setTargetPos( int32_t target )
{
    if( m_trap_phase == STOP &&
        target != m_current_pos )
    {
        // Determine number of steps and direction to target
        m_target_delta = target % m_range - m_current_pos ;
        if( abs( m_target_delta ) > m_range / 2 )
        {
            m_target_delta -= m_range ;
        }

        m_direction = 1 ;
        if( m_target_delta < 0 )
        {
            m_target_delta = -m_target_delta ;
            m_direction = -1 ;
        }

        // Init motion
        m_start_time = tick() ;
        m_distance_moved = 0  ;
        m_trap_phase = ACCEL ;
    }

    return m_target_delta ;
}

cTrapezoidStepper::int32_t update()
{
    int32_t t = tick() - m_start_time ;
    int32_t distance_to_move = m_distance_moved ;
    int32_t distance_to_target = m_target_delta - m_distance_moved ; 
    int32_t current_velocity = 0 ;
    int32_t stopping_distance = 0 ;

    switch( m_trap_phase )
    {
        case ACCEL :
        {
            current_velocity = (m_accel * t) / ONE_SECOND ;
            stopping_distance = (current_velocity * current_velocity) / (2 * m_decel) ;

            m_vpeak = current_velocity ;
            if( distance_to_target <= stopping_distance )
            {
                // Reset for next phase
                m_start_time = tick() ;
                m_target_delta = distance_to_target ; 
                m_distance_moved = 0 ;
                distance_to_move = 0 ;

                m_trap_phase = DECEL ;
            }
            else if( current_velocity >= m_vmax )
            {
                // Reset for next phase
                m_start_time = tick() ;
                m_target_delta = distance_to_target ; 
                m_distance_moved = 0 ;
                distance_to_move = 0 ;

                m_trap_phase = CONSTANT ;
            }
            else
            {
                distance_to_move = m_accel * (t * t) / (2 * ONE_SECOND * ONE_SECOND) ;
            }
        }
        break ;

        case CONSTANT :
        {
            m_vpeak = m_vmax ;
            current_velocity = m_vmax ;
            stopping_distance = (current_velocity * current_velocity) / (2 * m_decel) ;

            if( distance_to_target <= stopping_distance )
            {
                // Reset for next phase
                m_start_time = tick() ;
                m_target_delta = distance_to_target ; 
                m_distance_moved = 0 ;
                distance_to_move = 0 ;

                m_trap_phase = DECEL ;
            }
            else
            {
                distance_to_move = (t * m_vmax) / ONE_SECOND ;
            }
        }
        break ;

        case DECEL :
        {
            current_velocity = m_vpeak - (m_decel * t) / ONE_SECOND ;

            if( distance_to_target <= 0 )
            {
                m_trap_phase = STOP ;
            }
            else
            {
                distance_to_move = (m_vpeak * t) / ONE_SECOND - 
                                    (m_decel * (t * t) / (2 * ONE_SECOND * ONE_SECOND)) ;
            }
        }
        break ;

        default :
        {
            distance_to_move = m_distance_moved ;
        }
        break ;
    }


    // Do steps
    int32_t steps = (distance_to_move - m_distance_moved) * m_direction ;
    m_stepper.step( steps ) ;

    // Update position
    m_distance_moved = distance_to_move ;
    m_current_pos += steps ;
    m_current_pos %= m_range ;

    return m_current_pos ;
}