%Yash Gupta
%S20200010234
%Paper code D
%Question:-
%Write a MATLAB program to perform the following operations:
%- Generate a discrete signal x(n) of sequence length of 20
%- Compute the autocorrelation 7;.,(m) = x(n) * x(—n)
%- Find the spectra of signal 7..(m)
%- Plots the generated signal, 7,,(n) and spectra of 7;,(n)
%solution:-
xn=[1:20];
x=[-1,2,-3,4,3,-2,1,5,6,7,-8,9,0,9,8,-7,6,-5,0,0];%20 random outputs
%calculation of x(-n) using sigfold
[yf,xf]=sigfold(x,xn);
%convulation of x(n) with x(-n)
nyb=xn(1)+xf(1);
nye=xn(length(xn))+xf(length(xf));
ny=[nyb:nye];
Xrr=zeros(1,length(ny));
j=1;
for i=1:length(ny)
    [hf , hnf]=sigfold(yf,xf);
    [shf,shnf]=sigshift(hf,hnf,ny(i));
    [xnew,nm]=sigmult(x,xn,shf,shnf);
    Xrr(j)=sum(xnew);
    j=j+1;
end
%calculation of spectrum of Xrr
ll=10;
Magnitude=[];%array of magnitude
i=1;
temp=[];
Phase=[];%array of phase
index=[];
for k=1:1:length(Xrr)
    temp(i)=Xrr(i)*exp(-i*pi*ny(i));
    magnitude(i)=abs(temp(i));
    Phase(i)=phase(temp(i));
    i=i+1;
    
end
%graphs
subplot(4,1,1);
stem(xn,x);
title('x(n)');
xlabel('n');
ylabel('x(n)');
subplot(4,1,2);
stem(ny,Xrr);
title('Xrr= convulation of x(n)and x(-n)');
xlabel('n');
ylabel('Xrr(n)');
subplot(4,1,3);
stem(ny,magnitude);
title('Magnitude');
xlabel('n');
ylabel('magnitude of Xrr(n)');
subplot(4,1,4);
stem(ny,Phase);
title('Phase');
xlabel('n');
ylabel('phase of Xrr(n)');
%functions used
function [y,n] = sigfold(x,n)
y = fliplr(x); n = -fliplr(n);
end
function [y,x]=sigmult(y1,x1,y2,x2)
x=[min([x1,x2]):max([x1,x2])];
ll1=zeros(1,length(x));
m1=x1(1)-x(1);
t1=[1:length(x1)];
ll1(m1+t1)=y1;
ll2=zeros(1,length(x));
m2=x2(1)-x(1);
t2=[1:length(x2)];
ll2(m2+t2)=y2;
y=ll1.*ll2;
end
function [y,n] = sigshift(x,m,k)
n = m+k; y = x;
end
