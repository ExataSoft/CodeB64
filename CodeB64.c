/* Algoritmo de codificação Base64, 
   diretamente da base decimal sem usar 
   base binária e operador de deslocamento de bits. 
   Acesse https://www.onlinegdb.com/online_c_compiler 
   para executar testes. 
*/ 
#include <stdio.h>  
#define Max 100 //Comprimento máximo da String.  
  
//-------------------------------  
// Base64=[A..Z,a..z,0..9,/,+]  
// Exemplos: DtoB(0)  retorna 'A'  
//           DtoB(25) retorna 'Z'  
//           DtoB(63) retorna '+'  
//-------------------------------  
char DtoB (int D)  
{  
  if(D<26)  
    return 'A' + D;  
  else   
  if(D<52)  
    return 'a'+(D-26);          
  else if(D<62)  
    return '0'+(D-52);                
  else if(D<63)   
    return '/';  
  else return '+';       
}  
  
//--------------------------------------  
//Comprimento da String recursivamente.   
//--------------------------------------  
int len(char *s)  
{  
   return (*s)?1+len(++s):0;      
}  
  
//--------------------------------  
//Codifica uma String em Base64. 
//Suporta apenas caracteres  
//imprimíveis. ASCII - 32 a 126 
//--------------------------------  
void CodeB64(char *sd, char *sc)  
{ char a,b,c;   
  int i,k=0,p=0,t=len(sd),n=t/3,r=t%3;    
  for(i=0;i<n;i++)  
  {     
    a=sd[k++]; b=sd[k++]; c=sd[k++];  
    sc[p++]=DtoB(a/4);  
    sc[p++]=DtoB((a%4)*16+b/16);  
    sc[p++]=DtoB((b%16)*4 + c/64);  
    sc[p++]=DtoB(c%64);  
  }        
  if(r)  
  {  
    a=sd[k++]; b=0;  
    if(r-1) b=sd[k++];  
    sc[p++]=DtoB(a/4);  
    sc[p++]=DtoB((a%4)*16+b/16);  
    sc[p]='=';  
    if(r-1) sc[p++]=DtoB((b%16)*4);  
    sc[p++]='=';         
  }  
  sc[p]='\x0';  
}  
//---------------------------------------   
//Rotina Principal.  
//---------------------------------------  
int main ()  
  {       
    char sd[Max];  
    char sc[Max]; 
    
    printf("\n [ CodeB64 - Codifica em Base64 ]\n");
    printf(" Digite a String a ser codificada: ");
    scanf("%s",sd);
    
    CodeB64(sd,sc);  
    printf("\n Código em Base64: %s",sc);  
    return 0;  
  }  
//----------------------------------------  
