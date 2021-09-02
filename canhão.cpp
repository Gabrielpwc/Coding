#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
int main()
{
 setlocale(LC_ALL, "Portuguese");
/******************************************************************************
Apresenta��o dos integrantes do grupo e introdu��o
*******************************************************************************/
 printf("\t---APS - Algor�tmos de Programa��o---\n\t---Lan�amento de Proj�teis---");
 printf("\nCurso: Ci�ncias da Programa��o\tCampus: Paulista 1\tPer�odo: Matutino");
 printf("\nNomes:\nGABRIEL PACH� WENZEL CARVALHO\t\tRA: 21568186");
 printf("\nHENRIQUE KIMIO HORIUCHI\t\t\tRA: 21516384");
 printf("\nISABELLE VIT�RIA CATEZANI DOS SANTOS\tRA: 21521184");
 printf("\nLUCCA RICHARD PEREZ\t\t\tRA: 21593430");
 printf("\nMATEUS KENJI VICENTE\t\t\tRA: 21539337");
 printf("\n\n");
/******************************************************************************
C�digo principal
*******************************************************************************/
 float radianos,sen,cosen,angulo,v0,g,ymax,t,xf,alvo,dalvo,malvo,al;
 int choose=0;
 printf("Digite a velocidade inicial(m/s):\n");
 scanf("%f",&v0);
 while(v0<0){
 printf("\a\nDigite um valor positivo para a velocidade:\n");
 scanf("%f",&v0);
 }
 printf("\nA seguir fa�a o mesmo para acelera��o(m/s^2):\n");
 scanf("%f",&g);
 while(g<0){
 printf("\a\nNesse caso, a=-g,a gravidade nao pode ser negativa, forne�a outro valor\n");
 scanf("%f",&g);
 }
 while(g==0){
 printf("\a\nForne�a um valor diferente de 0, pois ele n�o se moveria.\n");
 scanf("%f",&g);
 }
 printf("\nAgora, digite um angulo em graus(�)\n");
 scanf("%f",&angulo);
 while(angulo<=0 && angulo>=90){
 printf("\a\nO valor precisa estar entre 0 e 90� por favor tente novamente:\n");
 scanf("%f",&angulo);
 }
 printf("\nEnfim, Digite a dist�ncia do alvo ao canh�o(m) e seu tamanho, respctivamente(m)\n");
 scanf("%f%f",&dalvo,&alvo);
 while(alvo>50 && dalvo<0){
 printf("\a\nTamanho de alvo inv�lido, por favor digite um valorentre 0 e 50\n");
 scanf("%f",&alvo);
 }
 radianos = (angulo * M_PI)/180;
 printf("\n\n\t****Informa��es informadas****\n");
 printf("Velocidade(m/s):\t%f\n",v0);
 printf("Aceleracao(m/s^2):\t%f\n",g);
 printf("Angulo(�):\t\t%f\n",angulo);
 printf("Tamanho do alvo:\t%f\n",alvo);
 printf("Dist�ncia do alvo:\t%f\n\n",dalvo);
 start:
 printf("\nIndique o desejado:\n1)Calcular a Altura Maxima\n2)Calcular o tempo de trajeto\n3)Calcular o alcance horizontal.\n4)Calcular se o proj�til acertou o alvo ou n�o\n5)Calcule todas as infroma��es acima\n6)Sair.\n\n");
 scanf("%d",&choose);
 if(choose==1){
 sen= sin(radianos);
 ymax=(pow(v0,2)*(pow(sen,2)))/(2*g);
 printf("\aAltura m�xima(m)=%f\n",ymax);
 printf("\n\n");
 goto start;
 }
 if(choose==2){
 sen= sin(radianos);
 t=(2*v0*sen)/g;
 printf("\aTempo de voo(s)=%f\n",t);
 printf("\n\n");
 goto start;
 }
 if(choose==3){
 cosen=cos(radianos);
 sen= sin(radianos);
 xf=(2*pow(v0,2)*(cosen*sen)/g);
 printf("\aAlcance Horizontal(m)=%f\n",xf);
 printf("\n\n");
 goto start;
 }
 if(choose==4){
 cosen=cos(radianos);
 sen= sin(radianos);
 xf=(2*pow(v0,2)*(cosen*sen)/g);
 malvo=alvo+dalvo;
 if(xf<dalvo){
 al=dalvo-xf;
 printf("\nO proj�til n�o chegou no alvo por %f metros\n",al);
 }
 if(xf>dalvo && xf<malvo){
 printf("\no proj�til acertou o alvo\n");
 }
 if(xf>malvo){
 al=xf-malvo;
 printf("\no proj�til passou do alvo por %f metros\n",al);
 }
 goto start;
 }
 if(choose==5){
 sen= sin(radianos);
 ymax=(pow(v0,2)*(pow(sen,2)))/(2*g);
 printf("\aAltura m�xima(m)=\t%f\n",ymax);
 t=(2*v0*sen)/g;
 printf("\aTempo de trageto(s)=\t%f\n",t);
 cosen=cos(radianos);
 xf=(2*pow(v0,2)*(cosen*sen)/g);
 printf("\aAlcance Horizontal(m)=\t%f\n",xf);
 malvo=alvo+dalvo;
 if(xf<dalvo){
 al=dalvo-xf;
 printf("\nO proj�til n�o chegou no alvo por %f metros\n",al);
 }
 if(xf>dalvo && xf<malvo){
 printf("\no proj�til acertou o alvo\n");
 }
 if(xf>malvo){
 al=xf-malvo;
 printf("\no proj�til passou do alvo por %f metros\n",al);
 }
 goto start;
 }
 if(choose==6){
 system("pause");
 exit(1);
 }
 end:
 return 0;}
