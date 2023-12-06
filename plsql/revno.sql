declare
num1 int;
num2 int;

begin
num1:=&num1;
num2:=0;
loop
num2:=num2*10+mod(num1,10);
num1:=num1/10;
exit when num1=0;
end loop;
dbms_output.put_line('Reverse is  '||num2);
end;
/
