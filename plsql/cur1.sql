DECLARE
CURSOR empcur IS select emp_name,salary from employee;
ename employee.emp_name%type;
esal employee.salary%type;

BEGIN
OPEN empcur;
FETCH empcur into ename,esal;

while empcur%found
LOOP
dbms_output.put_line('empname'||ename);
dbms_output.put_line('salary'||esal);
FETCH empcur into ename,esal;

END LOOP;
CLOSE empcur;

END;