create or replace trigger ship_check
before insert
on shipment
for each row

declare
stock number;

begin
	select parts_stock into stock from parts where parts_id=:new.parts_id;

	if inserting then
	stock:=stock+:new.parts_qty;
		if stock>500 then
		RAISE_APPLICATION_ERROR(-20001,'Limit Exceeded');
		else
		update parts set parts_stock=stock where parts_id=:new.parts_id;
		end if;
	end if;
end;