#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <direct.h>
#include <windows.h>

/*Funci�n:  obtenerId(), sin parametros
  Acci�n:   Devuelve un c�digo de 14 caracteres �nico formado por la siguiente combinaci�n AAAAMMDDHHMMSS*/

char *obtenerId()
{
    static char id_Codigo[15];
    time_t tiempo;
    struct tm *tm;
    tiempo=time(NULL);
    tm=localtime(&tiempo);
    strftime(id_Codigo,15,"%Y%m%d%H%M%S",tm);
    return id_Codigo;
}

/*Funci�n:  bisiento(pasar por valor el a�o)
  Acci�n:   Devuevle 1 si el a�o es bisiesto, 0 si no lo es*/

int bisiesto(int anio)
{
    if ((anio%4==0 && anio%100!=0) || anio%400==0)
        return 1;
    else
        return 0;
}

/*Funci�n:  completarCeros(pasar por valor el dato, pasar la cantidad de ceros que tiene el dato)
  Acci�n:   Devuelve un string completando con ceros a la izquierda, el n�mero que necesitamos*/

char *completarCeros(int numero,int cantidad)
{
    int i;
    static char ceros[10];
    memset(ceros,0,sizeof(ceros));
    char valor[10];
    itoa(numero,valor,10);
    for(i=0;i<cantidad-strlen(valor);i++)
        ceros[i]='0';
    strcat(ceros,valor);
    return ceros;
}

/*Funci�n:  cls() sin parametros
  Acci�n:   Borra la pantalla*/

void cls()
{
    system("cls");
}

/*Funci�n:  pausa() sin parametros
  Acci�n:   Realiza una pausa colocando leyenda y esperando el accionar de una tecla*/

void pausa()
{
    system("pause");
}

/*Funci�n:  linea(pasar por valor el largo de la l�nea (1 a 80))
  Acci�n:   Genera una l�nea llena que tiene la longuitud que el usuario requiere*/

void linea(int largo)
{
    int i;
    for (i=1;i<=largo;i++)
        printf("%c",196);
    printf("\n");
}

/*Funci�n:  invalido() sin parametros
  Acci�n:   Devuelve un mensaje indicando que el dato ingresado es inv�lido y pidiendo que reintente*/

void invalido()
{
    linea(Largo);
    Color(RED,WHITE);
    printf("El DATO ingresado es INVALIDO, por favor REINTENTE                              \n");
    Color(BLACK,WHITE);
    linea(Largo);
    pausa();
}

/*Funci�n:  bienvenida() sin par�metros
  Acci�n:   Muestra el mensaje de bienvenida al sistema*/

void bienvenida()
{
    int i;
    cls();
    gotoxy(60,0);
    printf("<,>");
    gotoxy(0,1);
    linea(Largo);
    gotoxy(0,2);
    linea(Largo);
    gotoxy(0,3);
    Color(WHITE,RED);
    for (i=0;i<6;i++)
    {
        gotoxy(0,3+i);
        printf("                                                                                ");
    }
    gotoxy(15,3);
    printf("BIENVENIDO AL PROGRAMA");
    gotoxy(15,5);
    printf("ESPERE MIENTRAS SE VERIFICA EL SISTEMA");
    Color(BLACK,WHITE);
    gotoxy(0,6);
    linea(Largo);
    gotoxy(0,7);
    Color(BLACK,WHITE);
    //printf("\n");
}

/*Funci�n:  finaliza() sin par�metros
  Acci�n:   Muestra el mensaje de salida del sistema*/

void finaliza()
{
    cls();
    gotoxy(0,2);
    linea(Largo);
    gotoxy(0,3);
    Color(WHITE,RED);
    printf("                                                                                ");
    gotoxy(29,3);
    printf("PROGRAMA FINALIZADO");
    Color(BLACK,WHITE);
    gotoxy(0,4);
    linea(Largo);
}

/*Funci�n:  gotoxy(pasar por valor la coordenada x de la pantalla,pasar por valor la coordenada y de la pantalla)
  Acci�n:   Ubica el cursor en la posici�n indicada por las coordenadas (x: 0-80, y: 0-25*/

void gotoxy(int x,int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

/*Funci�n:  completo() sin par�metros
  Acci�n:   Muestra un mensaje de operaci�n exitosa*/

void completo()
{
    printf("\n");
    linea(Largo);
    Color(GREEN,WHITE);
    printf("LA OPERACION SE COMPLETO EN FORMA EXITOSA                                       \n");
    Color(BLACK,WHITE);
    linea(Largo);
}

/*Funci�n:  verifica_fecha(pasar por valor el a�o, pasar por valor el mes, pasar por valor el d�a)
  Acci�n:   Devuelve 1 si la fecha es correcta y 0 si es incorrecta con su correspondiente mensaje*/

int verifica_fecha(int a,int m, int d)
{
    if (d>=1 && (m>=1 || m<=12) && a>=2020)
    {
        switch (m)
        {
            case 4: case 6: case 9: case 11:
                if (d<=30)
                    return 1;
                break;
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if (d<=31)
                    return 1;
                break;
            case 2: if (bisiesto(a)==1 && d<=29)
                        return 1;
                    else
                        if (d<=28)
                            return 1;
                    break;
        }
    }
    printf("\nFECHA ingresada es INVALIDA --> [REINTENTE] <--\n");
    return 0;
}

/*Funci�n:  verifica_numero_rango(pasar por valor el dato, pasar por valor el rango m�nimo, pasar por valor el rango m�ximo)
  Acci�n:   Devuelve 1 si el dato ingresado es correcto y 0 si no lo es*/

int verifica_numero_rango(int numero,int rango_min,int rango_max)
{
    if (numero>=rango_min && numero<=rango_max)
        return 1;
    else
        printf("El NUMERO ingresado est� fuera del RANGO\n");
    return 0;
}

/*Funci�n:  letra_comprobante(pasar por valor el dato num�rico)
  Acci�n:   Devuelve A o B dependiendo el n�mero de comprobante*/

char *letra_comprobante(int numero)
{
    static char letra[2];
    memset(letra,0,sizeof(letra));
    switch (numero)
    {
        case 1: case 2: case 3:     strcpy(letra,"A");
                                    break;
        case 6: case 7: case 8:     strcpy(letra,"B");
                                    break;
        case 11: case 12: case 13:  strcpy(letra,"C");
                                    break;
    }
    return letra;
}

/*Funci�n:  nombre_comprobante(pasar por valor el dato num�rico, pasar por valor un caracter 'c' corto/'l' largo)
  Acci�n:   Devuelve el nombre del comprobante, largo o corto dependiendo de la necesidad del usuario*/

char *nombre_comprobante(int numero,char largo)
{
    static char nombre[16];
    strcpy(nombre,"");
    memset(nombre,0,sizeof(nombre));
    switch (numero)
    {
        case 1: case 6: case 11:    if (largo=='l')
                                    strcpy(nombre,"FACTURA");
                                        else
                                    strcpy(nombre,"FV");
                                    break;
        case 2: case 7: case 12:    if (largo=='l')
                                        strcpy(nombre,"NOTA DE DEBITO");
                                    else
                                        strcpy(nombre,"ND");
                                    break;
        case 3: case 8: case 13:    if (largo=='l')
                                        strcpy(nombre,"NOTA DE CREDITO");
                                    else
                                        strcpy(nombre,"NC");
                                    break;
    }
    return nombre;
}

/*Funci�n:  recuadro(pasar por valor la posici�n dentro del recuadro, pasar por valor el largo que va a tener)
  Acci�n:   Muestra por pantalla la l�nea pedida del recuadro
  Datos:    Los caracteres especiales del recuadro est�n definidos por 218,191,195,180,192,217,179 de la tabla ASCII*/

void recuadro(int pos,int largo)
{
    int j;
    char borde[7]={218,191,195,180,192,217,179};
    printf("%c",borde[pos]);
    for(j=0;j<largo;j++)
        printf("%c",196);
    printf("%c",borde[pos+1]);
}


void menu(int *opcion, menuopciones m[], int r) {
    int opcionSeleccionada = 0;

    while(true) {

        system("cls"); // Limpia la pantalla (solo en sistemas Windows, puedes usar alternativas en otros sistemas)

        Color(BLUE,YELLOW);
        printf("%s\n", m[0].menu);

        // Muestra las opciones del menú
        Color(BLACK,WHITE);
        for (int i = 1; i < r; i++) {
            printf("%d. %s\n", i , m[i].menu);
        }

        printf("\nIngrese el numero de la opcion y presione Enter: ");
        scanf("%d", &opcionSeleccionada);

        if (opcionSeleccionada >= 1 && opcionSeleccionada < r) {
            if(opcionSeleccionada == (r-1) )
                {
                    *opcion = 0;
                }else{
                    *opcion = opcionSeleccionada;
                }
            return; // Sale de la función si la opción es válida
        }
    }
}


/*
void submenu(int *opcion, menuopciones m[], int r, int y) {

    int opcionSeleccionada = 0;

    while (true) {
        system("cls"); // Limpia la pantalla (solo en sistemas Windows, puedes usar alternativas en otros sistemas)
        Color(BLUE,YELLOW);
        printf("%s\n", m[0].menu);
        // Muestra las opciones del menú
        Color(BLACK,WHITE);
        for (int i = 1; i < r; i++) {
            gotoxy(1, y + i);
            printf("%d. %s\n", i , m[i].menu);
        }

        printf("\n Ingrese el numero de la opcion y presione Enter: ");
        scanf("%d", &opcionSeleccionada);

        if (opcionSeleccionada >= 1 && opcionSeleccionada < r) {
            *opcion = opcionSeleccionada;

            return; // Sale de la función si la opción es válida
        }
    }


    int opcionSeleccionada = 0;
    gotoxy(0,y);
    Color(BLUE,YELLOW);
    printf("                                                                                ");
    gotoxy(0,y);
    printf("%s",m[0].menu);
    do
    {
        for(int i=1;i<r;i++)
        {
            gotoxy(1, y + i);
            printf("%d. %s\n", i , m[i].menu);
        }

        printf("\n Ingrese el numero de la opcion y presione Enter: ");
        scanf("%d", &opcionSeleccionada);

        Color(BLACK,WHITE);
        printf("\n");
        linea(Largo);


    } while (opcionSeleccionada < 1 && opcionSeleccionada >= r);
    *opcion = opcionSeleccionada;

    return; // Sale de la función si la opción es válida

}
*/


/*
Funci�n:  menu(pasar por referencia la variable opcion, pasar por valor la estructura menuopciones, pasar por valor
            la cantidad de items del men�)
  Acci�n:   Escribe en pantalla el men� de opciones usando como anexo la funci�n recuadro(p,l), para hacerlo funcionar
            utiliza las flechas arriba, abajo y enter

void menu(int *opcion,menuopciones m[],int r )
{
    char tecla;
    int pos_x=27,posicion=1,i,largo=25;
    do
    {
        cls();
        gotoxy(pos_x,1);
        Color(BLUE,YELLOW);
        recuadro(0,largo);
        gotoxy(pos_x,2);
        printf("%c%s%c",179,m[0].menu,179);
        gotoxy(pos_x,3);
        recuadro(2,largo);
        Color(BLUE,YELLOW);
        for(i=1;i<r;i++)
        {
            if (posicion>=1 && posicion<=r)
            {
                if (posicion==i)
                {
                    gotoxy(pos_x,i+3);
                    printf("%c",179);
                    Color(YELLOW,BLUE);
                    printf("%s",m[i].menu);
                    Color(BLUE,YELLOW);
                    printf("%c",179);
                    Color(BLACK,WHITE);
                }
                else
                {
                    gotoxy(pos_x,i+3);
                    Color(BLUE,YELLOW);
                    printf("%c%s%c\n",179,m[i].menu,179);
                }
            }
        }
        gotoxy(pos_x,r+3);
        Color(BLUE,YELLOW);
        recuadro(4,largo);
        Color(BLACK,WHITE);
        tecla=getch();
        switch (tecla)
        {
            case 80:    posicion++;
                        if (posicion>r-1)
                            posicion=1;
                        break;
            case 72:    posicion--;
                        if (posicion<1)
                            posicion=r-1;
                        break;
            case 13:    if (r-1!=posicion)
                            *opcion=posicion;
                        else
                            *opcion=0;
                        break;
        }
    } while (tecla!=13);
}
*/



/*Funci�n:  menu(pasar por referencia la variable opcion, pasar por valor la estructura menuopciones, pasar por valor
            la cantidad de items del men�, pasar por valor la posici�n vertical en la pantalla)
  Acci�n:   Escribe en pantalla el submen� de opciones usando como anexo la funci�n recuadro(p,l), para hacerlo funcionar
            utiliza las flechas derecha, izquierda, enter, escape
*/
void submenu(int *opcion,menuopciones m[],int r,int y)
{
    char tecla;
    int posicion=1,i;
    gotoxy(0,y);
    Color(BLUE,YELLOW);
    printf("                                                                                ");
    gotoxy(0,y);
    printf("%s",m[0].menu);
    do
    {
        for(i=1;i<r;i++)
        {
            if (posicion>=1 && posicion<=r)
            {
                if (posicion==i)
                {
                    gotoxy(i*11,y);
                    Color(YELLOW,BLUE);
                    printf("[%s]",m[i].menu);
                }
                else
                {
                    gotoxy(i*11,y);
                    Color(BLUE,YELLOW);
                    printf(" %s ",m[i].menu);
                }
            }
        }
        Color(BLACK,WHITE);
        printf("\n");
        linea(Largo);
        tecla=getch();
        switch (tecla)
        {
            case 77:    posicion++;
                        if (posicion>r-1)
                            posicion=1;
                        break;
            case 75:    posicion--;
                        if (posicion<1)
                            posicion=r-1;
                        break;
            case 13:    if (r!=posicion)
                            *opcion=posicion;
                        break;
            case 27:    *opcion=0;
                        break;
        }
    } while (tecla!=13 && tecla!=27);
}


/*Funci�n:  noEncontrado() sin par�metros
  Acci�n:   Muestra un mensaje de registro inexistente*/

void noEncontrado()
{
    printf("\n");
    linea(Largo);
    Color(RED,WHITE);
    printf("REGISTRO/s INEXISTENTE/s                                                        \n");
    Color(BLACK,WHITE);
    linea(Largo);
}

/*Funci�n:  cancela() sin par�metros
  Acci�n:   Muestra un mensaje de operaci�n cancelada*/

void cancela()
{
    printf("\n");
    linea(Largo);
    Color(RED,WHITE);
    printf("OPERACION CANCELADA                                                             \n");
    Color(BLACK,WHITE);
    linea(Largo);
}

/*Funci�n:  verificaCUIT(pasar por valor la cadena de caracteres que identifica al documento)
  Acci�n:   Regresa 1 si el documento ingresado es v�lido, 0 si no lo es*/

int verificaCUIT(char cuit_cuil_dni[])
{
    int i,contador=0,digitos[10]={5,4,3,2,7,6,5,4,3,2};
    for (i=0;i<strlen(cuit_cuil_dni)-1;i++)
        if (cuit_cuil_dni[i]-48>=0 && cuit_cuil_dni[i]-48<=9)
            contador=contador+(cuit_cuil_dni[i]-48)*digitos[i];
        else
            return 0;
    if (strlen(cuit_cuil_dni)==11)
    {
        contador=contador%11;
        contador=11-contador;
        if (cuit_cuil_dni[10]-48==contador)
            return 1;
    }
    else
        if (strlen(cuit_cuil_dni)>6 && strlen(cuit_cuil_dni)<9)
            return 1;
    return 0;
}

/*Funci�n:  nombreDocumento(pasar por valor el c�digo num�rico que identifica el documento)
  Acci�n:   Devuelve el nombre del tipo de comprobante*/

char *nombreDocumento(int tipo)
{
    static char tipo_documento[20];
    memset(tipo_documento,0,sizeof(tipo_documento));
    switch (tipo)
    {
        case 80:    strcpy(tipo_documento,"CUIT");
                    break;
        case 86:    strcpy(tipo_documento,"CUIL");
                    break;
        case 96:    strcpy(tipo_documento,"DNI");
                    break;
        case 99:    strcpy(tipo_documento,"Sin Identificar");
                    break;
        default:    strcpy(tipo_documento,"DESCONOCIDO");
    }
    return tipo_documento;
}

/*Funci�n:  capturaCaracter(pasar por valor la cantidad de caracteres a cargar)
  Acci�n:   Captura los caracteres transformandolos a n�meros hasta conseguir la cantidad de caracteres o presionar enter
  Objetivo: Devolver en una variable num�rica el n�mero digitado*/

int capturaCaracter(int cant_caracteres)
{
    char caracter;
    int valorNumerico=0;
    do
    {
        do
        {
            caracter=getch();
        } while ((caracter-48<0 || caracter-48>9) && caracter-13!=0);
        printf("%c",caracter);
        if (caracter-13!=0)
        {
            valorNumerico=(valorNumerico*10)+(caracter-48);
            cant_caracteres--;
        }
        else
            cant_caracteres=0;
    } while (cant_caracteres!=0);
    return valorNumerico;
}

/*Funci�n:  tipoIVA(pasar por valor el c�digo num�rico que identifica al tipo de IVA)
  Acci�n:   Devuelve el nombre correspondiente al c�digo*/

char *tipoIVA(int valor)
{
    static char tipo_iva[25];
    memset(tipo_iva,0,sizeof(tipo_iva));
    switch (valor)
    {
        case 1: strcpy(tipo_iva,"RESPONSABLE INSCRIPTO");
                break;
        case 2: strcpy(tipo_iva,"MONOTRIBUTO");
                break;
        case 3: strcpy(tipo_iva,"CONSUMIDOR FINAL");
                break;
        case 4: strcpy(tipo_iva,"EXENTO");
                break;
        case 5: strcpy(tipo_iva,"SIN IDENTIFICAR");
    }
    return tipo_iva;
}

/*Funci�n:  invalido() sin parametros
  Acci�n:   Devuelve un mensaje indicando que el dato ingresado es inv�lido y pidiendo que reintente.*/

void archivoInvalido()
{
    linea(Largo);
    Color(RED,WHITE);
    printf("El ARCHIVO que se intent%c ABRIR no EXISTE                                       \n",162);
    Color(BLACK,WHITE);
    linea(Largo);
    pausa();
}

/*Funci�n:  archivoGeneraComprobante(pasar por valor la coordenada vertical de la pantalla)
  Acci�n:   Devuelve un mensaje indicando que el comprobante se guardo y el archivo se gener� con exito.*/

void archivoGeneraComprobante()
{
    linea(Largo);
    Color(GREEN,WHITE);
    printf("El COMPROBANTE se GUARDO y GENERO en forma EXITOSA                              ");
    Color(BLACK,WHITE);
}

/*Funci�n:  cargarFecha(pasar por referencia el dia, mes, a�o del d�a, pasar por valor las coordenas x,y de la pantalla,
            pasar por valor la leyenda)
  Acci�n:   Verifica y retorna la fecha cargada.*/

void cargarFecha(int *dia,int *mes,int *anio,int x,int y,char leyenda[])
{
    time_t date;
    struct tm *tm;
    date=time(NULL);
    tm=localtime(&date);
    do
    {
        gotoxy(0,y);
        printf("\nFecha %s [DD/MM/AAAA] => __/__/____",leyenda);
        gotoxy(x,y+1);
        *dia=capturaCaracter(2);
        gotoxy(x+3,y+1);
        *mes=capturaCaracter(2);
        gotoxy(x+6,y+1);
        *anio=capturaCaracter(4);
    } while (verifica_fecha(*anio,*mes,*dia)==0 || (*anio<1900+tm->tm_year && *dia<tm->tm_mday && *mes<tm->tm_mon+1));
    gotoxy(0,y+2);
    printf("                                                                                ");
    gotoxy(0,y+2);
}

/*Funci�n:  compararFechas(pasar por valor dia, mes y a�o de la fecha actual y dia, mes y a�o fecha vencimiento)
  Acci�n:   Retorna 1 si es menor o igual, 0 si est� vencida.*/

int compararFechas(int dia_1,int mes_1,int anio_1,int dia_v,int mes_v,int anio_v)
{
    int fecha_1=0,fecha_v=0;
    fecha_1=(anio_1*100+mes_1)*100+dia_1;
    fecha_v=(anio_v*100+mes_v)*100+dia_v;
    if (fecha_1<fecha_v)
        return 1;
    else
        if (fecha_1==fecha_v)
            return 0;
    return -1;
}

/*Funci�n:  desplazamiento(pasar por valor la estructura con los registros, pasar por valor
            el n�mero de registro "dato", pasar por valor el rango del vector)
  Acci�n:   Crea una lista desplegable que devuelve un valor entero correspondiente a la posici�n del registro dentro
            del archivo.*/

int listaDesplegable(lista_Desplegable registro[],int dato,int r)
{
    char tecla;
    int posicion=0,largo=68,opcion;
    do
    {
        cls();
        leyendaRegistro(dato);
        gotoxy(5,3);
        recuadro(0,largo);
        gotoxy(5,4);
        mostrarRegistroLeyenda(dato,4);
        gotoxy(5,5);
        recuadro(2,largo);
        mostrarRegistro(registro,r,posicion,6);
        tecla=getch();
        switch (tecla)
        {
            case 80:    posicion++;
                        if (posicion>r-1)
                            posicion=0;
                        break;
            case 72:    posicion--;
                        if (posicion<0)
                            posicion=r-1;
                        break;
            case 13:    if (r!=posicion)
                            opcion=posicion;
                        else
                            opcion=0;
                        break;
        }
    } while (tecla!=13);
    return opcion;
}

/*Funci�n:  leyendaRegistro(pasar por valor el registro num�rico del dato)
  Acci�n:   Imprime por pantalla la leyenda principal de la Funci�n lista desplegable.*/

void leyendaRegistro(int dato)
{
    linea(Largo);
    switch (dato)
    {
        case 1: Color(WHITE,RED);
                printf("SELECCIONE EL TALONARIO                                      TECLAS [UP] [DOWN] \n");
                Color(BLACK,WHITE);
                break;
        case 2: Color(WHITE,RED);
                printf("INGRESE LOS ITEMS A FACTURAR                                 TECLAS [UP] [DOWN] \n");
                Color(BLACK,WHITE);
                break;
        case 3: Color(WHITE,RED);
                printf("SELECCIONE LA FACTURA PARA ANULAR                            TECLAS [UP] [DOWN] \n");
                Color(BLACK,WHITE);
                break;
        case 4: Color(WHITE,RED);
                printf("SELECCIONE EL CLIENTE A MODIFICAR                            TECLAS [UP] [DOWN] \n");
                Color(BLACK,WHITE);
                break;
    }
    linea(Largo);
}

/*Funci�n:  mostrarRegistroLeyenda(pasar por valor el n�mero correspondiente al dato registro, pasar por valor la
            posicion y de la pantalla)
  Acci�n:   Imprime en pantalla la cabecera del listado correspondiente al dato que se est� buscando en la lista desplegable
            1=Talonario, 2=Stock, 3 Comprobante.*/

void mostrarRegistroLeyenda(int registro,int y)
{
    switch (registro)
    {
        case 1: printf("%cCod. TC N%c Comprobante     Est. Tipo",179,167);
                break;
        case 2: printf("%cCod. Nombre Producto           Descripci%cn",179,162);
                break;
        case 3: printf("%cCod. Fecha      N%c Factura     Total",179,167);
                break;
        case 4: printf("%cId.  Raz%cn Social         Documento   Nombre Comercial",179,162);
                break;
    }
    gotoxy(74,y);
    printf("%c",179);
}

/*Funci�n:  mostrarRegistro(pasar por valor vector talonario, pasar por valor vector stock, pasar por valor el rango,
            pasar por valor la posicion, pasar por valor el dato, pasar por valor la posicion y de la pantalla.
  Acci�n:   Imprime por pantalla el resultado del desplazamiento de la lista desplegable.*/

void mostrarRegistro(lista_Desplegable registro[],int r,int posicion,int y)
{
    int j,rango=3,inc=1;
    if (r<3)
        rango=r;
    for(j=0;j<rango;j++)
    {
        if (posicion>=0 && posicion<r)
        {
            if (posicion==posicion-j)
            {
                gotoxy(1,y);
                printf("    %c",179);
                Color(RED,WHITE);
                printf("                                                                    ");
                gotoxy(6,y);
                printf("%s",registro[posicion+j].registro);
                Color(BLACK,WHITE);
                gotoxy(74,y++);
                printf("%c    ",179);
            }
            else
            {
                gotoxy(1,y);
                if (posicion+j<r)
                    printf("    %c%s",179,registro[posicion+j].registro);
                else
                {
                    if (posicion+j==r && j==2)
                        inc=2;
                    printf("    %c%s",179,registro[j-inc].registro);
                }
                gotoxy(74,y++);
                printf("%c",179);
            }
        }
    }
    gotoxy(5,y);
    recuadro(4,Largo-12);
}

/*Funci�n:  Color(pasar por valor el color de fondo, pasar por valor el color del texto)
  Acci�n:   Muestra en pantalla el color seleccionado para los caracteres.*/

void Color(int Background, int Texto)
{
    HANDLE Console=GetStdHandle(STD_OUTPUT_HANDLE);
    int New_Color=Texto+(Background*16);
	SetConsoleTextAttribute(Console,New_Color);
}

/*Funci�n:  registroDuplicado(sin parametros)
  Acci�n:   Muestra por pantalla un mensaje si un registro est� duplicado.*/

void registroDuplicado()
{
    linea(Largo);
    Color(RED,WHITE);
    printf("REGISTRO DUPLICADO                                                              \n");
    Color(BLACK,WHITE);
    linea(Largo);
}
