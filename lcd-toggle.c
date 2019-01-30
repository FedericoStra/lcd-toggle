#include <stdio.h>
#include <stdlib.h>

int main() {
	char state;

	FILE *lcd_file = fopen("/sys/class/backlight/intel_backlight/bl_power", "r+");
	if (lcd_file == NULL) {
		perror("Opening");
		exit(EXIT_FAILURE);
	}

	int nread = fread(&state, sizeof(char), 1, lcd_file);
	if (nread != 1) {
		perror("Reading");
		exit(EXIT_FAILURE);
	}

	/* printf("The current state is %c\n", buf[0]); */
	
	if (state == '0')
		state = '1';
	else if (state == '1')
		state = '0';

	fseek(lcd_file, 0L, SEEK_SET);

	int nwritten = fwrite(&state, sizeof(char), 1, lcd_file);
	if (nwritten != 1) {
		perror("Writing");
		exit(EXIT_FAILURE);
	}

	fclose(lcd_file);
}
