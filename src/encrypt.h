/*
 * All copyright and related rights waived via CC0.
 */

#ifndef ENCRYPT_H
#define ENCRYPT_H

#define STRDEFNUM		6
#define INTDEFNUM		1
#define IPNUM			5


static char *strdefs[STRDEFNUM][2] = {{"PK", "sekrit PK string"},
					{"DP1", "sekrit DP1 string"},
					{"DP2", "sekrit DP2 string"},
					{"DP3", "sekrit DP3 string"},
					{"CH", "sekrit CH string"},
					{"DERP", "sekrit DERP string"}};

static char *intdefs[INTDEFNUM][2] = {{"IPNUM", IPNUM}};


static char *ips[IPNUM] = { "1.1.1.1",
				"2.2.2.2",
				"3.3.3.3",
				"4.4.4.4",
				"5.5.5.5"};

#endif

