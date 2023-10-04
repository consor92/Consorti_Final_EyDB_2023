# Desarrollo Final Estructuras y Bases de Datos

Desarrollo final de la asignatura Estructuras y Bases de Datos cursada en ciclo lectivo 2020 Turno Tarde con el profesor Alejandro Behringer en el ISNPT UTN.
Administración digitalizada de los sistemas de facturación y stock de la empresa Pepito S.A.

Cliente: Pyme de Servicios
Descripción de la Actividad: Venta, Instalación y monitoreo sistemas de seguridad.
Requerimientos: Un sistema que realice el manejo de clientes, proveedores, facturación, compras, stock y
listados de IVA Ventas/Compras.


## Propuesta a lograr:
Actualmente el cliente maneja los datos de compra/venta de productos y servicios mediante una planilla de cálculo
un tanto obsoleta, cada parte del proceso debe realizarse en forma manual, dificultando el manejo de los clientes y
anulando la posibilidad de llevar un stock adecuado de los productos y servicios que se venden. Las facturas se emiten
de forma semiautomática, requiriendo una carga manual para emitirla, el control de las mismas se realiza cargando
los datos a mano, lo cual implica una gran pérdida de tiempo.
La propuesta es mejorar el área administrativa para que los usuarios tengan una aplicación dedicada que les permita
sustituir este medio genérico y les brinde una mayor fiabilidad en la carga, manejo y resguardo de los datos generados.
También mejorar la organización y accesibilidad de los mismos para que puedan ser utilizados por el área contable.

## Límites y Alcances del Proyecto:
Una vez terminado el programa, él cliente podrá realizar altas, bajas, modificaciones y listados (ABML) en los distintos
módulos del sistema, Podrá crear y manejar tanto a clientes como proveedores. Para ventas tendrá la posibilidad de
emitir, guardar y administrar facturas, notas de crédito y débito, del tipo (A) y (B) con posibilidad de incorporar el
formato electrónico. Para
compras, podrá realizar (ABML) y controlar adecuadamente el stock, controlando el nivel del mismos para realizar
pedidos de renovación en caso de ser necesarios. Este manejo de compras y ventas, no permite realizar reportes
mensuales o ajustados a un rango de fecha especifico.


## Documentation

[Documentation](https://github.com/consor92/Consorti_Final_EyDB_2023/tree/Doc)

[Ante Proyecto](https://github.com/consor92/Consorti_Final_EyDB_2023/blob/Doc/Ante%20Proyecto%20EyDB%202020.pdf)



### Authors

- [@consor92](https://www.github.com/consor92)


### Deployment

Como ejecutar este proyecto

```bash
  El proyecto se encuentra compilado con Minggw32 por CodeBlock IDE.
  Dispone de un fichero ejecutable (main.exe) con la compilacion funcional.

  Se dispone de una vercion con datos Pre-Cargados:

  Para el mismo debe copiar la carpeta EMPRESA en la unidad de disco C:\ o en su        defecto respetar la ruta que se encuentre en el FileConfig ( empresa.cfg ).

  El sistema cuenta con un reinicio de archivos para uso inicial que crea dichos ficheros, para entrar ene sta configurar elimine o renombre el archivo empresa.cfg, elimine el archivo main.o y ejecute el archivo main.exe.

  Es posible que deba ejecutarlo con permisos de Adminisrador, ya que la ruta por defecto de los ficheros en en el directorio C:
