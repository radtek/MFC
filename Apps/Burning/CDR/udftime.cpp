#include "stdafx.h"
#include <time.h>
#include "ecma_167.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#define EPOCH_YEAR 1970
#define MAX_YEAR_SECONDS	69
#define SPD 0x15180 /*3600*24*/
#define SPY(y,l,s) (SPD * (365*y+l)+s)
#define SECS_PER_HOUR	(60 * 60)
#define SECS_PER_DAY	(SECS_PER_HOUR * 24)
#define DIV(a,b) ((a) / (b) - ((a) % (b) < 0))
#define LEAPS_THRU_END_OF(y) (DIV (y, 4) - DIV (y, 100) + DIV (y, 400))

#ifndef __isleap
/* Nonzero if YEAR is a leap year (every 4 years,
   except every 100th isn't, and every 400th is).  */
#define	__isleap(year)	\
  ((year) % 4 == 0 && ((year) % 100 != 0 || (year) % 400 == 0))
#endif

/* How many days come before each month (0-12).  */
const unsigned short int __mon_yday[2][13] =
{
	/* Normal years.  */
	{ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
	/* Leap years.  */
	{ 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
};


time_t year_seconds[MAX_YEAR_SECONDS]= {
/*1970*/ SPY( 0, 0,0), SPY( 1, 0,0), SPY( 2, 0,0), SPY( 3, 1,0), 
/*1974*/ SPY( 4, 1,0), SPY( 5, 1,0), SPY( 6, 1,0), SPY( 7, 2,0), 
/*1978*/ SPY( 8, 2,0), SPY( 9, 2,0), SPY(10, 2,0), SPY(11, 3,0), 
/*1982*/ SPY(12, 3,0), SPY(13, 3,0), SPY(14, 3,0), SPY(15, 4,0), 
/*1986*/ SPY(16, 4,0), SPY(17, 4,0), SPY(18, 4,0), SPY(19, 5,0), 
/*1990*/ SPY(20, 5,0), SPY(21, 5,0), SPY(22, 5,0), SPY(23, 6,0), 
/*1994*/ SPY(24, 6,0), SPY(25, 6,0), SPY(26, 6,0), SPY(27, 7,0), 
/*1998*/ SPY(28, 7,0), SPY(29, 7,0), SPY(30, 7,0), SPY(31, 8,0), 
/*2002*/ SPY(32, 8,0), SPY(33, 8,0), SPY(34, 8,0), SPY(35, 9,0), 
/*2006*/ SPY(36, 9,0), SPY(37, 9,0), SPY(38, 9,0), SPY(39,10,0), 
/*2010*/ SPY(40,10,0), SPY(41,10,0), SPY(42,10,0), SPY(43,11,0), 
/*2014*/ SPY(44,11,0), SPY(45,11,0), SPY(46,11,0), SPY(47,12,0), 
/*2018*/ SPY(48,12,0), SPY(49,12,0), SPY(50,12,0), SPY(51,13,0), 
/*2022*/ SPY(52,13,0), SPY(53,13,0), SPY(54,13,0), SPY(55,14,0), 
/*2026*/ SPY(56,14,0), SPY(57,14,0), SPY(58,14,0), SPY(59,15,0), 
/*2030*/ SPY(60,15,0), SPY(61,15,0), SPY(62,15,0), SPY(63,16,0), 
/*2034*/ SPY(64,16,0), SPY(65,16,0), SPY(66,16,0), SPY(67,17,0), 
/*2038*/ SPY(68,17,0)
};

//extern struct timezone sys_tz;


time_t *
udf_stamp_to_time(time_t *dest, long *dest_usec, timestamp src)
{
	int yday;
	Uchar type = src.typeAndTimezone >> 12;
	int16 offset;

	if (type == 1)
	{
		offset = src.typeAndTimezone << 4;
		/* sign extent offset */
		offset = (offset >> 4);
		if (offset == -2047) /* unspecified offset */
			offset = 0;
	}
	else
		offset = 0;

	if ((src.year < EPOCH_YEAR) ||
		(src.year > EPOCH_YEAR+MAX_YEAR_SECONDS))
	{
		*dest = -1;
		*dest_usec = -1;
		return NULL;
	}
	*dest = year_seconds[src.year - EPOCH_YEAR];
	*dest -= offset * 60;

	yday = ((__mon_yday[__isleap (src.year)]
		[src.month-1]) + (src.day-1));
	*dest += ( ( (yday* 24) + src.hour ) * 60 + src.minute ) * 60 + src.second;
	*dest_usec = src.centiseconds * 10000 + src.hundredsOfMicroseconds * 100 + src.microseconds;
	return dest;
};


timestamp *
udf_time_to_stamp(timestamp *dest, time_t tv_sec, long tv_usec)
{
	long int days, rem, y;
	const unsigned short int *ip;
	int16 offset=0;

	//offset = -sys_tz.tz_minuteswest;

	if (!dest)
		return NULL;

	dest->typeAndTimezone = 0x1000 | (offset & 0x0FFF);

	tv_sec += offset * 60;
	days = tv_sec / SECS_PER_DAY;
	rem = tv_sec % SECS_PER_DAY;
	dest->hour = rem / SECS_PER_HOUR;
	rem %= SECS_PER_HOUR;
	dest->minute = rem / 60;
	dest->second = rem % 60;
	y = 1970;


	while (days < 0 || days >= (__isleap(y) ? 366 : 365))
	{
		long int yg = y + days / 365 - (days % 365 < 0);

		/* Adjust DAYS and Y to match the guessed year.  */
		days -= ((yg - y) * 365
			+ LEAPS_THRU_END_OF (yg - 1)
			- LEAPS_THRU_END_OF (y - 1));
		y = yg;
	}
	dest->year = (int16)y;
	ip = __mon_yday[__isleap(y)];
	for (y = 11; days < (long int) ip[y]; --y)
		continue;
	days -= ip[y];
	dest->month = y + 1;
	dest->day = days + 1;

	dest->centiseconds = tv_usec / 10000;
	dest->hundredsOfMicroseconds = (tv_usec - dest->centiseconds * 10000) / 100;
	dest->microseconds = (tv_usec - dest->centiseconds * 10000 -
		dest->hundredsOfMicroseconds * 100);
	return dest;
};


