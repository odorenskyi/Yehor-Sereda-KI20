#ifndef MODULESSEREDA_H_INCLUDED
#define MODULESSEREDA_H_INCLUDED

float s_calculation(float x, float z);

float income_eval(float x, float z, int y);

float mid_temperature_celsius(float t_arr[6]);

float mid_temperature_farengates(float t_arr[6]);

int bit_counter(int N);

int create_file(char * exist_file, char * output_file);

int input_time(char * exist_file);

void calculation_write(float x, float z, int b, char * exist_file, int clear_file = 0);

#endif // MODULESSEREDA_H_INCLUDED
