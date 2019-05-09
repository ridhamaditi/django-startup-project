p1=[1 1 1 -1 1 -1 1 1 1];
p2=[1 1 1 1 1 1 1 -1 -1];
disp('P1');
disp(p1);
disp('P2');
disp(p2);
t=[1 -1];
w=[0 0 0 0 0 0 0 0 0];
yin=0;
alpha=1;
for i=1:9
yin=yin+(p1(i)*w(i));
endfor
disp('Y-in');
disp(yin);
if (yin>0)
  y=1;
elseif (yin<0)
  y=-1;
else
y=0;
endif
disp('Y');
disp(y);
if (t(1)~=y)
  for i=1:9
    wnew(i)=w(i)+(alpha*t(1)*p1(i));
  endfor
endif
disp('Wnew');
disp(wnew);
for i=1:9
  yin=yin+(wnew(i)*p2(i));
endfor
disp('Y-in');
disp(yin);
if (yin>0)
  y=1;
elseif (yin<0)
  y=-1;
else
  y=0;
endif
disp('Y');
disp(y);
if (t(2)~=y)
  for i=1:9
    wnew(i)=wnew(i)+(t(2)*p2(i));
  endfor
endif
disp('Wnew');
disp(wnew);