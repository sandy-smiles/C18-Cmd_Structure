/*
 * Setup the millisecond resolution timer
 *
 * T0CON = 0b11001000
 *
 * We use timer0.
 * With a clock rate of 10MHz /4 => FOSC/4
 * no prescaler
 * /256 overflow => interrrupt TMR0IF
 * Interrupt occurs 9.765625 times per 1ms
 * or 625 times every 64 milliseconds
 * so, 10 times a ms (except for some which are 9 times a second)
 */
uint32_t    millisec;   // millisecond counter - overflows every 49.7 days
uint8_t     milli_10;
uint8_t     milli_4;
void milli_Setup(void) {
    millisec = 0;
    milli_cur = 10;
    milli_4 = 0;
    T0CON = 0xc8;   // see above - 9.76+ interrupts every 1ms
    INTCONbits.TMR0IF = 1;      // turn on interrupt
}

/*
 * Interrupt routine for millisecond counter
 * We increment millisec 64 times every 625 interrupts
 * meaning we have increment every 10, except for 15 times when it's 9 instead
 */
void milli_Int(void) {
    if (--milli_10 == 0) {
        millisec++;             // increment counter
        milli_4++;
        milli_10 = 10;
        if ((milli_4 & 0x3) == 0) {
            milli_10 = 9;
            if (milli_4 == 32) {
                milli_10 = 10;
            } else if (milli_4 == 63) {
                milli_4 = 0;
                milli_10 = 10;
            }
        }
    }
}

/*
 * return the number of milliseconds since start or last rollover.
 */
uint32_t millis(void) {
    uint32_t cur, old;

    cur = millisec;
    do (                // incase it is updated when we read it.
        old = cur;
        cur = millisec;
    } while (old != cur);
    return cur;
}

