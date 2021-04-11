clear all, clc;
% Ex1.
%ex1();

% Ex2. Boring stuff

% Ex3.
%ex3(23);

% Ex4. Use rectangle
%ex4();

% Ex5.
%ex5('x^2-2',[1,5],0.01);

% Ex6.
ex6(6);

function ex1()
    for i = 1:32
        a(i) = 0;
    end
    a(1) = 1;
    for j = 1:64
        for i = 1:32
            a(i)=2*a(i);
            if a(i) > 9
                a(i) = a(i)-10;
                a(i+1) = a(i+1) + 0.5;
            end
        end
    end
    fprintf('answer is ');
    for i = 1:31
        fprintf('%d', a(33-i));
    end
    fprintf('%d', a(1)-1);
end
function ex2()
    wardrobe(1) = struct('Type','Jumpers','Color','Blue','Quantity',2,'Bought',0);
end
function ex3(n)
    fd = fopen('ex3.txt','w');
    for i = 0:10
       fprintf(fd,'%d x %d = %d\n',n,i,n*i); 
    end
    fclose(fd);
end
function ex4()
    figure;
    rectangle('Position',[0,0,4,4],'EdgeColor','k');hold on;
    x = linspace(0,2);
    y = 0.5*x+4;
    plot(x,y,'k');hold on;
    x = linspace(4,2);
    y = -0.5*x+6;
    plot(x,y,'k');hold on;
end
function ex5(fun,interval,precision)
    str = strcat('@(x) ',fun);
    f = str2func(str);
    a = interval(1); b = interval(2);
    for i = 1:20
       c = (a+b)/2;
       if abs(a-c)<precision
           break;
       end
       if f(a)*f(c)<=0
           b = c;
       else
           a = c;
       end
    end
    disp(c);
end
function ex6(n)
    %fd = fopen('ex6.txt','w');
    for i = 1:n
        for j = 1:n-i
            fprintf('   ');
        end
        a = rot90(diag(rot90(pascal(i))));
        disp(a);
        %writematrix(a,'ex6.txt','Delimiter','tab','WriteMode','append');
        fprintf('\n');
    end
    %fclose(fd);
end
