declare
rad number;
i number;
area number;
begin
for rad in 3 .. 7
loop
insert into areas values(rad,3.14*rad*rad);
end loop;
end;
/
