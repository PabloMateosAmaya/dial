#include <iostream>
#include <stdio.h>
#include <time.h>


using namespace std ;


/*

    PRÁCTICA 1: ANÁLISIS DE LA EFICIENCIA DE LOS ALGORITMOS (C/C++)

    ASIGNATURA: DISEÑO DE ALGORITMOS
    CURSO:      2022-2023
    SUBGRUPO:   U1 / U2

    APELLIDOS:Mateos Amaya
    NOMBRE:Pablo

*/



int queHace1 (int v[], int N){
    
  int mejor, suma ;
  
  mejor = 0 ;
  
  for (int i = 0 ; i < N ; i++){
      
    for (int j = i ; j < N ; j++){
        
       suma = 0 ;
       
       for (int k = i ; k <= j ; k++) suma = suma + v[k] ;
       
       if (suma > mejor) mejor = suma ;
       
    }
    
  }
  
  return mejor ;
  
}



/*
 
 EJERCICIO 1: Escribe el código en C++ de un algoritmo 'queHace2'
 que resuelva el mismo problema que el del algoritmo anterior
 'queHace1' pero usando solo dos bucles anidados.
 
 */
 
/*mejor=max{sumatorio[v[k]/0<=i<=k<=j<N]*/
int queHace2(int v[], int N){
        int suma , mejor;
        
        mejor = 0;
        for (int i = 0 ; i < N ; i++){
            suma = 0;
            for (int j = i ; j < N ; j++){
                suma += v[j];
                if (mejor < suma) {mejor = suma; }
            }
        }
    
    
    return mejor;
}
/*mejor=max{sumatorio[v[k]/0<=i<=k<=j<N]*/

/*
 
 EJERCICIO 2: Escribe el código en C++ de un algoritmo 'queHace3'
 que resuelva el mismo problema que el del algoritmo anterior
 'queHace1' pero usando solo un bucle.
 
 */
 
/*{v vector de longitud N>=1]}*/
int queHace3(int v[], int N){
    int suma , mejor;
    
    mejor = v[0]; 
    suma = 0;
    
    for (int i = 0 ; i < N ; i++){
        if (v[i] < suma + v[i]) {
            suma += v[ i ];
        }
        else{
            suma=v[i];
            
        }
        if (suma>mejor){ mejor=suma;}
        }
        
        
    
    return mejor;
}
/*mejor=max{sumatorio[v[k]/0<=i<=k<=j<N]*/



int main()
{
    
    /* EJECUCIÓN DE LOS PROGRAMAS */
    
    const int DIM = 50 ;
    int v[DIM] ;
    int N ;
   
    cout << "Introduce la longitud del vector: " ;
    cin >> N ;
    cout << endl ;
    
    cout << "Introduce las " << N << " componentes del vector: \n" ;
    for (int i = 0 ; i < N ; i++) cin >> v[i] ;
    cout << endl ;

    cout << "Vector = " ;
    for (int i = 0 ; i < N ; i++) cout << v[i] << " " ;
    cout << endl << endl ;
    cout << "Resultado de la funcion 'queHace1': " << queHace1(v, N) << "\n" ;
    cout << endl ;
    cout << "Resultado de la funcion 'queHace2': " << queHace2(v, N) << "\n" ;
    cout << endl ;
    cout << "Resultado de la funcion 'queHace3': " << queHace3(v, N) << "\n" ;
    cout << endl ;


    /* MEDIDAS DEL TIEMPO DE EJECUCION DE LOS PROGRAMAS */
  
    
    int repeticiones ;
    int tamanyos[DIM] ;
    double tiempos[DIM] ;
    clock_t t1, t2 ;
    
    cout << "Introduce el numero de repeticiones: " ;
    cin >> repeticiones ;
    cout << endl ;

    for (int i = 0 ; i < N ; i++) tamanyos[i] = i + 1 ;
  
    cout << "Medidas del tiempo de ejecucion del programa 'queHace1': \n" << endl ;

    for (int k = 0 ; k < N ; k++){
        
       t1 = clock();
       
       for (int i = 0 ; i < repeticiones ; i++){
           
          queHace1(v, tamanyos[k]) ;
          
       }
       
       t2 = clock() ;
       
       tiempos[k] = (double(t2 - t1) / CLOCKS_PER_SEC) / repeticiones ;
       
    }
    
    for (int k = 0 ; k < N ; k++)
         cout << "Longitud = " << tamanyos[k] << "; Tiempo = " << tiempos[k] << endl ;
    
    cout << endl ;
    
    
    
    
    /*
     
     EJERCICIO 3: Escribe el código en C++ para obtener las medidas del tiempo de ejecución
     de los programas 'queHace2' y "queHace3', y compara los resultados obtenido con los del
     programa 'queHace1'. ¿Cuál de los tres programas es más eficiente? ¿Por qué?
     
     */
    cout << endl ;

    for (int i = 0 ; i < N ; i++) tamanyos[i] = i + 1 ;
  
    cout << "Medidas del tiempo de ejecucion del programa 'queHace2': \n" << endl ;

    for (int k = 0 ; k < N ; k++){
        
       t1 = clock();
       
       for (int i = 0 ; i < repeticiones ; i++){
           
          queHace2(v, tamanyos[k]) ;
          
       }
       
       t2 = clock() ;
       
       tiempos[k] = (double(t2 - t1) / CLOCKS_PER_SEC) / repeticiones ;
       
    }
    
    for (int k = 0 ; k < N ; k++)
         cout << "Longitud = " << tamanyos[k] << "; Tiempo = " << tiempos[k] << endl ;
    
    cout << endl ;
    
    cout << endl ;

    for (int i = 0 ; i < N ; i++) tamanyos[i] = i + 1 ;
  
    cout << "Medidas del tiempo de ejecucion del programa 'queHace3': \n" << endl ;

    for (int k = 0 ; k < N ; k++){
        
       t1 = clock();
       
       for (int i = 0 ; i < repeticiones ; i++){
           
          queHace3(v, tamanyos[k]) ;
          
       }
       
       t2 = clock() ;
       
       tiempos[k] = (double(t2 - t1) / CLOCKS_PER_SEC) / repeticiones ;
       
    }
    
    for (int k = 0 ; k < N ; k++)
         cout << "Longitud = " << tamanyos[k] << "; Tiempo = " << tiempos[k] << endl ;
    
    cout << endl;
    
}
