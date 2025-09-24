clc;
clear;

%%
n1=1000;
n2=100;

m=linspace(0.01,1.15,n2);
t=linspace(0,2*pi,n1);
y=zeros(n1,n2);

for i=1:length(m)

    abc=m(i)*sin([t',t'-2*pi/3 ,t'+2*pi/3]);
    
    ZeroSequency= (max(abc,[],2) + min(abc,[],2))*-0.5;
    
    ABC=abc+[ZeroSequency, ZeroSequency, ZeroSequency];
    
    DutyCycle=(ABC+1)/2;
    
    mmax=max(DutyCycle,[],2);
    mmin=min(DutyCycle,[],2);
    mmid=sum(DutyCycle,2)-mmax-mmin;
    
    y(:,i)=(mmin+mmid)<1&(mmax+mmid)>1;
end

mesh(y);
