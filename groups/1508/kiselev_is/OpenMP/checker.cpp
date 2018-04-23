#include "checker.h"
#include <iostream>


int main(int argc, char * argv[]) {

	if (argc != 3) {
		checker_result.write_verdict(NO);
		checker_result.write_message("       No verdict. Bad parameters         ");
		return 1;
	}
	char* wey = new char(12);
	for (int i=0;i<12;i++)
		wey[i] = argv[2][i];

	checker_result.write_message(wey);

	int num_threads = atoi(argv[1]);
	int size;

	double* buf;

	double Myresult = 80;
	double perfect_res = 0.0;

	double confines[4];

	double line_time;
	double time;

	FILE * ons;
	FILE * buo;

	Func* fun = nullptr;

	for (char bu = '0'; bu <= '9'; bu++) {
		wey[10] = bu;
		
		buo = fopen(wey, "rb");
		ons = fopen(strcat(wey, ".ans"), "rb");
		
		fread(&size, sizeof(int), 1, buo);
		buf = new double(size);

		fun = new Func(size);
		for (int i = 0; i < 7; i++) {
			fread(buf, sizeof(*buf), size, buo);
			switch (i) {
			case 0: {
				fun->SetCoeffs(buf);
				break;
			}
			case 1: {
				fun->SetXindexs(buf);
				break;
			}
			case 2: {
				fun->SetYindexs(buf);
				break;
			}
			case 3: {
				fun->SetXcos(buf);
				break;
			}
			case 4: {
				fun->SetYcos(buf);
				break;
			}
			case 5: {
				fun->SetXsin(buf);
				break;
			}
			case 6: {
				fun->SetYsin(buf);
				break;
			}
			default:
				break;
			}
		}
		// границы интегрирования
		fread(confines, sizeof(*confines), 4, buo);

		//fclose(buo);
		time = omp_get_wtime();

		Myresult = TIntegral(fun, confines[0], confines[1], confines[2], confines[3], num_threads);

		time = omp_get_wtime() - time;
		//buo = fopen(strcat(argv[2],".ans"), "rb");

		fread(&perfect_res, sizeof(perfect_res), 1, ons);

		fread(&line_time, sizeof(line_time), 1, ons);

		if (module(Myresult - perfect_res) < 1) {
			if (time <= line_time) {
				checker_result.write_message(wey);
				checker_result.write_message("    AC. Unswer is correct.    \n");
				checker_result.write_verdict(AC);
			}
			else {
				checker_result.write_message(wey);
				checker_result.write_message("    TL. Execution time exceeded.  \n");
				checker_result.write_verdict(TL);
			}
		}
		else {
			checker_result.write_message(wey);
			checker_result.write_message("     DE. Incorrect unswer.         \n");
			checker_result.write_verdict(DE);
		}
		fclose(buo);
		fclose(ons);
		fun->~Func();
		fun = nullptr;
		buf = nullptr;
		wey = nullptr;
		wey = new char(12);
		for (int i = 0; i<12; i++)
			wey[i] = argv[2][i];
	}
	return 0;
}