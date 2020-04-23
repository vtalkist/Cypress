
typedef struct
{ 
	char* morse;
	char* ascii;
} morse_table_t;

void blink(char *morse);
void manage(int i);
void line(void);
void dot(void);

int main(void) {
	char input[] = "BOGDAN"; // тут вводиш слово

	morse_table_t table[] = { { ".-", "A" },
							{ "-...", "B" },
							{ "-.-.", "C" },
							{ "-..",  "D" },
							{ ".",    "E" },
							{ "..-.", "F" },
							{ "--.",  "G" },
							{ "....", "H" },
							{ "..",   "I" },
							{ ".---", "J" },
							{ "-.-",  "K" },
							{ ".-..", "L" },
							{ "--",   "M" },
							{ "-.",   "N" },
							{ "---",  "O" },
							{ ".--.", "P" },
							{ "--.-", "Q" },
							{ ".-.",  "R" },
							{ "...",  "S" },
							{ "-",    "T" },
							{ "..-",  "U" },
							{ "...-", "V" },
							{ ".--",  "W" },
							{ "-..-", "X" },
							{ "-.--", "Y" },
							{ "--..", "Z"}};

	for(char *ptr = input; *ptr != '\0'; ptr++)
		for (int i = 0; i < 26; ++i)
		{
			if(*ptr == 32) CyDelay(PAUSE_S);
			else if (*ptr == *(table[i].ascii))
			{
				blink(table[i].morse);
				break;
			}
		}
	return 0;
}

void blink(char *morse)
{
	for (char *pointer = morse; *pointer != '\0'; pointer++)
		manage(*pointer == 46 ? 1 : 0);
}

void dot(void)
{
	CyDelay(PAUSE);
	LED_Write(1);
	LED_Write(0);
	CyDelay(DOT);
	LED_Write(1);
}

void line(void)
{
	CyDelay(PAUSE);
	LED_Write(0);
	CyDelay(LINE);
	LED_Write(1);
}

void manage(int i)
{
	if (i == 1)
		dot();
	else if (i == 0)
		line();
}
