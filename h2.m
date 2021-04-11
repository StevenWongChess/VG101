clear all, clc;
% Ex1.
% ex1();

% Ex2.
% ex2();

% Ex4. Not finished
%ex4_it('x^2-2',[1,2],5);

% Ex5. 
%isarmstrong(153)
%ex5(140)

% Ex6.
%ex6(4,3,2021)

function out = ex1()
    while(1)
       in = input('pls input a year: ');
       a = cast(in, 'int8');
       if a <= 0
           continue;
       end
       if mod(in, 4) ~= 0
           out = 0;
       elseif mod(in, 100) ~= 0
           out = 1;
       elseif mod(in, 400) ~= 0 
           out = 0;
       else
           out = 1;
       end
       break;
    end
end
function ex2()
    in = input('please enter a number: ');
    in = in + 1;
    while 1
        if isprime(in) == 1
            [judge, a, b] = pytha(in);
            if judge == 1
                sprintf('next prime is %d, with first is %d and second is %d',in, a, b)
                break;
            end
        end
        in = in + 1;
    end
end
function [judge, a, b] = pytha(in)
    judge = 0;
    a = 0; b = 0;
    q = ceil(sqrt(in));
    for i=1:q
        for j=1:q
            if (i^2+j^2) == in
                a=i;
                b=j;
                judge = 1;
            end
        end
    end
end
function root = ex4_it(func, interval, precision)
    str = strcat('@(x) ',func);
    f = str2func(str);
    x(1) = interval(1);
    x(2) = interval(2);
    a = 0;
    for n = 3:4*precision
        x(n)=(x(n-2)*f(x(n-1)) - x(n-1)*f(x(n-2)))/(f(x(n-1))-f(x(n-2)));
        if abs(x(n) - x(n-1)) < 0.1^(precision)
            a = n;
            break;
        end
    end
    root = x(a);
    sprintf('root is %.*f', precision, root)
end
function next = ex5(n)
    next = n;
    while 1
        if isarmstrong(next)
            break;
        end
        next = next + 1;
    end   
end
function result = isarmstrong(n)
    sum = n;
    while n > 0;
        digit = n - floor(n/10)*10;
        sum = sum - digit^3;
        n = floor(n/10);
    end
    if sum == 0
        result = 1;
    else
        result = 0;
    end    
end
function day = ex6(d, m, cy)
    c = floor(cy/100);
    y = cy-100*c;
    ans = 1 + d + floor((13*m-1)/5)+y+floor(y/4)+floor(c/4)-2*c;
    day = mod(ans, 7);
end