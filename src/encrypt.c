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
#include <stdint.h>
#include <string.h>
#include "encrypt.h"
#include "crypto.h"

void write_quote(FILE *fp)
{
	fprintf(fp, "%c", 0x22);
}

void write_lf(FILE *fp)
{
	fprintf(fp, "\n");
}

void write_value(FILE *fp, char *buffer, int len)
{
	write_quote(fp);

	for (int i = 0; i < len; i++) {
		fprintf(fp, "%cx%02X", 92, (uint8_t )*buffer++);
	}

	write_quote(fp);
}

int main(void)
{
	FILE *fp;
	fp = fopen("src/const.h", "w");
	fprintf(fp, "#ifndef CONST_H\n#define CONST_H\n\n");

	for (int i = 0; i < STRDEFNUM; i++) {
		fprintf(fp, "#define %s ", strdup(strdefs[i][0]));
		char *buffer = strdup(strdefs[i][1]);
		int len = strlen(buffer);
		x(buffer);
		write_value(fp, buffer, len);
		write_lf(fp);
	}

	write_lf(fp);

	for (int i = 0; i < INTDEFNUM; i++) {
		fprintf(fp, "#define %s 0x", strdup(intdefs[i][0]));
		uint32_t xorred = ((uint32_t)intdefs[i][1]) ^ 0xDEADBEEF;
		fprintf(fp, "%08X", xorred);
		write_lf(fp);
	}

	write_lf(fp);

	fprintf(fp, "static char *ips[%i] = {", IPNUM);
	for (int i = 0; i < IPNUM; i++) {
		char *buffer = strdup(ips[i]);
		int len = strlen(buffer);
		x(buffer);
		write_value(fp, buffer, len);
		if (i < IPNUM - 1) {
			fprintf(fp, ",\n");
		} else {
			fprintf(fp, "};\n");
		}
	}

	fprintf(fp, "\n#endif\n");
	fclose(fp);

}
