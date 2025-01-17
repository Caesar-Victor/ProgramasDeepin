clear all;close all;clc;
pkg load control
t_max = 0.2;
m1 = 300; m2 = 120; m3 = 150; m4 = 700; m5 = 80;
k1 = 48.866; k2 = 915522.58; k3 = 1206875.43; k4 = 1178694.84;
k5 = 36.7265; k6 = 136.4661; k7 = 38.6679; k8 = 4761249.39; k9 = 389232.42;
c4 = 0.8981; c5 = 33114.21; c6 = 1.7284; c7 = 6764.6574;
c8 = 8648277.61; c9 = 1295.52;

t = 0:0.01:t_max;

dy_dt = @ (t,y) [y(2);
  y(4);
  y(6);
  y(8);
  y(10);
  (-(k1+k2+k3+k4)*y(1)+k2*y(2)+k3*y(3)+k4*y(4)-c4*y(6)+c4*y(9))/m1;
  (+k2*y(1)-(k2+k5+k6)*y(2)-(c5+c6)*y(7)+k6*y(4)+c6*y(9))/m2;
  (k3*y(1)-(k3+k7+k8)*y(3)-(c7+c8)*y(8)+k8*y(4)+c8*y(9))/m3;
  (k4*y(1)+c4*y(6)+k6*y(2)+c6*y(7)+k8*y(3)+c8*y(8)-(k4+k6+k8+k9)*y(4)-(c4+c6+c8+c9)*y(9)+k9*y(5)+c9*y(10))/m4;
  (k9*y(4)+c9*y(9)-k9*y(5)-c9*y(10))/m5];

y0 = [0 0 0 0 0 0 0 0 0 50];
[t, y] = ode45(dy_dt, [0 t_max], y0);
figure
plot(t,y(:,10))
grid on
