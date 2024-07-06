#include"pacientes.h"

void cadastra_paciente(Pacientes paci[]){

   int tamanho;
   int confirma;
   int novo_tamanho;

   printf("Digite quantos pacientes deseja-se cadastrar: ");
   scanf("%i", &tamanho);
   setbuf(stdin, NULL);

   paci = (Pacientes*)malloc(tamanho * (sizeof(Pacientes)));//alocacao de memoria para o cadastro 

   for(int i = 0; i < tamanho; i++){

      printf("\n");
      printf("Digite o nome do paciente (%i): ", i);
      fgets(paci[i].nomes_pacientes, 99, stdin);
      paci[i].nomes_pacientes[strcspn(paci[i].nomes_pacientes, "\n")] = '\0';
      setbuf(stdin, NULL);

      printf("\n");
      printf("Digite a enfermidade do paciente (%i): ", i);
      fgets(paci[i].enfermidades, 99, stdin);
      paci[i].enfermidades[strcspn(paci[i].enfermidades, "\n")] = '\0';
      setbuf(stdin, NULL);
 
      printf("\n");
      printf("Digite a idade do paciente (%i) em anos de vida: ", i);
      scanf("%i", &paci[i].idades);
      setbuf(stdin, NULL);

      while(paci[i].idades < 0){

         printf("\n");
         printf("Favor entrar com uma idade valida!\n");
         printf("Digite a idade do paciente (%i): ", i);
         scanf("%i", &paci[i].idades);
         setbuf(stdin, NULL);

      }//tratamento de valor negativo

      printf("\n");
      printf("Digite a altura do paciente (%i) em metros: ", i);
      scanf("%f", &paci[i].alturas);
      setbuf(stdin, NULL);

      while(paci[i].alturas <= 0){

         printf("\n");
         printf("Favor entrar com uma altura valida!\n");
         printf("Digite a altura do paciente (%i): ", i);
         scanf("%f", &paci[i].alturas);
         setbuf(stdin, NULL);

      }//tratamento de valor negativo ou zero

      printf("\n");
      printf("Digite o peso do paciente (%i) em kilos: ", i);
      scanf("%f", &paci[i].pesos);
      setbuf(stdin, NULL);

      while(paci[i].pesos <= 0){

         printf("\n");
         printf("Favor entrar com um peso valida!\n");
         printf("Digite a altura do paciente (%i): ", i);
         scanf("%f", &paci[i].pesos);
         setbuf(stdin, NULL);

      }//tratamento de valor negativo

      paci[i].id = i;//atribui um identificador para cada paciente

   }//for tamanho

   do{

      printf("\n");
      printf("Deseja realizar mais cadastros? (0 para sim e 1 para nao)\n");
      scanf("%i", &confirma);
      setbuf(stdin, NULL);

      while (confirma != 0 || confirma != 1){

         printf("\n");
         printf("Digite 0 para continuar o cadastro ou 1 para interromper:\n");
         scanf("%i", &confirma);
         setbuf(stdin, NULL);

      }//se opcao for invalida digita de novo      
      
      if(confirma == 0){

         printf("\n");
         printf("Qual a quantidade dos novos cadastros?\n");
         scanf("%i", &novo_tamanho);
         setbuf(stdin,NULL);

         while(novo_tamanho <= 0){
            
            printf("Sem valores negativos ou zero.\n");
            printf("Digite a quantidade dos novos cadastros?\n");
            scanf("%i", &novo_tamanho);
            setbuf(stdin,NULL);

         }//tratamento da nova quantidade de cadastros         

         paci = (Pacientes*)realloc(paci, (tamanho + novo_tamanho) * (sizeof(Pacientes)));//realocacao de memoria para os novos cadastros

         for(int i = tamanho; i < tamanho + novo_tamanho; i++){

            printf("\n");
            printf("Digite o nome do paciente (%i): ", i);
            fgets(paci[i].nomes_pacientes, 99, stdin);
            paci[i].nomes_pacientes[strcspn(paci[i].nomes_pacientes, "\n")] = '\0';
            setbuf(stdin, NULL);

            printf("\n");
            printf("Digite a enfermidade do paciente (%i): ", i);
            fgets(paci[i].enfermidades, 99, stdin);
            paci[i].enfermidades[strcspn(paci[i].enfermidades, "\n")] = '\0';
            setbuf(stdin, NULL);
      
            printf("\n");
            printf("Digite a idade do paciente (%i) em anos de vida: ", i);
            scanf("%i", &paci[i].idades);
            setbuf(stdin, NULL);

            while(paci[i].idades < 0){

               printf("\n");
               printf("Favor entrar com uma idade valida!\n");
               printf("Digite a idade do paciente (%i): ", i);
               scanf("%i", &paci[i].idades);
               setbuf(stdin, NULL);

            }//tratamento de valor negativo

            printf("\n");
            printf("Digite a altura do paciente (%i) em metros: ", i);
            scanf("%f", &paci[i].alturas);
            setbuf(stdin, NULL);

            while(paci[i].alturas <= 0){

               printf("\n");
               printf("Favor entrar com uma altura valida!\n");
               printf("Digite a altura do paciente (%i): ", i);
               scanf("%f", &paci[i].alturas);
               setbuf(stdin, NULL);

            }//tratamento de valor negativo ou zero

            printf("\n");
            printf("Digite o peso do paciente (%i) em kilos: ", i);
            scanf("%f", &paci[i].pesos);
            setbuf(stdin, NULL);

            while(paci[i].pesos <= 0){

               printf("\n");
               printf("Favor entrar com um peso valido!\n");
               printf("Digite a altura do paciente (%i): ", i);
               scanf("%f", &paci[i].pesos);
               setbuf(stdin, NULL);

            }//tratamento de valor negativo

            paci[i].id = i;

            tamanho = tamanho + novo_tamanho;

         }//for tamanho + novo tamanho informado

      }//if continua cadstro

      else if(confirma == 1){
         
         break;

      }//else if interrompe cadastro   

   }while(confirma == 0 || confirma == 1);//while desejar continuar o cadastro

   FILE *arquivo = fopen("cadastro_de_pacientes.dat", "wb");

   for(int i = 0; i < tamanho; i++){

      fwrite(paci[i].nomes_pacientes, sizeof(char), 99, arquivo);
      fwrite(paci[i].id, sizeof(int), 1, arquivo);
      fwrite(paci[i].idades, sizeof(int), 1, arquivo);
      fwrite(paci[i].alturas, sizeof(float), 1, arquivo);
      fwrite(paci[i].pesos, sizeof(float), 1, arquivo);
      fwrite(paci[i].enfermidades, sizeof(char), 1, arquivo);     

   }//coloca os dados atribuidos em um arquivo texto

   printf("\nO cadastro foi salvo no arquivo ""cadastro_de_pacientes.txt"".\n");

   fclose(arquivo);
   free(paci);

return;
}//funcao cadastra paciente

