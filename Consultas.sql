use facturacionempresa;

/* Consulta 1 - VERIFICAR PRODUCTOS CON BAJO STOCK, AGREGADO DE GANANCIA COMO DATO DE COLOR */			
select upper(S.nombre) as Nombre, S.descripcion, S.cantidad, (S.precio_venta - S.precio_compra) as ganancia 
from stock as S
where S.cantidad < 150
order by  S.cantidad DESC;


/* Consulta 2 -  MOSTRAR LAS 3 COMPRAS MAS ALTAS DEL MES ACTUAL*/
select f.numero_factura ,  f.total as Factura_alta , f.fecha
from factura as f
where MONTH( f.fecha ) = MONTH( sysdate() )
order by Factura_alta DESC
limit 3; 


/* Consulra 3 - DATOS DE LOS CLIENTES QUE COMPRARON EN EL MES ACTUAL */
select nombre_comercial, nombre_fantacia, telefono, direccion, localidad, piso, dpto, codigo_postal, documento, cli.num_cliente,num_talonario, fecha, numero_factura, total
from cliente_proveedor as cli join factura as f 
on cli.id_empresa = f.num_cliente
where MONTH( f.fecha ) = MONTH( sysdate() )
order by f.fecha DESC;

/*Consulta 4 - QUE PRODUCTOS SE COMPRORON/VENDIERON EN EL MES */ 
select nombre, descripcion
from (
		select I.id_codigo, S.nombre, S.descripcion, I.idItem, I.cantidad
		from stock as S, items as I
		where I.id_codigo = S.idStock 
    ) as T, factura as F
where MONTH( F.fecha ) = MONTH( sysdate() )
group by descripcion
having count(*) > 0
order by nombre DESC;

/*Consulta 5 - facturacion mensual de una sucursal */ 

select sucursal, sum(iva21) as iva_del_mes, sum( total ) as Facturacion_mensual
from factura
where sucursal = 249 and  MONTH( fecha ) = MONTH( sysdate() );

/*Consulta 6 - mes de mayor facturacion */

select sucursal, iva_del_mes, max(resumen.Facturacion_mensual) as total , fecha
from (
		select  sucursal, sum(iva21) as iva_del_mes, sum( total ) as Facturacion_mensual, fecha
		from factura
		group by MONTH( fecha ) 
    ) as resumen;



