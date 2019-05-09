x1 = [1 1 0 0];
x2 = [1 0 1 0];
w = 1;
theta = 1;
v = x1.*w + x2.*w;
for i=1:4
if v(i)>theta
  y(i) = 1;
else
y(i) = 0;
end
end
disp(y)
