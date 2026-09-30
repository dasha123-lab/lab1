#include <stdio.h>
#include <math.h>
int main () {
float x, y, z, U, hx = 1, hy = 0.7, hz = 2;
float x0 = 1, x1 = 2;
float y0 = 0.1, y1 = 0.7;
float z0 = 1, z1 = 3;
float min_U = 1000000.0;
float best_x = 0, best_y = 0, best_z = 0;
int found = 0;
printf("-----------------------------\n");
printf("|  x  |  y  |  z  |    U    |\n");
printf("-----------------------------\n");
for (x = x0; x <= x1 + 0.0001; x += hx) {
for (y = y0; y <= y1 + 0.0001; y += hy) {
for (z = z0; z <= z1 + 0.0001; z += hz) {
float arg_ctg = pow(x, y) + 3.0 * pow(z, 2.0);
float ctg_val = cos(arg_ctg) / sin(arg_ctg);
float arg_log = fabs((pow(x, 3.0) - y) / z);
float ln_val = log(arg_log);
U = ctg_val - ln_val;
printf("| %.1f | %.1f | %.1f | %12.4f |\n", x, y, z, U);
if (found == 0 || U < min_U) {
min_U = U;
best_x = x;
best_y = y;
best_z = z;
found = 1; 
}
}
}
}
printf("-----------------------------\n");
if (found) {
printf("min_U = %.4f\n", min_U);
printf("x = %.1f\n", best_x);
printf("y = %.1f\n", best_y);
printf("z = %.1f\n", best_z);
}
return 0;
}
