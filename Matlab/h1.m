clear all, clc;

% Ex1. 
% see https://github.com/RichardLitt/standard-readme

% Ex2.
x=[3;2;6;8]; y=[4;1;3;5];
x+y;
x.^y;
y./x;
z=x.*y;
w=sum(z,'all');
x'*y-w;

% Ex3.
in=linspace(60,12345987,10);
ex3(in);

% Ex4.
[lap, meter] = ex4(1100);

% Ex7.
length(primes(5));
prod(randi(10,5,1));

 
function out = ex3(in) 
    out=in/(3600*24);
end

function [lap, meter] = ex4(in)
    lap = floor(in/400);
    meter = in - 400*lap;
end
