putty = importfile('putty60sek_obroty w dwoch osiach.log');
figure(1);
plot(putty(:,1),'r')
hold on;
plot(putty(:,2),'g')
plot(putty(:,3),'b')
hold off;
legend('x','y','z')