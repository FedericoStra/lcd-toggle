#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>

const char lcd_path[] = "/sys/class/backlight/intel_backlight/bl_power";

int main() {
	char state;

	FILE *lcd_file = fopen(lcd_path, "r+");
	if (lcd_file == NULL)
		error(EXIT_FAILURE, errno, "Write %s", lcd_path);

	int nread = fread(&state, sizeof(char), 1, lcd_file);
	if (nread != 1)
		error(EXIT_FAILURE, errno, "Read %s", lcd_path);

	/* printf("The current state is %c\n", buf[0]); */
	
	if (state == '0')
		state = '1';
	else if (state == '1')
		state = '0';

	fseek(lcd_file, 0L, SEEK_SET);

	int nwritten = fwrite(&state, sizeof(char), 1, lcd_file);
	if (nwritten != 1)
		error(EXIT_FAILURE, errno, "Write %s", lcd_path);

	fclose(lcd_file);
}
