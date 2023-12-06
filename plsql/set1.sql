CREATE OR REPLACE trigger acc_trig
before delete or update 
on account
for each row

begin

if :old.acc_balance<=50 then
RAISE_APPLICATION_ERROR(-20500,'BALANCE LESS THAN 50');
end if;

if deleting then
insert into backupacc values(:old.acc_no,:old.acc_balance,sysdate,'delete');
elsif updating then
insert into backupacc values(:old.acc_no,:old.acc_balance,sysdate,'update');

end if;

end;