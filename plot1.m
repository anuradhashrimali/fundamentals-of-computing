% Run the results script
plotval2;

figure(1);
semilogy(x, euler);
title('Euler Method');
xlabel('n');
ylabel('y value');

print -depsc gr1.eps

figure(2);
semilogy(x, heun);
title('Heun Method');
xlabel('n');
ylabel('y value');

print -depsc gr2.eps

figure(3);
semilogy(x, midp);
title('Midpoint Method');
xlabel('n');
ylabel('y value');

print -depsc gr3.eps

figure(4);
semilogy(x, euler, 'k--o', x, heun, 'r-x', x, midp, 'b-^');
title('Comparison');
xlabel('n');
ylabel('y value');
legend('Euler','Heun', 'Midpoint', 'Location','NorthWest');
print -depsc gr.eps
