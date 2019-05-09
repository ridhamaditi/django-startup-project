x1=[1 1 -1 -1];
x2=[1 -1 1 -1];
bin=[1 1 1 1];
t=[1 -1 -1 -1];
w=[0 0];
b=0;
disp(x1);
disp(x2);
disp(t);
for i=1:4
w1(i)=w(1)+(x1(i)*t(i));
w(1)=w1(i);
endfor
disp('W1');
disp(w1);
#w1new(i)=w(i);
for i=1:4
w2(i)=w(2)+(x2(i)*t(i));
w(2)=w2(i);
endfor
disp('W2');
disp(w2);
for i=1:4
b1(i)=b+(t(i)*bin(i));
b=b1(i);
endfor
disp('B');
disp(b1);