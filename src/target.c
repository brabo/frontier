/*
 * Copyright (c) 2016 brabo <brabo@centropy.info>. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "const.h"
#include "crypto.h"

int main(void)
{
	char *msg = strdup(PK);
	x(msg);
	printf("\ndecrypted: %s\n", msg);
	msg = strdup(DP1);
	x(msg);
	printf("\ndecrypted: %s\n", msg);
	msg = strdup(DP2);
	x(msg);
	printf("\ndecrypted: %s\n", msg);
	msg = strdup(DP3);
	x(msg);
	printf("\ndecrypted: %s\n", msg);
	msg = strdup(CH);
	x(msg);
	printf("\ndecrypted: %s\n", msg);
	msg = strdup(DERP);
	x(msg);
	printf("\ndecrypted: %s\n", msg);

	uint32_t ipcount = IPNUM ^ 0xDEADBEEF;
	printf("\ndecrypted: %i\n",ipcount);

	srand(time(NULL));

	for (int i = 0; i < 20; i++) {
		int r = rand() % (ipcount);
		msg = strdup(ips[r]);
		x(msg);
		printf("IP %i: %s\n", r, msg);
	}
}
