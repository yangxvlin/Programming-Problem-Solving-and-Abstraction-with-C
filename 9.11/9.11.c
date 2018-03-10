#include <stdio.h>
#include <math.h>

#define ROCKRT 10.0
#define FUEL 8.0
#define CONSUME 0.8
#define K 0.6
#define GRAVITY 9.81
#define A 0.1
#define TIME_LIMIT 10.0
#define THRUST 500.0
#define EPSILEN 0.000001

double calculaton(double step);
double calculaton2();

int main() {
	double increment = 1.0;
	int i = 0;
	for (i = 0; i < 9; i++) {
		increment = pow(0.1, i);
		calculaton(increment);
	}
	//calculaton2();
}

double calculaton(double step) {
	double amplitude = 0.0, max_amplitude = 0.0, fight_time = 0.0, time = 0.0;
	double v = 0.0;
	while ((time <= TIME_LIMIT) && (amplitude >= 0.0)) {
		if (v != 0.0) {
			v = v + (THRUST  - GRAVITY * ((ROCKRT + FUEL) - CONSUME * time) - (fabs(v) / v) * K * A * v * v ) / ((ROCKRT + FUEL) - CONSUME * time) * time;
		} else {
			v = v + (THRUST  - GRAVITY * ((ROCKRT + FUEL) - CONSUME * time) - K * A * v * v ) / ((ROCKRT + FUEL) - CONSUME * time) * time;
		}
		amplitude += v * step;
		
		if (amplitude > max_amplitude) {
			max_amplitude = amplitude;
		}
		//printf("t = %4.2lfs, h = %11.5lfm, v = %10.5lf\n", time, amplitude, v);
		
		if (amplitude >= 0) {
			fight_time += step;
		}
		time += step;
	}
	printf("step = %.10lf, max h = %lfm, duration = %lfs\n", step, max_amplitude, fight_time);
}

double calculaton2() {
	double fight_time = 0.0, t0 = 0.0, t1 = 10.0, delta = 0.001;
	double v = 0.0;
	int modify = 1;
	double left_amplitude = v + (THRUST / ((ROCKRT + FUEL) - CONSUME * t0) - GRAVITY - K * A * v * v / ((ROCKRT + FUEL) - CONSUME * t0)) * t0;
	double right_amplitude = v + (THRUST / ((ROCKRT + FUEL) - CONSUME * t1) - GRAVITY - K * A * v * v / ((ROCKRT + FUEL) - CONSUME * t1)) * t1;
	
	while (fabs(left_amplitude - right_amplitude) >= EPSILEN) {
		
		
		printf("%lf\n", v);
		if (modify == 0) {
			v = v + (THRUST / ((ROCKRT + FUEL) - CONSUME * t0) - GRAVITY - K * A * v * v / ((ROCKRT + FUEL) - CONSUME * t0)) * t0;
			modify = 1;
			left_amplitude = v * t0;
			t0 = (t0 + t1) / 2.0;
		} else if (modify == 1) {
			v = v + (THRUST / ((ROCKRT + FUEL) - CONSUME * t1) - GRAVITY - K * A * v * v / ((ROCKRT + FUEL) - CONSUME * t1)) * t1;
			modify = 0;
			right_amplitude = v * t1;
			t1 = (t0 + t1) / 2.0;
		}
		
	}
	//printf("%lf, %lf\n", t0, t1);
	printf("max h = %lfm, duration = %lfs\n", left_amplitude, t0);
}

