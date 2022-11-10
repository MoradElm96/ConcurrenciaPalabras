#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>

 

int contarPalabra1(FILE *f, char *nombreFichero, int ContadorPalabra1, int estado, int leido)
{
     
      
    char letra1 = 'e';
    char letra2 = 's';
    char letra3 = 't';
    char letra4 = 'a';

    f = fopen(nombreFichero, "r");

    while (!feof(f))
    {
        leido = tolower(fgetc(f));
       

        switch (estado)
        {
        case 0:
            if (leido == letra1)
                estado = 1;
            break;
        case 1:
            if (leido == letra2)
                estado = 2;
            else if (leido == letra1)
                estado = 2;
            else
                estado = 0;
            break;

        case 2:
            if (leido == letra3)
                estado = 3;
            else if (leido == letra2)
                estado = 3;
            else
                estado = 0;
            break;

        default: // estado 3
            if (leido == letra4)
            {
                estado = 0;
                ContadorPalabra1++;
            }
            else if (leido == letra1)
                estado = 1;
            else
                estado = 0;

            break;
        }
    }
    fclose(f);

    return ContadorPalabra1;
}

int contarPalabra2(FILE *f,char *nombreFichero, int ContadorPalabra2, int estado, int leido)
{

    char letra1 = 'l';
    char letra2 = 'o';
    char letra3 = 's';
    

   f = fopen(nombreFichero, "r");

    while (!feof(f))
    {
       
        leido = tolower(fgetc(f));
        switch (estado)
        {
        case 0:
            if (leido == letra1)
                estado = 1;
            break;
        case 1:
            if (leido == letra2)
                estado = 2;
            else if (leido == letra1)
                estado = 2;
            else
                estado = 0;
            break;

        default:
            if (leido == letra3){
                estado = 0;
                ContadorPalabra2++;
            }
            else if (leido == letra2)
                estado = 1;
            else
                estado = 0;
            break;

        
        }
    }
    fclose(f);
    return ContadorPalabra2;
}



int contarPalabra3(FILE *f,char *nombreFichero, int ContadorPalabra3, int leido,int estado)
{
    char letra1 = 'l';
    char letra2 = 'a';
  

    f = fopen(nombreFichero, "r");

    while (!feof(f))
    {
         leido = tolower(fgetc(f));
        switch (estado)
        {
        case 0:
            if (leido == letra1)
                estado = 1;
            break;

        default:
            if (leido == letra2)
            { 
                estado = 0;
                ContadorPalabra3++;
            }
                
            else if (leido == letra1)
                estado = 1;
            else
                estado = 0;
            break;

        }
         
        }

         fclose(f);
    return ContadorPalabra3;
    }
   
   


int contarPalabra4(FILE *f,char *nombreFichero, int ContadorPalabra4, int leido,int estado)
{

    char letra1 = 'l';
    char letra2 = 'o';
    char letra3 = 'r';
    char letra4 = 'e';
    char letra5 = 'm';

    //char palabra[50] = "lorem";

    f = fopen(nombreFichero, "r");
   


    while (!feof(f))
    {
        // printf("%c", leido);
        leido = tolower(fgetc(f));
        switch (estado)
        {
        case 0:
            if (leido == letra1)
                estado = 1;
            break;
        case 1:
            if (leido == letra2)
                estado = 2;
            else if (leido == letra1)
                estado = 2;
            else
                estado = 0;
            break;

        case 2:
            if (leido == letra3)
                estado = 3;
            else if (leido == letra2)
                estado = 3;
            else
                estado = 0;
            break;


        case 3:
            if(leido == letra4)
               estado=4;
            else if (leido == letra3)
                 estado = 4;
            else        
                 estado =0;
             break;     

        default: // estado 4
            if (leido == letra5)
            {
                estado = 0;
                ContadorPalabra4++;
            }
            else if (leido == letra1)
                estado = 1;
            else
                estado = 0;

            break;
        }
    }
    fclose(f);
    return ContadorPalabra4;
}

int contarPalabra5(FILE *f,char *nombreFichero, int ContadorPalabra5, int leido,int estado)
{

    char letra1 = 'i';
    char letra2 = 'p';
    char letra3 = 's';
    char letra4 = 'u';
    char letra5 = 'm';

 

    f = fopen(nombreFichero, "r");

    while (!feof(f))
    {
        // printf("%c", leido);
        leido = tolower(fgetc(f));
        switch (estado)
        {
        case 0:
            if (leido == letra1)
                estado = 1;
            break;
        case 1:
            if (leido == letra2)
                estado = 2;
            else if (leido == letra1)
                estado = 2;
            else
                estado = 0;
            break;

        case 2:
            if (leido == letra3)
                estado = 3;
            else if (leido == letra2)
                estado = 3;
            else
                estado = 0;
            break;


        case 3:
            if(leido == letra4)
               estado=4;
            else if (leido == letra3)
                 estado = 4;
            else        
                 estado =0;
             break;     

        default: // estado 4
            if (leido == letra5)
            {
                estado = 0;
                ContadorPalabra5++;
            }
            else if (leido == letra1)
                estado = 1;
            else
                estado = 0;

            break;
        }
    }
    fclose(f);
    return ContadorPalabra5;
}
/// funciones genericas para enviar y leer por Pipes para comunicar al padre el resultado
void enviarNumPalabras(int fd[], int numPalabras)
{
    // pipe fd
    close(fd[0]);
    write(fd[1], &numPalabras, sizeof(numPalabras));
    close(fd[1]);
}
// leo el numero escrito por el pipe y lo retorno, para posteriormente su comprobacion
int leerNumeroPalabras(int fd[])
{

    int resultado;
    close(fd[1]); // cerramos el descriptor de escritura
    read(fd[0], &resultado, sizeof(resultado));
    close(fd[0]);

    return resultado;
}

 static FILE *f;

int main(int argc, char *argv[])
{
  
   
    f= fopen(argv[1], "r"); //recibe por argumento el fichero texto
    if (!f)
    {
        printf("no se ha podido abrir el archivo");
        return 1;
    }
   

    if (argc < 2)
	{
		printf("Faltan los argumentos\n");
		exit(0);
	}

    char *nombreFichero = argv[1];

    int estado = 0;
    int contadorPalabra1 = 0;
    int contadorPalabra2 = 0;
    int contadorPalabra3 = 0;
    int contadorPalabra4 = 0;
    int contadorPalabra5 = 0;
    int leido; // variable para caracteres

    

    int fd1[2], fd2[2], fd3[2], fd4[2], fd5[2];
    pipe(fd1);
    pipe(fd2);
    pipe(fd3);
    pipe(fd4);
    pipe(fd5);

    pid_t pid_hijo1, pid_hijo2, pid_hijo3, pid_hijo4, pid_hijo5;

    /// HIJO1
    pid_hijo1 = fork();
    if (pid_hijo1 == 0)
    {
        printf("Soy el hijo 1 estoy contando la letra A... Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());
        enviarNumPalabras(fd1, contarPalabra1(f,nombreFichero, contadorPalabra1, estado, leido));
        sleep(1);
        exit(0);
    }

    /// HIJO 2
    pid_hijo2 = fork();
    if (pid_hijo2 == 0)
    {

        printf("Soy el hijo 2 estoy contando la letra E... Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());

        enviarNumPalabras(fd2, contarPalabra2(f,nombreFichero, contadorPalabra2, estado, leido));
        sleep(1);
        exit(0);
    }

    /// HIJO 3
    pid_hijo3 = fork();
    if (pid_hijo3 == 0)
    {

        printf("Soy el hijo 3 estoy contando la letra I... Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());
        enviarNumPalabras(fd3,contarPalabra3(f,nombreFichero, contadorPalabra3, estado, leido));
        sleep(1);
        exit(0);
    }

    /// HIJO 4
    pid_hijo4 = fork();
    if (pid_hijo4 == 0)
    {

        printf("Soy el hijo 4 estoy contando la letra O...  Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());
        enviarNumPalabras(fd4,contarPalabra4(f,nombreFichero, contadorPalabra4, estado, leido));
        sleep(1);
        exit(0);
    }

    /// HIJO 5
    pid_hijo5 = fork();
    if (pid_hijo5 == 0)
    {

        printf("Soy el hijo 5 estoy contando la letra U... Mi padre es= %d, Mi PID= %d \n", getppid(), getpid());
         enviarNumPalabras(fd5,contarPalabra5(f,nombreFichero, contadorPalabra5, estado, leido));
        sleep(1);
        exit(0);
    }

    // PADRE

    wait(NULL); // esperamos que terminen los hijos
    printf("\nProceso PADRE = %d, mi PID: %d \n", getppid(), getpid());
    //Duda como hacer que lea las palabras de una variable y dividirlos en char para poder hacer el diagrama de flujo
    printf("\nLa palabra 1 ESTA se repite : %d veces\n", leerNumeroPalabras(fd1));
    printf("\nLa palabra 2 LOS repite : %d veces\n", leerNumeroPalabras(fd2));
    printf("\nLa palabra 3 LA repite : %d veces\n", leerNumeroPalabras(fd3));
    printf("\nLa palabra 4 LOREM repite : %d veces\n", leerNumeroPalabras(fd4));
    printf("\nLa palabra 5 IPSUM se repite : %d veces\n", leerNumeroPalabras(fd5));

  

    printf("\nFin del programa\n");

    exit(0);
}
